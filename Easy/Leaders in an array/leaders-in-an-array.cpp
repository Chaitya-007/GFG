//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        
        // Brute Force
        // T.C => O(N^2)
        // S.C => O(N)
        // vector<int> vec;
        
        // for(int i = 0; i < n; i++)
        // {
        //     int flag = 1;
        //     for(int j  = i + 1; j < n; j++)
        //     {
        //         if(a[i] >= a[j])
        //         {
                    
        //         }
        //         else
        //         {
        //             flag = 2;
        //             break;
        //         }
        //     }
            
        //     if(flag == 1)
        //     {
        //         vec.emplace_back(a[i]);
        //     }
        // }
        
        // return vec;
        
        // Better
        
        vector<int> vec;
        int maxo = a[n-1];
        vec.emplace_back(maxo);
        
        for(int i = n - 2; i >= 0 ; i--)
        {
            if(a[i] >= maxo)
            {
                // vec.emplace_back(a[i]);
                vec.insert(vec.begin(),a[i]);
                maxo = a[i];
            }
        }
        
        // reverse(vec.begin(),vec.end());
        
        return vec;
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends