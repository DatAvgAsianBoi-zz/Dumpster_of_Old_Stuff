#include "Graph.h"

Graph::Graph(ifstream & inFS){
      int num_vertices;
      int num_edges;
      inFS >> num_vertices;
      inFS >> num_edges;

      for(int i = 0; i < num_vertices; i++){
            string currVertice;
            Vertex *temp = new Vertex();
            inFS >> currVertice;
            temp-> label = currVertice;
            vertices.push_back(*temp);
      }

      for(int i = 0; i < num_edges; i++){
            string vertex1;
            string vertex2;
            int cost;
            inFS >> vertex1;
            inFS >> vertex2;
            inFS >> cost;
            pair <int, int> neighbor;
            neighbor.first = pos(vertex2);
            neighbor.second = cost;
            if(pos(vertex1) < 0)
                  cout << "WTF" << endl;
            vertices.at(pos(vertex1)).neighbors.push_back(neighbor);
      }
}
Graph::~Graph(){}
void Graph::output_graph(const string& filename){
      ofstream fout(filename);
      if(!fout){
            cout << "Output File Not Found" << endl;
            return;
      }
      fout<<"digraph G {"<<endl;
      for(unsigned i = 0; i < vertices.size(); i++)
            fout <<"\t" << vertices.at(i).label << "[label=\"" << vertices.at(i).label << "\nDistance:" << vertices.at(i).distance << "\"]" << endl;

      for(unsigned i = 0; i < vertices.size(); i++){
            list<pair<int,int>> neighborHood = vertices.at(i).neighbors;
            int neighborsSize = neighborHood.size();
            for(int j = 0; j < neighborsSize; j++){
                  int adjacent = neighborHood.front().first;
                  neighborHood.pop_front();
                  fout << "\t" << vertices.at(i).label << "->" << vertices.at(adjacent).label << endl;
            }//inner for loop
      }//outter for loop

      fout << "}";
}
void Graph::bfs(){
      resetVertex();
      vertices.at(0).color = "GRAY";
      vertices.at(0).distance = 0;
      vertices.at(0).prev = nullptr;

      queue<int> bfsq;
      bfsq.push(0);

      while(!bfsq.empty()){
            int currVertex = bfsq.front();
            bfsq.pop();
            list<pair<int,int>> copyList = vertices.at(currVertex).neighbors;
            int currNeighborSize = vertices.at(currVertex).neighbors.size();
            for(int i = 0; i < currNeighborSize; i++){
                  int neighborIndex = copyList.front().first;
                  copyList.pop_front();

                  if(vertices.at(neighborIndex).color == "WHITE"){
                        vertices.at(neighborIndex).color = "GRAY";
                        vertices.at(neighborIndex).distance = vertices.at(currVertex).distance + 1;
                        vertices.at(neighborIndex).prev = &vertices.at(currVertex);
                        bfsq.push(neighborIndex);
                  }//if statement
            }//for loop
            vertices.at(currVertex).color = "BLACK";
      }//whilte loop
}




//Private
int Graph::pos(const string& label){
      int count = 0;
      for(Vertex v: vertices)
            if(v.label == label)
                  return count;
            else
                  count++;
      return -1;
}
void Graph::resetVertex(){
      for(unsigned i = 0; i < vertices.size(); i++){
            vertices.at(i).distance = INT_MAX;
            vertices.at(i).color = "WHITE";
            vertices.at(i).prev = nullptr;
      }
}
