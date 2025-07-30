#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        } 
        for (int i = 0; i < n; ++i){
            cin >> b[i];
        } 

        long long x = -1;
        bool conflict = false;

        for (int i = 0; i < n; ++i) {
            if (b[i] != -1) {
                long long currX = a[i] + b[i];
                if (x == -1) {
                    x = currX;
                } else if (x != currX) {
                    conflict = true;
                    break;
                }
            }
        }

        if (conflict) {
            cout << 0 << endl;
            continue;
        }

        if (x != -1) {
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                if (b[i] == -1) {
                    long long neededB = x - a[i];
                    if (neededB < 0 || neededB > k) {
                        valid = false;
                        break;
                    }
                }
            }
            cout << (valid ? 1 : 0) << endl;
        } else {
            long long L = 0, R = a[0] + k;
            for (int i = 0; i < n; ++i) {
                L = max(L, a[i]);
                R = min(R, a[i] + k);
            }
            int ans =  (L > R ? 0 : (R - L + 1));
            cout<<ans<<endl;
        }
    }

    return 0;
}
