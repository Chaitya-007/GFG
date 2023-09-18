//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long number){
        
        // Your code here    
        
        // int x = 2;
        
        // if(n == 0)
        // {
        //     return 0;
        // }
        
        // if(n == 1)
        // {
        //     return 1;
        // }
        
        // while(x <= n)
        // {
        //     if(n%x == 0)
        //     {
        //         x = x*2;
        //     }
        //     else
        //     {
        //         return 0;
        //     }
        // }
        // return 1;
        
          if(number==0){
          return false; 
       } 
       
       return ((number&(number-1))==0);
        
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends