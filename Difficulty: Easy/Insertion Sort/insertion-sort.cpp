class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        // code here
        for (int i = 0; i <= n - 1; i++) {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                j--;
            }
        }
    }
};