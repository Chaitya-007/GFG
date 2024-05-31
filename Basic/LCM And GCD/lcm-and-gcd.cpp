//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        // long long lcm;
        // long long gcd;
        
        // M-1
        // for(long long i = 1; i <= min(A,B); i++)
        // {
        //     if(A%i == 0 && B%i == 0)
        //     {
        //         gcd = i;
        //     }
        // }
        
        // for(long long i = min(A,B) ; i >= 1; i--)
        // {
        //     if(A%i == 0 && B%i == 0)
        //     {
        //         gcd = i;
        //         break;
        //     }
        // }
        
        long long product = A*B;
        
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
        
        
        long long lcm;
        long long gcd;
        
        if(A==0ll)
        {
            gcd = B;
        }
        else
        {
            gcd = A;
        }
        
        lcm = product/gcd;
        
        vector<long long> vec = {lcm,gcd};
        
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