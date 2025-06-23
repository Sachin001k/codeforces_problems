#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    unordered_map<string,int>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        s[i] = str;
       
    }
    for(auto i:s){
        m[i]++;
    }

    vector<string> ans(n);
    for(int i=n-1;i>=0;i--){
        
       if(m[s[i]] >1){
            
            string a = to_string(m[s[i]]-1);
            ans[i] = s[i]+a;
            m[s[i]]--;
        }
        else if(m[s[i]] == 1){
            ans[i] = "OK";
            m[s[i]]--;

        }
        
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }

    return 0;

} 

