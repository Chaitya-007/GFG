//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int soln = 0;
        
        vector<int> row = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> col = {0, 1, 1, 1, 0, -1, -1, -1};
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int getcount = 0;
                if (matrix[i][j] == 1) {
                    for (int k = 0; k < 8; k++) {
                        int r = i + row[k];
                        int c = j + col[k];
                        
                        if (r >= 0 && r < n && c >= 0 && c < m && matrix[r][c] == 0) {
                            getcount++;
                        }
                    }
                    if (getcount > 0 && getcount % 2 == 0) {
                        soln++;
                    }
                }
            }
        }
        return soln;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends