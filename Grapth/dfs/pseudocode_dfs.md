```pseudocode
procedure explore(G, v)
    Input:  G = (V, E) is a graph; v ∈ V
    Output: visited(u) is set to true for all nodes u reachable from v
    
    visited(v) = true
    previsit(v)
    for each edge (u, v) ∈ E:
        if not visited(u): explore(u)
    postvisit(v)

procedure previsit(v)
    pre[v] = clock
    clock = clock + 1

procedure postvisit(v)
    post[v] = clock
    clock = clock + 1

procedure dfs(G)
    for all v ∈ V:
        visited(v) = false
    
    for all v ∈ V:
        if not visited(v): explore(v)
```