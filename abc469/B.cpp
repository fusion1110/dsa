#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int n, count = 0;
  cin >> n;
  cin >> s;

  s = 'x' + s + 'x';
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'x' && s[i] == 'x' && s[i + 1] == 'x')
      count++;
  }
  cout << count << endl;
}
