// task: https://stepik.org/lesson/13030/step/6?unit=4382

#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
  double dist;

  Point() {
    cin >> x >> y;
    dist = x * x + y * y;
  }

  bool operator<(const Point& p) { return dist < p.dist; }

  friend ostream& operator<<(ostream& out, const Point& p) {
    out << p.x << ' ' << p.y;
    return out;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Point> points(n);
  sort(points.begin(), points.end());
  for (auto& it : points) {
    cout << it << '\n';
  }
  return 0;
}
