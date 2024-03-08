//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	        vector<int> hash(26,0);
    for(auto x : s){
        hash[x-'a']++;
    }
    unordered_map<int,int> mp;
    for(auto h : hash){
       if(h){
           mp[h]++;
       }
    }
    if(mp.size()==1){ // only one frequency element
        return true;
    }
    if(mp.size()>2){// more then two distinct frequencies
        return false;
    }
    // two distinct frequencies
    int p=0;
    int q=0;
    for(auto a : mp){
        if(p==0){
            p=a.first;
            q=a.second;
        }
        else{
            int r=a.first;
            int s=a.second;
            if(p>1 && r>1){ // both of them greater than 1
                if(q>1 || s>1){ // if any one of them appears more than once, like
                                // 2 3 3 or 2 2 3 3 or 2 2 3 all these cases are invalid
                    return false;
                }
                else{
                    return abs(p-r)<2; // if both appear only once like 2 3 or 4 6
                                       // check difference
                }
            }
            else{       // one of them is equal to 1
                if(q>1 && s>1){ // if both appear more than once  1 1 1 2 2 or 4 4 1 1
                    return false;
                }
                else{
                    if(p==1 && q>1 && s==1){ // if 1 appears more than one time and other one
                                           // appear only once 1 1 1 2 then the non repeating one
                        return r==2;      // must be equal to 2
                    }
                    else if( r==1 && s>1 && q==1 ){
                        return p==2;       // same case as above as we dont know which one is 1
                                          // p or r
                    }
                    else{
                        return true;   // otherwise if 1 comes only one time then its always true
                                       // 1 3 3 3 3 or 1 5 5 5 
                    }
                }
            }
        }
    }
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends