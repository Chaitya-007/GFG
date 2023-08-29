//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>v;
        
        //sorting in descending order accordint to profit
        sort(arr,arr+n,compare);
        
        //declaring two arrays to store the result and free slots
        int result[n];
        bool slots[n];
        
        //Initializing all slots as free
        for(int i = 0 ; i < n ; i++)
        {
            slots[i] = false;
        }
        
        //Outer loop => Iterating through array
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = min(n,arr[i].dead) - 1; j>=0 ; j--)
            {
                if(slots[j] == false)
                {
                    result[j] = i;
                    slots[j] = true;
                    break;
                }
            }
        }
        
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(slots[i] == true)
            {
                count++;
                sum = sum + arr[result[i]].profit;
                // cout<<arr[result[i]].profit<<" ";
            }
        }
        v.emplace_back(count);
        v.emplace_back(sum);
        return v;
        
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends