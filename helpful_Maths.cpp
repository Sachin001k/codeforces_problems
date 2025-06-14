#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    string k="";
    int len = s.size();
    for(int i=0;i<len;i++){
        if(s[i] != '+'){
            k.push_back(s[i]);
        }
    }

    sort(k.begin(),k.end());
    string ans = "";
    for(int i=0;i<k.size();i++){
        ans.push_back(k[i]);
        if(i != k.size()-1){
            ans.push_back('+');
        }
    }

    cout<<ans<<endl;

    return 0;
}
