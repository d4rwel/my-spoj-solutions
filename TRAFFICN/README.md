# TRAFFICN - Traffic Network

[TRAFFICN on SPOJ.com](https://www.spoj.com/problems/TRAFFICN/)

* network consists of n nodes
* m one-way roads connecting pairs of nodes 
* to reduce the length of the shortest path between two different critical nodes s and t, a list of k two-way roads are proposed as candidates to be constructed
* task is to write a program to choose one two-way road from the proposed list in order to minimize the resulting shortest path between s and t.

Input

numTests
n m k s t
di ci li
uj vj qj

1 ≤ numTests ≤ 20
n ≤ 10000 : number of nodes
m ≤ 100000 : number of lines (di ci li)
k < 300 : number of lines (uj vj qj)
1 ≤ s ≤ n : starting node
1 ≤ t ≤ n : target node
0 < li ≤ 1000 : length of ith one-way road from node di to ci
0 < qj ≤ 1000 : two-way road length qj connecting node uj to vj.

Output

For each data set, write on one line the smallest possible length of the shortest path after building the chosen one two-way road from the proposed list. In case, there does not exist a path from s to t, write -1.

```
Sample Input
1
4 5 3 1 4
1 2 13
2 3 19
3 1 25
3 4 17
4 1 18
1 3 23
2 3 5
2 4 25	

Sample Output
35
```

## Solution

The task is to calculate a shortest path from s to t for every shortcut (two-way road), and pick the minimum of these shortest paths.

To solve this, first all shortest path from starting node to all other nodes and all shortest paths (with the reversed graph) from target node to all other nodes get calculated. This means the shortest path algorithm will be executed exactly 40 times. A shortcut then has to connect a node reachable from starting point and a node reachable from target node, creating a new path from starting node to target node. This new path is a possible new shortest path between those nodes. To calculate the length of this new path, there are three cases:

1. Starting node and target node are not connected without shortcut. The beginning of the shortcut is reachable from starting node, and the ending of the shortcut is reachable from target node. The length of the new path is: `shortestpath(starting node, beginning of shortcut) + length of shortcut + shortestpath(target node, ending of shortcut)`.
2. Starting node and target node are not connected without shortcut. The beginning of the shortcut is reachable from target node, and the ending of the shortcut is reachable from beginning node. The length is: `shortestpath(target node, beginning of shortcut) + length of shortcut + shortestpath(starting node, ending of shortcut)`.
3. Starting node and target node are connected without shortcut. Beginning of shortcut and ending of shortcut are both reachable from starting node and target node. The length is then: `length of shortcut + minimum of(shortestpath(starting node, ending of shortcut), shortestpath(starting node, beginning of shortcut)) + minimum of(shortestpath(target node, ending of shortcut), shortestpath(target node, beginning of shortcut))`.

All other cases get dismissed, because starting node and target node are not connected.

To calculate the shortest path, *dijkstra's algorithm* with a *priority queue* will be used as the number of nodes can be high. The algorithm does not need to track the path.

The graph will be implemented as an *adjacency list*. The elements store only weight of edge and ending node.

## Golang solution

```sh
$ cat input.txt | go run main.go
```

Profile CPU running time:

```sh
$ go build main.go
$ cat input.txt | ./main -cpuprofile cpu.prof
$ go tool pprof cpu.prof
(pprof) top10
```

## Create random input

Tweak the numbers in the script before. If you want to create a big input like on SPOJ testing maching, you can go and make a coffee in between :)

```sh
$ python make_input.py
```
