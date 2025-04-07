#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array {
    private:
        size_t size;
        T* storage;

    public:
        Array(int size) {
            this->size = size;
            this->storage = new T[size];
        }

        ~Array() {
            delete[] storage;
        }
        
        void setValue(size_t index, T value) {
            if(index < 0 || index >= this->size) {
                throw out_of_range("Cannot set element with this index");
            }

            this->storage[index] = value;
        }

        T getValue(size_t index) const {
            if(index < 0 || index >= this->size) {
                throw out_of_range("Cannot set element with this index");
            }

            return this->storage[index];
        }
};

template <typename M>
class Array1 {
private:
    size_t size;
    unique_ptr<M[]> storage;

public:
    // Constructor
    Array1(size_t size) : size(size), storage(make_unique<M[]>(size)) {}

    // No need for a destructor — handled by unique_ptr

    void setValue(size_t index, const M& value) {
        if (index < 0 || index >= this->size) {
            throw out_of_range("Index out of range in setValue");
        }
        storage[index] = value;
    }

    M getValue(size_t index) const {
        if (index < 0 || index >= this->size) {
            throw out_of_range("Index out of range in getValue");
        }
        return storage[index];
    }
};


int main() {
    Array<int> myArr(5);

    myArr.setValue(0, 1);
    cout << myArr.getValue(0) << endl;

    Array1<int> myArr1(2);

    myArr1.setValue(0, 1122);
    cout << myArr1.getValue(0) << endl;



    
    return 0;
}