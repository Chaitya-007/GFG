//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        
        int i = 0;
        int j = 0;
        
        vector<int> vec;
        int element;
        
        while(i <= (n-1) && j <= (m-1))
        {
            if(i != 0 || j != 0)
            {
                 element = vec.back(); 
            }
            // gives O(1)
            
            if(arr1[i] == arr2[j])
            {
                if(i == 0)
                {
                 vec.emplace_back(arr1[i]);   
                }
                else if(element != arr1[i])
                {
                    vec.emplace_back(arr1[i]);
                }
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j])
            {
                if(i == 0)
                {
                 vec.emplace_back(arr1[i]);   
                }
                
                else if(element != arr1[i])
                {
                    vec.emplace_back(arr1[i]);
                }
                
                i++;
            }
            else 
            {
                if(j == 0)
                {
                    vec.emplace_back(arr2[j]);
                }
                else if(element != arr2[j])
                {
                    vec.emplace_back(arr2[j]);
                }
                
                j++;
            }
        }
        
        while(i <= (n-1))
        {
            int element = vec.back();
            
            if(element < arr1[i])
            {
                vec.emplace_back(arr1[i]);
            }
            
            i++;
        }
        
        while(j <= (m-1))
        {
            int element = vec.back();
            
            if(element < arr2[j])
            {
                vec.emplace_back(arr2[j]);
            }
            
            j++;
        }
        
        return vec;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends