//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        int count = 0;
        
        for(int i = 0; i < str1.length(); i++)
        {
            if(mp1.find(str1[i]) == mp1.end())
            {
            mp1[str1[i]] = count;
            count++; 
            }
            
        }
        
        count = 0;
        
        for(int i = 0; i < str2.length(); i++)
        {
            if(mp2.find(str2[i]) == mp2.end())
            {
            mp2[str2[i]] = count;
            count++; 
            }
        }
        
        // int count = 0;
        
        // for(auto itr = mp1.begin(); itr != mp1.end(); itr++)
        // {
        //     itr->second = count;
        //     count++;
        // }
        
        // count = 0;
        // for(auto itr = mp2.begin(); itr != mp2.end(); itr++)
        // {
        //     itr->second = count;
        //     count++;
        // }
        
        vector<int> vec1;
        vector<int> vec2;
        
        for(int i = 0; i < str1.length(); i++)
        {
           vec1.emplace_back(mp1[str1[i]]); 
        }
        
        for(int i = 0; i < str2.length(); i++)
        {
            vec2.emplace_back(mp2[str2[i]]);
        }
        
        if(vec1 == vec2)
        {
            return true;
        }
        
        return false;
        
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends