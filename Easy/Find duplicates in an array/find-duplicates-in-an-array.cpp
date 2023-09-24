//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        map<int,int>m;
        vector<int>v;
        for(int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        for(auto itr = m.begin(); itr != m.end() ; itr++)
        {
            if(itr->second > 1)
            {
                v.emplace_back(itr->first);
            }
        }
        if(v.empty())
        {
            v.emplace_back(-1);
            return v;
        }
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends