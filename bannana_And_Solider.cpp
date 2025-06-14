#include<iostream>
using namespace std;

int main(){
    int k, n, w; // k = cost of bannana , n total doller he has, w no. of banana
    cin>>k>>n>>w;

    int cost = 0;
    for(int i=1;i<=w;i++){
        cost += i*k;
    }

    if(n>cost){
        cout<<0<<endl;
    }
    else{
        int borrowMoney = cost-n;
        cout<<borrowMoney<<endl;
    }

    return 0;

}