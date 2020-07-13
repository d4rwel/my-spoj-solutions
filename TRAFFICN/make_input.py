#!/usr/bin/env python3
import random
import networkx as nx
import matplotlib.pyplot as plt

# running time with default config on 1 core of Intel i5 4650K: ~ 10 mins

numTests = 20  # 1 ≤ numTests ≤ 20
r = open('_res.txt', 'x')
f = open('_input.txt', 'x')
f.write('{}\n'.format(numTests))
for _ in range(numTests):
    numNodes = 10000  # n ≤ 10000 : number of nodes
    # probability controls the number of edges
    probability = 9 / numNodes  # default 9 / numNodes
    numShortcuts = 299  # k < 300 : number of lines (uj vj qj)
    maxWeight = 1000  # default 1000
    s = random.randint(0, numNodes-1)  # 1 ≤ s ≤ n : starting node t = random.randint(0, numNodes-1)  # 1 ≤ t ≤ n : target node

    G = nx.fast_gnp_random_graph(numNodes, probability, directed=True)
    # G = nx.barabasi_albert_graph(numNodes, 1)
    # G = nx.to_directed(G)
    for (u, v) in G.edges():
        li = random.randint(1, maxWeight)  # 0 < li ≤ 1000 : length di to ci
        G.edges[u, v]['weight'] = li

    shortcuts = list()
    for _ in range(numShortcuts):
        uj, vj = random.sample(range(0, numNodes), 2)
        qj = random.randint(1, maxWeight)  # 0 < qj ≤ 1000 : length uj to vj
        shortcuts.append((uj, vj, qj))

    shortest_paths = list()
    for (u, v, w) in shortcuts:
        H = G.copy()
        try:
            H.remove_edge(u, v)
        except nx.NetworkXError:
            pass
        try:
            H.remove_edge(v, u)
        except nx.NetworkXError:
            pass
        H.add_edge(u, v, weight=w)
        H.add_edge(v, u, weight=w)
        try:
            sslen = nx.shortest_path_length(
                    H, source=s, target=t, weight='weight')
            shortest_paths.append(sslen)
        except nx.NetworkXNoPath:
            pass
    if len(shortest_paths) > 0:
        r.write('{}\n'.format(min(shortest_paths)))
    else:
        r.write('{}\n'.format(-1))

    numEdges = nx.number_of_edges(G)  # m ≤ 100000 : number of lines (di ci li)
    f.write('{} {} {} {} {}\n'.format(
        numNodes, numEdges, numShortcuts, s+1, t+1))
    for (u, v) in G.edges():
        f.write('{} {} {}\n'.format(u+1, v+1, G.edges[u, v]['weight']))
    for (u, v, w) in shortcuts:
        f.write('{} {} {}\n'.format(u+1, v+1, w))

f.close()
r.close()
