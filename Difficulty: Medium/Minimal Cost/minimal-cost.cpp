//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int solve(int i, vector<int>& arr, int k, vector<int>& dp) {
    if (i == 0) return 0; // Base case: If at the first step, no cost.

    if (dp[i] != -1) return dp[i]; // Memoization step.

    int minsteps = INT_MAX;
    
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int left = abs(arr[i] - arr[i - j]) + solve(i - j, arr, k, dp);
            minsteps = min(minsteps, left);
        }
    }
    
    return dp[i] = minsteps; // Store the computed result.
}

    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1); // Initialize DP array.
        return solve(n - 1, arr, k, dp);
        
        fp
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends