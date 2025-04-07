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
            throw overflow_error("Stack underflow: Cannot pop from empty stack");
        }

        T res = head->val;
        head = move(head->next);  // this deletes the old head automatically
        return res;
    }
};



int main() {
    Stack<double> stack;

    try
    {
        stack.pop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}