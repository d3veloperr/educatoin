#include <iostream>
using namespace std;

unsigned int changeBit(unsigned int number, int position, bool value) {
   
    unsigned int mask = 1 << position;
    
    if (value) {
        return number | mask;
    } else {
        return number & ~mask;
    }
}

int main() {
    unsigned int number;
    int position;
    bool value;
    
    cout << "Введите число: ";
    cin >> number;
    
    cout << "Введите позицию бита (0-31): ";
    cin >> position;
    
    cout << "Введите значение (0 или 1): ";
    cin;
}