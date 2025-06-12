#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n; //n number of test cases
    int count = 0;
    while(n--){
         //variable
        string x; // operation ++ or --;
        cin>>x;
        
        int len = x.size();
        if(x[0]=='+'){
            count++;
        }
        else if(x[0] == '-'){
            count--;
        }
        else if(x[0] == 'X'){
            if(x[len-1] == '+'){
                count++;
            }
            else{
                count--;
            }
        }
        
    }
    cout<<count<<endl;

    return 0;

}