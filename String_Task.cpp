#include<iostream>
#include<string>

using namespace std;
string toLowerCase(string s){

    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i] <='Z'){
            s[i] = s[i]-'A'+'a';
        }
    }

    return s;
}
int main(){
    string s;
    cin>>s;

    s = toLowerCase(s);
    //removing vowel
    string res = "";
    for(int i=0;i<s.size();i++){
        if(s[i] !='a' && s[i] !='e' && s[i] != 'o' && s[i] != 'i' && s[i] !='u' && s[i] != 'y'){
            res.push_back('.');
            res.push_back(s[i]);
        }
    }

    cout<<res<<endl;

    return 0;
}