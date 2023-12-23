#include <iostream>
#include <list>
using namespace std;

int main() {
    list<char> L;

    L.push_front('b');  // b
    L.push_back('c');   // bc
    L.push_front('a');  // abc
    
    cout << L.front() << " ";
    L.pop_front();      // bc
    cout << L.front() << " ";
    L.pop_front();       // c
    cout << L.front() << endl;

    L.push_back('d');   // cd
    L.push_back('f');   // cdf
    auto itr = L.begin();
    itr++;
    itr++;
    L.insert(itr, 'e');   // cdef

    cout << L.front() << " ";
    L.pop_front();      // def
    cout << L.front() << " ";
    L.pop_front();       // ef
    cout << L.front() << " ";
    L.pop_front();       // f
    cout << L.front() << endl;

    return 0;
}