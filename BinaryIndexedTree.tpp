#include <iostream>
#include "BinaryIndexedTree.h"

template<class T>
void BIT<T>::iUpdate(unsigned long long i, T value) {
    T sum = 0;
    unsigned long long sqroot = i & (-i);
    for (unsigned long long j = i - sqroot + 1; j < i; j++) {
        sum += original[j];
    }
    elements[i] = sum + value;
}

template<class T>
BIT<T>::BIT(unsigned long long size) : curSize(0), maxSize(size), elements(new T[size + 1]()),
                                    original(new T[size + 1]()) {}

template<class T>
BIT<T>::BIT(unsigned long long size, T *array) : curSize(0), maxSize(size), elements(new T[size + 1]),
                                                   original(new T[size + 1]) {
    for (int i = 1; i <= size; i++) {
        Insert(array[i]);
    }
}

template<class T>
BIT<T>::~BIT() {
    delete[] elements;
    delete[] original;
}

template<class T>
T BIT<T>::Get(unsigned long long i) {
    if (i > curSize) {
        cerr << "Out of array\n";
        return -1;
    } else {
        T sum = 0;
        while (i != 0) {
            sum += elements[i];
            i -= i & (-i);
        }
        return sum;
    }
}

template<class T>
T BIT<T>::operator[](unsigned long long i) {
    return Get(i);
}

template<class T>
T BIT<T>::GetOriginal(unsigned long long i) {
    if (i>0 && i<=curSize) {
        return original[i];
    }
    cerr<<"Out of array";
    return -1;
}

template<class T>
T BIT<T>::GetBetween(unsigned long long a, unsigned long long b) {
    if (a <= curSize && b >= 1 && b <= curSize) {
        b--;
        if (b < a) {
            return Get(a) - Get(b);
        }
        return Get(b) - Get(a);
    } else {
        cerr << "Out of array\n";
        return -1;
    }
}

template<class T>
void BIT<T>::Insert(T value) {
    if (curSize < maxSize) {
        curSize++;
        original[curSize] = value;
        iUpdate(curSize, value);
    } else {
        cerr << "Reached the maximum length\nProvide a longer array to resolve this issue\n";
    }
}

template<class T>
void BIT<T>::Delete(unsigned long long i) {
    if (i >= 1 && i <= curSize) {
        for (unsigned long long j = i; j < curSize; j++) {
            original[j] = original[j + 1];
        }
        curSize--;
        for (unsigned long long j = i; j <= curSize; j++) {
            iUpdate(j, original[j]);
        }
    } else {
        cerr << "Out of array\n";
    }
}

template<class T>
void BIT<T>::Change(unsigned long long i, T value) {
    if (i > 0 && i <= curSize) {
        T aux = original[i] - value;
        original[i] = value;
        while (i <= curSize) {
            elements[i] -= aux;
            i += i & (-i);
        }
    } else {
        cerr << "Out of array\n";
    }
}

template<class T>
void BIT<T>::Print() {
    for (unsigned long long i = 1; i <= curSize; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}