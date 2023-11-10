//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string str="";stack<int> st;
        int num=1;
        for(int i=0;i<S.length();i++){
            char ch=S.at(i);
            if(ch=='D'){
                st.push(num);
                num++;
            }else{
                st.push(num);
                num++;
                while(st.size()>0){
                   str=str+to_string(st.top());
                    
                    st.pop();
                }
            }
        }
               st.push(num);
                while(st.size()>0){
                    str=str+to_string(st.top());
                    st.pop();
                }
                return str;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends