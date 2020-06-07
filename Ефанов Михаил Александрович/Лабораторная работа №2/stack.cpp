#include<iostream>
#include<ctime>
#include <stdlib.h>
#include<time.h>

using namespace std;

class STACK {
public:
    STACK();

    STACK(const STACK &origStack);

    ~STACK();

    int getStackSize();

    void push(int value);

    pair<bool, int> getElement();

    void print();

private:
    int *stack;
    int stack_size;
    int N;
};

STACK::STACK(const STACK &origStack) {
    stack = new int[origStack.N];
    stack_size = origStack.stack_size;
    N = origStack.N;
    for (int i = 0; i < N; i++) {
        stack[i] = origStack.stack[i];
    }
}

STACK::~STACK() {
    delete[] stack;
}

void STACK::push(int value) {
    int *tmp;
    tmp = stack;

    N++;

    if (N >= stack_size) {
        stack = new int[N * 2];
        stack_size = stack_size * 2;
    }
    for (int i = 0; i < N - 1; i++) {
        stack[i] = tmp[i];
    }
    stack[N - 1] = value;
    delete[] tmp;
}

pair<bool, int> STACK::getElement() {
    pair<bool, int> a = {};
    if (N == 0) {
        a = {false, -1};
        return a;
    }
    N--;
    a = {true, stack[N]};
    return a;
}

void STACK::print() {
    if (N == 0) {
        cout << "EMPTY STACK" << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        cout << "element " << i << ": = " << stack[i] << endl;
    }
    cout << endl;
}

int STACK::getStackSize() {
    return stack_size;
}

STACK::STACK() {
    N = 0;
    stack = {};
    stack_size = 1;
}


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    STACK *stack1 = new STACK;
    cout << "������� ������ ������ ����� �1: ";
    cout << stack1->getStackSize() << endl;
    cout << "���������� � ���� �1 ������� 2" << endl;
    stack1->push(2);
    cout << "���������� � ���� �1 ������� 2" << endl;
    stack1->push(2);
    cout << "���������� � ���� �1 ������� 2" << endl;
    stack1->push(2);
    cout << "���������� � ���� �1 ������� 3" << endl;
    stack1->push(3);
    cout << "������� ������ ������ ����� �1: ";
    cout << stack1->getStackSize() << endl;
    cout << "����1:" << endl;
    stack1->print();
    pair<bool, int> element = stack1->getElement();
    cout << "��������� �������� ����� (����� ��������, ��������): ";
    cout << element.first << " " << element.second << endl;
    element = stack1->getElement();
    cout << "��������� �������� ����� (����� ��������, ��������): ";
    cout << element.first << " " << element.second << endl;
    element = stack1->getElement();
    cout << "��������� �������� ����� (����� ��������, ��������): ";
    cout << element.first << " " << element.second << endl;
    element = stack1->getElement();
    cout << "��������� �������� ����� (����� ��������, ��������): ";
    cout << element.first << " " << element.second << endl;
    element = stack1->getElement();
    cout << "��������� �������� ����� (����� ��������, ��������): ";
    cout << element.first << " " << element.second << endl;
    cout << "����1:" << endl;
    stack1->print();
    cout << "���������� � ���� �1 ������� 2" << endl;
    stack1->push(2);
    cout << "����1:" << endl;
    stack1->print();
    STACK *stack2 = new STACK(*stack1);
    cout << "������� ������ ������ ����� �2: ";
    cout << stack2->getStackSize() << endl;
    cout << "���������� � ���� �2 ������� 2" << endl;
    stack2->push(2);
    cout << "���������� � ���� �2 ������� 10" << endl;
    stack2->push(10);
    cout << "���������� � ���� �2 ������� 20" << endl;
    stack2->push(20);
    cout << "������� ������ ������ ����� �2: ";
    cout << stack2->getStackSize() << endl;
    cout << "����1:" << endl;
    stack1->print();
    cout << "����2:" << endl;
    stack2->print();
    delete stack1;
    delete stack2;
    return 0;
}

