#include<iostream>
using namespace std;

int main(){
    int a,b; //weight of Limak and bob
    cin>>a>>b;
    

    int cntYears = 0;
    while(a<=b){
        cntYears++;
        a = 3*a;
        b = 2*b;
    }

    cout<<cntYears<<endl;

    return 0;

}
