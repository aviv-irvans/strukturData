#include <iostream>
using namespace std;

int main() {
    int pilihan;
    int S[10];
    int top, data;

    cout << "=== PROGRAM STACK ===" << endl;
    cout << "1. PUSH dan POP berdasarkan nilai" << endl;
    cout << "2. PUSH sampai penuh lalu POP sampai kosong" << endl;
    cout << "Pilih program: ";
    cin >> pilihan;

    // PROGRAM 1
    if (pilihan == 1) {

        top = -1;

        cout << "\n=== PUSH DAN POP ===" << endl;

        while (true) {
            cout << "Input data: ";
            cin >> data;

            if (data == 999) {
                cout << "Program selesai." << endl;
                break;
            }

            // Jika data >= 60, PUSH
            if (data >= 60) {

                if (top == 9) {
                    cout << "Stack Penuh" << endl;
                    break;
                }

                top++;
                S[top] = data;

                cout << "Data " << data << " berhasil di-PUSH." << endl;
            }

            // Jika data < 60, POP
            else {

                if (top == -1) {
                    cout << "Stack Kosong" << endl;
                    break;
                }

                cout << "Data yang di-POP: " << S[top] << endl;
                top--;
            }
        }
    }

    // PROGRAM 2
    else if (pilihan == 2) {

        top = -1;

        cout << "\n=== PROSES PUSH ===" << endl;

        while (true) {
            cout << "Input data: ";
            cin >> data;

            // 999 = selesai input
            if (data == 999) {
                break;
            }

            // Jika stack penuh
            if (top == 9) {
                cout << "Stack Penuh" << endl;
                break;
            }

            // PUSH
            top++;
            S[top] = data;

            cout << "Data " << data << " berhasil di-PUSH." << endl;
        }

        // PROSES POP
        cout << "\n=== PROSES POP ===" << endl;

        while (top != -1) {
            cout << "Data yang di-POP: " << S[top] << endl;
            top--;
        }

        cout << "Stack Kosong" << endl;
    }

    else {
        cout << "Pilihan tidak tersedia." << endl;
    }

    return 0;
}