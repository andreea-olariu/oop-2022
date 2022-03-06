#include <cstring>
#include "globalFunctions.h"
#include "Student.h"

int compareValues(int a, int b) {
    if(a > b) {
        return 1;
    } else if(a < b) {
        return -1;
    }
    return 0;
}

int globalFunctions::comparesNames(Student &S1, Student &S2) {
    if(strcmp(S1.getName(), S2.getName()) > 0) {
        return 1;
    } else if(strcmp(S1.getName(), S2.getName()) < 0) {
        return -1;
    }
    return 0;
}

int globalFunctions::comparesAverageGrade(Student &S1, Student &S2) {
    return compareValues(S1.getAverageGrade(), S2.getAverageGrade());
}

int globalFunctions::comparesMathGrade(Student &S1, Student &S2) {
    return compareValues(S1.getGradeMath(), S2.getGradeMath());
}

int globalFunctions::comparesHistoryGrade(Student &S1, Student &S2) {
    return compareValues(S1.getGradeHistory(), S2.getGradeHistory());
}

int globalFunctions::comparesEnglishGrade(Student &S1, Student &S2) {
    return compareValues(S1.getGradeEnglish(), S2.getGradeEnglish());
}