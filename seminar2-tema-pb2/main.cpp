#include <iostream>
#include "Student.h"
#include "globalFunctions.h"
int main() {
    Student St1, St2;
    St1.setName("Ileana");
    St2.setName("Vanea");

    St1.setGradeEnglish(10.0);
    St2.setGradeEnglish(5.0);

    St1.setGradeMath(7.0);
    St2.setGradeMath(9.0);

    St1.setGradeHistory(9.5);
    St2.setGradeHistory(8.0);

    std::cout << globalFunctions::comparesAverageGrade(St1, St2);
    std::cout << '\n';
    std::cout << globalFunctions::comparesNames(St1, St2);
    return 0;
}
