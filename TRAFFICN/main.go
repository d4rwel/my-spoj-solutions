package main

import (
	"bufio"
	"container/heap"
	"flag"
	"fmt"
	"log"
	"math"
	"os"
	"runtime/pprof"
)

var (
	reader     *bufio.Reader = bufio.NewReader(os.Stdin)
	writer     *bufio.Writer = bufio.NewWriter(os.Stdout)
	cpuprofile               = flag.String("cpuprofile", "", "write cpu profile to `file`")
)

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
	from   int
	to     int
	weight int
}

type Node struct {
	graphIndex         int
	adjList            []*Edge
	dist               int
	reachableFromStart bool
	heapIndex          int
}

type Graph struct {
	spStart  ShortestPathLengths
	spTarget ShortestPathLengths
	nodes    []*Node
}

func NewGraph(numNodes int) *Graph {
	return &Graph{
		nodes: make([]*Node, numNodes),
	}
}

func (g *Graph) AddNode(index int) {
	g.nodes[index] = &Node{
		graphIndex: index,
	}
}

func (g *Graph) AddEdge(from, to, weight int) {
	g.nodes[from].adjList = append(g.nodes[from].adjList, &Edge{
		from:   from,
		to:     to,
		weight: weight,
	})
}

func (g *Graph) dijkstra(start int) {
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
				queue.update(g.nodes[e.to], u.dist+e.weight)
			}
		}
	}
}

type ShortestPathLengths struct {
	from      int
	dist      []int
	reachable []bool
}

func (g *Graph) getShortestPathLengths(startIndex int) ShortestPathLengths {
	g.dijkstra(startIndex)
	lengths := make([]int, len(g.nodes))
	reachableFromStart := make([]bool, len(g.nodes))
	for index, node := range g.nodes {
		lengths[index] = node.dist
		if node.dist < math.MaxInt32 {
			reachableFromStart[index] = true
		}
	}
	return ShortestPathLengths{
		from:      startIndex,
		dist:      lengths,
		reachable: reachableFromStart,
	}
}

func (g *Graph) getShortestPathLengthWithNewEdge(e *Edge) int {
	if g.spStart.reachable[g.spTarget.from] && g.spStart.reachable[e.to] && g.spStart.reachable[e.from] {
		minFromStart := 0
		minFromTarget := 0
		if g.spStart.dist[e.to] < g.spStart.dist[e.from] {
			minFromStart = g.spStart.dist[e.to]
		} else {
			minFromStart = g.spStart.dist[e.from]
		}
		if g.spTarget.dist[e.to] < g.spTarget.dist[e.from] {
			minFromTarget = g.spTarget.dist[e.to]
		} else {
			minFromTarget = g.spTarget.dist[e.from]
		}
		return e.weight + minFromStart + minFromTarget
	} else if g.spStart.reachable[e.to] && g.spTarget.reachable[e.from] {
		return e.weight + g.spStart.dist[e.to] + g.spTarget.dist[e.from]
	} else if g.spStart.reachable[e.from] && g.spTarget.reachable[e.to] {
		return e.weight + g.spStart.dist[e.from] + g.spTarget.dist[e.to]
	}
	return math.MaxInt32
}

func main() {
	flag.Parse()
	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal("could not create CPU profile: ", err)
		}
		defer f.Close() // error handling omitted for example
		if err := pprof.StartCPUProfile(f); err != nil {
			log.Fatal("could not start CPU profile: ", err)
		}
		defer pprof.StopCPUProfile()
	}

	defer writer.Flush()

	var numTests int
	scanf("%d\n", &numTests)
	for i := 0; i < numTests; i++ {
		var (
			numNodes       int
			numEdges       int
			numTwoWayEdges int
			startIndex     int
			targetIndex    int
			from           int
			to             int
			weight         int
		)
		scanf("%d %d %d %d %d\n", &numNodes, &numEdges, &numTwoWayEdges, &startIndex, &targetIndex)
		startIndex--
		targetIndex--
		graph := NewGraph(numNodes)
		reversedGraph := NewGraph(numNodes)
		for j := 0; j < numNodes; j++ {
			graph.AddNode(j)
			reversedGraph.AddNode(j)
		}
		for j := 0; j < numEdges; j++ {
			scanf("%d %d %d\n", &from, &to, &weight)
			from--
			to--
			graph.AddEdge(from, to, weight)
			reversedGraph.AddEdge(to, from, weight)
		}
		graph.spStart = graph.getShortestPathLengths(startIndex)
		spLengths := make([]int, numTwoWayEdges+1)
		spLengths[0] = graph.spStart.dist[targetIndex]
		graph.spTarget = reversedGraph.getShortestPathLengths(targetIndex)
		for j := 0; j < numTwoWayEdges; j++ {
			scanf("%d %d %d\n", &from, &to, &weight)
			from--
			to--
			shortcut := &Edge{
				from:   from,
				to:     to,
				weight: weight,
			}
			spLengths[j+1] = graph.getShortestPathLengthWithNewEdge(shortcut)
		}
		minimum := spLengths[0]
		for _, val := range spLengths {
			if val < minimum {
				minimum = val
			}
		}
		if minimum == math.MaxInt32 {
			minimum = -1
		}
		printf("%d\n", minimum)
	}
}
