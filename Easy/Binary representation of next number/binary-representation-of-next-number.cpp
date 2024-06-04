//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
                int carry=1,n=s.length();
        string ans;
        for(int i=n-1;i>=0;i--){
            int d=s[i]-'0';
            ans=to_string(d^carry)+ans;
            carry&=d;
        }
        if(carry) ans='1'+ans;
        // To remove leading zeros
        int i=0;
        for(;i<ans.length();i++) if(ans[i]!='0') break;
        return string(begin(ans)+i,end(ans));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends