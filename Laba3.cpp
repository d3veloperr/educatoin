
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>

using namespace std;

void printMatrix(int* mat, int N);

void fillRandom(int* mat, int N) {
    system("cls");
    cout << "Заполнение случайными числами от 1 до 50...\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = rand() % 50 + 1;
            *(mat + i * N + j) = value;

            COORD coord;
            coord.X = j * 5;
            coord.Y = i + 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << setw(4) << value;
            cout.flush();
            Sleep(50);
        }
    }

    COORD coord;
    coord.X = 0;
    coord.Y = N + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showProcess(int* mat, int N, int row, int col, int value) {
    COORD coord;
    coord.X = col * 5;
    coord.Y = row + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << setw(4) << value;
    cout.flush();
    Sleep(100);
}

void fillSpiral(int* mat, int N) {
    system("cls");
    cout << "Заполнение по спирали...\n";

    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            int value = rand() % (N * N) + 1;
            *(mat + top * N + j) = value;
            showProcess(mat, N, top, j, value);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            int value = rand() % (N * N) + 1;
            *(mat + i * N + right) = value;
            showProcess(mat, N, i, right, value);
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                int value = rand() % (N * N) + 1;
                *(mat + bottom * N + j) = value;
                showProcess(mat, N, bottom, j, value);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                int value = rand() % (N * N) + 1;
                *(mat + i * N + left) = value;
                showProcess(mat, N, i, left, value);
            }
            left++;
        }
    }

    COORD coord;
    coord.X = 0;
    coord.Y = N + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fillSnake(int* mat, int N) {
    system("cls");
    cout << "Заполнение змейкой...\n";

    for (int col = 0; col < N; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < N; row++) {
                int value = rand() % (N * N) + 1;
                *(mat + row * N + col) = value;
                showProcess(mat, N, row, col, value);
            }
        } else {
            for (int row = N - 1; row >= 0; row--) {
                int value = rand() % (N * N) + 1;
                *(mat + row * N + col) = value;
                showProcess(mat, N, row, col, value);
            }
        }
    }

    COORD coord;
    coord.X = 0;
    coord.Y = N + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void sumMainDiagonal(int* mat, int N) {
    int sum = 0;

    cout << "\nИсходная матрица:";
    printMatrix(mat, N);

    cout << "Элементы главной диагонали:\n";
    for (int i = 0; i < N; i++) {
        int value = *(mat + i * N + i);
        cout << "A[" << i << "][" << i << "] = " << value << endl;
        sum += value;
        Sleep(200);
    }

    cout << "\nСумма элементов главной диагонали = " << sum << endl;
}

void swapBlocks1(int* mat, int N) {
    int h = N / 2;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            int temp = *(mat + i * N + j);
            *(mat + i * N + j) = *(mat + (i + h) * N + j);
            *(mat + (i + h) * N + j) = *(mat + (i + h) * N + (j + h));
            *(mat + (i + h) * N + (j + h)) = *(mat + i * N + (j + h));
            *(mat + i * N + (j + h)) = temp;
        }
    }
}

void swapBlocks2(int* mat, int N) {
    int h = N / 2;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            swap(*(mat + i * N + j), *(mat + (i + h) * N + (j + h)));
            swap(*(mat + i * N + (j + h)), *(mat + (i + h) * N + j));
        }
    }
}

void swapBlocks3(int* mat, int N) {
    int h = N / 2;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            swap(*(mat + i * N + j), *(mat + (i + h) * N + j));
            swap(*(mat + i * N + (j + h)), *(mat + (i + h) * N + (j + h)));
        }
    }
}

void swapBlocks4(int* mat, int N) {
    int h = N / 2;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            swap(*(mat + i * N + j), *(mat + i * N + (j + h)));
            swap(*(mat + (i + h) * N + j), *(mat + (i + h) * N + (j + h)));
        }
    }
}

void insertSort(int* mat, int N) {
    int* end = mat + N * N - 1;
    for (int* i = mat + 1; i <= end; i++) {
        int key = *i;
        int* j = i - 1;
        while (j >= mat && *j > key) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

void doMath(int* mat, int N, int num, char op) {
    int* end = mat + N * N - 1;
    for (int* p = mat; p <= end; p++) {
        if (op == '+') *p += num;
        else if (op == '-') *p -= num;
        else if (op == '*') *p *= num;
        else if (op == '/' && num != 0) *p /= num;
    }
}

void printMatrix(int* mat, int N) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << *(mat + i * N + j);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand(time(0));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введите размер матрицы N (6,8,10): ";
    cin >> N;
    if (N != 6 && N != 8 && N != 10) N = 8;

    int* matrix = new int[N * N];
    int choice;

    cout << "\nВыберите метод заполнения:\n";
    cout << "1. Спираль\n";
    cout << "2. Змейка\n";
    cout << "3. Случайное заполнение\n";
    cout << "4. ИДЗ\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        fillSpiral(matrix, N);
    }
    else if (choice == 2) {
        fillSnake(matrix, N);
    }
    else if (choice == 3) {
        fillRandom(matrix, N);
    }
    else if (choice == 4) {
        int subChoice;
        cout << "\nИДЗ:\n";
        cout << "1. Заполнить матрицу\n";
        cout << "Ваш выбор: ";
        cin >> subChoice;

        if (subChoice == 1) {
            fillRandom(matrix, N);
            sumMainDiagonal(matrix, N);
        }
    }

    cout << "\nИсходная матрица:";
    printMatrix(matrix, N);

    cout << "\nВыберите метод перестановки блоков:\n";
    cout << "1. По часовой стрелке\n";
    cout << "2. По диагонали\n";
    cout << "3. Вертикально\n";
    cout << "4. Горизонтально\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) swapBlocks1(matrix, N);
    else if (choice == 2) swapBlocks2(matrix, N);
    else if (choice == 3) swapBlocks3(matrix, N);
    else if (choice == 4) swapBlocks4(matrix, N);

    cout << "\nПосле перестановки блоков:";
    printMatrix(matrix, N);

    insertSort(matrix, N);
    cout << "\nПосле сортировки:";
    printMatrix(matrix, N);

    int num;
    char op;
    cout << "\nВведите операцию (+ - * /): ";
    cin >> op;
    cout << "Введите число: ";
    cin >> num;

    doMath(matrix, N, num, op);

    cout << "\nПосле операции:";
    printMatrix(matrix, N);

    delete[] matrix;
    return 0;
}
