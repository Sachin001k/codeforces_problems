#include<iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int count = 0; //will count if score greater than k;
    int lastVal = 0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a; //score by contestents
        
        if(i<=k && a>0){
            count++; //will advance to next round
        }
        else if(i>k && a == lastVal){
            count++;
        }
        else{
            break;
        }
        lastVal = a;
    }

    cout<<count<<endl;

}