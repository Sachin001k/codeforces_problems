#include<iostream>
#include<string>

using namespace std;

string to_lower(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = s[i]-'A' + 'a';
        }
    }
    return s;
}
int main(){
    string s1, s2;
    cin>>s1;
    cin>>s2;

    s1 = to_lower(s1);
    s2 = to_lower(s2);

    if(s1 == s2){
        cout<<0<<endl;
    }
    else if(s1>s2){
        cout<<1<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;

}