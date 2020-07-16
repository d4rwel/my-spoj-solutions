package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

type Vertex struct {
	graphIndex int
	dist       int
	heapIndex  int
}

type Edge struct {
	cost int
	to   int
}

type Graph struct {
	vertices []*Vertex
	names    map[string]int // vertices["gdansk"] = 1
	adjList  [][]*Edge
}

func NewGraph(numVertices int) *Graph {
	return &Graph{
		vertices: make([]*Vertex, numVertices),
		names:    make(map[string]int),
		adjList:  make([][]*Edge, numVertices),
	}
}

func (g *Graph) AddVertex(index int, cityName string) {
	v := Vertex{graphIndex: index}
	g.names[cityName] = index
	g.vertices[index] = &v
}

func (g *Graph) GetGraphIndex(cityName string) int {
	return g.names[cityName]
}

:type MinPriorityQueue []*Vertex

func (mpq MinPriorityQueue) Len() int { return len(mpq) }

func (mpq MinPriorityQueue) Less(i, j int) bool {
	return mpq[i].dist < mpq[j].dist
}

func (mpq MinPriorityQueue) Swap(i, j int) {
	mpq[i], mpq[j] = mpq[j], mpq[i]
	mpq[i].heapIndex = i
	mpq[j].heapIndex = j
}

func (mpq *MinPriorityQueue) Push(x interface{}) {
	n := len(*mpq)
	vertex := x.(*Vertex)
	vertex.heapIndex = n
	*mpq = append(*mpq, vertex)
}

func (mpq *MinPriorityQueue) Pop() interface{} {
	old := *mpq
	n := len(old)
	vertex := old[n-1]
	old[n-1] = nil
	vertex.heapIndex = -1
	*mpq = old[0 : n-1]
	return vertex
}

func (mpq *MinPriorityQueue) update(vertex *Vertex, newEstimate int) {
	vertex.dist = newEstimate
	heap.Fix(mpq, vertex.heapIndex)
}

func dijkstra(g *Graph, start, end int) int {
	q := make(MinPriorityQueue, len(g.vertices))
	i := 0
	for _, vertex := range g.vertices {
		vertex.dist = 200000
		vertex.heapIndex = i
		q[i] = vertex
		i++
	}
	heap.Init(&q)
	q.update(g.vertices[start], 0)
	for q.Len() > 0 {
		u := heap.Pop(&q).(*Vertex)
		for _, edge := range g.adjList[u.graphIndex] {
			v := g.vertices[edge.to]
			if v.dist > u.dist+edge.cost {
				q.update(g.vertices[v.graphIndex], u.dist+edge.cost)
			}
		}
		if u == g.vertices[end] {
			return u.dist
		}
	}
	return 42
}

func main() {

	defer writer.Flush()

	var (
		numTestCases  int
		numCities     int
		cityName      string
		numNeighbours int
		neighbourCity int
		transportCost int
		numPaths      int
		srcCity       string
		dstCity       string
	)

	scanf("%d\n", &numTestCases)
	for testCase := 0; testCase < numTestCases; testCase++ {
		scanf("%d\n", &numCities)
		graph := NewGraph(numCities)
		for currCity := 0; currCity < numCities; currCity++ {
			scanf("%s\n", &cityName)
			graph.AddVertex(currCity, cityName)
			scanf("%d\n", &numNeighbours)
			graph.adjList[currCity] = make([]*Edge, numNeighbours)
			for i := 0; i < numNeighbours; i++ {
				scanf("%d %d\n", &neighbourCity, &transportCost)
				e := Edge{transportCost, neighbourCity - 1}
				graph.adjList[currCity][i] = &e
			}
		}
		scanf("%d\n", &numPaths)
		for i := 0; i < numPaths; i++ {
			scanf("%s %s\n", &srcCity, &dstCity)
			printf("%d\n", dijkstra(graph, graph.GetGraphIndex(srcCity), graph.GetGraphIndex(dstCity)))
		}
		scanf("\n")
	}
}
