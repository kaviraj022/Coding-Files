'''1. Graph Representations:
    Adjacency List: Each node has a list of its neighbors.
    Adjacency Matrix: A 2D matrix where matrix[u][v] represents the edge weight or existence.

2. Graph Operations and Complexities:
    | **Operation**                | **Adjacency List Complexity** | **Adjacency Matrix Complexity** |
    |------------------------------|-------------------------------|---------------------------------|
    | **Graph Construction**       | O(V + E)                      | O(V²)                           |
    | **Add Edge (u, v)**          | O(1)                          | O(1)                            |
    | **Remove Edge (u, v)**       | O(E)                          | O(1)                            |
    | **Check Edge (u, v)**        | O(E)                          | O(1)                            |
    | **DFS / BFS Traversal**      | O(V + E)                      | O(V²)                           |
    | **Dijkstra's Algorithm**     | O((V + E) log V)              | O(V²)                           |
    | **Bellman-Ford Algorithm**   | O(VE)                         | O(V³)                           |
    | **Floyd-Warshall Algorithm** | O(V³)                         | O(V³)                           |
    | **Topological Sort**         | O(V + E)                      | Not Applicable                  |
    | **Find Connected Components**| O(V + E)                      | O(V²)                           |
    | **Minimum Spanning Tree      | O((V + E) log V)              | O(V²)                           |
                    (Prim's)**    
    | **Minimum Spanning Tree      | O(E log E)                    | O(E log E)                      |
                    (Kruskal's)**

3. Key Takeaways:
Adjacency List:
    Efficient for sparse graphs (𝐸≈𝑉).
    Faster graph traversal and memory-efficient.
Adjacency Matrix:
    Efficient for dense graphs (𝐸≈𝑉^2).
    Quick edge checks but consumes more memory.

4. When to Use What?
    Sparse Graph: Adjacency List (Efficient storage and traversal).
    Dense Graph: Adjacency Matrix (Quick edge lookup).
    Shortest Path (Non-negative weights): Dijkstra with Priority Queue.
    Shortest Path (Negative weights): Bellman-Ford.
    All-Pairs Shortest Path: Floyd-Warshall.'''

class Solution:

    def bfsOfGraph(self, graph: List[List[int]]) -> List[int]:
        seen=set()
        res=[]
        dq=deque([0])
        seen.add(0)
        while(dq):
            node=dq.popleft()
            res.append(node)
            for nears in graph[node]:
                if nears not in seen:
                    dq.append(nears)
                    seen.add(nears)
        return res

    def dfsOfGraph(self, adj):
        res=[]
        seen=set()
        def dfs(root):
            nonlocal res,seen
            if root in seen:
                return
            res.append(root)
            seen.add(root)
            for i in adj[root]:
                dfs(i)
        dfs(0)
        return res

    #Undirected Graph BFS
    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        seen = set()
        def bfs(start):
            queue = deque([(start, -1)])  
            seen.add(start)
            while queue:
                node, parent = queue.popleft()
                for neighbor in adj[node]:
                    if neighbor not in seen:
                        seen.add(neighbor)
                        queue.append((neighbor, node))
                    elif neighbor != parent:                          
                        return True
            return False
        for i in range(V): 
            if i not in seen:
                if bfs(i):
                    return True
        return False

    #Directed Graph BFS
    def isCyclic(self, V: int, adj: List[List[int]]) -> bool:
        in_degree = [0] * V  # Stores in-degree of each node
        # Compute in-degree for all nodes
        for i in range(V):
            for neighbor in adj[i]:
                in_degree[neighbor] += 1
        # Push all nodes with in-degree = 0 into the queue
        queue = deque([i for i in range(V) if in_degree[i] == 0])
        count = 0  # To track the number of processed nodes
        while queue:
            node = queue.popleft()
            count += 1  # Processed a node
            # Reduce in-degree of all neighbors
            for neighbor in adj[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
        # If all nodes are processed, no cycle. Otherwise, cycle exists.
        return count != V  # Cycle exists if some nodes remain unprocessed

    #Undirected Graph DFS
    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        seen=set()
        def dfs(child,parent):
            seen.add(child)
            for i in adj[child]:
                if i not in seen:
                    if(dfs(i,child)):
                        return True
                elif(parent!=i):
                    return True
            return False
        for i in range(V):
            if i not in seen:
                if(dfs(i,-1)):
                    return True
        return False

    #Directed Graph DFS
    def isCyclic(self, V : int , adj : List[List[int]]) -> bool :
        seen=set()
        def dfs(root,curr):
            if root in curr:
                return True
            if root in seen:
                return False
            curr.add(root)
            for nears in adj[root]:
                if(dfs(nears,curr)):
                    return True
            seen.add(root)
            curr.remove(root)
            return False
        for i in range(V):
            if i not in seen:
                if(dfs(i,set())):
                    return True
        return False

    def topologicalSort(self,adj):
        stack=[]
        seen=set()
        def dfs(root):
            nonlocal stack,seen
            if root in seen:
                return
            for near in adj[root]:
                if near not in seen:
                    dfs(near)
            seen.add(root)
            stack.append(root)
        for i in range(len(adj)):
            if i not in seen:
                dfs(i)
        return stack[::-1]

    from collections import deque

    #Topological sort(Kahns algorithm)
    def topologicalSort(self,adj):
        v=len(adj)
        inDegree=[0]*v
        for i in range(v):
            for nears in adj[i]:
                inDegree[nears]+=1
        dq=deque([i for i in range(v) if inDegree[i]==0])
        cnt=0
        res=[]
        while(dq):
            node=dq.popleft()
            res.append(node)
            cnt+=1
            for nears in adj[node]:
                inDegree[nears]-=1
                if inDegree[nears]==0:
                    dq.append(nears)
        return res if cnt==v else []

    def dijkstra(self, adj: List[List[Tuple[int, int]]], src: int) -> List[int]:
        v=len(adj)
        dist=[float('inf')]*v
        heap=[]
        dist[src]=0
        heappush(heap,(0,src))
        while(heap):
            distance,node=heappop(heap)
            for near,weight in adj[node]:
                if distance+weight<dist[near]:
                    dist[near]=distance+weight
                    heappush(heap,(dist[near],near))
        return dist
        #if there a unconnected part to source then change them as -1
        