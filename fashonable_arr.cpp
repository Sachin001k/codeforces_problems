#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int,int> maxMin(vector<int> &arr, int n){
    int mini = arr[0];
    int maxi = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }

        if(arr[i]<mini){
            mini = arr[i];
        }
    }

    return {maxi,mini};
}

int main(){
    
    int t;
    cin>>t;
    

    while(t--){


        int n ;
        cin>>n;
        vector<int> arr(n);
        //input to array
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());
        int cnt1 = 0, cnt2 = 0;
        int s = 0;
        int e = arr.size()-1;

        while(s<e){
            if((arr[s]+arr[e])%2 == 1){
                cnt1++;
                s++;
            }
            else{
                break;
            }
        }
        s=0;
        e=n-1;
        while(s<e){
            if((arr[s]+arr[e])%2){
                cnt2++;
                e--;
            }
            else{
                break;
            }
        }

        int ans = min(cnt1,cnt2);
        cout<<ans<<endl;
        


        /*
        int n;
        cin>>n;
        int evenCnt=0;
        int oddCnt=0;
        vector<int> arr(n);
       
        //input to the array and counting
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2){
                oddCnt++;
            }
            else{
                evenCnt++;
            }
        }
        //counting the odd and even number
        if(oddCnt==n || evenCnt==n){
            cout<<0<<endl;
            return 0;
        }
        else{
            int ans = min(oddCnt,evenCnt);
            cout<<ans<<endl;
            
        }
            */

    }
        return 0;

    
  

    /*
    
    //finding max and min
    pair<int,int> p;
    p = maxMin(arr,n);
    int first = p.first;
    int second = p.second;
    //check for 2 conditions 1st when 1 is odd other is even and vice vers

    //int ans = (first + second)%2;
    if(first % 2 == 0 && second %2 == 0){
        cout<<0<<endl;
        return 0;
    }
    
    */


}