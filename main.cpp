#include <iostream>
#include <string>
using namespace std;

class FranctionalNumber {
    private: 
        int numerator;
        int denominator;

    public:
        FranctionalNumber(int num, int den) : numerator(num), denominator(den) {}

    FranctionalNumber operator+(const FranctionalNumber& other) {
        int num = this->numerator * other.denominator + this->denominator * other.numerator;
        int den = this->denominator * other.denominator;

        return FranctionalNumber(num, den);
    }

    FranctionalNumber operator++() {
        this->numerator += this->denominator;

        return *this;
    }

    FranctionalNumber operator++(int) {
        FranctionalNumber temp = *this;

        this->numerator += this->denominator;

        return temp;
    }

    bool operator==(const FranctionalNumber& f) {
        if(this->numerator == f.numerator && this->denominator == f.denominator) {
            return true;
        }

        return false;
    }

    friend ostream& operator<<(ostream& out, FranctionalNumber& f);
    friend istream& operator>>(istream& in, FranctionalNumber& f);
};

ostream& operator<<(ostream& out, FranctionalNumber& f) {
    out << f.numerator << " / " << f.denominator;

    return out;
}

//With empty constructor
istream& operator>>(istream& in, FranctionalNumber& f) {
    char delim;
    in >> f.numerator >> delim >> f.denominator;

    return in;
}

int main() {
    FranctionalNumber f1(5, 6);
    FranctionalNumber f2(3, 4);

    FranctionalNumber f3 = f1 + f2;

    cout << f3 << endl;

    return 0;
}