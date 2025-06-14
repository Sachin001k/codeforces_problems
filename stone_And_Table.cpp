#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    //code
    int cnt = 0;
    for(int i=1;i<s.size();i++){
        if(s[i-1] == s[i]){
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;

}