#include<iostream>

using namespace std;

int main(){
    int m; //rows
    int n; //cols
    cin>>m>>n;

    int total = 0;
    if(n%2 ==0){
        //even column we can place the domino pieces completely
        total = m*(n/2);
        cout<<total<<endl;
        
    }
    else if(m%2 == 0){
        //rows even
        total = (m/2)*n;
        cout<<total<<endl;  
    }else if(m%2 == 1 && n%2 == 1){
        //both of them are odd
        int totalbox = m*n; //which is odd
        total = totalbox-1;
        cout<<total/2 <<endl;

    }

    return 0;
}