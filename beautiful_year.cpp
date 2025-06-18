#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool isUnique(int n){
    
    string k = to_string(n);
    char a = k[0];
    char b = k[1];
    char c = k[2];
    char d = k[3];
    if(a==b || a==c || a==d || b==c || b==d || c==d){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int n;
    cin>>n;

    while(true){
        n = n+1;
        if(isUnique(n)){
            cout<<n<<endl;
            break;
        }
    }

    return 0;
    

}