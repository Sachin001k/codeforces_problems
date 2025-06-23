#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//binomial function
long long binom(int n, int k) { 
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int target = 0;
    for (char c : s1) {
        if(c == '+'){
            target += 1;
        }
        else{
            target += -1;
        }
        //target += (c == '+') ? 1 : -1;
    }
    int base = 0, unknowns = 0;
    for (char c : s2) {
        if (c == '+'){
            base++;
        }
        else if (c == '-'){
            base--;
        }
        else unknowns++;
    }
    int diff = target - base;
    if ((diff + unknowns) % 2 != 0 || abs(diff) > unknowns) {
        cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    }
    int x = (diff + unknowns) / 2;
    if (x < 0 || x > unknowns) {
        cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    }
    long long ways = binom(unknowns, x);
    long long total = 1LL << unknowns; //multiply by 2 to the power unknown values time
    double prob = (double)ways / total;
    cout << fixed << setprecision(12) << prob << endl;
    return 0;
}
