#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, V;
  cin >> N >> V;

  vector<ll> w;
  for (int a = 0; a < N; a++) {
    ll x;
    cin >> x;
    w.push_back(x);
  }

  ll ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        if (i + j + k + 3 <= V && ans < w[i] + w[j] + w[k])
          ans = w[i] + w[j] + w[k];
      }
    }
  }

  cout << ans << endl;
  return 0;
}
