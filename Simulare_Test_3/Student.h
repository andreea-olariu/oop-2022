#ifndef SIMULARE_TEST_3_STUDENT_H
#define SIMULARE_TEST_3_STUDENT_H

#define SIZE 101

struct ggrade {
    const char *subj;
    int grade;
};

class Student {
    const char* name;
    ggrade grades [SIZE];
    int countSubj;
    float avg;
public:
    Student();
    Student(const char*);
    const char* GetName();
    void PrintNote();
    void setName(const char*);
    int& operator[](const char*);
    void computeAvg();
    float getAvg();
    operator float();
};


#endif //SIMULARE_TEST_3_STUDENT_H
