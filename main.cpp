#include "./main/heap.h"
#include <iostream>
using namespace std;

int main() {
    Heap<int> h;
    int input;
    for(int i = 0; i < 8; i++) {
        cout << "Insert number: ";
        cin >> input;
        h.insert(input);
    }
    h.printHeap();
    cout << h.remove(10) << endl;
    h.printHeap();
    return 0;
}