#include <iostream>

// Finding the greatest common divisor
int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap (a, b);
    }
    return a;
}

// Finding the least common multiple
int lcm(int a, int b) {
    return a / gcd (a, b) * b;
}

int main() {
    int a,b;
    std::cin >> a >> b;
    std::cout << gcd(a,b) << " " << lcm(a,b);
    return 0;
}


