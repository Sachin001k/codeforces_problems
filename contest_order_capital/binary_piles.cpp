#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long moves = 0;
        long long oneCnt = 0;
        for(int i=0;i<n;i++){
            long long a,b,c,d;
            cin>>a>>b>>c>>d;
            if (c > a) {
                moves += (c - a);  //
            }
        }
        cout<<moves<<endl;
    }

    return 0;
}