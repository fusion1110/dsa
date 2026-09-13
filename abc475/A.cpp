#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int main() {
  string s, ans;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    ans += s[i];

    if (i != s.length() - 1)
      ans += 'o';
  }
  cout << ans << endl;
}
