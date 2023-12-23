#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> S;

    S.push(3);
    S.push(7);
    S.push(1);
    cout << "Stack size = " << S.size() << endl;

    cout << S.top() << " ";         // 1
    S.pop();                        // Stackの頂点から要素を削除

    cout << S.top() << " ";         // 7
    S.pop();

    cout << S.top() << " " << endl; // 3
    S.pop();

    cout << "Stack size = " << S.size() << endl;
    return 0;
}