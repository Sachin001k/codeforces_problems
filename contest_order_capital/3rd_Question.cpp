#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<tuple<int, int, int>> points; // (x, y, index)

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y, i + 1);
        }

        // Sort by x + y
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b);
        });

        int l = 0, r = n - 1;
        while (l < r) {
            int i1 = get<2>(points[l]);
            int i2 = get<2>(points[r]);
            cout << i1 << " " << i2 << '\n';
            ++l;
            --r;
        }
    }

    return 0;
}
