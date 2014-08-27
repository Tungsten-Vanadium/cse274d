// classes example
#include <iostream>
#include "rectangle.h"

using namespace std;

int main () {
  Rectangle rect;

  Rectangle *pHead = new Rectangle();

  // This creates a copy of the object in memory
  Rectangle rect2 = rect;

  rect2.set_values(4, 5);

  cout<< "area for rect2 " << rect2.area() << endl;
  cout<< "area for rect " << rect.area() << endl;

  // Creates a pointer to a rectangle object
  Rectangle *pRect;

  // assign the pointer to the object
  pRect = &rect;

  cout << "area for pointer " << pRect->area() << endl;
  cout << "memory location for rect " << pRect << endl;

  pRect = &rect2;

  cout << "area for pointer " << pRect->area() << endl;
  cout << "memory location for rect2 " << pRect << endl;

  Rectangle &refRect = rect;

  cout << "area for reference " << refRect.area() << endl;

  return 0;
}
