//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        int element = 0;
        vector<int> res;
        
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto itr : mp)
        {
            if(itr.second == 2)
            {
                res.emplace_back(itr.first);
            }
        }
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(mp.find(i + 1) == mp.end())
            {
                res.emplace_back(i+1);
            }
        }
        
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends