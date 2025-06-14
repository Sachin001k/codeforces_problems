#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;

    int len = s.size();
    int cnt = 0;
    int arr[26] = {0};
    //storing the frequency of characters
    for(int i=0;i<len;i++){
        char ch = s[i];
        arr[ch-'a']++;
    }

    for(int i=0;i<26;i++){
        if(arr[i] != 0){
            cnt++;
        }
    }
    
    if(cnt&1){
        cout<<"IGNORE HIM!"<<endl;
    }
    else{
        cout<<"CHAT WITH HER!"<<endl;
    }

}