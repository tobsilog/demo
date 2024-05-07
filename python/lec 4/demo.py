import matplotlib.pyplot as plt
import networkx as nx

seed = 55
# Use seed for reproducibility
G = nx.Graph()
plt.figure(figsize=(10, 8))
# Add nodes
G.add_nodes_from(["A", "B", "C", "D", "E", "F", "G", "I"])
# Add edges
edgelist = [("A", "C"), ("A", "I"), ("C", "B"), ("C", "E"), ("C", "D"), ("B", "E"), ("I", "E"), ("E", "F"), ("F", "G"), ("G", "E")]
G.add_edges_from(edgelist)
pos = nx.planar_layout(G)  # Seed for reproducible layout
nx.draw_networkx_edge_labels(
    G, pos,
    edge_labels={("A", "C"):10, ("A", "I"):5, ("C", "B"):20, ("C", "E"):15, ("C", "D"):30, ("B", "E"):25, ("I", "E"):40, ("E", "F"):35, ("F", "G"):50, ("G", "E"):45},
    font_color='red'
)
nx.draw(
    G, pos=pos, edge_color='black', width=1, linewidths=1,
    node_size=500, node_color='pink', alpha=0.9,
    with_labels=True
)

plt.show()

plt.figure(figsize=(10, 8))
# Use the same nodes and edges from G to create K
K = nx.Graph()
K.add_nodes_from(G.nodes)
edges = [("A", "I"), ("A", "C"), ("B", "C"), ("C", "D"), ("C", "E"), ("E", "F"), ("E", "G")]
K.add_edges_from(edges)
pos = nx.planar_layout(G)  # Use the positions from G
nx.draw_networkx_edge_labels(
    K, pos,
    edge_labels={("A", "I"):5, ("A", "C"):10, ("B", "C"):20, ("C", "D"):30, ("C", "E"):15, ("E", "F"):35, ("E", "G"):45},
    font_color='purple'
)
nx.draw(
    K, pos=pos, edge_color='black', width=1, linewidths=1,
    node_size=500, node_color='pink', alpha=0.9,
    with_labels=True
)

plt.show()

plt.figure(figsize=(10,8))
P = nx.Graph()
P.add_nodes_from(G.nodes)
primdedge = [("A", "I"), ("A", "C"), ("C", "B"), ("C", "D"), ("C", "E"), ("E", "F"), ("E", "G")]
P.add_edges_from(primdedge)
pos = nx.planar_layout(G)
nx.draw_networkx_edge_labels(
    P, pos,
    edge_labels={("A", "I"):5, ("A", "C"):10, ("B", "C"):20, ("C", "D"):30, ("C", "E"):15, ("E", "F"):35, ("E", "G"):45},
    font_color='purple'
)
nx.draw(
    P, pos=pos, edge_color='black', width=1, linewidths=1,
    node_size=500, node_color='pink', alpha=0.9,
    with_labels=True
)

plt.show()

plt.figure(figsize=(10,8))
D = nx.Graph()
D.add_nodes_from(G.nodes)
D.add_edges_from(G.edges)
pos = nx.planar_layout(G)
nx.draw_networkx_edge_labels(
    D, pos,
    edge_labels={("A", "C"):10, ("A", "I"):5, ("C", "B"):20, ("C", "E"):15, ("C", "D"):30, ("B", "E"):25, ("I", "E"):40, ("E", "F"):35, ("F", "G"):50, ("G", "E"):45},
    font_color='red'
)

nx.draw_networkx_edges(
    D, pos=pos,
    edgelist=[("A", "C"), ("A", "I"), ("C", "B"), ("C", "E"), ("C", "D"), ("G", "E"), ("E", "F")],
    edge_color='yellow'
)
nx.draw(
    P, pos=pos, width=1, linewidths=1,
    node_size=500, node_color='pink', alpha=0.9,
    with_labels=True
)

plt.show()
