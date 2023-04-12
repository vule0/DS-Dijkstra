#ifndef EDGE_H
#define EDGE_H

#include "Vertex.hpp"


class Vertex;

class Edge {
  public:
  Edge();
  Edge(Vertex* vertexOne, Vertex* vertexTwo, unsigned long weight);
  //Getter methods
  Vertex* getVertexOne();
  Vertex* getVertexTwo();
  unsigned long getWeight();
  private:
  Vertex* vertexOne; //Vertex 1's label.
  Vertex* vertexTwo; //Vertex 2's label.
  unsigned long weight; //Weight of the edge.
  //friend class Graph;
};

#endif