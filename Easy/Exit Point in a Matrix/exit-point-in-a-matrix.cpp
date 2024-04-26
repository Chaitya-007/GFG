//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int choice=0;
        int i=0,j=0;
        int x,y;
        while((i<n && i>=0)&&(j<m && j>=0)){
            if(matrix[i][j]==1){
                choice=(choice+1)%4;
                matrix[i][j]=0;
            }
            x=i;
            y=j;
            switch(choice){
                case 0: j+=1;
                break;
                case 1:i+=1;
                break;
                case 2:j-=1;
                break;
                case 3:i-=1;
                break;
            }
        }
        
        return{x,y};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends