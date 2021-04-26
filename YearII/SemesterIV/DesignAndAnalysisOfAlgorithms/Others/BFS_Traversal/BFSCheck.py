from collections import deque

def addEdge(adj: list, u, v):
	adj[u].append(v)
	adj[v].append(u)

def bfsCheckCycle(adj: list, s, v, visited: list):
  parent = [-1] * v

  q = deque()
  visited[s] = True
  q.append(s)

  while q != []:
    u = q.pop()
    for v in adj[u]:
      if not visited[v]:
        visited[v] = True
        q.append(v)
        parent[v] = u
      elif parent[u] != v:
        return True
  return False

def cycleCheck(adj: list, V):

	visited = [False] * V

	for i in range(V):
		if not visited[i] and bfsCheckCycle(adj, i, V, visited):
			return True
	return False

if __name__ == "__main__":
	V = 5
	adj = [[] for i in range(V)]
	addEdge(adj, 0, 1)
	addEdge(adj, 1, 3)
	addEdge(adj, 3, 4)
	addEdge(adj, 4, 2)
	addEdge(adj, 2, 0)
	
	if cycleCheck(adj, V):
		print("Yes! There is cycle.")
	else:
		print("No! There is no cycle.")