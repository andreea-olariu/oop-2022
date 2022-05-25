#ifndef SEMINAR_10_TEMA_ARRAYITERATOR_H
#define SEMINAR_10_TEMA_ARRAYITERATOR_H

template<class T>
class ArrayIterator
{
private:
    T* elem;
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator();
    ArrayIterator(int _current, T* _elem);
    ArrayIterator& operator++ ();
    ArrayIterator& operator-- ();
    bool operator= (ArrayIterator<T> &);
    bool operator!= (ArrayIterator<T> &);
    T* GetElement();
};

template<class T>
ArrayIterator<T>::ArrayIterator() {
    Current = 0;
    elem = nullptr;
}

template<class T>
ArrayIterator<T> &ArrayIterator<T>::operator++() {
    elem++;
    Current++;
    return *this;
}

template<class T>
ArrayIterator<T> &ArrayIterator<T>::operator--() {
    elem--;
    Current--;
    return *this;
}

template<class T>
bool ArrayIterator<T>::operator=(ArrayIterator<T> & A) {
    if(this = A)
        return true;
    return false;
}

template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T> & A) {
    if(this != A)
        return true;
    return false;
}

template<class T>
T *ArrayIterator<T>::GetElement() {
    return elem;
}

template<class T>
ArrayIterator<T>::ArrayIterator(int _current, T* _elem) {
    Current = _current;
    memcpy(elem, _elem, sizeof(T*));
    delete _elem;
}


#endif //SEMINAR_10_TEMA_ARRAYITERATOR_H
