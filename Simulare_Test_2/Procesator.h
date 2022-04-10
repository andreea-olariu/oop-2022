#ifndef SIMULARE_TEST_2_PROCESATOR_H
#define SIMULARE_TEST_2_PROCESATOR_H
#define SIZE 500

class Procesator {
public:
    Procesator() {};
    virtual void Proceseaza(char*) = 0;
    virtual void Print() = 0;
    virtual ~Procesator() {};
};


#endif //SIMULARE_TEST_2_PROCESATOR_H
