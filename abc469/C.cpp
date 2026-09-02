#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  int n;
  vector<int> a;
  cin >> n >> s;

  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'x')
      a.push_back(i);
  }

  int len = a.size();
  for (int i = 1; i <= n; ++i) {
    if (len < i)
      cout << n << endl;
    else
      cout << a[i - 1] << endl;
  }
}
