#include<iostream>
using namespace std;

bool isLucky(int n){
    if(n==0){
        return false;
    }

    while(n){
        int digit = n%10;
        if(digit != 4 && digit != 7){
            return false;
        }

        n = n/10;


    }
    return true;
}

int main(){
    
    string s;
    cin>>s;
    
    int luckyDigits = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '4' || s[i] == '7'){
            luckyDigits++;
        }
    }

    if(isLucky(luckyDigits)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}