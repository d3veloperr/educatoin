#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    setlocale(0, "");
    int number;
    do
    {
        cout << "Какую лабораторную хотите открыть?" << endl;
        cin >> number;
        switch (number)
        {
        case 1:
            system("C:\\Users\\zheka\\source\\repos\\lab1\\x64\\Debug\\lab1.exe");
            break;
        case 2:
            system("C:\\Users\\zheka\\source\\repos\\lab2\\x64\\Debug\\lab2.exe");
            break;
        case 3:
            system("C:\\Users\\zheka\\source\\repos\\Laba3\\x64\\Debug\\Laba3.exe");
            break;
        case 4:
            system("C:\\Users\\zheka\\source\\repos\\lab4\\x64\\Debug\\lab4.exe");
            break;
        default:
            cout << "Такой работы нет" << endl;
            break;
        }
        cout << endl;
    } while (number);
    return 0;
}
