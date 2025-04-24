//{ Driver Code Starts
import java.util.*;

class Disjoint {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) a[i] = i;
            int k = sc.nextInt();
            GfG g = new GfG();
            for (int i = 0; i < k; i++) {
                String s = sc.next();
                if (s.equals("UNION")) {
                    int x = sc.nextInt();
                    int z = sc.nextInt();
                    g.unionSet(a, x, z);
                } else {
                    int x = sc.nextInt();
                    int parent = g.find(a, x);
                    System.out.print(parent + " ");
                }
            }
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/
class GfG {
    int find(int par[], int x) {
        // add code here.
        if(x == par[x])
        {
            return x;
        }
        
        return par[x] = find(par,par[x]);
    }

    void unionSet(int par[], int x, int z) {
        // add code here.
        int x_par = find(par,x);
        int z_par = find(par,z);
        
        if(x_par == z_par) return;
        else
        {
            par[x_par] = z_par;
        }
    }
}
