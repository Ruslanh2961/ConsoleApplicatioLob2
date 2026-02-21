#include <iostream>
#include <cstdlib>  
#include <ctime>  
using namespace std;


void exercise3() {
    const int SIZE = 10;

    cout << "\n=== УПРАЖНЕНИЕ 3 ===\n";

    cout << "\n1) Статический массив, индексы:\n";
    int staticArray[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        staticArray[i] = i * i;
    }
    for (int i = 0; i < SIZE; ++i) {
        cout << "staticArray[" << i << "] = " << staticArray[i] << endl;
    }

    cout << "\n2) Статический массив, указатели:\n";
    int staticArray2[SIZE];
    int* ptr = staticArray2;
    for (int i = 0; i < SIZE; ++i) {
        *(ptr + i) = i * i;
    }
    for (int i = 0; i < SIZE; ++i) {
        cout << "staticArray2[" << i << "] = " << *(ptr + i) << endl;
    }

    cout << "\n3) Динамический массив, индексы:\n";
    int* dynArray = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        dynArray[i] = i * i;
    }
    for (int i = 0; i < SIZE; ++i) {
        cout << "dynArray[" << i << "] = " << dynArray[i] << endl;
    }
    delete[] dynArray;

    cout << "\n4) Динамический массив, указатели:\n";
    dynArray = new int[SIZE];
    int* ptrDyn = dynArray;
    for (int i = 0; i < SIZE; ++i) {
        *(ptrDyn + i) = i * i;
    }
    for (int i = 0; i < SIZE; ++i) {
        cout << "dynArray[" << i << "] = " << *(ptrDyn + i) << endl;
    }
    delete[] dynArray;
}


void mergeArrays() {
    cout << "\n=== Слияние двух упорядоченных массивов ===\n";

    int arr1[] = { 1, 3, 5, 7, 9 };
    int arr2[] = { 2, 4, 6, 8, 10, 12, 14 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;

    int* merged = new int[size3];

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            *(merged + k) = arr1[i];
            ++i;
        }
        else {
            *(merged + k) = arr2[j];
            ++j;
        }
        ++k;
    }

    while (i < size1) {
        *(merged + k) = arr1[i];
        ++i;
        ++k;
    }

    while (j < size2) {
        *(merged + k) = arr2[j];
        ++j;
        ++k;
    }

    cout << "Результирующий массив:\n";
    for (int idx = 0; idx < size3; ++idx) {
        cout << merged[idx] << " ";
    }
    cout << endl;

    delete[] merged;
}

struct Node {
    int data;       
    Node* prev;     
    Node* next;     
};

void exercise4() {
    cout << "\n=== УПРАЖНЕНИЕ 4: Двусвязный список ===\n";

    const int LIST_SIZE = 10;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 1; i <= LIST_SIZE; ++i) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode; // первый элемент
        }
        tail = newNode;
    }

    cout << "Список (с начала): ";
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Список (с конца):  ";
    current = tail;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;

    current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr)); // для возможного использования rand()

    exercise3();
    mergeArrays();
    exercise4();

    return 0;
}