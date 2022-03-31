#include <iostream>

#include "src/Weight.h"

using namespace std;

int main() {
   cout << "Starting fatCat" << endl ;

   Weight noWeight;
   noWeight.dump();

   Weight myWeight( 3.14, Weight::KILO, 20 );
   myWeight.dump();

   cout << "Done with fatCat" << endl;
   return 0;
}
