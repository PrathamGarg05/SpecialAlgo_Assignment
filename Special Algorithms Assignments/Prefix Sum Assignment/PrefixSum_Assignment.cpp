#include<iostream>
#include<vector>
using namespace std;
class NumArray{
//1
vector<int> pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre = vector<int>(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
    }
    int sumRange(int left, int right) {
        if(left == 0) return pre[right];
        return pre[right] - pre[left-1];
    }
};

//2
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = 0;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        int last = nums[n-1];
        nums[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            int cur = nums[i];
            nums[i] = nums[i+1] + last;
            last = cur;
        }
        for(int i=0;i<n;i++){
            if(pre[i] == nums[i]) return i;
        }
        return -1;
    }

//3
vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        ans[0] = 2*nums[0];
        int max = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>max) max = nums[i];
            ans[i] = ans[i-1] + max + nums[i];
        }
        return ans;
    }

//4
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int p = bookings.size();
        vector<int> ans(n,0);
        for(int i=0;i<p;i++){
            int idx1 = bookings[i][0];
            int idx2 = bookings[i][1];
            ans[idx1-1] += bookings[i][2];
            if(idx2<n) ans[idx2] += (-bookings[i][2]);
        }
        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
int main(){

}