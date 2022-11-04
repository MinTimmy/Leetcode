# Peseudocode
[problem link](...)
[answer link](https://stackoverflow.com/questions/40569424/breadth-first-tree)

```
public Node breadthFirst(Node T, Node searchNode){
  Queue queue = new Queue();
  queue.queue(T);

  while (!queue.isEmpty()) {
    Node curNode = queue.dequeue();
    if (curNode == null) continue;

    if (curNode.value().equals(searchNode.value()) {
      return curNode;
    }

    queue.queue(curNode.left);
    queue.queue(curNode.right);
  } 

  return null; //or throw exception not found
}
```


$x \in A$
