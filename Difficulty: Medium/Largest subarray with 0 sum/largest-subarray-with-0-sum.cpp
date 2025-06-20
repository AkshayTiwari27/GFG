/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& a) {
        // code here
        int n = a.size(); // size of the array

        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
    
        for (int i = 0; i < n; i++) {
            // calculate the prefix sum till index i:
            sum += a[i];
    
            // if the sum == k, update the maxLen:
            if (sum == 0) {
                maxLen = max(maxLen, i + 1);
            }
    
            // calculate the sum of remaining part i.e. x - k:
            int rem = sum;
    
            // Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
    
            // Finally, update the map checking the conditions:
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
    
        return maxLen;

        
    }
};