//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        
        unordered_map<char,int>map;
        
        for(auto x:s){
            map[x]++;
        }
        
        // for(auto x:map)cout<<x.second;
        vector<int>ans;
        for(auto x:map){
            ans.push_back(x.second);
        }
        
    sort(ans.begin(),ans.end(),greater<int>());
    int sum=0;
    int j=0;
    
    while(k>0){
        
        if(ans[j]!=1){
            ans[j]--;
             sort(ans.begin(),ans.end(),greater<int>());
            k--;
           
        }
       else if(ans[j]==1){
             ans[j]--;
            k--;
            j++;
        }
        
       else if(ans[j]==0)j++;
        
        
    }
    for(int i=0;i<ans.size();i++){
        int temp=ans[i];
        temp=temp*temp;
        sum+=temp;
    }
        
        
        return sum;
      
    }
    
    
    
   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends