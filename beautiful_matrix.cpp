#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>> mat(5, vector<int>(5));
    //input to the matrix
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>mat[i][j];
        }
        cout<<endl;
    }

    int rowIndex=0,colIndex=0; // row and col where 1 is found let's assume
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(mat[i][j]==1){
                rowIndex = i+1;
                colIndex = j+1;
                break;
            }
        }
    }

    int ans = abs(3-rowIndex)+abs(3-colIndex); //since we can perform only 1 operation 
    cout<<ans<<endl;

    return 0;


}