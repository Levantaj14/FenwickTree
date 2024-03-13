#include <iostream>
#include "BinaryIndexedTree.h"
#include <vector>
//a fad [0, n] intervallummal dolgozik

using namespace std;

int main() {
    int tomb[16];
    //vector<int> tomb(16);
    for (int i = 1; i <= 15; i++) {
        tomb[i] = i;
    }
    //BIT elem(15, tomb);
    BIT<int> elem(9);
    //elem.Get(3);
    //BIT valami();
/*    for (int i = 1; i <= 15; i++) {
        elem.Insert(i);
    }*/
    //cout<<elem.Get(10)<<endl;
    elem.Insert(5);
    elem.Insert(7);
    elem.Insert(9);
    elem.Insert(-3);
    elem.Insert(0);
    elem.Insert(6);
    elem.Insert(2);
    elem.Insert(8);
    elem.Insert(4);
    elem.Print();
    elem.Change(2, 2);
    elem.Print();
    return 0;
}
