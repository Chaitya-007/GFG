//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
       int temp = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (char &ch : s)
        {
            if (isalpha(ch)) 
            {
                int pos = ch - 'a';
                if (!(temp & (1 << pos))) 
                {
                    temp = temp | (1 << pos);
                }
            }
        }
        int ans = __builtin_popcount(temp);
        return ans == 26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends