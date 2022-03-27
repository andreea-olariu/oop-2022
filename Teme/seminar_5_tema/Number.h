#ifndef SEMINAR_5_TEMA_NUMBER_H
#define SEMINAR_5_TEMA_NUMBER_H

class Number{
    int base;
    char* value;
    int numericalValueBase10;
public:
    Number(const char * value, int base); // where base is between 2 and 16
    Number(const Number&);
    Number(Number&&);
    Number(int);
    Number(int x, int _base);
    ~Number();

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
    friend Number operator+(Number, const Number&);
    friend Number operator-(Number, const Number&);
    friend Number operator*(Number, const Number&);
    friend Number operator/(Number, const Number&);
    bool operator>(const Number&);
    bool operator<(const Number&);
    bool operator>=(const Number&);
    bool operator<=(const Number&);
    bool operator==(const Number&);
    Number& operator=(const Number&);
    Number& operator=(char*);
    Number& operator=(int);
    friend bool operator*=(Number&, const Number&);
    friend bool operator+=(Number&, const Number&);
    friend bool operator-=(Number&, const Number&);
    friend bool operator/=(Number&, const Number&);
    int operator[](int);
    int operator--();
    int operator--(int);
};

#endif //SEMINAR_5_TEMA_NUMBER_H
