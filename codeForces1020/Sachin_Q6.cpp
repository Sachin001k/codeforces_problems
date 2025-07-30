#include <bits/stdc++.h>
using namespace std;

int main() {
    

    int t; 
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;
        string s; 
        cin >> s;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int max_size = 0;

        auto get = [&](int i, int j) {
            return (i == j ? (s[j] == '0' ? '1' : '0') : s[j]);
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] || get(i, j) != '0') continue;

                // BFS from (i, j)
                int size = 0;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    size++;

                    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
                    for (auto [dx, dy] : dirs) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (!visited[nx][ny] && get(nx, ny) == '0') {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                max_size = max(max_size, size);
            }
        }

        cout << max_size << "\n";
    }

    return 0;
}
