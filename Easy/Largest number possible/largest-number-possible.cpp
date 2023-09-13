//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int smar){
        // code here
        if(smar == 0 && N==1)  return "0";
        if(smar == 0 && N > 1) return "-1";
        string res = "";
        for(int i{0}; i < N; ++i){
            if(smar > 9){
                res += '9';
                smar -= 9;
            }
            else{
                res +=(smar + '0');
                smar = 0;
            }
        }
        return smar == 0 ? res : "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends