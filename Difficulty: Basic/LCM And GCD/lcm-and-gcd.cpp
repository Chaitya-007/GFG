//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long a = A;
        long long b = B;
        while(A > 0 && B > 0)
        {
            if(A > B)
            {
                A = A % B;
            }
            else
            {
                B = B % A;
            }
        }
        
        long long gcd;
        
        if(A == 0)
        {
            gcd = B;
        }
        else
        {
            gcd = A;
        }
        
        long long lcm = (a*b)/gcd;
        vector<long long> res = {lcm,gcd};
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends