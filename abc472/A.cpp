#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  for (char &c : s)
    if (c != 'A')
      c = '.';

  cout << s << endl;
}
