#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

vector<int> get_divisors(int n){
    vector<int>ans;
    if(n==0){
        return ans;
    }

    int val = sqrt(n);
    for(int i=1;i<=val;i++){
        if(n%i == 0){
            ans.push_back(i);
            if(i != n/i){
                ans.push_back(n/i);
            }
        }
    }

    return ans;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size(); //taking gcd of size will give the length of repitive strings
    int g = gcd(n,m);

    vector<int> divisors = get_divisors(g);
    int ans = 0;

    for(int d:divisors){
        bool samePrefix = true;
        for(int i=0;i<d;i++){
            if(s1[i] != s2[i]){
                samePrefix = false;
                break;
            }
        }
        //checking prefix
        if(!samePrefix){
            continue;
        }

        //means we got the valid prefix of size d;
        bool prefix1 = true;
        for(int i=0;i<n;i++){ //for length of s1
            if(s1[i] != s1[i%d]){
                prefix1 = false;
                break;
            }
        }
        if(!prefix1){
            continue;
        }

        bool prefix2 = true;
        for(int i=0;i<m;i++){ //for lenght of s2
            if(s2[i] != s2[i%d]){
                prefix2 = false;
                break;
            }
        }
        
        if(prefix2){
            ans++;
        }

    }
    cout<<ans<<endl;

    return 0;
}