
#ifndef SEMINAR_4_TEMA_SORT_H
#define SEMINAR_4_TEMA_SORT_H


class Sort {
    int count;
    int* nums;
public:
    Sort(int, int, int);
    Sort(int[], int);
    Sort(char*);
    Sort(int, ...);
    void InsertSort(bool ascendent=false);
    void QuickSort(int, int);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();

    int  GetElementFromIndex(int index);
};

#endif //SEMINAR_4_TEMA_SORT_H
