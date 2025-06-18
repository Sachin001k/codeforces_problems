#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s; //Anton and Danik

    int aCnt = 0;
    int dCnt = 0;

    for(int i=0;i<n;i++){
        if(s[i] == 'A'){
            aCnt++;
        }
        else{
            dCnt++;
        }
    }

    if(aCnt>dCnt){
        cout<<"Anton"<<endl;
    }
    else if(aCnt == dCnt){
        cout<<"Friendship"<<endl;
    }
    else{
        cout<<"Danik"<<endl;
    }

    return 0;
}