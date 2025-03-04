#include <iostream>
#include <vector>
#include <map>
#include <queue>
// https://www.codingame.com/training/medium/death-first-search-episode-1


int main() {
    struct Node {
        std::vector<int> neighbours;
        bool isGateway = false;
    };

    struct Graph {
        std::map<int, Node> nodes;
    } graph;

    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    std::cin >> n >> l >> e; std::cin.ignore();

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        std::cin >> n1 >> n2; std::cin.ignore();
        graph.nodes[n1].neighbours.push_back(n2);
        graph.nodes[n2].neighbours.push_back(n1);
    }

    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        std::cin >> ei; std::cin.ignore();
        graph.nodes[ei].isGateway = true;
    }
    
    //setup done
    //print the graph so we can see stuff
    for (std::pair<int, Node> node : graph.nodes) {
        if(node.second.isGateway) std::cerr << "Gateway ";
        std::cerr << "Index: " << node.first;
        std::cerr << " Neighbours: ";
        for(int i : node.second.neighbours) std::cerr << i << " ";
        std::cerr << std::endl;
    }
    int out[2];
    // game loop
    while (1) {
        std::queue<int> q;
        std::vector<bool> visited(graph.nodes.size(), false);
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        std::cin >> si; std::cin.ignore();
        visited[si] = true;
        q.push(si);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            std::cerr << "Current node: " << currentNode << std::endl;
            for (int x : graph.nodes[currentNode].neighbours) {
                if (!visited[x]) {
                    visited[x] = true;
                    std::cerr << "Visited: " << x << std::endl;
                    if (graph.nodes[x].isGateway) {
                        out[0] = currentNode;
                        out[1] = x;
                        while (!q.empty()) q.pop();
                        break;
                    }
                    else{
                        q.push(x);
                    }
                }
            }
        }
        std::cout << out[0] << " " << out[1] << std::endl;
    }
    return 1;
}