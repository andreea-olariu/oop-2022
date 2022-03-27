#include <iostream>
class Base {
protected:
    int x;
public:
    void SetX(int x);
    void Print2();
};

class N_1 {
protected:
    int x;
public:
    N_1() : x(1) {};
    N_1(int val) : x(val) {
        std::cout << "N_1\n";
    };
    virtual void SetX(int a) {
        this->x = a;
        std::cout << "SetX from N_1\n";
    }
};

class N_2 {
    int y;
public:
    N_2(int val) : y(val) {
        std::cout << "N_2\n";
    };
};
class N_3 {
    int z;
public:
    N_3(int val) : z(val) {
        std::cout << "N_3\n";
    };
};

class Numbers : public N_1, public N_2, public N_3 {
private:
    N_1 num;
public:
    Numbers() : num(1), N_2(2), N_3(3), N_1(1) {
        std::cout << "Numbers\n";
    };
    void SetX(int a, int b) {
        this->x = a;
        std::cout << "SetX from Numbers\n";
    }
};

void Base::SetX(int x) {
    this->x = x;
}

class Derived : public Base {
public:
    void Print();
};

void Base::Print2() {
    std::cout << x;
}

void Derived::Print() {
    std::cout << x;
}

class Color {
public:
    virtual void printColor() {
        std::cout << "Printez culoare\n";
    }
};

class Figure  {
public:
   virtual void Draw() {
        std::cout << "Draw from Figure\n";
    }
};

class Circle : public Figure, public Color {
public:
    void Draw() {
        std::cout << "Draw from Circle\n";
    }
};

class Square : public Figure {
public:
    void Draw() {
        std::cout << "Draw from Square\n";
    }
};

class A {
public:
    virtual void x() = 0;
};

class B : public A {
public:
    void x() {
        std::cout << "Hello\n";
    }
};

int main() {
//    Derived d1;
//    d1.SetX(4);
//    d1.Print();
//    d1.Print2();
//    Numbers n;
//    n.N_1::SetX(2);

//    Figure *f[2];
//    f[0] = new Square();
//    f[1] = new Circle();
//    std::cout << "Size ul lui f[1] este: " << sizeof(f[1]) << '\n';
//    for(int i = 0; i < 3; i++)
//        f[i]->Draw();
    B b;
    b.x();

    A* a;

    return 0;
}
