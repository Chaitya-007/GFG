//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> raj;
        raj['I']=1;
        raj['V']=5;
        raj['X']=10;
        raj['L']=50;
        raj['C']=100;
        raj['D']=500;
        raj['M']=1000;
        
        int num=0;
        for(int i=0;i<str.length();i++)
        {
            // if its last index
            if(i==str.length()-1)
            {
                num+=(raj[str[i]]);
                continue;
            }
            
            if(raj[str[i]]<raj[str[i+1]])
            num+=(-raj[str[i]]);
            else
            num+=raj[str[i]];
        }
        
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends