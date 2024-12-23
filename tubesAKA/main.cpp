#include <iostream>
#include <fstream> // Untuk menulis data ke file
#include <chrono>  // Untuk menghitung waktu eksekusi
#include <cmath>   // Untuk menghasilkan angka besar
using namespace std;
using namespace std::chrono;

// Fungsi iteratif untuk menghitung jumlah digit
int countDigitsIterative(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

// Fungsi rekursif untuk menghitung jumlah digit
int countDigitsRecursive(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + countDigitsRecursive(n / 10);
    }
}

int main() {
    // Uji untuk berbagai ukuran input
    for (int i = 1; i <= 10000000; i *= 10) {
        int jumlah = countDigitsIterative(i);
        int input = pow(10, i) - 1; // Bilangan dengan digit sebanyak i

        // Hitung waktu untuk iteratif
        auto startIterative = high_resolution_clock::now();
        countDigitsIterative(input);
        auto endIterative = high_resolution_clock::now();
        auto durationIterative = duration_cast<nanoseconds>(endIterative - startIterative).count();

        // Hitung waktu untuk rekursif
        auto startRecursive = high_resolution_clock::now();
        countDigitsRecursive(input);
        auto endRecursive = high_resolution_clock::now();
        auto durationRecursive = duration_cast<nanoseconds>(endRecursive - startRecursive).count();

        // Tulis data ke file
        cout << "Input size: " << i
             << ", Iterative: " << durationIterative << " ns"
             << ", Recursive: " << durationRecursive << " ns"
             << ", Digits: "<< jumlah << endl;
    }

    return 0;
}
