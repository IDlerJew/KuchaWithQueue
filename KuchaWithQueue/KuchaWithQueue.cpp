

#include <iostream>
#include <vector>
using namespace std;

// Функция меняет элементы местами
void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Функция сортирует
void heapify(vector<int>& hT, int i) {
    int size = hT.size();

    // Находим самое большое значение среди 
    // корневого, правого и левого дочернего элемента
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;

    // Меняем местами и продолжаем сортировку,
    // если значение корневого элемента не самое большое
    if (largest != i) {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

// Функция вставляет элемент
void insert(vector<int>& hT, int newNum) {
    int size = hT.size();
    if (size == 0) {
        hT.push_back(newNum);
    }
    else {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(hT, i);
        }
    }
}

// Функция удаляет элемент
void deleteNode(vector<int>& hT, int num) {
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++) {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);

    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(hT, i);
    }
}

// Выводим дерево в консоль
void printArray(vector<int>& hT) {
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

// Всё сделано на основе max-heap
int main() {
    setlocale(0, "rus");
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Массив max-heap: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    cout << "После удаления элемента: ";

    printArray(heapTree);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
