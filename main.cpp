#include <iostream>
#include <string>
using namespace std;

class FranctionalNumber {
    private: 
        int numerator;
        int denominator;

    public:
        FranctionalNumber() {}
        FranctionalNumber(int num, int den) : numerator(num), denominator(den) {}

    FranctionalNumber operator+(const FranctionalNumber& other) {
        int num = this->numerator * other.denominator + this->denominator * other.numerator;
        int den = this->denominator * other.denominator;

        return FranctionalNumber(num, den);
    }

    FranctionalNumber operator-(const FranctionalNumber& other) {
        int num = this->numerator * other.denominator - this->denominator * other.numerator;
        int den = this->denominator * other.denominator;

        return FranctionalNumber(num, den);
    }

    FranctionalNumber operator*(const FranctionalNumber& other) {
        int num = this->numerator *  other.numerator;
        int den = this->denominator * other.denominator;

        return FranctionalNumber(num, den);
    }

    FranctionalNumber operator/(const FranctionalNumber& other) {
        int num = this->numerator *  other.denominator;
        int den = this->denominator * other.numerator;

        return FranctionalNumber(num, den);
    }

    bool operator==(const FranctionalNumber& other) {
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }

    bool operator!=(const FranctionalNumber& other) {
        return this->numerator != other.numerator || this->denominator != other.denominator;
    }

    bool operator>(const FranctionalNumber& other) {
        if(this->denominator == other.denominator) {
            return this->numerator > other.numerator;
        }

        int initNumerator = this->numerator * other.denominator;
        int otherNumerator = other.numerator * this->denominator;

        return initNumerator > otherNumerator;
    }

    bool operator>=(const FranctionalNumber& other) {
        if(this->denominator == other.denominator) {
            return this->numerator >= other.numerator;
        }

        int initNumerator = this->numerator * other.denominator;
        int otherNumerator = other.numerator * this->denominator;

        return initNumerator >= otherNumerator;
    }

    bool operator<(const FranctionalNumber& other) {
        if(this->denominator == other.denominator) {
            return this->numerator < other.numerator;
        }

        int initNumerator = this->numerator * other.denominator;
        int otherNumerator = other.numerator * this->denominator;

        return initNumerator < otherNumerator;
    }

    bool operator<=(const FranctionalNumber& other) {
        if(this->denominator == other.denominator) {
            return this->numerator <= other.numerator;
        }

        int initNumerator = this->numerator * other.denominator;
        int otherNumerator = other.numerator * this->denominator;

        return initNumerator <= otherNumerator;
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

    friend ostream& operator<<(ostream& out, FranctionalNumber& f);
    friend istream& operator>>(istream& in, FranctionalNumber& f);
};

ostream& operator<<(ostream& out, FranctionalNumber& f) {
    out << f.numerator << " / " << f.denominator;

    return out;
}


istream& operator>>(istream& in, FranctionalNumber& f) {
    char delim;
    in >> f.numerator >> delim >> f.denominator;

    return in;
}

int main() {
    FranctionalNumber f1(5, 6);
    FranctionalNumber f2(5, 6);
    FranctionalNumber f3 = f1 * f2;
    f3 = f3 / f2;

    cout << (f1 != f2) << endl;

    return 0;
}