class Graph:
    """
    Graph implementation using adjacency list
    Supports both directed and undirected graphs
    """
    
    def __init__(self, directed=False):
        self.graph = {}
        self.directed = directed
    
    def add_vertex(self, vertex):
        """Add a vertex to the graph"""
        if vertex not in self.graph:
            self.graph[vertex] = []
    
    def add_edge(self, u, v, weight=1):
        """Add an edge between vertices u and v"""
        # Add vertices if they don't exist
        self.add_vertex(u)
        self.add_vertex(v)
        
        # Add edge from u to v
        self.graph[u].append((v, weight))
        
        # If undirected, add edge from v to u
        if not self.directed:
            self.graph[v].append((u, weight))
    
    def get_vertices(self):
        """Get all vertices in the graph"""
        return list(self.graph.keys())
    
    def get_edges(self):
        """Get all edges in the graph"""
        edges = []
        for u in self.graph:
            for v, weight in self.graph[u]:
                if self.directed or u <= v:  # Avoid duplicates in undirected graph
                    edges.append((u, v, weight))
        return edges
    
    def bfs(self, start):
        """
        Breadth-First Search traversal
        Time Complexity: O(V + E)
        Space Complexity: O(V)
        """
        if start not in self.graph:
            return []
        
        visited = set()
        queue = [start]
        result = []
        
        while queue:
            vertex = queue.pop(0)
            if vertex not in visited:
                visited.add(vertex)
                result.append(vertex)
                
                # Add unvisited neighbors to queue
                for neighbor, _ in self.graph[vertex]:
                    if neighbor not in visited:
                        queue.append(neighbor)
        
        return result
    
    def dfs(self, start):
        """
        Depth-First Search traversal (iterative)
        Time Complexity: O(V + E)
        Space Complexity: O(V)
        """
        if start not in self.graph:
            return []
        
        visited = set()
        stack = [start]
        result = []
        
        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                visited.add(vertex)
                result.append(vertex)
                
                # Add unvisited neighbors to stack (reverse order for consistent traversal)
                for neighbor, _ in reversed(self.graph[vertex]):
                    if neighbor not in visited:
                        stack.append(neighbor)
        
        return result
    
    def dfs_recursive(self, start, visited=None, result=None):
        """
        Depth-First Search traversal (recursive)
        """
        if visited is None:
            visited = set()
        if result is None:
            result = []
        
        if start not in self.graph:
            return result
        
        visited.add(start)
        result.append(start)
        
        for neighbor, _ in self.graph[start]:
            if neighbor not in visited:
                self.dfs_recursive(neighbor, visited, result)
        
        return result
    
    def has_path(self, start, end):
        """Check if there's a path between start and end vertices"""
        if start not in self.graph or end not in self.graph:
            return False
        
        visited = set()
        queue = [start]
        
        while queue:
            vertex = queue.pop(0)
            if vertex == end:
                return True
            
            if vertex not in visited:
                visited.add(vertex)
                for neighbor, _ in self.graph[vertex]:
                    if neighbor not in visited:
                        queue.append(neighbor)
        
        return False
    
    def shortest_path_bfs(self, start, end):
        """
        Find shortest path using BFS (unweighted graph)
        Returns the path and its length
        """
        if start not in self.graph or end not in self.graph:
            return None, 0
        
        if start == end:
            return [start], 0
        
        visited = set()
        queue = [(start, [start])]
        
        while queue:
            vertex, path = queue.pop(0)
            
            if vertex not in visited:
                visited.add(vertex)
                
                for neighbor, _ in self.graph[vertex]:
                    if neighbor == end:
                        return path + [neighbor], len(path)
                    
                    if neighbor not in visited:
                        queue.append((neighbor, path + [neighbor]))
        
        return None, 0
    
    def is_cyclic(self):
        """Check if the graph contains a cycle"""
        if self.directed:
            return self._is_cyclic_directed()
        else:
            return self._is_cyclic_undirected()
    
    def _is_cyclic_directed(self):
        """Check for cycle in directed graph using DFS"""
        color = {vertex: 'white' for vertex in self.graph}
        
        def dfs_visit(vertex):
            color[vertex] = 'gray'
            
            for neighbor, _ in self.graph[vertex]:
                if color[neighbor] == 'gray':  # Back edge found
                    return True
                if color[neighbor] == 'white' and dfs_visit(neighbor):
                    return True
            
            color[vertex] = 'black'
            return False
        
        for vertex in self.graph:
            if color[vertex] == 'white':
                if dfs_visit(vertex):
                    return True
        return False
    
    def _is_cyclic_undirected(self):
        """Check for cycle in undirected graph using DFS"""
        visited = set()
        
        def dfs_visit(vertex, parent):
            visited.add(vertex)
            
            for neighbor, _ in self.graph[vertex]:
                if neighbor not in visited:
                    if dfs_visit(neighbor, vertex):
                        return True
                elif neighbor != parent:  # Back edge found
                    return True
            return False
        
        for vertex in self.graph:
            if vertex not in visited:
                if dfs_visit(vertex, None):
                    return True
        return False
    
    def connected_components(self):
        """Find all connected components in undirected graph"""
        if self.directed:
            raise ValueError("Connected components are defined for undirected graphs")
        
        visited = set()
        components = []
        
        for vertex in self.graph:
            if vertex not in visited:
                component = []
                self._dfs_component(vertex, visited, component)
                components.append(component)
        
        return components
    
    def _dfs_component(self, vertex, visited, component):
        """Helper method for finding connected components"""
        visited.add(vertex)
        component.append(vertex)
        
        for neighbor, _ in self.graph[vertex]:
            if neighbor not in visited:
                self._dfs_component(neighbor, visited, component)
    
    def __str__(self):
        """String representation of the graph"""
        result = []
        for vertex in self.graph:
            neighbors = [f"{v}({w})" for v, w in self.graph[vertex]]
            result.append(f"{vertex} -> {', '.join(neighbors)}")
        return '\n'.join(result)

