#include<iostream>
#include<vector>
#include<numeric>

using namespace std;
long long gcd(long long a, long long b){
    while(b){
        a = a%b;
        swap(a,b);
    }

    return a;
}
long long lcm(long long a, long long b){
    return (a/gcd(a,b))*b;
}
int main(){
    //1862D ICE cream Balls
    //1328B beautiful string
    //2091E Interesting Ratio
    //2074D counting pair
    //476B dreamoon and wifi
    //1899D Yarik and musical notes
    //182D Common Divisors
    //4C registration system

    int t;
    cin>>t; //test cases
    while(t--){
        int n;
        cin>>n;
        vector<long long> k(n);
        long double sum = 0.0;
        for(int i=0;i<n;i++){
            cin>>k[i];
            sum += 1.0/(k[i]);
        }

        if(sum >= 1.0){
            cout<<-1<<endl;
            continue;
        }

        //checking LCM
        long long LCM = 1;
        for(long long num:k){
            LCM = lcm(LCM, num);
        }
        
        //x_i values
        vector<long long> x(n);
        long long sum1 = 0;
        for(int i=0;i<n;i++){
            x[i] = LCM/k[i];
            sum1 += x[i];
        }

        if(sum1 >= LCM){
            cout<<-1<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;


    }
    cout<<endl;
    

    return 0;
}