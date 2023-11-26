//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<int> vec;
    vector<int> pattern(int N){
        // code here
        if(N<=0)
        {
            vec.emplace_back(N);
            return vec;
        }
        
        vec.emplace_back(N);
        pattern(N - 5);
        vec.emplace_back(N);
        return vec;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends