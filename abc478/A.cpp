#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;

  for (ll i = 0; i < N; i++)
    cout << M / N + (i < M % N) << endl;
  return 0;
}
