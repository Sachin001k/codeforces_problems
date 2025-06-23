#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int gcd(int a, int b){
    while(b){
        a = a%b;
        swap(a,b);
    }
    return a;
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

const int MAX_N = 1e7;
vector<bool>is_prime;
vector<int>primes;

//sieve algo for prime numbers
void sieve() { 
    is_prime.resize(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= (sqrt(MAX_N)); ++i) {
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


int main(){
    
    sieve();
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long ans = 0;
        for(int p:primes){
            if(p>n){
                break;
            }
            ans += (n)/p;
        }

        cout<<ans<<endl;


    }
    return 0;
}