#include "PList.h"

int main()
{
  DList l;

  Num *two = new Num(2);
  Doub *pi = new Doub(3.14);
  Strn *yo = new Strn("yo");

  l.append(two);
  l.append(pi);
  l.append(yo);


  DList::iterator i;
  printf("Forward: ");
  for(i = l.begin();!i.end();i.increment())
  {
    Object *object = i.getObject();
    object->print();
  }

  printf("\n");

  return 0;
}
