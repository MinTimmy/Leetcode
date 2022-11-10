<ins> procedure explore </ins> (G, v)
&emsp; Input:  **G = (V, E)** is a graph; **v** $\in$ **V**
&emsp; Output: **visited(u)** is set to true for all nodes **u** reachable from **v**.
    
visited(v) = true
previsit(v)
for each edge (u, v) ∈ E:
&emsp; if not visited(u): explore(u)
postvisit(v)

---

<ins> procedure previsit</ins>(v)
&emsp; pre[v] = clock
&emsp; clock = clock + 1

---
<ins> procedure postvisit</ins>(v)
&emsp; post[v] = clock
&emsp; clock = clock + 1

---
<ins> procedure dfs</ins>(G)
for all v ∈ V:
&emsp; visited(v) = false
    
for all v ∈ V:
&emsp; if not visited(v): explore(v)