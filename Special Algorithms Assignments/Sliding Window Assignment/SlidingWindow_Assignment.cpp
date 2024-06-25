#include<iostream>
#include<vector>
using namespace std;

//1
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        int i = 1;
        int j = k;
        int count = 0;
        int minSum = k*threshold;
        if(sum>=minSum) count++;
        while(j<n){
            sum += arr[j] - arr[i-1];
            if(sum>=minSum) count++;
            i++;
            j++;
        }
        return count;
    }

//2
long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long count = 0;
        long long sum = 0;
        long long i = 0, j = 0;
        long long score = 0;
        while(j<n){
            sum += nums[j];
            score = sum*(j-i+1);
            while(score>=k){
                sum -= nums[i++];
                score = sum * (j-i+1);
            }
            count += j-i+1;
            j++;
        }
        return count;
    }

//3
int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0, j = 0, odd = 0, count = 0;
        while(j<n){
            if(nums[j]%2==1) {
                odd++;
                count = 0;
            }
            while(odd==k){
                count++;
                if(nums[i++]%2==1) odd--;
                cout<<i;
            }
            ans += count;
            j++;
        }
        return ans;
    }
int main(){

}