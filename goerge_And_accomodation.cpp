#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n, vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>mat[i][j];
        }
    }

    
    int cnt = 0;
    for(int i=0;i<n;i++){
        int p = mat[i][0];
        int q = mat[i][1];
        if(q-p >= 2){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}