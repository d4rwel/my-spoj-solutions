#!/usr/bin/env python3
import networkx as nx
import random

min_edge_weight = 1
max_edge_weight = 5
grid_length = 10
num_vertices = grid_length*grid_length

G = nx.grid_2d_graph(grid_length, grid_length)
G = G.to_directed()
G = nx.convert_node_labels_to_integers(G)
for (u, v) in G.edges():
    G.edges[u, v]['weight'] = random.randint(min_edge_weight, max_edge_weight)

exit = random.randint(1, num_vertices-1)
shortest_paths = nx.shortest_path_length(G.reverse(), exit-1, weight='weight')
shortest_paths = shortest_paths.values()
print(shortest_paths)
timer = random.randint(1, max(shortest_paths))
result = 0
for shortest_path in shortest_paths:
    if shortest_path <= timer:
        result += 1

f = open('_input.txt', 'x')
f.write('{}\n'.format(num_vertices))
f.write('{}\n'.format(exit))
f.write('{}\n'.format(timer))
f.write('{}\n'.format(len(G.edges())))
for (u, v) in G.edges():
    f.write('{} {} {}\n'.format(u+1, v+1, G.edges[u, v]['weight']))
f.close()

f = open('_result.txt', 'x')
f.write('{}\n'.format(result))
