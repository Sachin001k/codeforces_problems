#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    //taking string as input
    while(n--){
        string s;
        cin>>s;
        // counting the total number of character
        int len = s.size();
        if(len<11){
            cout<<s<<endl; //printing the same words
        }else{
            //first char and last char
            char first = s[0];
            char last = s[len-1];
            
            string num = to_string(len-2);
            string output = "";
            output.push_back(first);
            output = output + num;
            output.push_back(last);
            cout<<output<<endl;

        }
        

    }

    return 0;
    
}