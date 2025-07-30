#include <bits/stdc++.h>
using namespace std;

int main() {
   

    int t; cin >> t;
    while (t--) {
        int n,q; cin >> n >> q;
        vector<int> p(n+1);
        vector<int> pos(n+1);
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        while (q--) {
            int l,r,k; cin >> l >> r >> k;

            int posk = pos[k];
            if (posk < l || posk > r) {
                cout << -1 << " ";
                continue;
            }

            // Simulate binary search for k in [l, r]
            int start = l, end = r;
            int d = 0;
            bool impossible = false;

            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid == posk) {
                    // p[mid] must be k, which it is by definition
                    break;
                } else if (mid < posk) {
                    // p[mid] must be < k
                    if (p[mid] >= k) d++;
                    start = mid + 1;
                } else {
                    // mid > posk
                    // p[mid] must be > k
                    if (p[mid] <= k) d++;
                    end = mid - 1;
                }
            }

            cout << d << " ";
        }
        cout << "\n";
    }

    return 0;
}
