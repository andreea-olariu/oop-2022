#include <iostream>
#include <cstring>
#include "Student.h"


Student::Student() {
    name = nullptr;
    countSubj = 0;
    for(int i = 0; i < SIZE; i++) {
        grades[i].grade = 0;
        grades[i].subj = nullptr;
    }
    avg = 0;
}

Student::Student(const char* _name) {
    name = _name;
    countSubj = 0;
    for(int i = 0; i < SIZE; i++) {
        grades[i].grade = 0;
        grades[i].subj = nullptr;
    }
    avg = 0;
}


const char *Student::GetName() {
    return name;
}

void Student::PrintNote() {
    for(int i = 0; i < countSubj; i++) {
        std::cout << grades[i].subj << ": " << grades[i].grade << '\n';
    }
}

void Student::setName(const char * _name) {
    name = _name;
}

int& Student::operator[](const char * _subj) {
    bool flag = false;
    for(int i = 0; i < countSubj; i++) {
        if(strcmp(_subj, grades[i].subj) == 0) {
            int&x = grades[i].grade;
            flag = true;
            return x;
        }
    }
    if(!flag) {
        grades[countSubj].subj = _subj;
        grades[countSubj].grade = 0;
        int&x = grades[countSubj++].grade;
        return x;
    }
}

void Student::computeAvg() {
    float sum = 0;
    for(int i = 0; i < countSubj; i++) {
        sum += grades[i].grade;
    }
    avg = (float)(sum / countSubj);
}

float Student::getAvg() {
    computeAvg();
    return avg;
}

Student::operator float() {
    computeAvg();
    return (float)(avg);
}
