#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &nums){
    int n = nums.size();
    for(int j=1;j<n;j++){
        int temp = nums[j];
        int k = j-1;

        while(k>=0){
            if(nums[k]>temp){
                nums[k+1] = nums[k];
                k = k-1;
            }
            else{
                break;
            }
        }
        nums[k+1] = temp;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    //taking input to num
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    insertionSort(nums);
    //adding first k elements
    
    int ans = 0;
    for(int i=0;i<k;i++){
        ans += nums[i];
    }
    cout<<ans<<endl;

    return 0;

}
