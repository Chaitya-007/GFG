//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
          vector<int>v1;
         int n=mat.size();
         n=n-1;
         for(int i=0;i<=2*n;i++){
             for(int j=0;j<=i;j++){
                 if(i-j<=n && j<=n){
                     if(i%2==0){
                         v1.push_back(mat[i-j][j]);
                     }
                     else{
                         v1.push_back(mat[j][i-j]);
                     }
                 }
             }
         }
         return v1;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends