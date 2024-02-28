//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
             int n=s.length();
        int count=0;
        int i=n-1;
        int b=1,p=0;
        while(count<3 && i>=0)
        {   
            int d=s[i]-'0';
            p=(d*b)+p;
            count++;
            i--;
            b=b*10;
            // cout<<p<<" "<<d<<endl;
        }
        return  (p%8==0)?1:-1;
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends