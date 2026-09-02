#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    v[i] = l;
  }

  int total = accumulate(v.begin(), v.end(), 0);
  int lhs = 0;
  int ans = INT_MAX;

  for (int i = 0; i < n; ++i) {
    lhs += v[i];
    int rhs = total - lhs;

    ans = min(ans, abs(lhs - rhs));
  }

  cout << ans << endl;
}
