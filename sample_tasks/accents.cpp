// task: https://stepik.org/lesson/13029/step/9?unit=4381

#include <bits/stdc++.h>
using namespace std;

// Перевод строки в верхний регистр
string toupper(string s) {
  string up = "";
  for (auto c : s) {
    up += toupper(c);
  }
  return up;
}

// Подсчет кол-ва заглавных букв в строке
int upperCount(string s) {
  int cnt = 0;
  for (auto c : s)
    if (c >= 'A' && c <= 'Z') cnt++;
  return cnt;
}

int main() {
  int n, cnt = 0;
  cin >> n;
  string s;
  set<string> udar, up;
  while (n--) {
    cin >> s;
    udar.insert(s);
    up.insert(toupper(s));
  }
  while (cin >> s) {
    // Если количество ударений не равно 1 - ошибка
    if (upperCount(s) != 1) {
      cnt++;
      continue;
    }
    // Если слово найдено в словаре ударений - не ошибка
    if (udar.find(s) != udar.end()) {
      continue;
    }
    // Если слово нашлось в словаре up
    // и при этом не было обработано на предыдущем шаге - ошибка
    if (up.find(toupper(s)) != up.end()) {
      cnt++;
    }
    // Остальные случаи ошибками не являются
  }
  cout << cnt;
  return 0;
}
