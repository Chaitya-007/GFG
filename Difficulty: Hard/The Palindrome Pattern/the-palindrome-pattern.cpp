//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
           int row = arr.size();
        int col = arr[0].size();
        
        for(int i = 0; i < row; i++){
            
            for(int j = 0; j < col; j++){
                
                if(arr[i][j] != arr[i][(col-1)-j]){
                    break;
                }
                
                if(j == col-1){
                    string ans = to_string(i) + " R";
                    return ans;
                }
            }
        }
        
        for(int i = 0; i < col; i++){
            
            for(int j = 0; j < row; j++){
                
                if(arr[j][i] != arr[(row-1)-j][i]){
                    break;
                }
                
                if(j == row-1){
                    string ans = to_string(i) + " C";
                    return ans;
                }
            }
        }
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends