#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n; //tram stops
    vector<vector<int>> mat(n, vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>mat[i][j];
        }
    }

    int maxi = 0;
    int currCnt = 0;
    for(int i=0;i<n;i++){
        int a = mat[i][0];
        int b = mat[i][1];
        currCnt = (currCnt - a) + b;
        maxi = max(maxi, currCnt);
    }

    cout<<maxi<<endl;
    return 0;


}