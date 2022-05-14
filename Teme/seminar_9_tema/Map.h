#include <iostream>
#ifndef SEMINAR_9_TEMA_MAP_H
#define SEMINAR_9_TEMA_MAP_H

template <typename T, typename R>
struct Pair {
    T key;
    R value;
};

template<typename T, typename R>
struct Iterator {
private:
    Pair<T, R>* pair;
    int index;
    struct Triplet{
        T key;
        R value;
        int i;
    };
public:
    Iterator(Pair<T, R>* ptr, int index) : pair(ptr), index(index) {};
    bool operator!=(Iterator<T, R>& it) {
        if(it.pair != this->pair)
            return true;
        return false;
    }
    Iterator& operator++() {
        pair++;
        index++;
        return *this;
    }
    Triplet operator*() {
        Triplet tr = {this->pair->key, this->pair->value, this->index};
        return tr;
    }
};

template <typename T, typename R>
class Map {
private:
    int counter;
    Pair<T, R> pairs[100];
    void addElement(T key, R value) {
        pairs[counter].key = key;
        pairs[counter].value = value;
        counter++;
    }
public:
    Map();
    R& operator[](T key);
    Iterator<T, R> begin();
    Iterator<T, R> end();
    Pair<T, R>& Set(T key, R value);
    int Count();
    void Clear();
    bool Delete(const T& key);
    bool Includes(const Map<T, R>& map);
    bool Get(const T& key, R& value);
};

template<typename T, typename R>
Map<T, R>::Map() {
    counter = 0;
}

template<typename T, typename R>
R& Map<T, R>::operator[](T key) {
    for(int i = 0; i < counter; i++) {
        if(pairs[i].key == key) {
            return pairs[i].value;
        }
    }
    addElement(key, R());
    return pairs[counter-1].value; // default value
}

template<typename T, typename R>
Pair<T, R> &Map<T, R>::Set(T key, R value) {
    for(int i = 0; i < counter; i++) {
        if(pairs[i].key == key) {
            return pairs[i];
        }
    }
    addElement(key, value);
}

template<typename T, typename R>
int Map<T, R>::Count() {
    return counter;
}

template<typename T, typename R>
Iterator<T, R> Map<T, R>::begin() {
    return {pairs, 0};
}

template<typename T, typename R>
Iterator<T, R> Map<T, R>::end() {
    return {pairs + counter, counter};
}

template<typename T, typename R>
void Map<T, R>::Clear() {
    counter = 0;
}

template<typename T, typename R>
bool Map<T, R>::Delete(const T &_key) {
    for(int i = 0; i < counter; i++) {
        if(pairs[i].key == _key) {
           for(int j = i; j < counter - 1; j++) {
               pairs[j] = pairs[j + 1];
               counter--;
           }
           break;
        }
    }

}

template<typename T, typename R>
bool Map<T, R>::Includes(const Map<T, R> &map) {
    if(counter != map.counter)
        return false;
    for(int i = 0; i < counter; i++) {
        if(pairs[i] != map.pairs[i])
            return false;
    }
    return true;
}

template<typename T, typename R>
bool Map<T, R>::Get(const T &key, R &value) {
    for(int i = 0; i < counter; i++) {
        if(pairs[i].key == key) {
            value = pairs[i].value;
            return true;
        }
    }
    return false;
}


#endif //SEMINAR_9_TEMA_MAP_H
