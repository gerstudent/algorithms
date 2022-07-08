#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
  bool swapflag;
  for (int i = 0; i < n - 1; i++) {
    swapflag = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swapflag = true;
        swap(arr[j], arr[j + 1]);
      }
    }
    if (!swapflag) {
      break;
    }
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
  bubbleSort(arr, n);
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }
  return 0;
}
