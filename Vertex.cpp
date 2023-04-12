#include "Vertex.hpp"



Vertex::Vertex(){
    this->value = "";
}

std::string Vertex::getValue()
{
    return value;
}

//Adjacency List Methods
void Vertex::addAdjacent(Vertex *v, unsigned long w) //Adds a vertex and edge to the adjacency list.
{
    adj.insert({v, w});
}
void Vertex::removeAdjacent(Vertex *v, unsigned long w) //Removes a vertex from adjacency list.
{   
    std::map<Vertex *, unsigned long>::iterator it = this->adj.begin();
    for (it = this->adj.begin(); it != this->adj.end(); it++){
        if (it->first == v && it->second == w){
            this->adj.erase(it);
        }
    }
}
std::map<Vertex *, unsigned long> Vertex::getAdjacent() // Returns the adjacency list of a vertex
{
    return this->adj;
}
