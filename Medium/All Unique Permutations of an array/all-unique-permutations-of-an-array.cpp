//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
      void solve(vector<int>temp,vector<vector<int>>&ans,vector<int> &arr,int index,set<vector<int>>&st){
       if(index==arr.size()){
        st.insert(temp);
           return ;
       }
       
       for(int i=index;i<arr.size();i++){
           
           swap(temp[index],temp[i]);
           solve(temp,ans,arr,index+1,st);
           swap(temp[index],temp[i]);
           
       }
       
   } 
    
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
           vector<int>temp=arr;
        set<vector<int>>st;
        
        vector<vector<int>>ans;
        solve(temp,ans,arr,0,st);
       
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends