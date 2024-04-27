# graph theory in python

import networkx as nx

import matplotlib.pyplot as plt

# G = nx.Graph()
# G = nx.DiGraph()
# G = nx.MultiGraph()
# G = nx.MultiDiGraph()

# G.add_edge(1, 2)
# G.add_edge(2, 3, weight = 0.9) 
# G.add_edge("A", "B")
# G.add_edge("B", "B")
# G.add_node("C")
# G.add_node(print)

# nx.draw_spring(G, with_labels = True)
# plt.show()

# topics in lecture 3
# graph

graph = nx.Graph()
graph.add_edge(1, 2)
graph.add_node(3)
graph.add_edge(3, 3)
nx.draw_spring(graph, with_labels = True)
plt.show()
# Explanation: 

# directed graph
digra = nx.DiGraph()
digra.add_edge("a", "b")
digra.add_edge("b", "c")
digra.add_edge("c", "a")
nx.draw(digra, with_labels = True)
plt.show()
# Explanation:

# simple graphs
simgra = nx.Graph()
simgra.add_edge("a", "b")
simgra.add_edge("b", "c")
simgra.add_edge("b", "d")
simgra.add_edge("c", "d")
nx.draw_spring(simgra, with_labels = True)
plt.show()
# Explanation:

# complete graphs
comgra = nx.complete_graph(5)
nx.draw_spring(comgra, with_labels = True)
plt.show()
# Explanation:

# bipartite graphs
bigra = nx.Graph()
setA = [1, 2, 3, 4]
setB = [7, 8, 9]
bigra.add_nodes_from(setA, bipartite = 0)
bigra.add_nodes_from(setB, bipartite = 1)

for nodeA in setA:
    for nodeB in setB:
        bigra.add_edge(nodeA,nodeB)
        
pos = {node: (0,i) for i, node in enumerate(setA)}
pos.update ({node: (1, i) for i, node in enumerate(setB)})

nx.draw_spring(bigra, with_labels = True)
plt.show()
# Explanation: 

# subgraphs
biggra = nx.Graph()
biggra.add_edge("a", "b")
biggra.add_edge("b", "c")
biggra.add_edge("b", "d")
biggra.add_edge("c", "d")
nx.draw(biggra, with_labels = True)
plt.show()

subgra = nx.Graph()
subgra.add_edge("b", "c")
subgra.add_edge("b", "d")
subgra.add_edge("c", "d")
nx.draw_spring(subgra, with_labels = True)
plt.show()
# Explanation: 


#Main graph 

g1 = nx.complete_graph(5)
g2 = nx.complete_graph(4)
g2 = nx.relabel_nodes(g2, {0: "A", 1: "B", 2: "C", 3: "D", 4: "E"})
exgra = nx.from_edgelist([(4, "X"), ("X", "A")])
G = nx.compose_all([g1, g2, exgra])
nx.draw_spring(G, with_labels = True)
plt.show()


# degree of vertex
print("Degree of each vertex: ")
print(dict(G.degree))
#Explanation: 

# handshake theorem
print("Twice number of edges: ")
print(nx.number_of_edges(G) * 2)
degrees = G.degree()
result = sum(deg for node, deg in degrees)
print("Sum of degrees of all vertices: ")
print(result)
#Explanation: 

# travelling in graph
print("\nTravelling in the main graph:")
#walk: 

for i in range(len(list(G.nodes()))):
    for j in range(i + 1, len(list(G.nodes()))):
        src = list(G.nodes())[i]
        dest = list(G.nodes())[j]
        if nx.has_path(G, src, dest):
            print(f"There is a path from {src} to {dest}.")
        else:
            print(f"There is no path from {src} to {dest}.")

walk = nx.shortest_path(G, src, dest)
#Explanation: 

#trail:
istrail = len(set(zip(walk, walk[1:]))) == len(walk) - 1
print(f"Is the walk from {src} to {dest} a trail?", is_trail)
#Explanation: 

#path:
is_path = len(set(walk)) == len(walk)
print(f"Is the walk from {src} to {dest} a path?", is_path)
#Explanation: 

#closed walk: 
is_closed_walk = walk[0] == walk[-1]
print(f"Is the walk from {src} to {dest} a closed walk?", is_closed_walk)
#Explanation: 

#circuit:
is_circuit = is_closed_walk and len(set(zip(walk, walk[1:]))) == len(walk) - 1
print(f"Is the walk from {src} to {dest} a circuit?", is_circuit)
#Explanation:
 
#simple circuit: 
is_simple_circuit = is_circuit and len(set(walk)) == len(walk) - 1
print(f"Is the walk from {src} to {dest} a simple circuit?", is_simple_circuit)
#Explanation:

# connectedness in graphs
if nx.connected_components(G):
    print("Graph is connected")
else: 
    print("Not connected")
#Explanation: 

# connected components
nx.draw(biggra, with_labels = True)
plt.show()
nx.draw(subgra, with_labels = True)
plt.show()

connect1 = list(nx.connected_components(biggra))
connect2 = list(nx.connected_components(subgra))

if connect1 == connect2:
    print("Graph 2 is a subgraph of Graph 1")
else:
    print("Grpahs are not connected")
#Explanation: 

# eulers circuit
if nx.is_eulerian(G):
    print("Eulerian circuit: ", list(nx.eulerian_circuit(G)))
else:
    print("The graph does not have an Eulerian circuit.")
#Explanation: 

# eulers trail
if nx.has_eulerian_path(G):
    print("Eulerian path: ", list(nx.eulerian_path(G)))
else:
    print("The graph does not have an Eulerian path.")
#Explanation: 

# Hamiltonian circuits

def hamilton(G):
    F = [(G, [list(G.nodes())[0]])]  # Corrected the nodes() method to list(G.nodes())
    n = len(G)
    while F:
        graph, path = F.pop()
        confs = []
        for node in graph.neighbors(path[-1]):
            conf_p = path[:]
            conf_p.append(node)
            conf_g = graph.copy()  # Use copy() method to create a copy of the graph
            conf_g.remove_node(path[-1])
            confs.append((conf_g, conf_p))
        for g, p in confs:
            if len(p) == n:
                return p
            else:
                F.append((g, p))
    return None

# usage
hamilton_circuit = hamilton(G)
if hamilton_circuit:
    print("Hamiltonian Circuit:", hamilton_circuit)
else:
    print("The graph does not have a Hamiltonian circuit.")

#Explanation: 

