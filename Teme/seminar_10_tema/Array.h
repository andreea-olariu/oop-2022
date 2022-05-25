#ifndef SEMINAR_10_TEMA_ARRAY_H
#define SEMINAR_10_TEMA_ARRAY_H
#include <cstdio>
#include "Exceptions.h"
#include "Compare.h"
#include "func.cpp"

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T> &otherArray); // constructor de copiere

    T& operator[] (int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();

    void print() {
        for(auto i = 0; i < Size; i++) {
            std::cout << *(List[i]) << " ";
        }
        std::cout << "\n";
    }
};

template<class T>
Array<T>::Array() {
    Capacity = 0;
    Size = 0;

}

template<class T>
Array<T>::Array(int capacity) {
    Capacity = capacity;
    Size = 0;
    List = new T*[Capacity];
    for(auto i = 0; i < Capacity; i++) {
        List[i] = new T();
    }
}

template<class T>
Array<T>::Array(const Array<T> &otherArray) {
    Capacity = otherArray.Capacity;
    Size = otherArray.Size;

    List = new T*[Capacity];
    for(auto i = 0; i < Capacity; i++) {
        List[i] = new T();
        memcpy(List[i], otherArray.List[i], sizeof(otherArray.List[i]));
    }
}


template<class T>
Array<T>::~Array() {
    for(auto i = 0; i < Capacity; i++) {
        delete List[i];
    }
    delete[] List;
    List = nullptr;
}

template<class T>
const Array<T> &Array<T>::operator+=(const T &newElem) {
    memcpy(List[Size++], &newElem, sizeof(&newElem));
    return *this;
}

template<class T>
T &Array<T>::operator[](int index) {
    if(index < 0 || index >= Size) {
        throw OutOfRangeException(index);
    } else {
        return *(List[index]);
    }
}

template<class T>
const Array<T> &Array<T>::Insert(int index, const T &newElem) {
    if(index < 0 || index >= Size) {
        throw OutOfRangeException(index);
    } else {
        shiftRight<T>(Size, index, List, 1);
        memcpy(List[index], &newElem, sizeof(&newElem));
        Size++;
        return *this;
    }
}

template<class T>
const Array<T> &Array<T>::Insert(int index, const Array<T> otherArray) {
    if(index < 0 || index >= Size) {
        throw OutOfRangeException(index);
    } else {
        shiftRight<T>(Size, index, List, otherArray.Size);
        for(auto i = index; i < index + otherArray.Size; i++)
            memcpy(List[i], otherArray.List[i - index], sizeof(T*));
        Size += otherArray.Size;
        return *this;
    }
}

template<class T>
const Array<T> &Array<T>::Delete(int index) {
    if(index < 0 || index >= Size) {
        throw OutOfRangeException(index);
    } else {
        shiftLeft<T>(Size, index, List, 1);
        List[Size - 1] = nullptr;
        Size--;
        return *this;
    }
}

template<class T>
int Array<T>::GetSize() {
    return Size;
}

template<class T>
int Array<T>::GetCapacity() {
    return Capacity;
}

template<class T>
void Array<T>::Sort() {
    for(auto i = 0; i < Size - 1; i++)
        for(auto j = i + 1; j < Size; j++)
            if(*(List[i]) > *(List[j]))
                std::swap(List[i], List[j]);
}

template<class T>
void Array<T>::Sort(int (*compare)(const T &, const T &)) {
    for(auto i = 0; i < Size - 1; i++)
        for(auto j = i + 1; j < Size; j++)
            if(compare(*(List[i]), *(List[j])) == -1)
                std::swap(List[i], List[j]);
}

template<class T>
void Array<T>::Sort(Compare *comparator) {
    for(auto i = 0; i < Size - 1; i++)
        for(auto j = i + 1; j < Size; j++)
            if(comparator->CompareElements(List[i], List[j]) == 1)
                std::swap(List[i], List[j]);
}

template<class T>
int Array<T>::Find(const T &elem) {
    for(auto i = 0; i < Size; i++) {
        const T temp = *(List[i]);
        if(temp == elem)
            return i;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T &elem, int (*compare)(const T &, const T &)) {
    for(auto i = 0; i < Size; i++) {
        const T temp = *(List[i]);
        if(compare(temp, elem) == 1)
            return i;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T &elem, Compare *comparator) {
    for(auto i = 0; i < Size; i++) {
        if(comparator->CompareElements(List[i], &elem));
            return i;
    }
    return -1;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator() {
    return ArrayIterator<T>(0, List[0]);
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator() {
    return ArrayIterator<T>(Size - 1, List[Size - 1]);
}

template<class T>
int Array<T>::BinarySearch(const T &elem) {
    auto left = 0;
    auto right = Size - 1;
    while(left <= right) {
        auto mid = left + (right - left) / 2;
        const T temp =  *(List[mid]);
        if(temp == elem)
            return mid;
        else if(elem > temp)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T &elem, int (*compare)(const T &, const T &)) {
    auto left = 0;
    auto right = Size - 1;
    while(left < right) {
        auto mid = left + (right - left) / 2;
        const T temp =  *(List[mid]);
        if(compare(temp, elem) == 0)
            return mid;
        else if(compare(temp, elem) == -1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T &elem, Compare *comparator) {
    auto left = 0;
    auto right = Size - 1;
    while(left < right) {
        auto mid = left + (right - left) / 2;
        if(comparator->CompareElements(List[mid], &elem) == 0)
            return mid;
        else if(comparator->CompareElements(List[mid], &elem) == -1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<class T>
bool Array<T>::operator=(const Array<T> &otherArray) {
    if(this = Array<T>(otherArray))
        return true;
    return false;
}


#endif //SEMINAR_10_TEMA_ARRAY_H
