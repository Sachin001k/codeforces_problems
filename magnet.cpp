#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int cnt = 0;
    int lastE = -1;
   
    while(n--){
        string s;
        cin>>s;
        int a = s[0];
        int b = s[1];
        
        if(lastE != -1 && lastE == s[0]){
            cnt++;
        }
        lastE = s[1];

    }

    cout<<cnt+1<<endl;

    return 0;
}