#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
#include <map>

/*
Matt Borek (z1951125)
Assignment 11
04/26/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Simple Graph Class.
 * 
 * Class to facilitate the creation and operation of a simple graph.
 * 
 */
class Graph {
 private:
  int                          size;            //graph size
  std::vector<std::list<int>>  adj_list;        //adjacency list matrix
  std::vector<char>            labels;          //used labels vector
  std::map<int, bool>          vertexVisited;   //visited vertex boolmap
  void                         Depthfirst(int); //public depthsearch function

  int                          previousVertex;  //index of previous vertex;
  std::vector<int>             traverseHistory; //traversal history vector
  std::vector<int>             traversePath;    //traversal path vector;

 public:
  Graph(const char* filename); //constructor
  ~Graph();                    //destructor
  int  Getsize() const;        //get size function
  void Traverse();             //traverse graph function
  void Print() const;          //print graph function
};

#endif  // GRAPH_H
