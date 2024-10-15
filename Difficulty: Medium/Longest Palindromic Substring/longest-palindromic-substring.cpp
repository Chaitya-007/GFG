//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int n = s.length();
        string str = "";
        int ans = 0;
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        for(int diff = 0; diff < n; diff++)
        {
            for(int i = 0, j = i + diff; j < n; i++,j++)
            {
                if(diff == 0)
                {
                    dp[i][j] = 1;
                }
                else if(diff == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = 2;
                    }
                }
                else
                {
                    if(diff > 1)
                    {
                        if(s[i] == s[j])
                        {
                           if(dp[i+1][j-1] > 0)
                           {
                               dp[i][j] = dp[i+1][j-1] + 2;
                           }
                        }
                        
                    }
                }
                
                if(dp[i][j] > 0)
                {
                    if(ans < j - i + 1)
                    {
                        ans = max(ans,j - i + 1);
                        str = s.substr(i,ans);
                    }
                }
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends