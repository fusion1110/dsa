#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  /*a/b rounds down in c*/
  if (a + b == 9 || a - b == 9 || a * b == 9 || a == b * 9)
    cout << "Nine\n";
  else
    cout << "Nein\n";
}
