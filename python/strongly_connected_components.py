# Strongly Connected Components (SCC) Algorithm
# Using Kosaraju's Algorithm and Tarjan's Algorithm
# Time Complexity: O(V + E) for both algorithms
# Space Complexity: O(V) for recursion stack and auxiliary arrays

from collections import defaultdict, deque

class Graph:
    """Graph class using adjacency list representation."""
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)
        self.reversed_graph = defaultdict(list)
    
    def add_edge(self, u, v):
        """Add an edge from vertex u to vertex v."""
        self.graph[u].append(v)
        self.reversed_graph[v].append(u)  # For Kosaraju's algorithm
    
    def kosaraju_scc(self):
        """
        Find strongly connected components using Kosaraju's algorithm.
        Returns a list of SCCs, where each SCC is a list of vertices.
        """
        # Step 1: Fill vertices in stack according to their finishing times
        visited = [False] * self.vertices
        stack = []
        
        def dfs_fill_stack(vertex):
            visited[vertex] = True
            for neighbor in self.graph[vertex]:
                if not visited[neighbor]:
                    dfs_fill_stack(neighbor)
            stack.append(vertex)
        
        # Fill vertices in stack
        for i in range(self.vertices):
            if not visited[i]:
                dfs_fill_stack(i)
        
        # Step 2: Create reversed graph and process vertices in reverse order
        visited = [False] * self.vertices
        sccs = []
        
        def dfs_scc(vertex, scc):
            visited[vertex] = True
            scc.append(vertex)
            for neighbor in self.reversed_graph[vertex]:
                if not visited[neighbor]:
                    dfs_scc(neighbor, scc)
        
        # Process vertices in reverse order of finishing times
        while stack:
            vertex = stack.pop()
            if not visited[vertex]:
                scc = []
                dfs_scc(vertex, scc)
                sccs.append(scc)
        
        return sccs
    
    def tarjan_scc(self):
        """
        Find strongly connected components using Tarjan's algorithm.
        Returns a list of SCCs, where each SCC is a list of vertices.
        """
        # Initialize arrays
        disc = [-1] * self.vertices  # Discovery time
        low = [-1] * self.vertices   # Low link value
        stack_member = [False] * self.vertices  # Whether vertex is in stack
        stack = []
        time = [0]  # Use list to make it mutable in nested function
        sccs = []
        
        def tarjan_dfs(vertex):
            # Initialize discovery time and low link
            disc[vertex] = low[vertex] = time[0]
            time[0] += 1
            stack.append(vertex)
            stack_member[vertex] = True
            
            # Visit all neighbors
            for neighbor in self.graph[vertex]:
                if disc[neighbor] == -1:  # Not yet visited
                    tarjan_dfs(neighbor)
                    low[vertex] = min(low[vertex], low[neighbor])
                elif stack_member[neighbor]:  # Back edge to vertex in stack
                    low[vertex] = min(low[vertex], disc[neighbor])
            
            # If vertex is head of SCC
            if low[vertex] == disc[vertex]:
                scc = []
                while True:
                    w = stack.pop()
                    stack_member[w] = False
                    scc.append(w)
                    if w == vertex:
                        break
                sccs.append(scc)
        
        # Process all vertices
        for i in range(self.vertices):
            if disc[i] == -1:
                tarjan_dfs(i)
        
        return sccs
    
    def get_scc_graph(self, sccs):
        """
        Create a condensed graph where each SCC is a single vertex.
        Returns the condensed graph and mapping from original vertices to SCC indices.
        """
        # Create mapping from vertex to SCC index
        vertex_to_scc = {}
        for i, scc in enumerate(sccs):
            for vertex in scc:
                vertex_to_scc[vertex] = i
        
        # Create condensed graph
        condensed_graph = defaultdict(set)
        for vertex in range(self.vertices):
            for neighbor in self.graph[vertex]:
                scc_vertex = vertex_to_scc[vertex]
                scc_neighbor = vertex_to_scc[neighbor]
                if scc_vertex != scc_neighbor:
                    condensed_graph[scc_vertex].add(scc_neighbor)
        
        return condensed_graph, vertex_to_scc

def create_sample_graph():
    """Create a sample graph for testing SCC algorithms."""
    # Graph with 8 vertices
    # 0 -> 1 -> 2 -> 0 (SCC 1)
    # 2 -> 3 (SCC 2)
    # 3 -> 4 -> 5 -> 3 (SCC 3)
    # 5 -> 6 (SCC 4)
    # 6 -> 7 (SCC 5)
    g = Graph(8)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(2, 0)  # Creates SCC: {0, 1, 2}
    g.add_edge(2, 3)  # Bridge to next SCC
    g.add_edge(3, 4)
    g.add_edge(4, 5)
    g.add_edge(5, 3)  # Creates SCC: {3, 4, 5}
    g.add_edge(5, 6)  # Bridge to next SCC
    g.add_edge(6, 7)  # Creates SCC: {6} and {7}
    return g

