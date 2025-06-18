#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int cntOne = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cntOne++;
            break;
        }
    }

    if(cntOne != 0){
        cout<<"HARD"<<endl;
    }
    else{
        cout<<"EASY"<<endl;
    }
    return 0;
}