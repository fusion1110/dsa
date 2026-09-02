#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, sum = 0;
  cin >> n;
  unordered_set<int> set;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (set.insert(a).second)
      sum += a;
    else {
      set.erase(a);
      sum -= a;
    }
  }

  cout << sum << endl;
}
