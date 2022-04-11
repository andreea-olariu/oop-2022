#ifndef SIMULARE_TEST_4_OPERATIE_H
#define SIMULARE_TEST_4_OPERATIE_H


class Operatie {
protected:
    const char *name;
public:
    Operatie() : name(nullptr) {};
    const char* GetName();
    virtual void printResult(int, int) = 0;
};


#endif //SIMULARE_TEST_4_OPERATIE_H
