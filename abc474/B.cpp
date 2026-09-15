#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    /*Checking group -> i is 0 indexed and x is 1 indexed*/
    if (i / 10 != (x - 1) / 10) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
