#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 0)
    cout << "ATCODER\n";

  string a = "ARC";
  vector<string> v;

  for (int i = 0; i < n; i++) {
    v.push_back(a);
    v.push_back("#");
  }

  for (auto &i : v)
    cout << i;

  cout << endl;

  return 0;
}
