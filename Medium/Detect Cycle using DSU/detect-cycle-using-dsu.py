class Solution:

    #Function to detect cycle using DSU in an undirected graph.
	def detectCycle(self, V, adj):
		#Code here
		parent = list(range(V))

        def find(u):
            if u != parent[u]:
                parent[u] = find(parent[u])
            return parent[u]

        def union(u, v):
            u_root, v_root = find(u), find(v)
            if u_root != v_root:
                parent[v_root] = u_root

        for u in range(V):
            for v in set(adj[u]):
                if v < u:
                    continue
                if find(u) == find(v):
                    return 1
                union(u, v)

        return 0



#{ 
 # Driver Code Starts

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.detectCycle(V, adj)
		print(ans)
# } Driver Code Ends