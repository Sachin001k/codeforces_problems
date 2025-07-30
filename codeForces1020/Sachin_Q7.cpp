#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> res(n + 1);
    int full_sum;

    cout << "? 1 " << n;
    for (int i = 1; i <= n; ++i) cout << " " << i;
    cout << endl;
    cout.flush();

    cin >> full_sum;

    for (int i = 2; i <= n; ++i) {
        cout << "? 1 1 " << i << endl;
        cout.flush();
        int single;
        cin >> single;
        res[i] = single;
    }

    cout << "? 1 1 1" << endl;
    cout.flush();
    int root_val;
    cin >> root_val;
    res[1] = root_val;

    vector<int> val(n + 1);
    for (int i = 2; i <= n; ++i) {
        val[i] = res[i] - res[1];
    }
    val[1] = res[1];

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        ans[i] = (val[i] - val[1]) + val[1];
        ans[i] = (ans[i] % 2 == 0 ? 1 : -1);
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "\n" : " ");
    }
    cout.flush();
}

int main() {
   
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
