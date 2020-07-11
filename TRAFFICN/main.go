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

const (
	debug   = false
	profile = true
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to `file`")

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

type Edge struct {
	from   int
	to     int
	weight int
}

type Node struct {
	graphIndex int
	adjList    map[int]int
	distance   int
	heapIndex  int
}

type Graph struct {
	nodes []*Node
}

func NewGraph(numNodes int) *Graph {
	return &Graph{
		nodes: make([]*Node, numNodes),
	}
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

func (g *Graph) RemoveEdge(from, to int) *Edge {
	if weight, ok := g.nodes[from].adjList[to]; ok {
		delete(g.nodes[from].adjList, to)
		return &Edge{
			from:   from,
			to:     to,
			weight: weight,
		}
	}
	return nil
}

func (g *Graph) AddShortcut(s *Edge) (*Edge, *Edge) {
	road := g.RemoveEdge(s.from, s.to)
	if road == nil || road.weight > s.weight {
		g.AddEdge(s.from, s.to, s.weight)
	} else {
		g.AddEdge(road.from, road.to, road.weight)
	}
	roadBack := g.RemoveEdge(s.to, s.from)
	if roadBack == nil || roadBack.weight > s.weight {
		g.AddEdge(s.to, s.from, s.weight)
	} else {
		g.AddEdge(roadBack.from, roadBack.to, roadBack.weight)
	}
	return road, roadBack
}

func (g *Graph) RemoveShortcut(shortcut, road, roadBack *Edge) {
	delete(g.nodes[shortcut.from].adjList, shortcut.to)
	if road != nil {
		g.AddEdge(road.from, road.to, road.weight)
	}
	delete(g.nodes[shortcut.to].adjList, shortcut.from)
	if roadBack != nil {
		g.AddEdge(roadBack.from, roadBack.to, roadBack.weight)
	}
}

func (g *Graph) Print() {
	for startIndex, startNode := range g.nodes {
		for endIndex, weight := range startNode.adjList {
			fmt.Printf("[%d] --%d--> [%d]\n", startIndex+1, weight, endIndex+1)
		}
	}
}

type MinPriorityQueue []*Node

func (mpq MinPriorityQueue) Len() int { return len(mpq) }

func (mpq MinPriorityQueue) Less(i, j int) bool {
	return mpq[i].distance < mpq[j].distance
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
	node.distance = newEstimate
	heap.Fix(mpq, node.heapIndex)
}

func dijkstra(graph *Graph, start, target int) int {
	queue := make(MinPriorityQueue, len(graph.nodes))
	i := 0
	for _, node := range graph.nodes {
		node.distance = math.MaxInt32
		node.heapIndex = i
		queue[i] = node
		i++
	}
	heap.Init(&queue)
	queue.update(graph.nodes[start], 0)
	for queue.Len() > 0 {
		u := heap.Pop(&queue).(*Node)
		for to, weight := range u.adjList {
			v := graph.nodes[to]
			if v.distance > u.distance+weight {
				queue.update(graph.nodes[to], u.distance+weight)
			}
		}
		if u == graph.nodes[target] {
			return u.distance
		}
	}
	return 42
}

func main() {
	var (
		numTests      int
		numNodes      int
		numEdges      int
		numShortcuts  int
		startingNode  int
		targetNode    int
		from          int
		to            int
		weight        int
		minimum       int
		shortestPaths []int
		graph         *Graph
	)

	if profile {
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
	}

	defer writer.Flush()

	scanf("%d\n", &numTests)
	for i := 0; i < numTests; i++ {
		scanf("%d %d %d %d %d\n", &numNodes, &numEdges, &numShortcuts, &startingNode, &targetNode)
		startingNode--
		targetNode--
		graph = NewGraph(numNodes)
		for j := 0; j < numNodes; j++ {
			graph.AddNode(j)
		}
		for j := 0; j < numEdges; j++ {
			scanf("%d %d %d\n", &from, &to, &weight)
			from--
			to--
			graph.AddEdge(from, to, weight)
		}
		if debug {
			graph.Print()
		}
		shortestPaths = make([]int, numShortcuts)
		for j := 0; j < numShortcuts; j++ {
			scanf("%d %d %d\n", &from, &to, &weight)
			from--
			to--
			s := &Edge{
				from:   from,
				to:     to,
				weight: weight,
			}
			a, b := graph.AddShortcut(s)
			//TODO do dijkstra
			result := dijkstra(graph, startingNode, targetNode)
			if debug {
				graph.Print()
				fmt.Println(result)
			}
			shortestPaths[j] = result
			graph.RemoveShortcut(s, a, b)
		}
		minimum = shortestPaths[0]
		for _, val := range shortestPaths {
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
