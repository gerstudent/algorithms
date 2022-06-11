#include <iostream>
using namespace std;

int gcdRecursive(int a, int b) {
    return a == 0 ? b : b == 0 ? a : a == b ? a : gcdRecursive(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcdRecursive(a, b);
}



