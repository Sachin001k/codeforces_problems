#include<iostream>
#include<algorithm>
using namespace std;



int pow(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++){
        ans = ans*a;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    //count total number of digits
    int k = n;
    int cnt = 0;
    int firstDigit = 0;

    while(k){
        cnt++;
        firstDigit = k%10;
        k = k/10;
    }
    
    int lucky_year = (firstDigit+1)*(pow(10,cnt-1));
    int ans =lucky_year-n;
    cout<<ans<<endl;
    

    return 0;
}