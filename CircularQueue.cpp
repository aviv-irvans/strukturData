#include <iostream>
using namespace std;

#define MAX 10

class CircularQueue {
private:
    int Q[MAX];
    int F;
    int R;
    int COUNTER;

public:

    // =========================================
    // INISIALISASI
    // =========================================
    CircularQueue() {
        F = 0;
        R = -1;
        COUNTER = 0;
    }

    // =========================================
    // CEK ANTRIAN PENUH
    // =========================================
    bool isFull() {
        return COUNTER == MAX;
    }

    // =========================================
    // CEK ANTRIAN KOSONG
    // =========================================
    bool isEmpty() {
        return COUNTER == 0;
    }

    // =========================================
    // INSERT SATU RECORD
    // =========================================
    void INSERT(int data) {

        if (COUNTER < MAX) {

            R = (R + 1) % MAX;
            Q[R] = data;
            COUNTER++;

            cout << "INSERT : " << data << endl;

        } else {

            cout << "Antrian penuh!" << endl;
        }
    }

    // =========================================
    // DELETE SATU RECORD
    // =========================================
    void DELETE() {

        if (COUNTER > 0) {

            cout << "DELETE : " << Q[F] << endl;

            F = (F + 1) % MAX;
            COUNTER--;

        } else {

            cout << "Antrian kosong!" << endl;
        }
    }

    // =========================================
    // SOAL 3
    // INSERT MAKSIMAL 10 RECORD
    // =========================================
    void isi10Record() {

        int data;

        cout << "\n====================================" << endl;
        cout << "      SOAL 3 - INSERT RECORD" << endl;
        cout << "====================================" << endl;

        for (int i = 1; i <= 10; i++) {

            // Jika antrian penuh, berhenti
            if (isFull()) {

                cout << "\nAntrian penuh!" << endl;
                cout << "Proses INSERT dihentikan." << endl;

                break;
            }

            cout << "Masukkan record ke-" << i << " : ";
            cin >> data;

            INSERT(data);
        }
    }

    // =========================================
    // SOAL 4
    // DELETE MAKSIMAL 10 RECORD
    // =========================================
    void hapus10Record() {

        cout << "\n====================================" << endl;
        cout << "      SOAL 4 - DELETE RECORD" << endl;
        cout << "====================================" << endl;

        for (int i = 1; i <= 10; i++) {

            // Jika antrian kosong, berhenti
            if (isEmpty()) {

                cout << "\nAntrian kosong!" << endl;
                cout << "Proses DELETE dihentikan." << endl;

                break;
            }

            DELETE();
        }
    }

    // =========================================
    // MENAMPILKAN F, R, COUNTER
    // =========================================
    void tampilPosisi() {

        cout << "\nF       = " << F << endl;
        cout << "R       = " << R << endl;
        cout << "COUNTER = " << COUNTER << endl;
    }

    // =========================================
    // MENAMPILKAN ISI QUEUE
    // =========================================
    void tampilQueue() {

        cout << "\nIsi Queue : ";

        if (isEmpty()) {

            cout << "Kosong" << endl;
            return;
        }

        int i = F;

        while (true) {

            cout << Q[i] << " ";

            if (i == R)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }

    // =========================================
    // SOAL 5
    // MENGHITUNG JUMLAH ELEMEN
    // BERDASARKAN F DAN R
    // =========================================
    void jumlahElemen() {

        int jumlah;

        /*
           Jika F <= R:
           jumlah = R - F + 1

           Jika F > R:
           berarti queue sudah melingkar:
           jumlah = MAX - F + R + 1
        */

        if (F <= R) {

            jumlah = R - F + 1;

        } else {

            jumlah = MAX - F + R + 1;
        }

        cout << "\n====================================" << endl;
        cout << "      SOAL 5 - JUMLAH ELEMEN" << endl;
        cout << "====================================" << endl;

        cout << "F = " << F << endl;
        cout << "R = " << R << endl;
        cout << "Jumlah elemen = " << jumlah << endl;
    }
};


// =========================================
// PROGRAM UTAMA
// =========================================
int main() {

    CircularQueue queue;

    cout << "========================================" << endl;
    cout << "       PROGRAM CIRCULAR QUEUE           " << endl;
    cout << "========================================" << endl;

    cout << "\nKondisi awal:" << endl;

    queue.tampilPosisi();
    queue.tampilQueue();


    // =====================================
    // SOAL 3
    // ISI MAKSIMAL 10 RECORD
    // =====================================

    queue.isi10Record();

    cout << "\nSetelah proses INSERT:" << endl;

    queue.tampilPosisi();
    queue.tampilQueue();


    // =====================================
    // SOAL 5
    // HITUNG JUMLAH ELEMEN
    // =====================================

    queue.jumlahElemen();


    // =====================================
    // SOAL 4
    // DELETE MAKSIMAL 10 RECORD
    // =====================================

    queue.hapus10Record();

    cout << "\nSetelah proses DELETE:" << endl;

    queue.tampilPosisi();
    queue.tampilQueue();


    // =====================================
    // SELESAI
    // =====================================

    cout << "\n========================================" << endl;
    cout << "              PROGRAM SELESAI           " << endl;
    cout << "========================================" << endl;

    return 0;
}
