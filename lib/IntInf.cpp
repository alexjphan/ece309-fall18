#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class IntInf
{

private:
    bool pos_inf;
    bool neg_inf;
    int value;

public:

    IntInf(int a = 0, bool b = false, bool c = false)
    {
        value = a;
        pos_inf = b;
        neg_inf = c;
    }

    void print()
    {
        if( undefined() == true)
            cout << "undefined\n";
        else if(pos_inf == true)
            cout << "positive infinity\n";
        else if(neg_inf == true)
            cout << "negative infinity\n";
        else
            cout << value << endl;
    }

    bool undefined() const
    {
        if (pos_inf == 1 && neg_inf == 1 ) return true;
    }

    IntInf& operator=(const IntInf &rhs)
    {
      if (&rhs == this) return *this;
      value = rhs.value;
      pos_inf = rhs.pos_inf;
      neg_inf = rhs.neg_inf;
      return *this;
    }

    IntInf& operator=(int x)
    {
      value = x;
      pos_inf = false;
      neg_inf = false;
      return *this;
    }

    IntInf operator+(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined() || (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf))
      {
          IntInf ret(0, true, true);
          return ret;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf)) return *this;
      if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf) return *this;
      if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)
      {
          IntInf ret(0, rhs.pos_inf, rhs.neg_inf);
          return ret;
      }

      IntInf ret(value + rhs.value, false, false);
      return ret;
    }

    IntInf operator-(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined() || (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf))
      {
          IntInf ret(0, true, true);
          return ret;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf)) return *this;
      if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf) return *this;
      if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)
      {
          IntInf ret(0, rhs.neg_inf, rhs.pos_inf);
          return ret;
      }


      IntInf ret(value - rhs.value, false, false);
      return ret;
    }

    IntInf operator*(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined())
      {
          IntInf ret(0, true, true);
          return ret;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf))
        {
          IntInf ret(0, true, false);
          return ret;
      }
      if( (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf))
      {
          IntInf ret(0, false, true);
          return ret;
      }
      if( (rhs.pos_inf || rhs.neg_inf) && value == 0)
      {
        IntInf ret(0, false, false);
        return ret;
      }

      if( (pos_inf || neg_inf) && rhs.value == 0)
      {
        IntInf ret(0, false, false);
        return ret;
      }

      if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf) return *this;
      if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)
      {
          IntInf ret(0, rhs.pos_inf, rhs.neg_inf);
          return ret;
      }
      IntInf ret(value * rhs.value, false, false);
      return ret;
    }

    IntInf operator/(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined())
      {
          IntInf ret(0, true, true);
          return ret;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf))
        {
          IntInf ret(0, true, false);
          return ret;
      }
      if( (pos_inf && rhs.neg_inf) || (neg_inf && rhs.pos_inf))
      {
          IntInf ret(0, false, true);
          return ret;
      }
      if( (pos_inf || neg_inf) && !rhs.pos_inf && !rhs.neg_inf) return *this;
      if (value == 0)
      {
          return 0;
      }
      if( (rhs.pos_inf || rhs.neg_inf) && !pos_inf && !neg_inf)
      {
          IntInf ret(0, rhs.pos_inf, rhs.neg_inf);
          return ret;
      }
      if( (pos_inf || neg_inf) && rhs.value == 0)
      {
          IntInf ret(0, true, true);
          return ret;
      }
      if( (rhs.pos_inf || rhs.neg_inf) && value == 0)
      {
          IntInf ret(0, false, false);
          return ret;
      }

      IntInf ret(value / rhs.value, false, false);
      return ret;
    }

    bool operator==(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined())
      {
          return false;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf))
      {
          return false;
      }
      if( (pos_inf || neg_inf) && (rhs.pos_inf || rhs.neg_inf))
      {
          return false;
      }

        if(pos_inf && (!rhs.pos_inf || !rhs.neg_inf))
            {
                return false;
            }
        if(neg_inf && (!rhs.pos_inf || !rhs.neg_inf))
            {
                return false;
            }
            return false;
    }

    bool operator>(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined())
      {
          return false;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf))
      {
          return false;
      }
      if (pos_inf && !rhs.pos_inf)
      {
          return true;
      }
      if (neg_inf && !rhs.neg_inf)
      {
          return false;
      }
      if (rhs.pos_inf && !pos_inf)
      {
          return false;
      }
      if (rhs.neg_inf && !neg_inf)
      {
          return true;
      }
      return false;

    }

     bool operator<(const IntInf &rhs)
    {
      if( undefined() || rhs.undefined())
      {
          return false;
      }
      if( (pos_inf && rhs.pos_inf) || (neg_inf && rhs.neg_inf))
      {
          return false;
      }
      if (pos_inf && !rhs.pos_inf)
      {
          return false;
      }
      if (neg_inf && !rhs.neg_inf)
      {
          return true;
      }
      if (rhs.pos_inf && !pos_inf)
      {
          return true;
      }
      if (rhs.neg_inf && !neg_inf)
      {
          return false;
      }
      return false;

    }
};

