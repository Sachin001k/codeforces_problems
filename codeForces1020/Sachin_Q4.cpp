#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] >= b[j]) {
            j++;
        }
        i++;
    }
    return j == m;
}

int main() {
   
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        sort(b.begin(), b.end());  // required beauties must be collected in order

        if (isPossible(a, b)) {
            cout << 0 << "\n";
            continue;
        }

        int low = 1, high = 1e9, answer = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            //  inserting flower with beauty = mid at every position
            bool found = false;
            for (int pos = 0; pos <= n; ++pos) {
                vector<int> modified = a;
                modified.insert(modified.begin() + pos, mid);
                if (isPossible(modified, b)) {
                    found = true;
                    break;
                }
            }

            if (found) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
