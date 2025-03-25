//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(vector<int>& arr, int i, int target, vector<vector<int>>&dp){
        if(i==0){
            if(target == 0 && arr[0] ==0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if(dp[i][target] !=-1) return dp[i][target];
        int notTake = solve(arr, i-1, target, dp);
        int take = 0;
        if(arr[i] <= target){
            take = solve(arr, i-1, target - arr[i], dp);
        }
        
        return dp[i][target] = take + notTake;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        if((total - d) %2 != 0 || total - d < 0) return 0;
        int target = (total - d)/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

        return solve(arr, n-1, target ,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends