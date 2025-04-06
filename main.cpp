#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
    T val;
    unique_ptr<Node<T>> next;

    Node(T v, unique_ptr<Node<T>> n) : val(v), next(move(n)) {
        
    }
};

template <typename T>
class Stack {
private:
    unique_ptr<Node<T>> head;

public:
    Stack() = default;

    void push(T val) {
        head = make_unique<Node<T>>(val, move(head));
    }

    T pop() {
        if (!head) {
            throw runtime_error("Stack underflow: Cannot pop from empty stack");
        }

        T res = head->val;
        head = move(head->next);  // this deletes the old head automatically
        return res;
    }
};



int main() {
    Stack<double> stack;

    for(int i = 0; i < 5; ++i) {
        stack.push(i / 2.0);
    }

    for(int i = 0; i < 5; ++i) {
        cout << stack.pop() << endl;
    }

    return 0;
}