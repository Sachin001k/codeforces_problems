#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    //f(n) = -1+2-3+4-5...
    //AP with -1,-3,-5,...
    //AP2 2,4,6,8..
    
    //odd sum
    int even = (n)/2;
    int odd = (n+1)/2;
    int ans = even*(even+1)-(odd*odd);
     
    cout<<ans<<endl;
    return 0;
}