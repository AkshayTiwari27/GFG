

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int maxi = INT_MIN;
        vector<int>leader;
        for(int i = arr.size()-1; i>= 0; i--){
            if(arr[i]>=maxi) leader.push_back(arr[i]);
            maxi = max(arr[i], maxi);
        }
        reverse(leader.begin(), leader.end());
        
        return leader;
    }
};