#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, k, max_count = 0;
  cin >> n >> k;

  unordered_map<int, int> class_count;

  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    class_count[c]++;
  }

  for (auto i : class_count)
    max_count = max(max_count, i.second);
  int count = 0;

  for (auto i : class_count) {
    if (i.second + 1 >= max_count)
      count++;
  }
  cout << count << endl;
}
