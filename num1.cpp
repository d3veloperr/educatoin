#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    cout 
        << "int: " << sizeof(int) << " байта\n"
        << "short int: " << sizeof(short int) << " байта\n"
        << "long int: " << sizeof(long int) << " байта\n"
        << "long long int: " << sizeof(long long int) << " байта\n"
        << "float: " << sizeof(float) << " байта\n"
        << "double: " << sizeof(double) << " байта\n"
        << "long double: " << sizeof(long double) << " байта\n"
        << "char: " << sizeof(char) << " байта\n"
        << "bool: " << sizeof(bool) << " байта\n";
}
