#include "Graph.hpp"


Graph::Graph() //Constructor
{
    this->V = 0;
    this->E = 0;
}

Graph::~Graph() //Destructor
{
    for (auto &x : vertices){
        delete x;
    }
    for (auto &x : edges){
        delete x;
    }
    vertices.clear();
    edges.clear();
}

void Graph::addVertex(std::string label)
{
    for (int i = 0; i < V; i++){  //Loop through vertices list and check if the vertex already exists
        if (vertices[i]->getValue() == label){
            std::cout << "Vertex already exists.\n";
            return;
        }
    }
    vertices.push_back(new Vertex(label));
    V++;
}

void Graph::removeVertex(std::string label)
{
    for (auto pos : edges){  //Removing all edges connected to the vertex
        if (pos->getVertexOne()->getValue() == label || pos->getVertexTwo()->getValue() == label){
            removeEdge(pos->getVertexOne()->getValue(), pos->getVertexTwo()->getValue());
        }
    }
    for (std::vector<Vertex *>::iterator pos = vertices.begin(); pos != vertices.end(); pos++){ // Removes the vertex
        if ((*pos)->getValue() == label){
            vertices.erase(pos);
            V--;
        }
    }
    for (auto pos : edges){
        if (pos->getVertexOne()->getValue() == label || pos->getVertexTwo()->getValue() == label){ //Second pass for removing edges connected to the vertex
            removeEdge(pos->getVertexOne()->getValue(), pos->getVertexTwo()->getValue());
        }
    }
    
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    //Loop through vertices vector to find both vertices.
    int i,j;
    for (i = 0; i < V; i++){
        if (vertices[i]->getValue() == label1){
            break;
        }
    }
    for (j = 0; j < V; j++){
        if (vertices[j]->getValue() == label2){
            break;
        }
    }
    if (i == V || j == V) //Ensures both vertices exist.
    {
        std::cout << "A vertex was not found in the graph.";
        return;
    }
    if (weight <= 0) //Can't have non-positive weights
    {
        std::cout << "Weight was non-positive.";
        return;
    }   
    //Check if edge exists already.
    for (auto edge : edges){
        if (edge->getVertexOne()->getValue() == label1 && edge->getVertexTwo()->getValue() == label2){
            std::cout << "Edge already exists.\n";
            return;
        }
    }
    //Add each vertex to each other's adjacency list.
    vertices[i]->addAdjacent(vertices[j], weight);
    vertices[j]->addAdjacent(vertices[i], weight);
    //Add Edge to Graph.
    edges.push_back(new Edge(vertices[i], vertices[j], weight));
    E++;
}

void Graph::removeEdge(std::string label1, std::string label2)
{
    std::vector<Edge *>::iterator pos;
    for (pos = edges.begin(); pos != edges.end(); pos++){ //Finding the edge to be removed, updating the adjacency lists of both vertices, then deleting the edge
    if ((*pos)->getVertexOne()->getValue() == label1 && (*pos)->getVertexTwo()->getValue() == label2){
        (*pos)->getVertexOne()->removeAdjacent((*pos)->getVertexTwo(), (*pos)->getWeight());
        (*pos)->getVertexTwo()->removeAdjacent((*pos)->getVertexOne(), (*pos)->getWeight());
        edges.erase(pos);
        break;
    }
}
    if (pos == edges.end()){ //If we didn't find it, we exit.
        std::cout << "Edge does not exist.\n";
        return;
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    std::vector<unsigned long> dist(V, INF);
    std::map<std::string, std::string> prevMap;
    std::priority_queue<std::pair<std::string, unsigned long>> pq;
    int i,j;
    //Finds the starting vertex.
    for (i = 0; i < V; i++)
    {
        if (vertices[i]->getValue() == startLabel)
            break;
    }
    dist[i] = 0; //Distance from source to source is 0.
    pq.push(std::make_pair(startLabel, 0));
    while (!pq.empty()) //Continues through the queue until it reaches the end of the graph.
    {
        //Takes the first element off the priority queue.
        std::pair<std::string, unsigned long> top = pq.top();
        pq.pop();
        for (i = 0; i < V; i++)
        {
        if (vertices[i]->getValue() == top.first) //Finds our vertex in the list.
            break;
        }

        //If our weight is bigger than the current distance, it skips it.
        if (top.second > dist[i])
            continue;

        std::map<Vertex *, unsigned long> adjList = vertices[i]->getAdjacent();
        //Checks all adjacent vertices for edges.
        for (auto it : adjList)
        {
            unsigned long altWeight = dist[i] + it.second;
            //Finds the adjacent vertex in our vertices list.
            for (j = 0; j < V; j++)
            {
                if (vertices[j]->getValue() == it.first->getValue())
                    break;
            }
            if (altWeight < dist[j]) //Checks for if the adjacent edge can be relaxed.
            {
                pq.push(std::make_pair(it.first->getValue(), altWeight));
                dist[j] = altWeight;
                prevMap[it.first->getValue()] = vertices[i]->getValue();
            }
        }
    }
    //Starts the path at the end.
    std::string end = endLabel;
    while (end != startLabel) //Iterates through the map to find the shortest path that was taken.
    {
        path.push_back(end);
        end = prevMap[end];
    }
    //Adds the starting vertex which was not added.
    path.push_back(startLabel);

    //Reverse the string to get the correct path.
    std::reverse(path.begin(), path.end());

    for (i = 0; i < V; i++) //Finds the recorded shortest distance to the end vertex.
    {
        if (vertices[i]->getValue() == endLabel)
        {
            break;
        }
    }

    return dist[i];
}
