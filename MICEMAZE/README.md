# MICEMAZE - Mice and Maze

[MICEMAZE on spoj.com](https://www.spoj.com/problems/MICEMAZE/)

The task is: Compute the travel time (cost) of the shortest path from every cell to the exit cell and output the number of travel times, which are lower than the maximum travel time.

The graph has at most 100 vertices (cells). This means there are at most 9900 connections (edges). There is a generous time and memory limit on this task, so an adjacency matrix (two-dimensional array) representing the graph should be sufficient. 

*Dijkstra's algorithm* will be used to compute the shortest path costs. The exit cell will be used as the starting point. The edges though have to be reversed. From there all other cells will be visited. Again, an array holding the shortest path estimates should be efficient enough in respect to running time. 

Make some input files and run the program against it. Compare the results:

```sh
$ python make_input.py
$ cat _input.txt | go run main.go
<some_result>
$ cat _res.txt
<correct_result>
```
