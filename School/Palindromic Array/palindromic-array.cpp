//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	int r,res,temp;
    	int flag = 1;
    	for(int i = 0 ; i < n ; i++)
    	{
    	    
    	    res = 0;
    	    temp = a[i];
    	    while(a[i]>0)
    	    {
    	        r = a[i]%10;
    	        a[i] = a[i]/10;
    	        res = res*10 + r;

    	    }
    	    
    	    
    	    if(res != temp)
    	    {
    	        flag = 2;
    	        break;
    	    }
    	}
    	
    	if(flag == 1)
    	{return 1;}
    	
    	return 0;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends