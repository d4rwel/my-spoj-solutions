package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
)

func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func dijkstra(g [][]int, start int) []int {

	numVertices := len(g)
	dist := make([]int, numVertices)
	visited := make([]bool, numVertices)

	for i := 0; i < numVertices; i++ {
		dist[i] = math.MaxInt32
		visited[i] = false
	}
	dist[start] = 0
	for i := 0; i < numVertices-1; i++ {
		min := math.MaxInt32
		u := -1
		for j := 0; j < numVertices; j++ {
			if visited[j] == false && dist[j] <= min {
				min = dist[j]
				u = j
			}
		}
		visited[u] = true
		for v := 0; v < numVertices; v++ {
			if !visited[v] && g[u][v] != 0 && dist[u] != math.MaxInt32 && dist[u]+g[u][v] < dist[v] {
				dist[v] = dist[u] + g[u][v]
			}
		}
	}
	return dist
}

func main() {
	var (
		numCells       int
		exit           int
		timer          int
		numConnections int
		from           int
		to             int
		cost           int
		miceOnTime     int
	)
	scanf("%d\n", &numCells)
	scanf("%d\n", &exit)
	exit--
	scanf("%d\n", &timer)
	scanf("%d\n", &numConnections)
	graph := make([][]int, numCells)
	for i := range graph {
		graph[i] = make([]int, numCells)
	}
	for i := 0; i < numConnections; i++ {
		scanf("%d %d %d\n", &from, &to, &cost)
		from--
		to--
		// reverse edges
		graph[to][from] = cost
	}
	shortestPaths := dijkstra(graph, exit)
	sort.Ints(shortestPaths)
	for _, mouseTime := range shortestPaths {
		if mouseTime <= timer {
			miceOnTime++
		}
	}
	fmt.Println(miceOnTime)
}
