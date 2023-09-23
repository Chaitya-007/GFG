//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long before_sum = a[0];
        long long get_total = 0;
        
        if(n == 1)
        {
            return 1;
        }
        
        if(n == 2)
        {
            return -1;
        }
        
        
        for(int i = 0; i < n; i++)
        {
            get_total = get_total + a[i];
        }
        
        for(int i = 1; i < n - 1; i++)
        {
            if(before_sum == (get_total - (before_sum + a[i])))
            {
                return (i+1);
            }
            
            before_sum = before_sum + a[i];
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends