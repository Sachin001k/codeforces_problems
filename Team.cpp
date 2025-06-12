#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    //taking input for each problem
    int cnt = 0; //will count the number of solved problems if 2 of them can solve
    while(n--){
        int P, V, T; //petya vasya tonya
        cin>>P>>V>>T;
        int oneCount = P+V+T;
        if(oneCount >= 2){
            cnt++;
        }
        
    }
    cout<<cnt<<endl;

    return 0;
}