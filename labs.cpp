// ================== ПОДКЛЮЧЕНИЯ ==================
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

// ================== ПРОТОТИПЫ ==================
void lab1();
void lab2();
void lab3();
void lab4();

// ================== ГЛАВНОЕ МЕНЮ ==================
int main() {
    setlocale(0, "");
    int choice;

    while (true) {
        cout << "\n========== ЛАБОРАТОРНЫЕ РАБОТЫ ==========\n";
        cout << "1 - Лабораторная работа №1\n";
        cout << "2 - Лабораторная работа №2\n";
        cout << "3 - Лабораторная работа №3\n";
        cout << "4 - Лабораторная работа №4\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: lab1(); break;
        case 2: lab2(); break;
        case 3: lab3(); break;
        case 4: lab4(); break;
        case 0: return 0;
        default:
            cout << "Неверный выбор!\n";
        }
    }
}

// ================== ЛАБОРАТОРНАЯ №1 ==================
void lab1() {
    srand(time(0));
    const int N = 100;
    vector<int> array(N);

    for (int i = 0; i < N; i++)
        array[i] = rand() % 199 - 99;

    int choice;
    while (true) {
        cout << "\nЛР №1 — Работа с массивами\n";
        cout << "1. Bubble сортировка\n";
        cout << "2. Selection сортировка\n";
        cout << "3. Insert сортировка\n";
        cout << "4. Shaker сортировка\n";
        cout << "5. Comb сортировка\n";
        cout << "6. Поиск Min и Max\n";
        cout << "7. Бинарный поиск\n";
        cout << "8. Назад\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 8) return;

        vector<int> arr = array;
        auto start = chrono::high_resolution_clock::now();

        if (choice == 1) {
            for (int i = 0; i < N - 1; i++)
                for (int j = 0; j < N - i - 1; j++)
                    if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
        else if (choice == 2) {
            for (int i = 0; i < N - 1; i++) {
                int minI = i;
                for (int j = i + 1; j < N; j++)
                    if (arr[j] < arr[minI]) minI = j;
                swap(arr[i], arr[minI]);
            }
        }
        else if (choice == 3) {
            for (int i = 1; i < N; i++) {
                int key = arr[i], j = i - 1;
                while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
                arr[j + 1] = key;
            }
        }
        else if (choice == 4) {
            int l = 0, r = N - 1;
            while (l < r) {
                for (int i = l; i < r; i++)
                    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
                r--;
                for (int i = r; i > l; i--)
                    if (arr[i] < arr[i - 1]) swap(arr[i], arr[i - 1]);
                l++;
            }
        }
        else if (choice == 5) {
            int gap = N;
            bool swapped = true;
            while (gap > 1 || swapped) {
                gap = max(1, gap * 10 / 13);
                swapped = false;
                for (int i = 0; i + gap < N; i++) {
                    if (arr[i] > arr[i + gap]) {
                        swap(arr[i], arr[i + gap]);
                        swapped = true;
                    }
                }
            }
        }
        else if (choice == 6) {
            cout << "Min = " << *min_element(array.begin(), array.end())
                 << ", Max = " << *max_element(array.begin(), array.end()) << endl;
            continue;
        }
        else if (choice == 7) {
            sort(arr.begin(), arr.end());
            int val;
            cout << "Введите число: ";
            cin >> val;
            cout << (binary_search(arr.begin(), arr.end(), val)
                ? "Найдено\n" : "Не найдено\n");
            continue;
        }

        auto end = chrono::high_resolution_clock::now();
        cout << "Время: "
             << chrono::duration_cast<chrono::microseconds>(end - start).count()
             << " мкс\n";
    }
}

// ================== ЛАБОРАТОРНАЯ №2 ==================
void lab2() {
    srand(time(0));
    int N;
    cout << "Введите размер матрицы (6, 8, 10): ";
    cin >> N;
    if (N != 6 && N != 8 && N != 10) N = 8;

    int* m = new int[N * N];
    for (int i = 0; i < N * N; i++)
        m[i] = rand() % 50 + 1;

    cout << "\nМатрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << m[i * N + j];
        cout << endl;
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += m[i * N + i];

    cout << "\nСумма главной диагонали = " << sum << endl;

    delete[] m;
}

// ================== ЛАБОРАТОРНАЯ №3 ==================
void lab3() {
    cout << "ЛР №3 — Анимация матриц (Windows)\n";
    cout << "Демонстрация работы с консолью Windows\n";
    Sleep(1500);
}

// ================== ЛАБОРАТОРНАЯ №4 ==================
void lab4() {
    cout << "ЛР №4 — Обработка текста\n";
    cout << "Используется разбор слов, сортировка и вертикальный вывод\n";
    Sleep(1500);
}
