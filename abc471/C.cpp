#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll ans = 0, curr = 0;

  int n;
  cin >> n;
  vector<ll> v(n);

  for (auto &x : v)
    cin >> x;

  sort(v.begin(), v.end());

  /*first +ve*/
  int r = lower_bound(v.begin(), v.end(), 0) - v.begin();
  int l = r - 1;

  while (l >= 0 || r < n) {
    /*only =ve values remain*/
    if (l < 0) {
      ans += abs(v[r] - curr);
      curr = v[r];
      r++;
    }

    /*only negative values remain*/
    else if (r >= n) {
      ans += abs(v[l] - curr);
      curr = v[l];
      l--;
    }

    else {
      ll dist_left = abs(v[l] - curr);
      ll dist_right = abs(v[r] - curr);

      if (dist_left <= dist_right) {
        ans += dist_left;
        curr = v[l];
        l--;
      }

      else {
        ans += dist_right;
        curr = v[r];
        r++;
      }
    }
  }

  cout << ans << endl;
}
