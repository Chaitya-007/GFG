//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
   static bool fun(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second>b.second)
        return true;
        else if(a.second<b.second)
        return false;
        else
        return a.first<b.first;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int,int> u;
        vector<pair<int,int>>v;
        vector<int>count;
        for(int i=0;i<arr.size();i++)
        {
            u[arr[i]]++;
        }
        for(auto x:arr)
        {
            v.push_back({x,u[x]});
        }
        sort(v.begin(),v.end(),fun);
        for(auto x:v)
        count.push_back(x.first);
        return count;
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends