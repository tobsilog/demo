import networkx as nx
import matplotlib.pyplot as plt

# Create the main graph
g1 = nx.complete_graph(5)
g2 = nx.complete_graph(4)
g2 = nx.relabel_nodes(g2, {i: chr(65 + i) for i in range(4)})  # More Pythonic way to relabel nodes
exgra = nx.from_edgelist([(4, "X"), ("X", "A")])
G = nx.compose_all([g1, g2, exgra])

# Draw the graph
nx.draw_spring(G, with_labels=True)
plt.show()

# Print the degree of each vertex
print("Degree of each vertex: ")
print(dict(G.degree))

# Handshaking theorem
print("Twice number of edges: ")
print(nx.number_of_edges(G) * 2)
degrees = G.degree()
result = sum(deg for node, deg in degrees)
print("Sum of degrees of all vertices: ")
print(result)

# Hamiltonian circuits
def hamilton(G):
    F = [(G, [list(G.nodes())[0]])]
    n = len(G)
    while F:
        graph, path = F.pop()
        confs = []
        for node in graph.neighbors(path[-1]):
            if node not in path:
                conf_p = path[:]
                conf_p.append(node)
                conf_g = nx.Graph(graph.edges())
                conf_g.remove_node(path[-1])
                confs.append((conf_g, conf_p))
        for g, p in confs:
            if len(p) == n:
                return p
            else:
                F.append((g, p))
    return None

# usage
print(hamilton(G))
