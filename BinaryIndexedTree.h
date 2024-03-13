#ifndef BINARISAN_INDEXELT_FAK_BINARYINDEXEDTREE_H
#define BINARISAN_INDEXELT_FAK_BINARYINDEXEDTREE_H

using namespace std;

template<class T>
class BIT {
private:
    //maximalis meret, es a jelenlegi merete a fanak
    unsigned long long maxSize, curSize;
    //a fa elemei
    T *elements;
    //a sorozat elemei
    T *original;

    void iUpdate(unsigned long long, T);

public:
    //konstruktor
    BIT(unsigned long long);

    //konstruktor, amely befogad egy tombot
    BIT(unsigned long long, T *);

    //destruktor
    ~BIT();

    //a sorozat [1, i] terjedo elemek osszege
    T Get(unsigned long long);

    //a sorozat [1, i] terjedo elemek osszege
    T operator[](unsigned long long);

    //visszateriti az eredit tomb i. erteket
    T GetOriginal(unsigned long long);

    //a sorozat [a, b] terjedo elemek osszege
    T GetBetween(unsigned long long, unsigned long long);

    //egy elemet beteszunk a sorozatba, majd frissiti a fat
    void Insert(T);

    //elem torlese a sorozatbol es a fabol
    void Delete(unsigned long long);

    //elem modositasa
    void Change(unsigned long long, T);

    //eredeti tomb kiirasa
    void Print();
};

#include "BinaryIndexedTree.tpp"

#endif //BINARISAN_INDEXELT_FAK_BINARYINDEXEDTREE_H
