#include "IntegerSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;

int collisions = 0;
int fails = 0;

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}

bool IntegerSetHT::insert(int data)
{
    bool eden = false;
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     return true;
   }
   if (eden == false) collisions++;
   eden = true;
   index = (index+1) % size;
  }
  // otherwise give up
   return false;
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}


int main()
{
    IntegerSetHT set(1000);
    srand(time(NULL));
	int r = rand();
for (int i = 0; i < 500; i++)
{
    r = rand();
	if(!set.insert(r)) fails++;
}
    cout << collisions << endl;
    cout << fails << endl;

  return 0;
}
