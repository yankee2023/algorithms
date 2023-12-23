#include <iostream>
#include <vector>
using namespace std;

static void print(vector<double> V) {
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << endl;
} 

int main() {
    vector<double> V;

    V.push_back(0.1);
    V.push_back(0.3);
    V.push_back(0.5);
    V[2] = 0.2;
    print(V);               // 0.1 0.3 0.2

    V.insert(V.begin() + 2, 0.7);
    print(V);               // 0.1 0.3 0.7 0.2

    V.erase(V.begin() + 1);
    print(V);               // 0.1 0.7 0.2

    V.push_back(0.9);
    print(V);               // 0.1 0.7 0.2 0.9
        
    return 0;
}