# Test the graph implementation
if __name__ == "__main__":
    # Test undirected graph
    print("=== Undirected Graph Test ===")
    g = Graph(directed=False)
    
    # Add edges
    edges = [('A', 'B'), ('A', 'C'), ('B', 'D'), ('C', 'D'), ('D', 'E')]
    for u, v in edges:
        g.add_edge(u, v)
    
    print("Graph structure:")
    print(g)
    
    print(f"\nVertices: {g.get_vertices()}")
    print(f"Edges: {g.get_edges()}")
    
    # Test traversals
    start_vertex = 'A'
    print(f"\nBFS from {start_vertex}: {g.bfs(start_vertex)}")
    print(f"DFS from {start_vertex}: {g.dfs(start_vertex)}")
    print(f"DFS Recursive from {start_vertex}: {g.dfs_recursive(start_vertex)}")
    
    # Test path finding
    start, end = 'A', 'E'
    print(f"\nPath from {start} to {end} exists: {g.has_path(start, end)}")
    path, length = g.shortest_path_bfs(start, end)
    print(f"Shortest path from {start} to {end}: {path} (length: {length})")
    
    # Test cycle detection
    print(f"\nGraph has cycle: {g.is_cyclic()}")
    
    # Test connected components
    print(f"Connected components: {g.connected_components()}")
    
    # Test directed graph
    print("\n=== Directed Graph Test ===")
    dg = Graph(directed=True)
    
    # Create a directed graph with cycle
    directed_edges = [('X', 'Y'), ('Y', 'Z'), ('Z', 'X'), ('X', 'W')]
    for u, v in directed_edges:
        dg.add_edge(u, v)
    
    print("Directed graph structure:")
    print(dg)
    
    print(f"\nDFS from X: {dg.dfs('X')}")
    print(f"Directed graph has cycle: {dg.is_cyclic()}")