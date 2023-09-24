//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        vector<int>v;
        int count = 1;
        
        // for(int i = 0; i<n ; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] == arr[i+1])
            {
                count++;
                if(count == 2)
                {
                    v.emplace_back(arr[i]);
                }
            }
            else
            {
                count = 1;
            }
        }
        
        if(v.empty())
        {
            v.emplace_back(-1);
            return v;
        }
        
        return v;
        
        
        
        
        
        // map<int,int>m;
        // for(int i = 0; i < n ; i++)
        // {
        //     m[arr[i]]++;
        // }
        // for(auto itr = m.begin(); itr != m.end(); i++)
        // {
            
        // }
        
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