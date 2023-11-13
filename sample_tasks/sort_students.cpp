// task: https://stepik.org/lesson/13030/step/7?unit=4382

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

struct Student {
  string name, surname;
  int math, phys, inf;
};

bool comp(Student a, Student b) {
  return a.math + a.phys + a.inf > b.math + b.phys + b.inf;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Student> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].name >> vec[i].surname;
    cin >> vec[i].math >> vec[i].phys >> vec[i].inf;
  }
  stable_sort(all(vec), comp);
  for (auto it : vec) {
    cout << it.name << ' ' << it.surname << '\n';
  }
  return 0;
}
