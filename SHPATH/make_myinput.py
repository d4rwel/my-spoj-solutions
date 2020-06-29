#!/usr/bin/env python3
import random
import string
import networkx as nx

s = 5
n = 10
r = 2
max_weight = 10
f = open('my_input.txt', 'x')
res = open('my_res.txt', 'x')
f.write('{}\n'.format(s))
for _ in range(s):
    f.write('{}\n'.format(n))
    # create random graph
    G = nx.barabasi_albert_graph(n, 2)
    for (u, v) in G.edges():
        G.edges[u, v]['weight'] = random.randint(0, max_weight)
    letters = string.ascii_lowercase
    for n in G.nodes():
        G.nodes[n]['name'] = ''.join(random.choice(letters) for _ in range(10))
    G = nx.to_directed(G)
    # nx.draw(G)
    # plt.show()
    # print graph
    for n in G.nodes():
        f.write('{}\n'.format(G.nodes[n]['name']))
        f.write('{}\n'.format(len(list(G[n]))))
        for neighbor in G[n]:
            f.write('{} {}\n'.format(
                neighbor+1, G.edges[n, neighbor]['weight']))
    f.write('{}\n'.format(r))
    for _ in range(r):
        src, dst = random.sample(range(0, n-1), 2)
        f.write('{} {}\n'.format(G.nodes[src]['name'], G.nodes[dst]['name']))
        res.write('{}\n'.format(nx.shortest_path_length(
            G, src, dst, 'weight')))
    f.write('\n')

f.close()
res.close()
