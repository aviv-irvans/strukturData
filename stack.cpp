#include <iostream>
using namespace std;

#define MAX 10

class DStack
{
private:
    int top1;
    int top2;
    int ele[MAX];

public:
    DStack();

    void pushA(int item);
    void pushB(int item);

    int popA(int *item);
    int popB(int *item);

    bool kosongStack1();
    bool kosongStack2();
};

// Inisialisasi Double Stack
DStack::DStack()
{
    top1 = -1;
    top2 = MAX;
}

// PUSH Stack1
void DStack::pushA(int item)
{
    if (top2 == top1 + 1)
    {
        cout << "Stack Overflow Stack1" << endl;
        return;
    }

    top1++;
    ele[top1] = item;
}

// PUSH Stack2
void DStack::pushB(int item)
{
    if (top2 == top1 + 1)
    {
        cout << "Stack Overflow Stack2" << endl;
        return;
    }

    top2--;
    ele[top2] = item;
}

// POP Stack1
int DStack::popA(int *item)
{
    if (top1 == -1)
    {
        return -1;
    }

    *item = ele[top1--];
    return 0;
}

// POP Stack2
int DStack::popB(int *item)
{
    if (top2 == MAX)
    {
        return -1;
    }

    *item = ele[top2++];
    return 0;
}

// Mengecek Stack1 kosong
bool DStack::kosongStack1()
{
    return top1 == -1;
}

// Mengecek Stack2 kosong
bool DStack::kosongStack2()
{
    return top2 == MAX;
}


int main()
{
    DStack s;
    int item;

    // Mengisi Stack1
    s.pushA(10);
    s.pushA(20);
    s.pushA(30);

    // Mengisi Stack2
    s.pushB(40);
    s.pushB(50);
    s.pushB(60);

    cout << "=== MENGELUARKAN STACK1 ===" << endl;

    // Mengambil isi Stack1 satu per satu
    while (!s.kosongStack1())
    {
        s.popA(&item);
        cout << "Menghapus Item dari Stack1 : "
             << item << endl;
    }

    cout << "Stack1 sudah kosong." << endl;


    cout << "\n=== MENGELUARKAN STACK2 ===" << endl;

    // Mengambil isi Stack2 satu per satu
    while (!s.kosongStack2())
    {
        s.popB(&item);
        cout << "Menghapus Item dari Stack2 : "
             << item << endl;
    }

    cout << "Stack2 sudah kosong." << endl;

    return 0;
}