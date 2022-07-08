#include <bits/stdc++.h>
using namespace std;

void combSort(int arr[], int n) {
  int step = n - 1;
  double factor = 1.2473309;
  while (step >= 1) {
    for (int i = 0; i + step < n; i++) {
      if (arr[i] > arr[i + step]) {
        swap(arr[i], arr[i + step]);
      }
    }
    step /= factor;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  combSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}