#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, h; //no. of friends and height
    cin>>n>>h;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //counting the width if it's greater than height
    int width = 0;
    for(int i=0;i<n;i++){
        if(a[i]<=h){
            width = width+1;
        }
        else{
            width = width+2;
        }
    }

    cout<<width<<endl;

    return 0;



}