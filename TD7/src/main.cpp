#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <queue>
#include <limits>

namespace Graph {
    struct WeightedGraphEdge {
        int to {};
        float weight {1.0f};

        // default ici permet de définit les opérateurs de comparaison membres à membres automatiquement
        // Cela ne fonction qu'en C++20, si vous n'avez pas accès à cette version je vous donne les implémentations des opérateurs plus bas
        bool operator==(WeightedGraphEdge const& other) const = default;
        bool operator!=(WeightedGraphEdge const& other) const = default;
    };

    struct WeightedGraph {
        // L'utilisation d'un tableau associatif permet d'avoir une complexité en O(1) pour l'ajout et la recherche d'un sommet.
        // Cela permet de stocker les sommets dans un ordre quelconque (et pas avoir la contrainte d'avoir des identifiants (entiers) de sommets consécutifs lors de l'ajout de sommets).
        // Cela permet également de pouvoir utiliser des identifiants de sommets de n'importe quel type (string, char, int, ...) et pas seulement des entiers.
        std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list;

        void add_vertex(int const id)
        {
            adjacency_list[id];
        }

        void add_directed_edge(int const from, int const to, float const weight = 1.0f)
        {
            adjacency_list[from].push_back({to, weight});
        }
        void add_undirected_edge(int const from, int const to, float const weight = 1.0f)
        {
            add_directed_edge(from, to, weight);
            add_directed_edge(to, from, weight);
        }
        
        // Même fonctionnement que pour WeightedGraphEdge
        bool operator==(WeightedGraph const& other) const = default;
        bool operator!=(WeightedGraph const& other) const = default;

        void DFS(int const node, std::vector<bool>& visited) const {
            visited[node] = true;
            std::cout << node << " ";
            for (auto const& edge : adjacency_list.at(node)) {
                if (!visited[edge.to]) {
                    DFS(edge.to, visited);
                }
            }
        }

        void print_DFS(int const start) const
        {
            std::vector<bool> visited(adjacency_list.size(), false);
            std::cout << "Traversee DFS a partir du noeud " << start << ": ";
            DFS(start, visited);
            std::cout << "\n";
        }

        void print_BFS(int const start) const
        {
            std::vector<bool> visited(adjacency_list.size(), false);
            std::queue<int> q;
            std::cout << "Traversee BFS a partir du noeud " << start << ": ";
            visited[start] = true;
            q.push(start);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                std::cout << node << " ";
                for (auto const& edge : adjacency_list.at(node)) {
                    if (!visited[edge.to]) {
                        visited[edge.to] = true;
                        q.push(edge.to);
                    }
                }
            }
            std::cout << "\n";
        }

        void add_edge(char from, char to, int weight) {
            adjacency_list[from].push_back(WeightedGraphEdge(to, weight));
        }

        std::unordered_map<char, int> dijkstra(char start) {
            std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> pq;
            std::unordered_map<char, int> distance;
            for (auto const& pair : adjacency_list) {
                distance[pair.first] = std::numeric_limits<int>::max();
            }
            distance[start] = 0;
            pq.push(std::make_pair(0, start));

            while (!pq.empty()) {
                char current = pq.top().second;
                int current_dist = pq.top().first;
                pq.pop();

                for (auto const& neighbor : adjacency_list[current]) {
                    char neighbor_node = neighbor.to;
                    int weight = neighbor.weight;
                    if (current_dist + weight < distance[neighbor_node]) {
                        distance[neighbor_node] = current_dist + weight;
                        pq.push(std::make_pair(distance[neighbor_node], neighbor_node));
                    }
                }
            }

            return distance;
        }
    };

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix)
    {
        WeightedGraph graph;
        int size = adjacency_matrix.size();
        for (int i = 0; i < size; ++i) {
            graph.add_vertex(i);
            for (int j = 0; j < size; ++j) {
                if (adjacency_matrix[i][j] != 0) {
                    graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
                }
        }
        }
        return graph;
    }

} // namespace

int main()
{
    std::vector<std::vector<float>> adjacency_matrix = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    Graph::WeightedGraph graph1 = Graph::build_from_adjacency_matrix(adjacency_matrix);

    Graph::WeightedGraph graph2;
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        graph2.add_vertex(i);
    }
    for (int i = 0; i < adjacency_matrix.size(); ++i) {
        for (int j = i + 1; j < adjacency_matrix.size(); ++j) {
            if (adjacency_matrix[i][j] != 0) {
                graph2.add_undirected_edge(i, j, adjacency_matrix[i][j]);
            }
        }
    }

    if (graph1 == graph2) {
        std::cout << "Les graphes sont egaux." << "\n";
    } else {
        std::cout << "Les graphes ne sont pas egaux. " << "\n";
    }

    Graph::WeightedGraph graph = Graph::build_from_adjacency_matrix(adjacency_matrix);

    graph.print_DFS(0);
    graph.print_BFS(0);

    // Dijkstra

    Graph::WeightedGraph graph3;
    graph3.add_edge('A', 'B', 1);
    graph3.add_edge('A', 'C', 5);
    graph3.add_edge('A', 'D', 2);
    graph3.add_edge('B', 'C', 4);
    graph3.add_edge('B', 'D', 5);
    graph3.add_edge('C', 'E', 3);
    graph3.add_edge('C', 'F', 4);
    graph3.add_edge('D', 'C', 2);
    graph3.add_edge('D', 'E', 5);
    graph3.add_edge('E', 'F', 3);

    char start_node = 'A';
    std::unordered_map<char, int> distances = graph3.dijkstra(start_node);

    std::cout << "Distances les plus courtes du noeud " << start_node << ":" << "\n";
    for (auto const& pair : distances) {
        std::cout << "Au noeud " << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}