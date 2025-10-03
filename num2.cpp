#include <iostream>
using namespace std;
int main()
{
   int value = -127;
   int order = sizeof(int) * 8;
   unsigned int mask = 1 << (order - 1);
   
   for (int i = 0; i < order; i++) {
       if (value & (mask >> i)) {
           cout << "1";
       }
       else {
           cout << "0";
       }
   }
}
