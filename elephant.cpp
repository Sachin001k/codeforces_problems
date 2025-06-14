#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    if(n<=5){
        cout<<1<<endl;
    }
    else{
        int rem = n%5;
        int Steps = n/5;
        if(rem != 0){
            Steps = Steps+1;
        }
        
        cout<<Steps<<endl;
        
    }
    

    return 0;
}