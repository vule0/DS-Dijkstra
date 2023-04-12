#ifndef GRAPH_H
#define GRAPH_H

//Ryan Chick U34829175 11/11/22
//Vu Le U43500182
//Creates a graph which uses Dijkstra's formula to find the shortest path.

#include <queue>
#include <algorithm>
#include <set>
#include "Edge.hpp" //Edge contains the definitions for Vertex. Vertex contains String and List.
#include "Vertex.hpp"
#include "GraphBase.hpp"

#define INF 0x3f3f3f3f //Infinity for use in initialization of the shortestPath method.
class Vertex;
class Edge;

typedef std::pair<unsigned long, std::string> edge;
class Graph {

  public: //Graph Methods
  Graph(); //Constructor
  ~Graph(); //Destructor
  void addVertex(std::string label);
  void removeVertex(std::string label);
  void addEdge(std::string label1, std::string label2, unsigned long weight);
  void removeEdge(std::string label1, std::string label2);
  unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

  private:
  int V; //Number of vertices in the graph;
  int E; //Number of edges in the graph;
  std::vector<Vertex *> vertices; //Vector containing all vertices in the graph.
  std::vector<Edge *> edges; //Vector containing all edges in the graph.
};

#endif