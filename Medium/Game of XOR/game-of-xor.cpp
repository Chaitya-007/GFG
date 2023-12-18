//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
         int ans=0;
        for(int i=0;i<N;i++){
            
                //A[i] will come N-i*1+i times
                //so just check if anyone of them is odd then xor will A[i] or xor will be 0
               
            if((i+1)%2 && (N-i)%2){
                //since both are odd it will contribute to the ans
                ans^=A[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends