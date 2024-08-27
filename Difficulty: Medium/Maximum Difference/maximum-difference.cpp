//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    
    void findpse(vector<int> &pse,vector<int> &arr,int n)
    {
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&st.top()>=arr[i])
            {
                st.pop();
            }
            pse[i]=st.empty()?0:st.top();
            st.push(arr[i]);
        }
    }
    void findnse(vector<int> &nse,vector<int> &arr,int n)
    {
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()>=arr[i])
            {
                st.pop();
            }
            nse[i]=st.empty()?0:st.top();
            st.push(arr[i]);
        }
    }
    
    
    int findMaxDiff(vector<int> &arr) {
        // Your code here
         int n=arr.size();
        vector<int> pse(n),nse(n);
        int maxi=INT_MIN;
        findpse(pse,arr,n);
        findnse(nse,arr,n);
        for(int i=0;i<n;i++)
        {
            maxi=max(abs(pse[i]-nse[i]),maxi);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends