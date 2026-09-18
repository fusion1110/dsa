#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int multi_source_bfs(vector<string> &v, ll h, ll w, ll k);

int main() {
  ll h, w, k;

  cin >> h >> w >> k;

  vector<string> v(h);

  for (auto &e : v)
    cin >> e;

  cout << multi_source_bfs(v, h, w, k) << endl;
}

int multi_source_bfs(vector<string> &v, ll h, ll w, ll k) {
  vector<ll> row(h, 0);
  vector<ll> col(w, 0);

  /*finding and storing all the bomb cols and rows*/
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v[i][j] == '#') {
        row[i] = '1';
        col[i] = '1';
      }
    }
  }

  int ans = 0;
  /*2D grid initialized to -1 to keep a track of visited coordinates and their
   * distances*/
  vector<vector<ll>> dist(h, vector<ll>(w, -1));

  /*pushing all the safe points to the queue...since its multi-source bfs
   * if it were normal bfs would have pushed only 1 */
  queue<pair<int, int>> q;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (row[i] == 0 && col[j] == 0) {
        /*marking it as safe*/
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  int dirs_i[] = {-1, 1, 0, 0};
  int dirs_j[] = {0, 0, 1, -1};

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    if (dist[i][j] <= k)
      ans++;

    for (int x = 0; x < 4; x++) {
      int ni = i + dirs_i[x];
      int nj = j + dirs_j[x];

      if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
        if (dist[ni][nj] == -1 && v[ni][nj] == '.') {
          dist[ni][nj] = dist[i][j] + 1;
          q.push({ni, nj});
        }
      }
    }
  }

  return ans;
}
