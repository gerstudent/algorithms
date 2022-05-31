#include <iostream>
using namespace std;

int recursiveGcd(int a, int b) {
    return a == 0 ? b : b == 0 ? a : a == b ? a : recursiveGcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << recursiveGcd(a, b);
}



