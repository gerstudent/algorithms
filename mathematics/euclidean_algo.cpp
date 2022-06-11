#include <iostream>
using namespace std;

// Finding the greatest common divisor
int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap (a, b);
    }
    return a;
}

// Finding the least common multiple
int lcm(int a, int b) {
    return a / gcd (a, b) * b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << " " << lcm(a,b);
    return 0;
}


