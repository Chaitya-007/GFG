//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  int distSubSeq(string s)
    {
        unordered_map<char, int> last;
        int count = 1;

        for (auto ch : s) {
            int newCount = 2 * count;

            if (last.find(ch) != last.end())
                newCount -= last[ch];

            last[ch] = count;
            count = newCount;
        }
        return count;
    }
    
  public:
    string betterString(string str1, string str2) {
        // code here
         int distSubSeq1 = distSubSeq(str1);
        int distSubSeq2 = distSubSeq(str2);

        return distSubSeq2 > distSubSeq1 ? str2 : str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends