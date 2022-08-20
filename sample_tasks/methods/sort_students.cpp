// task: https://stepik.org/lesson/13030/step/7?unit=4382

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using ull = unsigned long long;
using ld = long double;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;

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
