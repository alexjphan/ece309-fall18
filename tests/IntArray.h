class IntArray{
private:
    int *a;
    int length;
public:
    IntArray(const char* str){
        int i=0;
        while(str[i] != 0){
            i++;
        }
        length = i;
        for (i = 0; i < length; i++){
            a[i] = (int)str[i];
        }
    }

    IntArray(int size, int val=0){
        length = size;
        a = new int[size];
        for (int i = 0; i < size; i++){
            a[i] = val;
        }
    }

    int* geta(){return a;}

    int get(int index) const{return a[index];}

    int getlength(){return length;}

    void set(int index, int val){a[index] = val;}

    int& operator[](int index){return a[index];}

    IntArray& operator+=(const IntArray &rhs) {
        for(int i = 0; i < length && i < rhs.length; i++) {
            set(i, get(i) + rhs.get(i));
        }
        return *this;
    }

    IntArray operator+(const IntArray &rhs) const{
        IntArray temp(length);
        for(int i = 0; i < length; i++){
            temp[i] = get(i);
        }
        for(int i = 0; i < length && i < rhs.length; i++){
            temp[i] = get(i) + rhs.get(i);
        }
        return temp;
    }

    IntArray operator-(const IntArray &rhs) const{
        IntArray temp(length);
        for(int i = 0; i < length; i++){
            temp[i] = get(i);
        }
        for(int i = 0; i < length && i < rhs.length; i++){
            temp[i] = get(i) - rhs.get(i);
        }
        return temp;
    }

    IntArray operator*(int x) const{
        IntArray temp(length);
        for(int i = 0; i < length; i++){
            temp[i] = get(i) * x;
        }
        return temp;
    }

    IntArray operator/(int x) const{
        IntArray temp(length);
        for(int i = 0; i < length; i++){
            temp[i] = get(i) / x;
        }
        return temp;
    }

    IntArray operator<<(int count) const{
        IntArray temp(length);
        for(int i = 0; i < length; i++){
            if (i - count < 0)
                temp[i] = get(length + i - count);
            else
                temp[i] = get(i - count);
        }
        return temp;
    }

    operator char*() const{
        bool zero = false;
        char* temp = new char[length];
        for(int i = 0; i < length; i++){
            if(get(i) >=0 && get(i) <= 255){
                if(get(i) == 0)
                    zero = true;
                temp[i] = (char)get(i);
            }
            else
                temp[i] = ' ';
        }

        if(!zero){
            char* newtemp = new char[length+1];
            for(int i = 0; i < length; i++){
                newtemp[i] = temp[i]
            }
            newtemp[length] = (char)0;
            return newtemp;
        }
        return temp;
    }

    operator int() const{
        int average = 0;
        for(int i = 0; i < length; i++){
            average += a[i];
        }
        average = average / length;
        return average;
    }
};
