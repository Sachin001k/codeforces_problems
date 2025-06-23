#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long cnt = 0;
        long long firstBpos = -1;
        long long secondBpos = -1;

        for(long long i=n-2;i>=0;i--){
            long long pos = n-i-1; //b position 1st
            if(k <= pos+cnt){
                firstBpos = i;
                secondBpos = n-(k-cnt);
                break;
            }
            else{
                cnt += pos;
            }

        }
        string s(n,'a');
        s[firstBpos] = 'b';
        s[secondBpos] = 'b';
        cout<<s<<endl;
    }
    return 0;

}
