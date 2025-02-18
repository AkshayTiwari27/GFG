//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int total = 0;
        unordered_map<long long int, long long int>mp;
        mp[0] = 1;
        long long prefix_sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            prefix_sum += arr[i];
            
            if(mp.count(prefix_sum)){
                total += mp[prefix_sum]++;
            }
            else mp[prefix_sum] = 1;
        }
        
        return total;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends