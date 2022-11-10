#Pesudocode

[problem link](https://leetcode.com/problems/node-with-highest-edge-score/)
[answer link](https://zxi.mytechroad.com/blog/category/graph/)

```
procedure Solution(G)
    Input:  Graph G = (V, E), directed; vertex v ∈ V.
    Output: Return the node with the highest edge score.

    n is the number vertex in V
    s = [0,0, ... ,0] (list containing n 0s) 

    for all edges(v, u) in G:
        g[v] += u
    
    return max_element(g)
```