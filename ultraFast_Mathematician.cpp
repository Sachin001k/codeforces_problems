#include<iostream>
#include<string>

using namespace std;


int main(){
    string s1,s2;
    cin>>s1>>s2;
    int num = 0;
    string ans = "";
    for(int i=0;i<s1.size();i++){
        int a = s1[i];
        int b = s2[i];
        int res = a^b;
        
        char ch = res;
        ans.push_back(res);
    }
    for(int i:ans){
        cout<<int(i);
    }
    //cout<<ans<<endl;
    cout<<endl;
    return 0;

}