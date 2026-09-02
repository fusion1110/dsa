#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<string, int> count;
  int ans = 0;
  while (n--) {
    string s;
    cin >> s;

    for (auto &c : s)
      c = tolower(c);

    ans = max(ans, ++count[s]);
  }
  cout << ans << endl;
}
