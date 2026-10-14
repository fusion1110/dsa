#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> a_copy = a;
  sort(a_copy.begin(), a_copy.end());

  /*i -> is the first difference and j -> is the last difference*/
  int i = 0;
  while (i < n && a[i] == a_copy[i])
    i++;
  int j = n - 1;
  while (j >= 0 && a[j] == a_copy[j])
    j--;

  cout << (k >= j - i + 1 ? "Yes" : "No") << endl;
  return 0;
}
