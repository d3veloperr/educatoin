#include <iostream>
#include <bitset>
using namespace std;
void printDoubleBits(double num) {
   
    union {
        double source;        
        unsigned long long bits;
    } data;

    data.source = num; 
    bitset<64> binary(data.bits);
    cout << "Знаковый бит: " << binary[63] << endl;
    cout << "Порядок (11 бит): ";
    for(int i = 52; i <= 62; i++) {
        cout << binary[i];
    }
    cout << endl;
    cout << "Мантисса (52 бита): ";
    for(int i = 0; i <= 51; i++) {
        cout << binary[i];
    }
    cout << endl;
}

int main() {
    double number = 7; 
    cout << "Двоичное представление числа " << number << ":" << endl;
    printDoubleBits(number);
    return 0;
}