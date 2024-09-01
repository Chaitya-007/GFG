//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int dfs(int node, unordered_map<int, vector<int>>& mp, unordered_map<int, int>& memo, unordered_set<int>& visited) {
        if (memo.find(node) != memo.end()) {
            return memo[node];
        }

        visited.insert(node);
        int max_sum = 0;
        for (int neighbor : mp[node]) {
            max_sum = max(max_sum, dfs(neighbor, mp, memo, visited));
        }
        visited.erase(node);
        
        memo[node] = max_sum + node;
        return memo[node];
    }
    
    int maxPathSum(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < arr1.size() - 1; i++) {
            mp[arr1[i]].push_back(arr1[i + 1]);
        }
        for (int i = 0; i < arr2.size() - 1; i++) {
            mp[arr2[i]].push_back(arr2[i + 1]);
        }
        
        unordered_map<int, int> memo;
        unordered_set<int> visited;
        int ans = 0;
        
        if (!arr1.empty()) {
            ans = max(ans, dfs(arr1[0], mp, memo, visited));
        }
        if (!arr2.empty()) {
            ans = max(ans, dfs(arr2[0], mp, memo, visited));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends