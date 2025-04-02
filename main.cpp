#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class Author {
    public:
        Author(const string& name) : name(name) {}
    
    private: 
        string name;    
};

class Book {
    private:
        string title;
        Author& author;
    
    public:
        Book(const string& title, Author& author): title(title), author(author) {}    
};

int main() {
    Author author("Patrik");
    Book book("My book", author);


    return 0;
}