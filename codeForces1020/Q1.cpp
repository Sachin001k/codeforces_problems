#include<iostream>
#include<string>

using namespace std;

int main(){
    int t; //test cases
    cin>>t;
    while(t--){
        int n;//length of string
        cin>>n;
        string s;
        cin>>s;

        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                cnt0++;
            }
        }

        cnt1 = n-cnt0;
       
       
        cout<<(n+(cnt1*(n-2)))<<endl;
        
    }


    return 0;
}


