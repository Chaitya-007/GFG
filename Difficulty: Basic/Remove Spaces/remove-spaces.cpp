//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string modify (string str)
    {
        //code here.
        int count = 0;
        int n = str.length();
        for(int i = 0; i < n; i++)
        {
            if(str[i] != ' ')
            {
                str[count] = str[i];
                count++;
            }
        }
        str.resize(count);
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}


// } Driver Code Ends