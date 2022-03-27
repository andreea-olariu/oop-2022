#include <iostream>
#include "Student.h"

const char *Student::getName() const {
    const char* p;
    p = name;
    return p;
}

void Student::setName(char *newName) {
    strcpy(name, newName);
}

float Student::getGradeMath() const {
    return gradeMath;
}

bool Student::setGradeMath(float newGrade) {
    if(newGrade < 0 || newGrade > 10) {
        return false;
    } else {
        gradeMath = newGrade;
        return true;
    }
}

float Student::getGradeEnglish() const {
    return gradeEnglish;
}

bool Student::setGradeEnglish(float newGrade) {
    if(newGrade < 0 || newGrade > 10) {
        return false;
    } else {
        gradeEnglish = newGrade;
        return true;
    }
}

float Student::getGradeHistory() const {
    return gradeHistory;
}

bool Student::setGradeHistory(float newGrade) {
    if(newGrade < 0 || newGrade > 10) {
        return false;
    } else {
        gradeHistory = newGrade;
        return true;
    }
}

float Student::getAverageGrade() {
    return (gradeEnglish + gradeMath + gradeHistory) / 3.0f;
}
