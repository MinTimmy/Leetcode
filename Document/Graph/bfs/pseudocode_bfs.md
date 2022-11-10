<ins> procedure bfs</ins>(G, s)
Input: Graph **G = (V, E)**, directed or underected; vertex  **s $\in$ V**
Output: For all vertices **u** reachable from **s**, **dist(u)** is set to the distance from **s** to **u**.

for all u$\in$V
&emsp; dist(u) = $\infty$

dist(s) = 0
Q = [s] (queue containing just s)
while Q is not empty:
&emsp; u = eject(Q)
&emsp; for all edges (u, v) $\in$ E
&emsp; &emsp; if dist(v) = $\infty$:
&emsp; &emsp; &emsp; inject(Q, v)
&emsp; &emsp; &emsp; dist(v) = dist(u) + 1