//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        
        // sort(A.begin(),A.end());
        // sort(B.begin(),B.end());
        
        // int count = 0;
        
        // vector<int>v;
        // vector<int>v2;
        
        
        // for(int i = A.size() - 1; i >= 0; i--)
        // {
        //     for(int j = B.size() - 1; j >=0; j--)
        //     {
        //         int sum = (A[i] + B[j]);
        //         v.emplace_back(sum);
        //     }
        // }
        
        // sort(v.begin(),v.end());
        
        // // for(auto itr = v.rbegin(); count != K; itr--)
        // // {
        // //     cout<<*itr<<" ";
        // // }
        
        // for(int i = v.size() - 1; count != K ; i--)
        // {
        //     v2.emplace_back(v[i]);
        //     count++;
        // }
        
        // return v2;
        
         sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int>ans(k,0);
        int cnt=0;
        map<pair<int,int>,int>mp;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({a[n-1]+b[n-1],{n-1,n-1}});
        mp[{n-1,n-1}]=1;
        
        while(!pq.empty())
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x-1>=0&&mp.find({x-1,y})==mp.end())
            {  
              pq.push({a[x-1]+b[y],{x-1,y}});
              mp[{x-1,y}]==1;
            }
            if(y-1>=0&&mp.find({x,y-1})==mp.end())
            {
                pq.push({a[x]+b[y-1],{x,y-1}});
                mp[{x,y-1}]==1;
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