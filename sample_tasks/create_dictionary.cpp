// task: https://stepik.org/lesson/13029/step/8?unit=4381

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main() {
	// Создание латинско-английского словаря
  map<string, vector<string>> lat_dict;

  int n;
  cin >> n;

  // Чтение английско-латинского словаря
  for (int i = 0; i < n; i++) {
    string end, lat;

    cin >> eng >> lat;

    // Цикл до конца списка латинских слов
    bool end = false;
    while (!end) {
      // Чтение латинского слова вместе с запятыми
      cin >> lat;

      // Удаление запятых или отметка о конце списка латинских слов.
      if (lat[lat.length() - 1] == ',') {
        // Если в конце слова стоит запятая, значит оно не последнее.
        // Вырезание подстроки со словом
        lat = lat.substr(0, lat.length() - 1);
      } else {
        // Иначе - запятой в конце слова нет, значит оно последнее.
        end = true;
      }

      // Заполнение латинско-английского словаря
      lat_dict[lat].push_back(eng);
    }
  }

  // Вывод количества записей в латинско-английском словаре.
  cout << lat_dict.size() << '\n';

  // Вывод латинско-английского словаря
  for (auto word : lat_dict) {
    cout << word.fi << " - ";
    for (size_t i = 0; i < word.se.size(); i++) {
      cout << word.se[i] << ((i + 1 < word.se.size()) ? ", " : "\n");
    }
  }
  return 0;
}
