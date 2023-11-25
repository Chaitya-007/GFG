//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    queue<int>q1;
	    queue<int>q2;
	    for(int i = 0; i < n; i++)
	    {
	        if(i < n/2)
	        {
	           q1.push(arr[i]); 
	        }
	        else
	        {
	            q2.push(arr[i]);
	        }
	        
	    }
	    
	    for(int i = 0; i < n ; i++)
	    {
	        if(i%2 == 0)
	        {
	            arr[i] = q1.front();
	            q1.pop();
	        }
	        else
	        {
	            arr[i] = q2.front();
	            q2.pop();
	        }
	    }
	    
	    
	    
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends