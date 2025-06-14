#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;

    int len = s.size();
    int upperCase = 0;
    int lowerCase = 0;
    for(int i=0;i<len;i++){
        if(s[i]>='A' && s[i]<='Z'){
            upperCase++;
        }
        else{
            lowerCase++;
        }
    }

    if(upperCase>lowerCase){
        //converting into upper case
        for(int i=0;i<len;i++){
            if(s[i]>='a' && s[i]<='z'){
                s[i] = s[i]-'a'+'A';
            }
        }
    }
    else{
        for(int i=0;i<len;i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i]-'A'+'a';
            }
        }
    }

    cout<<s<<endl;
    return 0;
    

}