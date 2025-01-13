//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int mid,int n,int m){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*mid;
            if(ans>m) return 2;
        }
        if(ans==m) return 1;
        
        return 0;
    }
    int nthRoot(int n, int m) {
        // Code here.
        int left=1;
        int right=m;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(f(mid,n,m)==1) return mid;
            else if(f(mid,n,m)==0) left=mid+1;
            else right=mid-1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends