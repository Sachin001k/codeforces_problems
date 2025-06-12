#include<iostream>

using namespace std;

int main(){

    //input
    int n;
    cin>>n;
    //base case 
    if(n<0){
        return 0; //since weight can't be negative
    }
    if(n&1 || n == 2){
        //odd then they can't divide
        cout<<"NO"<<endl;
    }
    else{
        //even weight if it's greater than 2 than it can be divided into even part
        cout<<"YES"<<endl;
    }

    return 0;

}