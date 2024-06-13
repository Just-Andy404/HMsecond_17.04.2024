/*
���������� ����� ����� ��� ������ � ��������� (���������� ����). ���� ������ ����� ������������� ������. �����
���������� ����� �������� ��� ������ �� ������: ��������
������� � ����, �������� ������� �� �����, �������
���������� �������� � �����, ��������, ���� �� ����,
��������, ������ �� ����, ������� �����, ���������
��� �������� �������� ������� � �����.

�������� ���� �� ������ ������ �� ������������ ���� ��
������������ ������������ (��� ���������� ���������� �����
����� �������� ������ ����������� ������� ��� ������ ������).
*/

#include <iostream>
using namespace std;

class Stack {
    int capacity;
    int top;
    char* _Symbols;

public:
    Stack(int size) : capacity(size), top(-1) {
        _Symbols = new char[capacity];
    }

    ~Stack() {
        delete[] _Symbols;
    }

    void resize() {
        int newCapacity = capacity * 2;
        char* newArray = new char[newCapacity];

        for (int i = 0; i <= top; ++i) {
            newArray[i] = _Symbols[i];
        }

        delete[] _Symbols;
        _Symbols = newArray;
        capacity = newCapacity;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == capacity - 1;
    }

    void Push(char c) {
        if (IsFull()) {
            resize();
        }
        _Symbols[++top] = c;
    }

    char Pop() {
        if (!IsEmpty()) {
            return _Symbols[top--];
        }
        else {
            cout << "Stack is empty." << endl;
            return 0;
        }
    }

    char Peek() {
        if (!IsEmpty()) {
            return _Symbols[top];
        }
        else {
            cout << "Stack is empty." << endl;
            return 0;
        }
    }

    int Size() {
        return top + 1;
    }

    void Clear() {
        top = -1;
    }
};

int main() {
    Stack s(5);

    s.Push('a');
    s.Push('b');
    s.Push('c');
    s.Push('d');
    s.Push('e');
    s.Push('f');

    cout << "Top element: " << s.Peek() << endl;
    cout << "Stack size: " << s.Size() << endl;

    s.Pop();
    cout << "Top element after pop: " << s.Peek() << endl;
    cout << "Stack size after pop: " << s.Size() << endl;

    s.Clear();
    cout << "Stack size after clear: " << s.Size() << endl;

    return 0;
}
