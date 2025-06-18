#include<iostream>

using namespace std;

int main(){
    int n,m,a;
    cin>>n>>m>>a;
    int side1 = (m+a-1)/a;
    int side2 = (n+a-1)/a;

    int ans = side1*side2;
    cout<<ans<<endl;

    return 0;
}