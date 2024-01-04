//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     int singleElement(int arr[] ,int N) {
        // code here
        int ans,c=0;
        if(N==1){
            return arr[N-1];
        }
        unordered_map <int, int>mp;

   for(int i=0; i<N; i++)
      mp[arr[i]]++;

   for(auto it=mp.begin(); it!=mp.end(); it++){
       if(it->second==1)
       ans=it->first;
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
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends