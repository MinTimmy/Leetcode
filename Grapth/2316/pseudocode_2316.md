# Peseudocode
[problem link](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)
[answer link](https://zxi.mytechroad.com/blog/category/graph/)

```
procedure Solution_1(n, G) {
    Input:  Graph G = (V, E), undirected; vertex v ∈ V; n is the number of vertex in G
    Output: the number of pairs of different nodes that are unreachable from rach other

    g = [[], [], ... , []] (list containing n lists)
    for all edges(u, w) ∈ E:
        g[u].push_back(w)
        g[w].push_back(u)
    seen = [0,0, ... ,0] (list containing n 0s)
    ans = 0
    counter = 0 (Global Variable)

    for i=0 upon n:
        if(seen[i]++) continue
        counter = 0
        dfs(i)
        ans += (n-counter) * counter
    ans /= 2
}

procedure dfs(v){
    Input: v is the vertex of the graph.
    Output: how many vertexes it can travel from vertex v.

    counter++;
    for all edges(v, u) in E:
        if(seen[u]++ == 0) dfs(u)
}
```


$x \in A$
