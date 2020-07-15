# HIGHWAYS

[HIGHWAYS on spoj.com](https://www.spoj.com/problems/HIGHWAYS/)

* number of cities are connected by a network of highways
* Each highway is bidirectional and connects two cities, with a given travel time
* Task: What is the shortest time to get from a given city to another given city?

Input

numTestcases
n m start end
A B 

* number of cities n (2 ≤ n ≤ 100000)
* the number of highways m (1 ≤ m ≤ 100000)
* s = starting city
* e = ending city
* Cities are numbered from 1 to n.
* A = city
* B = another city
* t = time in minutes to travel along the highway (1 <= t <= 1000)

Output

* single line per test case containing minimum time from start to end
* no connection: 'NONE'

## Solution

Easy application of *dijkstra's algorithm* with a *priority queue*.
