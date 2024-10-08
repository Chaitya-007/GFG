//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long int MOD = 1000000007;
    long modInverse(long base) {
        return power(base, MOD - 2);
    }
    
       long power(long base, int exponent) {
        long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }
    
     int nCk(int n, int k) {
        long numerator = 1;
        long denominator = 1;

        for (int i = 0; i < k; i++) {
            numerator = (numerator * (n - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }
        return (int) ((numerator * modInverse(denominator)) % MOD);
    }
    
    long long  numberOfPaths(int M, int N)
    {
        return nCk(M + N - 2, M - 1);
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends