#include <iostream>
using namespace std;

void showBinary(float number) {
 
    float num = number;
    
    unsigned int *p = (unsigned int*)&num;
    
    unsigned int bits = *p;
    
    cout << "Двоичное представление числа " << number << ":\n";
    
    cout << "Знак: " << ((bits & 0x80000000) >> 31) << "\n";

    cout << "Порядок: ";
    for(int i = 7; i >= 0; i--) {
        cout << ((bits & (0x7F << 23)) >> (23 + i));
    }
    cout << "\n";

    cout << "Мантисса: ";
    for(int i = 22; i >= 0; i--) {
        cout << ((bits & (0x1 << i)) >> i);
    }
    cout << "\n";

    cout << "\nПолное представление:\n";
    cout << "Знак Порядок Мантисса\n";
    cout << ((bits & 0x80000000) >> 31) << "  ";

    for(int i = 7; i >= 0; i--) {
        cout << ((bits & (0x7F << 23)) >> (23 + i));
    }
    cout << "  ";

    for(int i = 22; i >= 0; i--) {
        cout << ((bits & (0x1 << i)) >> i);
    }
    cout << "\n";
}

int main() {
    float number = 3.14f;  
    showBinary(number);
    return 0;
}