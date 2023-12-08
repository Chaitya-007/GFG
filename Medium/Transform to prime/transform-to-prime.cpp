//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
       bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
   
 
    if (n%2 == 0 || n%3 == 0) return false; 
   
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
   
    return true; 
} 
    
    int minNumber(int arr[],int N)
    {
          int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(isPrime(sum))
        return 0;
        else
        {
          int prime =sum;
          bool found = false;
 
         while (!found) {
              prime++;
 
             if (isPrime(prime))
                  found = true;
         }
 
    return (prime-sum);
        }
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends