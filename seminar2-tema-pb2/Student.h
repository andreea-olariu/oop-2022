#ifndef SEMINAR2_TEMA_PB2_STUDENT_H
#define SEMINAR2_TEMA_PB2_STUDENT_H

class Student {
private:
    char name[21] = {};
    float gradeMath = 0.0;
    float gradeEnglish = 0.0;
    float gradeHistory = 0.0;
public:
    const char* getName() const;
    void setName(char *newName);
    float getGradeMath() const;
    bool setGradeMath(float newGrade);
    float getGradeEnglish() const;
    bool setGradeEnglish(float newGrade);
    float getGradeHistory() const;
    bool setGradeHistory(float newGrade);
    float getAverageGrade();
};

#endif //SEMINAR2_TEMA_PB2_STUDENT_H
