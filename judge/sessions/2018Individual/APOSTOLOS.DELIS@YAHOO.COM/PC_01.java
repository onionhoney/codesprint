import math
from collections import defaultdict


class Graph:

    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    # Use BFS to check path between s and d
    def isReachable(self, s, d):
        # Mark all the vertices as not visited
        visited = [False] * self.V

        # Create a queue for BFS
        queue = []

        # Mark the source node as visited and enqueue it
        queue.append(s)
        visited[s] = True

        while queue:
            # Dequeue a vertex from queue
            n = queue.pop(0)

            # If this adjacent node is the destination node,
            # then return true
            if n == d:
                return True

        #  Else, continue to do BFS
            for i in self.graph[n]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
        # If BFS is complete without visited d
        return False


if __name__ == "__main__":
    num_test_cases = int(input())

    for i in range(num_test_cases):
        num_rooms, current_passageways, passageways_to_create = list(map(int, (input().split())))
        g = Graph(num_rooms+1)
        for connection in range(current_passageways):
            a, b = list(map(int, (input().split())))
            g.addEdge(a, b)

        solutions = set({})
        for start in range(1,num_rooms + 1):
            for end in range(1, num_rooms+1):
                if start == end:
                    pass
                elif g.isReachable(start, end):
                    solutions.add((min(start, end), max(start, end)))
                elif passageways_to_create > 0:
                    g.addEdge(min(start, end), max(start, end))
                    solutions.add((min(start, end), max(start, end)))
                    passageways_to_create -= 1

        print(len(solutions))



