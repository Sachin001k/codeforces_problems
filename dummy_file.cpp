#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 10000000;

vector<int> primes;
vector<bool> is_prime;

void precompute_sieve() {
    is_prime.resize(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= static_cast<int>(sqrt(MAX_N)); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0;
        for (int p : primes) {
            if (p > n) break;
            ans += static_cast<long long>(n) / p;
        }
        cout << ans << '\n';
    }
    return 0;
}
