//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
   bool dfs(int node,int parent,vector<int>adj[],vector<bool>&vis) {

      vis[node]=true;

      for(auto it:adj[node]){

          if(!vis[it]){

              if(dfs(it,node,adj,vis)) return true;

          }

          else if(parent!=it)return true;

      }

      return false;

  }

    int isTree(int n, int m, vector<vector<int>> &adj) {

        // code here

        int cnt=0;

        vector<bool>vis(n, false);

        vector<int>newadj[n];

        for(auto it:adj){

            newadj[it[0]].push_back(it[1]);

            newadj[it[1]].push_back(it[0]);

        }

        

        bool flag=false;

        for(int I=0;I<n;I++) {

            if(!vis[I]){

                cnt++;

                if(dfs(I,-1,newadj,vis)==true){

                    flag=true;

                    break;

                }

            }

        }

        if(cnt<=1 and flag)return 0;

        if(cnt>1) return 0;

        if(flag)return 1;

        return 1;

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends