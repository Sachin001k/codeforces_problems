#include<iostream>
#include<vector>

using namespace std;



int main(){
    int n, k;
    cin>>n;
    cin>>k;
    if(k>n){
        cout<<-1<<endl;
        return 0;
    }
    vector<vector<int>> matrix(n,vector<int>(n,0));

    //for diagonal elements 1
    for(int i=0;i<n && k>0;i++){

        for(int j=0;j<n && k>0;j++){
            if(i==j){
                if(k>=1){
                    matrix[i][j] = 1;
                    k = k-1;
                }
               
            }
        }
    }

    //printing 2d matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    

} 