def create_simple_graph():
    """Create a simple graph for testing."""
    g = Graph(5)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(2, 0)  # SCC: {0, 1, 2}
    g.add_edge(3, 4)  # SCC: {3}, {4}
    return g

def print_sccs(sccs, algorithm_name):
    """Helper function to print SCC results."""
    print(f"{algorithm_name}:")
    for i, scc in enumerate(sccs):
        print(f"  SCC {i + 1}: {scc}")
    print(f"  Total SCCs: {len(sccs)}")
    print()

def analyze_scc_properties(sccs, graph):
    """Analyze properties of the SCCs."""
    print("SCC Analysis:")
    
    # Find largest and smallest SCCs
    if sccs:
        sizes = [len(scc) for scc in sccs]
        largest_scc = max(sizes)
        smallest_scc = min(sizes)
        
        print(f"  Largest SCC size: {largest_scc}")
        print(f"  Smallest SCC size: {smallest_scc}")
        print(f"  Average SCC size: {sum(sizes) / len(sizes):.2f}")
        
        # Find SCCs with specific sizes
        single_vertex_sccs = [scc for scc in sccs if len(scc) == 1]
        multi_vertex_sccs = [scc for scc in sccs if len(scc) > 1]
        
        print(f"  Single-vertex SCCs: {len(single_vertex_sccs)}")
        print(f"  Multi-vertex SCCs: {len(multi_vertex_sccs)}")
        
        if multi_vertex_sccs:
            print("  Multi-vertex SCCs:")
            for scc in multi_vertex_sccs:
                print(f"    {scc}")
    
    print()

# Example usage
if __name__ == "__main__":
    print("Strongly Connected Components Examples")
    print("=" * 60)
    
    # Test with sample graph
    print("Testing with Sample Graph:")
    graph = create_sample_graph()
    print("Graph structure:")
    print("0 -> 1 -> 2 -> 0 (SCC 1)")
    print("2 -> 3 (SCC 2)")
    print("3 -> 4 -> 5 -> 3 (SCC 3)")
    print("5 -> 6 (SCC 4)")
    print("6 -> 7 (SCC 5)")
    print()
    
    # Kosaraju's algorithm
    kosaraju_sccs = graph.kosaraju_scc()
    print_sccs(kosaraju_sccs, "Kosaraju's Algorithm")
    
    # Tarjan's algorithm
    tarjan_sccs = graph.tarjan_scc()
    print_sccs(tarjan_sccs, "Tarjan's Algorithm")
    
    # Analyze properties
    analyze_scc_properties(kosaraju_sccs, graph)
    
    # Test condensed graph
    print("Condensed Graph (SCC Graph):")
    condensed_graph, vertex_to_scc = graph.get_scc_graph(kosaraju_sccs)
    print(f"Vertex to SCC mapping: {vertex_to_scc}")
    print("Condensed graph edges:")
    for scc_vertex, neighbors in condensed_graph.items():
        print(f"  SCC {scc_vertex} -> {list(neighbors)}")
    print()
    
    # Test with simple graph
    print("Testing with Simple Graph:")
    simple_graph = create_simple_graph()
    print("Graph structure:")
    print("0 -> 1 -> 2 -> 0 (SCC 1)")
    print("3 -> 4 (SCC 2)")
    print()
    
    simple_kosaraju = simple_graph.kosaraju_scc()
    print_sccs(simple_kosaraju, "Kosaraju's Algorithm")
    
    simple_tarjan = simple_graph.tarjan_scc()
    print_sccs(simple_tarjan, "Tarjan's Algorithm")
    
    # Real-world example: Social network
    print("Real-world Example: Social Network")
    print("Finding groups of mutually connected people")
    
    social_network = Graph(6)
    # People: 0=Alice, 1=Bob, 2=Charlie, 3=Diana, 4=Eve, 5=Frank
    social_network.add_edge(0, 1)  # Alice knows Bob
    social_network.add_edge(1, 2)  # Bob knows Charlie
    social_network.add_edge(2, 0)  # Charlie knows Alice (mutual group)
    social_network.add_edge(3, 4)  # Diana knows Eve
    social_network.add_edge(4, 3)  # Eve knows Diana (mutual group)
    social_network.add_edge(5, 5)  # Frank knows only himself
    
    social_sccs = social_network.kosaraju_scc()
    people = ['Alice', 'Bob', 'Charlie', 'Diana', 'Eve', 'Frank']
    
    print("Social groups (mutually connected people):")
    for i, scc in enumerate(social_sccs):
        group_members = [people[vertex] for vertex in scc]
        print(f"  Group {i + 1}: {', '.join(group_members)}")
    print()
    
    # Performance comparison
    print("Performance Notes:")
    print("- Kosaraju's algorithm: Two DFS passes, easier to understand")
    print("- Tarjan's algorithm: Single DFS pass, more efficient in practice")
    print("- Both algorithms have O(V + E) time complexity")
    print("- Both algorithms are used in various graph algorithms and applications")
