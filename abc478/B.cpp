#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, V;
  cin >> N >> V;

  vector<ll> w(N + 1), prefixMax(N + 1);
  /*one indexed*/
  for (int i = 1; i <= N; i++) {
    cin >> w[i];
    prefixMax[i] = max(w[i], prefixMax[i - 1]);
  }
  ll ans = 0;

  for (int j = 3; j <= N; j++) {
    for (int k = 2; k < j; k++) {
      int budget = V - j - k;
      int i = min(j - 1, budget);

      if (i > 0)
        ans = max(ans, w[k] + w[j] + prefixMax[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
