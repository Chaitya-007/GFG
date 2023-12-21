//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        vector<int> a(N,1);


        vector<int> b(N,1);


        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]){
                a[i]=a[i]+a[i-1];
            } 
        }

 


        for(int i=N-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                b[i]=b[i]+b[i+1];
            }
        }

 


        vector<int>result(N,1);
        int sum=0;


        for(int i=0;i<N;i++){
            result[i]=max(a[i],b[i]);
            sum=sum+result[i];
        }


        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends