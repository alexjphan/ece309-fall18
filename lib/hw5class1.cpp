class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

class IntegerSetArray:public IntegerSet {
protected:
    int *a;
public:
    IntegerSetArray(int arraysize):IntegerSet(arraysize) {
        a = new int[arraysize];
        for(int i = 0; i < arraysize; i++) {
            a[i] = -1;
        }
    }
    bool insert(int x) {
        for (int i = 0; i < IntegerSet::size; i++) {
            if (a[i] < 0) {
                a[i] = x;
                return true;
            }
        }
        return false;
    }
    bool search(int x) const {
        for (int i = 0; i < IntegerSet::size; i++) {
            if (a[i] == x) {
                return true;
            }
        }
        return false;
    }
    void remove(int x){
        for (int i = 0; i < IntegerSet::size; i++) {
            if (a[i] == x) {
                a[i] = -1;
            }
        }
    }

};

int main(){
    int IntegerSetArray boob = new IntegerSetArray(5);
    boob.insert(3);

    return 0;
}
