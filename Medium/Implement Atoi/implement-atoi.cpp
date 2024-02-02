//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int sign=1;
        int i=0;
        int num=0;
        if(s[i]=='-'){
            sign=-1;
            ++i;
        }
        for(; i<s.size(); ++i){
            if(!isdigit(s[i])){
                return -1;
            }
            num=num*10+(s[i]-'0');
        }
        return sign*num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends