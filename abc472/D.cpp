#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long int;

int MS_bfs(vector<vector<char>> &v, int h, int w, int k) {
  vector<int> row(h, 0);
  vector<int> cols(w, 0);

  /*storing all the bombed rows & cols*/
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v[i][j] == '#') {
        row[i] = 1;
        cols[j] = 1;
      }
    }
  }

  int ans = 0;
  vector<vector<int>> d(h, vector<int>(w, -1));

  queue<pair<int, int>> q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (row[i] == 0 && cols[j] == 0) {
        d[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    /*starting point -> safe coordinate*/
    auto [i, j] = q.front();
    q.pop();

    /*marking the starting pos as 0*/
    if (d[i][j] <= k)
      ans++;

    int dirs_i[] = {-1, 1, 0, 0};
    int dirs_j[] = {0, 0, 1, -1};

    for (int x = 0; x < 4; x++) {
      int ni = i + dirs_i[x];
      int nj = j + dirs_j[x];

      if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
        if (v[ni][nj] == '.' && d[ni][nj] == -1) {
          d[ni][nj] = d[i][j] + 1;
          q.push({ni, nj});
        }
      }
    }
  }

  return ans;
}

int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  vector<vector<char>> v(h, vector<char>(w));

  for (ll i = 0; i < h; ++i) {
    for (ll j = 0; j < w; ++j) {
      char x;
      cin >> x;
      v[i][j] = x;
    }
  }

  cout << MS_bfs(v, h, w, k) << endl;
}
