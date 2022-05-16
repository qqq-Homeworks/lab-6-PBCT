// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#include "MyVector.hpp"

template<class T>
MyVector<T>::MyVector() {
    size = 0;
    maxsize = MAX_SIZE;
    pdata = new T[maxsize];
}

template<class T>
MyVector<T>::MyVector(T el, int maxsz) : maxsize(maxsz) {
    size = 1;
    pdata = new T[maxsz];
    pdata[0] = el;
}


//template<class T>
//template<class Compare>
//void MyVector<T>::sort(Compare cmp) {
//    std::sort(this->pdata, this->pdata + size, cmp);
//}

//template<>
//void MyVector<char *>::resize() {
//    if (size >= maxsize)
//        maxsize = (maxsize / 2 + 1) * 3;
//    else if (maxsize != MAX_SIZE && size <= maxsize / 2)
//        maxsize = (maxsize / 3 + 1) * 2;
//    else return;
//    char **newMemory = new char *[maxsize];
//
//    for (size_t i = 0; i < size; ++i) {
//        if (pdata[i] == NULL) break;
//        newMemory[i] = new char[strlen(pdata[i]) + 1];
//        strcpy(newMemory[i], pdata[i]);
//    }
//    for (size_t i = 0; i < size; ++i) {
//        delete[] pdata[i];
//
//    }
//    delete[] pdata;
//    pdata = newMemory;
//}

template<class T>
void MyVector<T>::resize() {
    if (size >= maxsize)
        maxsize = (maxsize / 2 + 1) * 3;
    else if (maxsize != MAX_SIZE && size <= maxsize / 2)
        maxsize = (maxsize / 3 + 1) * 2;
    else return;
    T *newMemory = new T[maxsize];

    for (size_t i = 0; i < size; ++i) {
        newMemory[i] = pdata[i];
    }
    delete[] pdata;
    pdata = newMemory;
}


template<class T>
MyVector<T>::MyVector(const MyVector &v) : maxsize(v.maxsize), size(v.size) {
    pdata = new T[v.maxsize];
    for (size_t i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
}


template<class T>
void MyVector<T>::add_element(T el) {
    size++;
    resize();
    pdata[size - 1] = el;
}


template<class T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template<class T>
bool MyVector<T>::delete_element(int i) {
    if (i > -1 && i < size) {
        for (size_t j = i; j < size - 1; ++j) {
            pdata[j] = pdata[j + 1];
        }
        size--;
        resize();
        return true;
    } else
        return false;
}

template<class T>
T &MyVector<T>::operator[](size_t i) {
    return pdata[i];
}

template<class T>
int MyVector<T>::find(T el) {
    int q = std::find_if(pdata, pdata + size, [el](T q) { return q == el; }) - pdata;
    if (q == size) q = -1;
    return q;
}


template<class T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v) {
    if (this != &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new T[v.maxsize];
        for (size_t i = 0; i < size; ++i) {
            pdata[i] = v.pdata[i];
        }
    }
    return *this;
}

template<class T>
ostream &operator<<(ostream &out, MyVector<T> &v) {
    for (size_t i = 0; i < v.size; ++i) {
        out << '[' << i << ']' << " : " << "{\"" << v.pdata[i] << "\"}" << endl;
    }
    return out;
}

template<class T>
T MyVector<T>::operator[](size_t i) const {
    return pdata[i];
}



