/*
    Time Complexity: O(log n)
    Auxiliary Space: O(1)
*/

#include <iostream>
using namespace std;

int binarySearch(const int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) {
            return m;
        }
        if (arr[m] > x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    inputArray(a, n);
    int x; cin >> x;
    int ans = binarySearch(a, 0, n, x);
    if (ans == -1) cout << "Element does not exist in the array";
    else cout << "x index: " << ans;
    return 0;
}

