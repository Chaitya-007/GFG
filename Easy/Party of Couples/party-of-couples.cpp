//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
        // map <int, int> hashset;
        // for(int i = 0; i < n; i++)
        // {
        //     hashset[arr[i]]++;
        // }
        
        // // for(auto itr : hashset)
        // // {
        // //     if(itr.second == 1)
        // //     {
        // //         return (itr.first);
        // //         // int element = itr.first;
        // //         // return element;
        // //     }
            
        // //     // cout<<itr.first<<"->"<<itr.second<<"\n";
        // // }
        
        // for(auto itr = hashset.begin(); itr != hashset.end(); itr++)
        // {
        //     if(itr->second == 1)
        //     {
        //         return (itr->first);
        //     }
        // }
        
        // if(n%2 == 0)
        
        // sort(arr, arr + n);
        
        // for(int i = 0; i < n; i = i + 2)
        // {
        //     if(i == (n - 1))
        //     {
        //         return arr[i];
        //     }
        //     if(arr[i] != arr[i+1])
        //     {
        //         return arr[i];
        //     }
            
        // }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            ans = ans^arr[i];
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends