#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n, m;
  ll k;

  cin >> n >> m >> k;

  vector<ll> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<bool> ate(n, false);
  ll sum = 0;

  for (int i = 0; i < n; i++) {
    if (i >= m && ate[i - m])
      sum -= v[i - m];

    if (sum + v[i] <= k) {
      ate[i] = true;
      sum += v[i];
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
