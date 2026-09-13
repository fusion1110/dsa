#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int main() {
  /*'n' and 's' are one indexed so adjusting them*/
  ll n, s, L;
  cin >> n >> s >> L;
  vector<ll> dist(n - 1);
  s--;
  for (auto &e : dist)
    cin >> e;
  int ans = 1;
  vector<ll> p(n);
  /*building prefix sum*/
  for (int i = 0; i < n - 1; i++)
    p[i + 1] = p[i] + dist[i];

  for (int l = 0; l <= s; l++) {
    for (int r = s; r < n; r++) {
      ll x = p[s] - p[l], y = p[r] - p[s];

      if (min(2 * x + y, 2 * y + x) <= L)
        ans = max(ans, r - l + 1);
    }
  }

  cout << ans << endl;
}
