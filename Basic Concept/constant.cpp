#include <iostream>
using namespace std;

#define LENGTH 20
#define BREADTH 15

int main() {
   const int  SIDE = 10;
   int recArea;  
   int sqArea;
   
   recArea = LENGTH * BREADTH;
   sqArea = SIDE * SIDE;
   cout << "\nArea of Rectangle\t:\t" << recArea;
   cout << "\nArea of Square\t:\t" << sqArea;
   return 0;
}
