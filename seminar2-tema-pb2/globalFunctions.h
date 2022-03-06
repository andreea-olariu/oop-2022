#ifndef SEMINAR2_TEMA_PB2_GLOBALFUNCTIONS_H
#define SEMINAR2_TEMA_PB2_GLOBALFUNCTIONS_H

#include "Student.h"
namespace globalFunctions {
    int comparesNames(Student &S1, Student &S2);

    int comparesEnglishGrade(Student &S1, Student &S2);

    int comparesMathGrade(Student &S1, Student &S2);

    int comparesHistoryGrade(Student &S1, Student &S2);

    int comparesAverageGrade(Student &S1, Student &S2);
}

#endif //SEMINAR2_TEMA_PB2_GLOBALFUNCTIONS_H
