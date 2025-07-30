#include <bits/stdc++.h>
using namespace std;

int query_cnt = 0;

int ask_sum(const vector<int>& nodes) {
    query_cnt++;
    cout << "? 1 " << nodes.size();
    for (int x : nodes) cout << " " << x;
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void toggle(int u) {
    query_cnt++;
    cout << "? 2 " << u << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, -1), depth(n + 1, -1);
        vector<int> f(n + 1);

        // BFS from node 1 to get depth and parent
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // Query f(u) for each node
        for (int i = 1; i <= n; ++i) {
            f[i] = ask_sum({i});
        }

        vector<int> val(n + 1);
        val[1] = f[1];
        for (int i = 2; i <= n; ++i) {
            val[i] = f[i] - f[parent[i]];
        }

        cout << "! ";
        for (int i = 1; i <= n; ++i) cout << val[i] << (i == n ? '\n' : ' ');
        cout.flush();
    }
    return 0;
}
