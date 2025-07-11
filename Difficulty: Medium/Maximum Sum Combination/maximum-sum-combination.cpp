class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
    
        // Max heap to store {sum, {i, j}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        set<pair<int, int>> used;
    
        // Push the largest sum combination
        maxHeap.push({A[0] + B[0], {0, 0}});
        used.insert({0, 0});
    
        vector<int> topK;
    
        // Extract K maximum sum combinations
        for (int count = 0; count < K; count++) {
            // Extract top element
            pair<int, pair<int, int>> top = maxHeap.top();
            maxHeap.pop();
    
            int sum = top.first;
            int i = top.second.first, j = top.second.second;
    
            topK.push_back(sum);
    
            // Push next combination (i+1, j) if within bounds and not used
            if (i + 1 < N && used.find({i + 1, j}) == used.end()) {
                maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
                used.insert({i + 1, j});
            }
    
            // Push next combination (i, j+1) if within bounds and not used
            if (j + 1 < N && used.find({i, j + 1}) == used.end()) {
                maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
                used.insert({i, j + 1});
            }
        }
    
        return topK;
    }
};