#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
    IntInf x;
    x = 6;
    IntInf y;
    y = 0;
    x.print();
    IntInf pos(0, true, false);
    IntInf neg(0, false, true);
    IntInf test1 = x + pos;
    test1.print();
    IntInf test2 = x - pos;
    test2.print();
    IntInf test3 = y * pos;
    test3.print();
    IntInf test4 = pos / x;
    test4.print();
    IntInf test5 = pos == pos;
    test5.print();
    IntInf test6 = pos > x;
    test6.print();
    IntInf test7 = pos < x;
    test7.print();


    return 0;
}
