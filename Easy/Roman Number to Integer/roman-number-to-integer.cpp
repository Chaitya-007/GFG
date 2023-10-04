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
         unordered_map<char,int> CP;
        CP['I']=1;
        CP['V']=5;
        CP['X']=10;
        CP['L']=50;
        CP['C']=100;
        CP['D']=500;
        CP['M']=1000;
        
        int num=0;
        for(int i=0;i<str.length();i++)
        {
            // if its last index
            if(i==str.length()-1)
            {
                num+=(CP[str[i]]);
                continue;
            }
            
            if(CP[str[i]]<CP[str[i+1]])
            num+=(-CP[str[i]]);
            else
            num+=CP[str[i]];
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