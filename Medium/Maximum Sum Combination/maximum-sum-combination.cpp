//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int>ans(k,0);
        int cnt=0;
        map<pair<int,int>,int>mps;
        priority_queue<pair<int,pair<int,int>>>pqs;
        pqs.push({a[n-1]+b[n-1],{n-1,n-1}});
        mps[{n-1,n-1}]=1;
        
        while(!pqs.empty())
        {
            int x=pqs.top().second.first;
            int y=pqs.top().second.second;
            pqs.pop();
            if(x-1>=0&&mps.find({x-1,y})==mps.end())
            {  
              pqs.push({a[x-1]+b[y],{x-1,y}});
              mps[{x-1,y}]==1;
            }
            if(y-1>=0&&mps.find({x,y-1})==mps.end())
            {
                pqs.push({a[x]+b[y-1],{x,y-1}});
                mps[{x,y-1}]==1;
            }
            ans[cnt++]=a[x]+b[y];
            if(cnt==k)return ans;
    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends