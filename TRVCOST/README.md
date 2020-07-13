# TRVCOST - Travelling cost

number of locations 0,1,..500
roads between pairs of location(say A and B ) cost for travelling between locations W
find minimum cost from location U (source) to Q number of other locations (destination).

Input

N : number of roads 
A B W : N line contains three integers, road from A to B with W fixed cost from A to B or from B to A
U : source
Q : the number of queries (finding cost) that he wants to perform.
V : Q lines (destination) for which minimum cost is to be found from U.

0<=A,B<=500
1<=W<=100
1<=N<=500
0<=U,V<=500
1<=Q<=500

Output
Print the required answer in each line or 'NO PATH' without quotes

Example

Input:
7
0 1 4
0 3 8
1 4 1
1 2 2
4 2 3
2 5 3
3 4 2
0
4
1
4
5
7

Output:
4
5
9
NO PATH

## Solution

The task is to enumerate shortest paths between a source and other nodes.

*Dijkstra's algorithm* with a *priority queue* will be used. This should be fairly overkill.

## Golang solution

```sh
$ cat sample_input.txt | go run main.go
```
