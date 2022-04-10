#ifndef PROBLEMA_2_VECTOR_H
#define PROBLEMA_2_VECTOR_H

template<typename T>
class Vector {
private:
    T* elements;
    int counter;
public:
    Vector();
    void push(T newElement);
    T pop();
    void removeAtIndex(int index);
    void insertAtIndex(T newElement, int index);
    void sort(bool(*)(T, T) = nullptr);
    T& get(int index);
    void set(T newObject, int index);
    int count();
    void printValues();
    int firstIndexOf(T, bool(*)(T, T) = nullptr);
};

template<typename T>
Vector<T>::Vector() {
    elements = nullptr;
    counter = 0;
}

template<typename T>
void Vector<T>::push(T newElement) {
    if(counter == 0) {
        elements = new T[1];
    } else {
        T* temp = new T[counter];
        for(int i = 0; i < counter; i++)
            temp[i] = elements[i];

        delete[] elements;
        elements = new T[2*counter];

        for(int i = 0; i < counter; i++)
            elements[i] = temp[i];
        delete[] temp;
    }
    elements[counter++] = newElement;
}

template<typename T>
T Vector<T>::pop() {
    if(counter != 0) {
        T temp = elements[counter];
        counter--;
        return temp;
    }
}

template<typename T>
void Vector<T>::removeAtIndex(int index) {
    if(index >= 0 && index < counter) {
        for(int i = index; i < counter; i++)
            elements[i] = elements[i + 1];
        counter--;
    }
}

template<typename T>
void Vector<T>::insertAtIndex(T newElement, int index) {
    if(index > 0 && index < counter) {
        T* temp = new T[counter];
        for(int i = 0; i < counter; i++)
            temp[i] = elements[i];
        delete[] elements;
        elements = new T[2*counter];
        for(int i = 0; i < counter; i++)
            elements[i] = temp[i];
        for(int i = counter; i > index; i--)
            elements[i] = elements[i-1];
        counter++;
        elements[index] = newElement;
    } else if(index == 0 && counter == 0) {
        elements = new T[1];
        elements[counter++] = newElement;
    }
}

template<typename T>
T& Vector<T>::get(int index) {
    if(index >= 0 && index < counter) {
        return elements[index];
    }
}

template<typename T>
int Vector<T>::count() {
    return counter;
}

template<typename T>
void Vector<T>::set(T newObject, int index) {
    if(index >= 0 && index < counter) {
        elements[index] = newObject;
    } else {
        printf("Indexul nu este deja folosit, deci nu pot folosi set\n");
    }
}

template<typename T>
void Vector<T>::printValues() {
    for(int i = 0; i < counter; i++)
        std::cout << elements[i] << " ";
    std::cout << '\n';
}

template<typename T>
void Vector<T>::sort(bool (*func)(T, T)) {
    for(int i = 0; i < counter - 1; i++)
        for(int j = i + 1; j < counter; j++) {
            if(func == nullptr) {
                if(elements[j] < elements[i])
                    std::swap(elements[i], elements[j]);
            } else {
                if(func(elements[i], elements[j]))
                    std::swap(elements[i], elements[j]);
            }
        }
}

template<typename T>
int Vector<T>::firstIndexOf(T obj, bool (*func)(T, T)) {
    for(int i = 0; i < counter; i++) {
        if(func == nullptr) {
            if(elements[i] == obj)
                return i;
        } else {
            if(func(obj, elements[i]))
                return i;
        }
    }
    return -1;
}


#endif //PROBLEMA_2_VECTOR_H
