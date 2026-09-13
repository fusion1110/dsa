#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int main() {
  int n;
  cin >> n;

  unordered_map<int, ll> m;

  while (n--) {
    ll amt;
    cin >> amt;
    ll bal = 0;

    ll pay = ((amt + 999) / 1000) * 1000;
    bal = pay - amt;

    m[100] += bal / 100;
    bal %= 100;

    m[10] += bal / 10;
    bal %= 10;

    m[1] += bal / 1;
    bal %= 1;
  }

  for (auto i : m)
    cout << i.second << " ";

  cout << endl;
}
