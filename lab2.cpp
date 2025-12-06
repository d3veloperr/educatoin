#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>

using namespace std;
int main() {
  setlocale(0, "");
  srand (time(0));
    
    const int N = 100;
    vector<int> array(N);

    for (int i = 0; i < N; i++) {
        array[i] = rand() % 199 - 99;
    }
    cout << "массив: ";
    for (int num : array) {
        cout << num << " ";
        cout << endl;
    }

    int choice;
    while (true) {
        cout << "\nВыберите действие:\n";
        cout << "1. Bubble сортировка\n";
        cout << "2. Selection сортировка\n";
        cout << "3. Insert сортировка\n";
        cout << "4. Shaker сортировка\n";
        cout << "5. Combo сортировка\n";
        cout << "6. Поиск Max и Min элементов\n";
        cout << "7. Поиск элемента в массиве\n";
        cout << "8. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            vector<int> sortedArray = array;
            auto start = chrono::high_resolution_clock::now();
            int n = sortedArray.size();
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (sortedArray[j] > sortedArray[j + 1]) {
                        swap(sortedArray[j], sortedArray[j + 1]);
                    }
                }
            }
            auto end = chrono::high_resolution_clock::now();
            cout << "Массив, отсортированный с помощью bubble сортировки: ";
            for (int num : sortedArray) {
                cout << num << " ";
            }
            cout << "\nВремя сортировки: "
                << chrono::duration_cast<chrono::microseconds>(end - start).count() << " мкс\n";
            break;
        }
        case 2: {
            vector<int> sortedArray = array;
            auto start = chrono::high_resolution_clock::now();
            int n = sortedArray.size();
            for (int i = 0; i < n - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < n; ++j) {
                    if (sortedArray[j] < sortedArray[minIndex]) {
                        minIndex = j;
                    }
                }
                swap(sortedArray[i], sortedArray[minIndex]);
            }
            auto end = chrono::high_resolution_clock::now();
            cout << "Массив, отсортированный с помощью selection сортировки: ";
            for (int num : sortedArray) {
                cout << num << " ";
            }
            cout << "\nВремя сортировки: "
                << chrono::duration_cast<chrono::microseconds>(end - start).count() << " мкс\n";
            break;
        }
        case 3: {
            vector<int> sortedArray = array;
            auto start = chrono::high_resolution_clock::now();
            int n = sortedArray.size();
            for (int i = 1; i < n; ++i) {
                int key = sortedArray[i];
                int j = i - 1;
                while (j >= 0 && sortedArray[j] > key) {
                    sortedArray[j + 1] = sortedArray[j];
                    j--;
                }
                sortedArray[j + 1] = key;
            }
            auto end = chrono::high_resolution_clock::now();
            cout << "Массив, отсортированный с помощью insert сортировки: ";
            for (int num : sortedArray) {
                cout << num << " ";
            }
            cout << "\nВремя сортировки: " 
                << chrono::duration_cast<chrono::microseconds>(end - start).count() << " мкс\n";
            break;
        }
        case 4: {
            vector<int> sortedArray = array;
            auto start = chrono::high_resolution_clock::now();
            int left = 0, right = sortedArray.size() - 1;
            while (left < right) {
                for (int i = left; i < right; ++i) {
                    if (sortedArray[i] > sortedArray[i + 1]) {
                        swap(sortedArray[i], sortedArray[i + 1]);
                    }
                }
                right--;
                for (int i = right; i > left; --i) {
                    if (sortedArray[i] < sortedArray[i - 1]) {
                        swap(sortedArray[i], sortedArray[i - 1]);
                    }
                }
                left++;
            }
            auto end = chrono::high_resolution_clock::now();
            cout << "Массив, отсортированный с помощью shaker сортировки: ";
            for (int num : sortedArray) {
                cout << num << " ";
            }
            cout << "\nВремя сортировки: "
                << chrono::duration_cast<chrono::microseconds>(end - start).count() << " мкс\n";
            break;
        }
        case 5: {
            vector<int> comboSortedArray = array;
            auto start = chrono::high_resolution_clock::now();
            int gap = comboSortedArray.size();
            bool swapped = true;

            while (gap > 1 || swapped) {
                gap = max(1, gap * 10 / 13); 

                swapped = false;
                for (int i = 0; i + gap < comboSortedArray.size(); ++i) {
                    if (comboSortedArray[i] > comboSortedArray[i + gap]) {
                        swap(comboSortedArray[i], comboSortedArray[i + gap]);
                        swapped = true;
                    }
                }
            }

            auto endTime = chrono::high_resolution_clock::now();
            cout << "Массив, отсортированный с помощью combo сортировки: ";
            for (int num : comboSortedArray) {
                cout << num << " ";
            }
            cout << "\nВремя комбинированной сортировки: "
                << chrono::duration_cast<chrono::microseconds>(endTime - start).count() << " мкс\n";
            break;
        }
        case 6: {
            auto minMaxStart = chrono::high_resolution_clock::now();
            int minElement = *min_element(array.begin(), array.end());
            int maxElement = *max_element(array.begin(), array.end());
            auto minMaxEnd = chrono::high_resolution_clock::now();

            cout << "Min элемент: " << minElement
                << ", Max элемент: " << maxElement << endl;
            cout << "Время поиска в неотсортированном массиве: "
                << chrono::duration_cast<chrono::microseconds>(minMaxEnd - minMaxStart).count()
                << " мкс\n";
            break;
        }
        case 7: {
            int searchValue;
            cout << "Введите число для поиска: ";
            cin >> searchValue;

            auto binaryStart = chrono::high_resolution_clock::now();

            vector<int> sortedArray = array;
            sort(sortedArray.begin(), sortedArray.end()); 
            bool foundBinary = binary_search(sortedArray.begin(), sortedArray.end(), searchValue);

            auto binaryEnd = chrono::high_resolution_clock::now();

            cout << "Число " << searchValue
                << (foundBinary ? " найдено" : " не найдено")
                << " с помощью бинарного поиска.\n";

            cout << "Время бинарного поиска: "
                << chrono::duration_cast<chrono::microseconds>(binaryEnd - binaryStart).count()
                << " мкс\n";

            break;
        }
        case 8:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    return 0;
}