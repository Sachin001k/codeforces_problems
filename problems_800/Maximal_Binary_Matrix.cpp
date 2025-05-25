#include<iostream>
#include<vector>

using namespace std;



int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    if (k > n*n) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> matrix(n,vector<int>(n,0));

    
     
    for(int i=0;i<n && k>0;i++){
        for(int j=i;j<n && k>=0;j++){
           if(i == j){
                if(k>=1){
                    matrix[i][i] = 1;
                    k = k-1;
                }
           }
           else{
                if(k>=2){
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                    k = k-2;
                }
           }
        }
    }

    //check if there are any remaining k
    if(k>0){
        cout<<-1<<endl;
        return 0;
    }
    //printing 2d matrix


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    

} 