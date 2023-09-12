//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N==1)
        return 0;
        
        long long TOTAL=1;
        for(long long K=2;K*K<=N;K++)
        {
            if(N%K==0)
            {
                TOTAL+=K;
                if(N/K!=K)
                TOTAL+=N/K;
            }
        }
        if(TOTAL==N)
        return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends