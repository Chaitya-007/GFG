//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>vec;
        for(int i = 0; i < n ; i++)
        {
            if(arr[i] <= x)
            {
                if(arr[i] == x)
                {
                   vec.emplace_back(i); 
                }
                
            }
            else
            {
                break;
            }
        }
        if(vec.empty())
        {
            vec.emplace_back(-1);
            vec.emplace_back(-1);
            return vec;
        }
        else if(vec.size() == 1)
        {
            int var = vec[0];
            vec.emplace_back(var);
            return vec;
        }
        else
        {
            int start = vec[0];
            int end = vec[vec.size() - 1];
            vec.clear();
            vec.emplace_back(start);
            vec.emplace_back(end);
            return vec;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends