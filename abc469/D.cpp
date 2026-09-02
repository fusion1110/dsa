#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a[m], b[m];

  for (int i = 0; i < m; ++i)
    cin >> a[i] >> b[i];

  auto count_for = [&](int x) {
    int y = -1;

    for (int i = 0; i < m; ++i) {
      if (a[i] != x && b[i] != x) {
        y = a[i];
        break;
      }
    }

    if (y == -1)
      return n - 1;

    for (int i = 0; i < m; ++i) {
      if (a[i] != x && b[i] != x && a[i] != y && b[i] != y)
        return 0;
    }

    return 1;
  };

  int ans = count_for(a[0]) + count_for(b[0]) - 1;

  cout << ans << endl;
}
