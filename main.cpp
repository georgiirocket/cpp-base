#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    T val;
    Node* next;
};

template <typename T>
class Stack {
    private: 
        Node<T>* head;

    public:
        Stack() : head(nullptr) {}
        
        void push(T val) {
            Node<T>* newHead = new Node<T>{val, head};
            head = newHead;
        }

        T pop() {
            T res = head->val;
            Node<T>* temp = head->next;

            delete head;
            head = temp;

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

    Stack<char> stack1;

    for(int i = 0; i < 5; ++i) {
        stack1.push(char('a' + i));
    }

    for(int i = 0; i < 5; ++i) {
        cout << stack1.pop() << endl;
    }
}