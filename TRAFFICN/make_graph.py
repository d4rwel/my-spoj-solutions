import networkx as nx
import matplotlib.pyplot as plt

drawTestCase = 10  # 1 is the first test case
target = 0
start = 0
shortcuts = []
G = nx.Graph()
with open('_input.txt') as f:
    numTests = int(f.readline())
    for testCase in range(numTests):
        n, m, k, s, t = [int(x) for x in f.readline().split()]
        if testCase+1 == drawTestCase:
            G.add_nodes_from(range(1, n+1))
            print('{} nodes in G'.format(m))
            start = s
            target = t
        for _ in range(m):
            fromIdx, toIdx, weight = [int(x) for x in f.readline().split()]
            if testCase+1 == drawTestCase:
                G.add_edge(fromIdx, toIdx, weight=weight)
        for _ in range(k):
            fromIdx, toIdx, weight = [int(x) for x in f.readline().split()]
            if testCase+1 == drawTestCase:
                shortcuts.append((fromIdx, toIdx))

print('Path from {} to {}: {}'.format(
    start, target, nx.has_path(G, start, target)))
print('Shortest path from {} to {}: {}'.format(
    start, target, nx.shortest_path_length(G, start, target, weight='weight')))
spNodes = nx.shortest_path(G, start, target, weight='weight')
spEdges = set(zip(spNodes, spNodes[1:]))
spNodes = spNodes[1:-1]
pos = nx.circular_layout(G)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw(G, pos, with_labels=True)
nx.draw_networkx_nodes(G, pos, nodelist=[start], node_color="green")
nx.draw_networkx_nodes(G, pos, nodelist=[target], node_color="red")
nx.draw_networkx_nodes(G, pos, nodelist=spNodes, node_color="yellow")
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
nx.draw_networkx_edges(G, pos, edgelist=spEdges, edge_color="yellow")
nx.draw_networkx_edges(G, pos, edgelist=shortcuts, edge_color="blue")
plt.show()
