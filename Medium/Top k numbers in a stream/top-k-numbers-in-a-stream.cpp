//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // Create a hash map to store the frequency of each element
        unordered_map<int, int> mp;
        
        // Create a set to maintain the top K elements along with their frequencies
        set<pair<int, int>> st;
        
        // Vector to store the final result
        vector<vector<int>> ans;
        
        // Iterate through the array
        for (int i = 0; i < N; ++i) {
            // Vector to store the top K elements at the current index
            vector<int> res;
            // Taking set(not unordered) as it stores the element in increasing order
            // Taking first number in pair is negative which will store the elements with their decreasing order of frequency
            
            // If the current element is already in the set, remove it to update its frequency
            if (mp[arr[i]] > 0) {
                st.erase({-mp[arr[i]], arr[i]});
            }
            mp[arr[i]]++;
            st.insert({-mp[arr[i]], arr[i]});
            
            // Variable to keep track of the number of elements added to the result vector
            int t = 0;
            for (auto j : st) {
                if (t >= K) {
                    break;
                }
                // Add the element to the result vector
                res.push_back(j.second);
                ++t;
            }
            ans.push_back(res);
        }
        
        // Return the final result
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends