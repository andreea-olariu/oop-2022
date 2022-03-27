#pragma once

#include <ostream>

// operatori care trebuie implementati:
// 1. op+, op-, op*
// care sa accepte doua numere complexe, un numar complex si un numar real, sau un numar real si un numar complex
// (9 in total)
// 2. op- unar
// 3. op== si op!=
// 4. op<< de streamuri pentru afisare
// 5. op++ prefixat si postfixat si op-- prefixat si postfixat
// 6. op() cu semnificatia de mai jos
// total: 18 operatori

// op++ postfixat TREBUIE sa foloseasca op++ prefixat
// op-- postfixat TREBUIE sa foloseasca op-- prefixat

// op+, op-, op* care iau un numar real TREBUIE sa foloseasca respectivii care iau numere complexe
// eg: op+(Complex, double) va apela op+(Complex, Complex)

class Complex {
private:
    double real_data;
    double imag_data;
public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex&);

    // daca numarul are doar o parte reala
    bool is_real() const;

    double real() const;
    double imag() const;
    // absolutul numarului
    double abs() const;
    // conjugatul
    Complex conjugate() const;

   // Complex& operator()(double real, double imag);
    friend Complex operator+(const Complex& l, const Complex& r);
    friend Complex operator+(const Complex& l, double r);
    friend Complex operator+(double l, const Complex& r);

    friend Complex operator-(const Complex& l, const Complex& r);
    friend Complex operator-(const Complex& l, double r);
    friend Complex operator-(double l, const Complex& r);

    friend Complex operator*(const Complex& l, const Complex& r);
    friend Complex operator*(const Complex& l, double r);
    friend Complex operator*(double l, const Complex& r);

    friend Complex operator-(const Complex& obj);
    friend bool operator==(const Complex& l, const Complex& r);
    friend bool operator!=(const Complex& l, const Complex& r);

    Complex operator()(double, double);

    Complex& operator++();
    Complex operator++(int);

    Complex& operator--();
    Complex operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};
