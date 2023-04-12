#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <map>
#include <list>
#include <iostream>
#include "Edge.hpp"

class Edge;
class Vertex{
  public:
  //Basic Vertex constructor and getter.
  Vertex();
  Vertex(std::string value) {this->value = value;};
  std::string getValue();

  //Adjacency List Methods
  bool adjacentEmpty() { return adj.empty(); } //Checks if adjacency list is empty (needed for removing the vertex).
  std::map<Vertex *, unsigned long> getAdjacent(); //Grabs the adjacency map for the vertex.
  void addAdjacent(Vertex *v, unsigned long w); //Adds a vertex to the adjacency list.
  void removeAdjacent(Vertex *v, unsigned long w); //Removes a vertex from adjacency list.
  
  private:
  std::string value; //Label of the value of the vertex.
  std::map<Vertex *, unsigned long> adj; //An adjacency list for the vertex containing all vertices the vertex shares an edge with and their weight.

  //friend class Graph;
};


#endif