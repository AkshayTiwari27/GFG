//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int solve(int i, vector<int>& height, vector<int>&dp){
        if(i==0) return dp[i] =0;
        
        
        if(dp[i]!= -1) return dp[i];
        int left = abs(height[i] - height[i-1]) + solve(i-1 , height,dp);
        int right = INT_MAX;
        if(i>1) right =abs(height[i] - height[i-2]) + solve(i-2 , height,dp);
        
        return dp[i] = min(left, right);
    }
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size()+1, -1);
        return solve(height.size() - 1, height,dp);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends