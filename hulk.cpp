#include <iostream>
#include <string>

using namespace std;
int main(){
    int n;
    cin >> n;

    string s = "";
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            s = s + "I hate ";
        }
        else
        {
            s = s + "that I love that ";
        }
    }
    if(n&1){
    s = s + "it";
    }
    else{
        s.pop_back();
        s.pop_back();
        s.pop_back();
        s.pop_back();
        s.pop_back();
        s = s+"it";
    }
    
    

    cout << s << endl;

    return 0;
}