//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& arr, int target, int i) {
    // Base case: all elements processed
    if (i < 0) return (target == 0) ? 1 : 0;
    
    // Check memoization table
    if (dp[i][target] != -1) return dp[i][target];
    
    // Don’t take the current element
    int nottake = solve(arr, target, i - 1);
    
    // Take the current element if possible
    int take = 0;
    if (arr[i] <= target) {
        take = solve(arr, target - arr[i], i - 1);
    }
    
    // Store and return the result
    return dp[i][target] = take + nottake;
}


    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
    dp = vector<vector<int>>(n, vector<int>(target + 1, -1));
    return solve(arr, target, n - 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends