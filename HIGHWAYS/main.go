package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

type MinPriorityQueue []*Node

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
	node := x.(*Node)
	node.heapIndex = n
	*mpq = append(*mpq, node)
}

func (mpq *MinPriorityQueue) Pop() interface{} {
	old := *mpq
	n := len(old)
	node := old[n-1]
	old[n-1] = nil
	node.heapIndex = -1
	*mpq = old[0 : n-1]
	return node
}

func (mpq *MinPriorityQueue) update(node *Node, newEstimate int) {
	node.dist = newEstimate
	heap.Fix(mpq, node.heapIndex)
}

type Edge struct {
	to     int
	weight int
}

type Node struct {
	graphIndex int
	adjList    []*Edge
	dist       int
	heapIndex  int
}

type Graph struct {
	nodes []*Node
}

func NewGraph(numNodes int) *Graph {
	g := &Graph{
		nodes: make([]*Node, numNodes),
	}
	for i := 0; i < numNodes; i++ {
		g.AddNode(i)
	}
	return g
}

func (g *Graph) AddNode(index int) {
	g.nodes[index] = &Node{
		graphIndex: index,
	}
}

func (g *Graph) AddEdge(from, to, weight int) {
	g.nodes[from].adjList = append(g.nodes[from].adjList, &Edge{
		to:     to,
		weight: weight,
	})
}

func (g *Graph) dijkstra(start, end int) int {
	queue := make(MinPriorityQueue, len(g.nodes))
	i := 0
	for _, node := range g.nodes {
		node.dist = math.MaxInt32
		node.heapIndex = i
		queue[i] = node
		i++
	}
	heap.Init(&queue)
	queue.update(g.nodes[start], 0)
	for queue.Len() > 0 {
		u := heap.Pop(&queue).(*Node)
		for _, e := range u.adjList {
			v := g.nodes[e.to]
			if v.dist > u.dist+e.weight {
				queue.update(v, u.dist+e.weight)
			}
		}
		if u == g.nodes[end] {
			return u.dist
		}
	}
	return 42 // not reached
}

func main() {
	var (
		numTestcases        int
		numCities           int
		numHighways         int
		start, end, A, B, t int
	)
	defer writer.Flush()
	scanf("%d\n", &numTestcases)
	for i := 0; i < numTestcases; i++ {
		scanf("%d %d %d %d\n", &numCities, &numHighways, &start, &end)
		start--
		end--
		graph := NewGraph(numCities)
		for j := 0; j < numHighways; j++ {
			scanf("%d %d %d\n", &A, &B, &t)
			A--
			B--
			graph.AddEdge(A, B, t)
			graph.AddEdge(B, A, t)
		}
		result := graph.dijkstra(start, end)
		if result == math.MaxInt32 {
			printf("NONE\n")
		} else {
			printf("%d\n", result)
		}
	}
}
