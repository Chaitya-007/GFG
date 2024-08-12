//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
          int l=0,r=0;
        int x=arr1.size();
        vector<int> temp;
        while(l<x&&r<x)
        {
            if(arr1[l]<=arr2[r])
            {
                temp.push_back(arr1[l]);
                l++;
            }
            else{
                temp.push_back(arr2[r]);
                r++;
            }
        }
        while(l<x)
        {
            temp.push_back(arr1[l]);
                l++;
        }
        while(r<x)
        {
            temp.push_back(arr2[r]);
                r++;
        }
        int ans=temp[x]+temp[x-1];
        return ans;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends