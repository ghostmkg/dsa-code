# Topological Sort Algorithm
# Time Complexity: O(V + E) where V is vertices and E is edges
# Space Complexity: O(V) for recursion stack and visited array

from collections import defaultdict, deque

class Graph:
    """Graph class using adjacency list representation."""
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        """Add an edge from vertex u to vertex v."""
        self.graph[u].append(v)
    
    def topological_sort_dfs(self):
        """
        Topological sort using DFS (recursive approach).
        Returns a list of vertices in topological order.
        """
        visited = [False] * self.vertices
        stack = []
        
        def dfs_util(vertex):
            visited[vertex] = True
            
            # Recur for all adjacent vertices
            for neighbor in self.graph[vertex]:
                if not visited[neighbor]:
                    dfs_util(neighbor)
            
            # Push current vertex to stack
            stack.append(vertex)
        
        # Visit all vertices
        for i in range(self.vertices):
            if not visited[i]:
                dfs_util(i)
        
        # Return reversed stack (topological order)
        return stack[::-1]
    
    def topological_sort_kahn(self):
        """
        Topological sort using Kahn's algorithm (BFS approach).
        Returns a list of vertices in topological order.
        """
        # Calculate in-degree for each vertex
        in_degree = [0] * self.vertices
        for i in range(self.vertices):
            for j in self.graph[i]:
                in_degree[j] += 1
        
        # Queue for vertices with no incoming edges
        queue = deque()
        for i in range(self.vertices):
            if in_degree[i] == 0:
                queue.append(i)
        
        result = []
        count = 0  # Count of visited vertices
        
        while queue:
            u = queue.popleft()
            result.append(u)
            count += 1
            
            # Reduce in-degree for all adjacent vertices
            for v in self.graph[u]:
                in_degree[v] -= 1
                if in_degree[v] == 0:
                    queue.append(v)
        
        # Check if there was a cycle
        if count != self.vertices:
            return None  # Cycle detected
        return result
    
    def has_cycle(self):
        """
        Check if the graph has a cycle using DFS.
        """
        WHITE, GRAY, BLACK = 0, 1, 2
        color = [WHITE] * self.vertices
        
        def dfs_has_cycle(vertex):
            color[vertex] = GRAY
            
            for neighbor in self.graph[vertex]:
                if color[neighbor] == GRAY:  # Back edge found
                    return True
                if color[neighbor] == WHITE and dfs_has_cycle(neighbor):
                    return True
            
            color[vertex] = BLACK
            return False
        
        for i in range(self.vertices):
            if color[i] == WHITE:
                if dfs_has_cycle(i):
                    return True
        return False
    
    def all_topological_sorts(self):
        """
        Find all possible topological sorts using backtracking.
        """
        in_degree = [0] * self.vertices
        for i in range(self.vertices):
            for j in self.graph[i]:
                in_degree[j] += 1
        
        visited = [False] * self.vertices
        result = []
        all_results = []
        
        def all_topological_sorts_util():
            # To indicate whether all topological are found or not
            flag = False
            
            for i in range(self.vertices):
                # If in_degree is 0 and not yet visited
                if in_degree[i] == 0 and not visited[i]:
                    # Reduce in-degree for all adjacent vertices
                    for j in self.graph[i]:
                        in_degree[j] -= 1
                    
                    # Include in result
                    result.append(i)
                    visited[i] = True
                    
                    # Recur for other vertices
                    all_topological_sorts_util()
                    
                    # Reset
                    visited[i] = False
                    result.pop()
                    for j in self.graph[i]:
                        in_degree[j] += 1
                    
                    flag = True
            
            # If no vertex with in_degree 0, we have a cycle
            if not flag:
                all_results.append(result[:])
        
        all_topological_sorts_util()
        return all_results

def create_sample_graph():
    """Create a sample DAG for testing."""
    # Graph with 6 vertices
    # 5 -> 2 -> 3 -> 1
    # 5 -> 0 -> 1
    # 4 -> 0 -> 1
    # 4 -> 1
    g = Graph(6)
    g.add_edge(5, 2)
    g.add_edge(5, 0)
    g.add_edge(4, 0)
    g.add_edge(4, 1)
    g.add_edge(2, 3)
    g.add_edge(3, 1)
    return g

def create_cyclic_graph():
    """Create a cyclic graph for testing."""
    g = Graph(3)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(2, 0)  # Creates a cycle
    return g

def print_topological_order(result, method_name):
    """Helper function to print topological sort result."""
    if result is None:
        print(f"{method_name}: Cycle detected - no valid topological order")
    else:
        print(f"{method_name}: {' -> '.join(map(str, result))}")

# Example usage
if __name__ == "__main__":
    print("Topological Sort Examples")
    print("=" * 50)
    
    # Test with DAG
    print("Testing with Directed Acyclic Graph (DAG):")
    dag = create_sample_graph()
    print("Graph structure:")
    print("5 -> 2 -> 3 -> 1")
    print("5 -> 0 -> 1")
    print("4 -> 0 -> 1")
    print("4 -> 1")
    print()
    
    # DFS approach
    dfs_result = dag.topological_sort_dfs()
    print_topological_order(dfs_result, "DFS Topological Sort")
    
    # Kahn's algorithm
    kahn_result = dag.topological_sort_kahn()
    print_topological_order(kahn_result, "Kahn's Algorithm")
    
    # Check for cycle
    print(f"Has cycle: {dag.has_cycle()}")
    print()
    
    # Test with cyclic graph
    print("Testing with Cyclic Graph:")
    cyclic_graph = create_cyclic_graph()
    print("Graph structure: 0 -> 1 -> 2 -> 0 (cycle)")
    print()
    
    # DFS approach on cyclic graph
    dfs_cyclic = cyclic_graph.topological_sort_dfs()
    print_topological_order(dfs_cyclic, "DFS on Cyclic Graph")
    
    # Kahn's algorithm on cyclic graph
    kahn_cyclic = cyclic_graph.topological_sort_kahn()
    print_topological_order(kahn_cyclic, "Kahn's on Cyclic Graph")
    
    # Check for cycle
    print(f"Has cycle: {cyclic_graph.has_cycle()}")
    print()
    
    # Test all topological sorts
    print("All possible topological sorts for DAG:")
    all_sorts = dag.all_topological_sorts()
    for i, sort in enumerate(all_sorts, 1):
        print(f"Option {i}: {' -> '.join(map(str, sort))}")
    print()
    
    # Real-world example: Course prerequisites
    print("Real-world Example: Course Prerequisites")
    print("Courses: 0=Math, 1=Physics, 2=Chemistry, 3=Biology, 4=CS")
    print("Prerequisites:")
    print("- CS requires Math and Physics")
    print("- Physics requires Chemistry")
    print("- Biology requires Chemistry")
    
    courses = Graph(5)
    courses.add_edge(2, 1)  # Chemistry -> Physics
    courses.add_edge(2, 3)  # Chemistry -> Biology
    courses.add_edge(0, 4)  # Math -> CS
    courses.add_edge(1, 4)  # Physics -> CS
    
    course_order = courses.topological_sort_kahn()
    if course_order:
        course_names = ['Math', 'Physics', 'Chemistry', 'Biology', 'CS']
        ordered_courses = [course_names[i] for i in course_order]
        print(f"Recommended course order: {' -> '.join(ordered_courses)}")
    else:
        print("Cycle detected in prerequisites!")