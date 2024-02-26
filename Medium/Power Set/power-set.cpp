//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		      int n = s.length();
            vector<string> result;
            int bit_string = pow(2,n);
            for(int i = 1; i < bit_string; i++) {
                //construct current string
                string a = {};
                for(int j = 0; j < n; j++) {
                    if((i>>j) & 1) {
                        a += s[j];
                    }
                }
                result.push_back(a);
            }
            sort(result.begin(), result.end());
            return result;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends