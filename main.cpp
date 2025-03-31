#include <iostream>
using namespace std;

class Item {
private:
    static inline int count = 0;
    int id;

public:
    Item() {
        count++;
        this->id = count;
    }

    static int getCount() {
        return count;
    }

    int getId() const {
        return this->id;
    }
};

int main() {
    for(int i = 0; i < 5; i++) {
        Item item;

        cout << "Id: " << item.getId() << endl;
        cout << "Count: " << item.getCount() << endl;
    }

    return 0;
}