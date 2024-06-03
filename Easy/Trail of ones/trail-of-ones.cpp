//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        long long a=1,b=1;
        long long mod=1e9+7;
        for(int i=1;i<n;i++){
            long long c=a;
            a=(a+b)%mod;
            b=c;
        }
        long long total=1;
        long long p=2;
        while(n){
            if(n&1) total=(total*p)%mod;
            p=(p*p)%mod;
            n>>=1;
        }
        return (total-(a+b)%mod+mod)%mod ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends