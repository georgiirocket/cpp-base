#include <iostream>
#include <string>
using namespace std;

struct MyException : public exception
{
    public:
        char const* what() const noexcept override {
            return "My exception message";
        }
};


int main() {

    try
    {
        throw MyException();
    }
    catch(const MyException& e)
    {
        std::cerr << e.what() << '\n';
    }   catch (const exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}