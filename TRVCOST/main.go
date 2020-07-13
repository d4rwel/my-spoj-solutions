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

type Node struct {
	graphIndex int
	adjList    map[int]int // adjList[graphIndex] = weight
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
	for index, _ := range g.nodes {
		g.AddNode(index)
	}
	return g
}

func (g *Graph) AddNode(index int) {
	g.nodes[index] = &Node{
		graphIndex: index,
		adjList:    make(map[int]int),
	}
}

func (g *Graph) AddEdge(from, to, weight int) {
	g.nodes[from].adjList[to] = weight
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
		for to, weight := range u.adjList {
			v := g.nodes[to]
			if v.dist > u.dist+weight {
				queue.update(g.nodes[to], u.dist+weight)
			}
		}
		if u == g.nodes[end] {
			return u.dist
		}
	}
	return 42
}

func main() {
	defer writer.Flush()

	var (
		numRoads   int
		from       int
		to         int
		cost       int
		source     int
		target     int
		numQueries int
	)

	scanf("%d\n", &numRoads)
	graph := NewGraph(501)
	for i := 0; i < numRoads; i++ {
		scanf("%d %d %d\n", &from, &to, &cost)
		graph.AddEdge(from, to, cost)
		graph.AddEdge(to, from, cost)
	}
	scanf("%d\n", &source)
	scanf("%d\n", &numQueries)
	for i := 0; i < numQueries; i++ {
		scanf("%d\n", &target)
		result := graph.dijkstra(source, target)
		if result < math.MaxInt32 {
			printf("%d\n", result)
		} else {
			printf("NO PATH\n")
		}
	}

}
