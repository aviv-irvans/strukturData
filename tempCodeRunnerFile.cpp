
    int data = stack[top];
    top--;
    return data;
}

int main() {
    int Stack1[MAX] = {10, 20, 30, 40, 50};
    int Stack2[MAX] = {60, 70, 80, 90, 100};

    int top1 = 4;
    int top2 = 4;

    cout << "=== Mengambil Isi Stack1 ===" << endl;

    while (!isEmpty(top1)) {
        int data = pop(Stack1, top1);
        cout << data << endl;
    }

    cout << "\n=== Mengambil Isi Stack2 ===" << endl;

    while (!isEmpty(top2)) {
        int data = pop(Stack2, top2);
        cout << data << endl;
    }

    return 0;
}