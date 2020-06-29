# SHPATH - The Shortest PATH

[SHPATH on spoj.com](https://www.spoj.com/problems/SHPATH/)

## Solution

The task is to calculate the minimum transportation cost between two cities. This is a *Single-pair shortest path* problem. There are no negative weighted edges, so *Dijkstra's algorithm* will be used (see chapter 24.3, Introduction to Algorithms).

The algorithm will be aborted as soon as the target city has been visited.

The shortest path does not have to be displayed, so the predecessors will be ignored in this version.

```
DIJKSTRA(G,w,s,e):
    INITIALIZE-SINGLE-PATH(G,s)
    Q = G.V
    while Q != {}
        u = EXTRACT-MIN(Q)
        for each vertex v in G.Adj[u]
            RELAX(u,v,w)
        if u == e
            return u.d

INITIALIZE-SINGLE-SOURCE(G,s):
    for each vertex v in G.V
        v.d = 200000
    s.d = 0

RELAX(u,v,w):
    if v.d > u.d + w(u, v)
        v.d = u.d + w(u, v) \\ DECREASE-KEY()
```

Assuming most of the cities are not directly connected, the graph will be sparse. So an *adjacency list* will be used for the graph data structure to save memory space. The edge costs will be stored in this list too.

`DIJKSTRA()` repeatedly selects a minimum shortest-path estimate from a data structure (`EXTRACT-MIN()`). It is almost a sure bet to assume, that an array with an O(n)-running time won't be sufficient for this SPOJ task. Hence a *min-priority queue* with an O(log(n))-running time for `EXTRACT-MIN()` and `DECREASE-KEY()` will be used.

To summarize, following will be implemented:

* *Dijkstra's algorithm*
* a *min-priority queue* (ch 6.5, Introduction to Algorithms)
* an *adjacency list*

## Profiling in Go

The Go implementation exceeded the time limit. To investigate, a profiling instrument with `pprof` was implemented. Display a call graph with running times in your browser:

```sh
$ python make-myinput.py
$ go build main.go
$ cat my_inptut.txt | ./main -cpuprofile cpu.prof
$ go tool pprof cpu.prof
(pprof) web
```

It turned out, that `fmt.Scan()` was using about 90% of the running time for syscalls. After using a buffered scanner with `bufio` the implementation passed.
