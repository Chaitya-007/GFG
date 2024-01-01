//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     bool canPair(vector<int> nums, int k) {
        int n=nums.size(),count=0;
        if(n%2==1) return false;
        vector<int> rem(k,0);
        for(int i=0;i<n;i++){
            rem[nums[i]%k]++;
        }
        if(rem[0]%2==1) return false;
        for(int i=1;i<k/2;i++){
            if(rem[i]!=rem[k-i]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends