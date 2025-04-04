#include <iostream>
#include <string>
using namespace std;

template <typename T, typename P>
struct Node
{
    T val1;
    P val2;
    Node* next;
};

template <typename T, typename P>
class Stack {
    private: 
        Node<T, P>* head;

    public:
        Stack() : head(nullptr) {}
        
        void push(T val1, P val2) {
            Node<T, P>* newHead = new Node<T, P>{val1, val2, head};
            head = newHead;
        }

        pair<T, P> pop() {
            pair<T, P> res = {head->val1, head->val2};
            P res1 = head->val2;
            Node<T, P>* temp = head->next;

            delete head;
            head = temp;

            return res;
        }
};

int main() {
    Stack<char, int> stack;

    for(int i = 0; i < 5; ++i) {
        stack.push(char('a' + i), i);
    }

    for(int i = 0; i < 5; ++i) {
        pair<char, int> p = stack.pop();

        cout << p.first << p.second << endl;
    }
}