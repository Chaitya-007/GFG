//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        vector<int> vec(32,0);
        for(int i = 0; i < 32; i++)
        {
            if(x & 1<<i)
            {
                vec[i] = 1;
            }
        }
        
        // for(auto itr : vec)
        // {
        //     cout<<itr;
        // }
        // cout<<endl;
        
        long long sum = 0;
        
        for(int i = 0; i < 32; i++)
        {
            if(vec[i] == 1)
            {
                sum += (1LL<<(31-i));
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends