//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int>lower,upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left,right;
        for(int i=0;i<N;i++){
            if(arr[i]<lower.top()) return 0;
            while(arr[i]>upper.top()){
                lower.pop();
                upper.pop();
            }
            left=lower.top();
            right=upper.top();
            lower.pop();
            upper.pop();
            lower.push(arr[i]);
            upper.push(right);
            
            lower.push(left);
            upper.push(arr[i]);
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends