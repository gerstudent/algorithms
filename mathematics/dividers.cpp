#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> fdividers(int x) {
    vector<int> dividers;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            dividers.push_back(i);
            if (i * i != x) {
                dividers.push_back(x / i);
            }
        }
    }
    return dividers;
}

int main() {
    int n; cin >> n;
    vector<int> divs = fdividers(n);
    sort(divs.begin(), divs.end());
    cout << divs.size() << endl;
    for (int div : divs){
        cout << div << " ";
    }
    return 0;
}