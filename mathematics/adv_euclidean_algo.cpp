#include <iostream>

int advancedGcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = advancedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    int a, b, x, y;
    std::cin >> a >> b >> x >> y;
    std::cout << advancedGcd(a, b, x, y);
    return 0;
}




