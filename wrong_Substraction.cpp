#include<iostream>

using namespace std;

int main(){
    int n, k; //n number and k is times to subtract
    cin>>n>>k;

    while(k){
        int lastDigit = n%10;
        if(lastDigit != 0){
            if(lastDigit > k){
                n = n-k;
                break;
            }
            else{
                n = n-lastDigit;
                k = k-lastDigit;
            }
        }
        else{
           n = n/10;
           k--;
        }
    }

    cout<<n<<endl;

    return 0;
}