//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int fun(int ind, vector<int>& height, vector<int> &dp)
  {
      if(ind == 0) return 0;
      
      if(dp[ind] != -1) return dp[ind];
      
      int first = abs(height[ind] - height[ind - 1]) + fun(ind-1,height,dp);
      int second = INT_MAX;
      if(ind - 2 >= 0)
      {
          second = abs(height[ind]-height[ind-2]) + fun(ind-2,height,dp);
      }
      
      return dp[ind] = min(first,second);
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return fun(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends