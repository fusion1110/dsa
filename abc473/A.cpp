#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (i >= n / 2)
      sum += a;
  }

  cout << sum << endl;
}
