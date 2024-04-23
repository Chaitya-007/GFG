//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int count = 0;
        int ans = 0;
        int mincount = INT_MAX;
        
        for(int i = 0; i < a.size(); i++)
        {
            count = 0;
            for(int j = 0; j < a[i].size(); j++)
            {
                if(a[i][j] == 1)
                {
                    count++;
                }
            }
            
            if(count < mincount)
            {
                mincount = count;
                ans = i + 1;
            }
        }
        
        // if(ans = 0)
        // {
        //     return 1;
        // }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends