#include<iostream>
#include<vector>

using namespace std;

int main(){

    int t;
    cin>>t; //test cases

    while(t--){
        int n,x;
        cin>>n>>x; //cell number and color
        vector<int>res;

        for(int i=0;i<x;i++){
            res.push_back(i);
        }

        for(int i=n-1;i>x;i--){
            res.push_back(i);
        }

        if (x < n) res.push_back(x);

        
        for (int i = x + 1; i < n; ++i)
            res.push_back(i);        

        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}