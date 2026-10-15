#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<vector<int>> events(n + 2); // r+1 can be equal to n+1
  for (int i = 0; i < q; i++) {
    int L, R, x;
    cin >> L >> R >> x;
    /*at L value x starts to exist and after R it does not*/
    events[L].push_back(x);
    events[R + 1].push_back(-x);
  }

  map<int, int> freq;

  for (int i = 1; i <= n; i++) {
    for (auto x : events[i]) {
      if (x > 0)
        freq[x]++;
      else {
        x *= -1;
        if (--freq[x] == 0)
          freq.erase(x);
      }
    }
    cout << freq.size() << " ";
  }

  return 0;
}
