//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long product = A*B;
        
        long long r = product;
        
        while(true)
        {
            r = A%B;
            if(r == 0)
            {
                break;
            }
            A = B;
            B = r;
        }
        
        vector<long long> vec;
        long long lcm = product/B;
        vec.emplace_back(lcm);
        vec.emplace_back(B);
        
        return vec;
        
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