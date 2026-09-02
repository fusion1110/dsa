#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int main() {
  ll r, c, k;
  cin >> r >> c >> k;
  vector<vector<char>> v(r, vector<char>(c));

  for (ll i = 0; i < r; ++i) {
    for (ll j = 0; j < c; ++j) {
      char x;
      cin >> x;
      v[i][j] = x;
    }
  }

  for (ll i = 0; i < r;) {
    for (ll j = 0; j < c;) {
      if (v[i][j] == '#') {
        i++;
        j++;
      } else {
        cout << "safe box: " << i << ", " << j << endl;
        break;
      }
    }
  }
}
