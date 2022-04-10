#ifndef SIMULARE_TEST_2_LISTAPARAGRAFE_H
#define SIMULARE_TEST_2_LISTAPARAGRAFE_H

#define SIZE 500

class ListaParagrafe {
    char* paragraphs[SIZE];
    int counter;
public:
    ListaParagrafe();
    void Add(const char*);
    char** begin();
    char** end();
};


#endif //SIMULARE_TEST_2_LISTAPARAGRAFE_H
