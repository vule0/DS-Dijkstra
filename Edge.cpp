#include "Edge.hpp"


Edge::Edge(){
    this->vertexOne = NULL;
    this->vertexTwo = NULL;
    this->weight = 0;
}

Edge::Edge(Vertex* vertexOne, Vertex* vertexTwo, unsigned long weight){
    this->vertexOne = vertexOne;
    this->vertexTwo = vertexTwo;
    this->weight = weight;
}
Vertex* Edge::getVertexOne() //getVertexOne
{
    return vertexOne;
}

Vertex* Edge::getVertexTwo()
{
    return vertexTwo;
}

unsigned long Edge::getWeight()
{
    return weight;
}