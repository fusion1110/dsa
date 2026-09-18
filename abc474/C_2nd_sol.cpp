#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, Q;
  cin >> N >> Q;

  vector<ll> p(N);
  for (ll &x : p)
    cin >> x;

  vector<ll> operations(Q);
  for (ll &x : operations)
    cin >> x;

  vector<bool> seen(N + 1, false);
  vector<ll> touched;

  for (int i = Q - 1; i >= 0; i--) {
    ll x = operations[i];

    if (!seen[x]) {
      seen[x] = true;
      touched.push_back(x);
    }
  }

  reverse(touched.begin(), touched.end());

  for (auto &x : p) {
    if (!seen[x])
      cout << x << " ";
  }

  for (auto &x : touched)
    cout << x << " ";

  cout << endl;
  return 0;
}
