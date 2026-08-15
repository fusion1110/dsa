#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<string, int> count;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    count[s]++;
  }

  int max_freq = 0;

  for (auto &[key, freq] : count) {
    max_freq = max(max_freq, freq);
  }

  cout << max_freq << endl;
}
