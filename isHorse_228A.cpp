#include<iostream>
#include<vector>
using namespace std;

int main(){
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    vector<int>res;
    res.push_back(s1);
    res.push_back(s2);
    res.push_back(s3);
    res.push_back(s4);

    int cnt = 0;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(res[i] == res[j]){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
    
   
}