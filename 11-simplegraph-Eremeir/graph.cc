#include "graph.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <locale>

/*
Matt Borek (z1951125)
Assignment 11
04/26/2022
I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

/**
 * @brief Depth First Search Algorithm
 * 
 * Traverse the graph according to depth-first search algorithim and keep track of the history and path of visited vertexes, then print them.
 * 
 * @param v vertex index value.
 */
void Graph::Depthfirst(int v) 
{
    traverseHistory.push_back(previousVertex); //Add the previous vertex to the history.
    traverseHistory.push_back(v);   //Add the current vertex to the history.

    traversePath.push_back(v);  //Add the current vertex to the path list.
    vertexVisited[v] = true;    //Permanently mark this vertex as having been visited.

    int vertexNumber  = 0; //The vertex index within the list of vertex relations.
    for(auto &edgeStatus : adj_list[v])
    {
        if(edgeStatus == 1 && !vertexVisited[vertexNumber]) //If the current vertex shares an edge with a vertex and that vertex hasn't been visited.
        {   
            previousVertex = v; //Update the previous vertex to this one.
            Depthfirst(vertexNumber); //Explore the shared vertex.
        }
        ++vertexNumber; //Check the next vertex index.
    }
}

/**
 * @brief Graph Constructor
 * 
 * Opens and reads a properly formatted input file and parses information into an adjacency list format for use in a simple graph.
 * 
 * @param filename of the input file to be read for data.
 */
Graph::Graph(const char* filename)
{
    std::fstream file;
    file.open(filename); //Open the file.
    if(!file.is_open()) //File open error.
    {
        std::cerr << "File could not be opened." << std::endl;
    }

    bool inputClosed = false;

    std::string tempSize;
    std::getline(file, tempSize); //Read the virst line which holds the intended graph size.
    size = std::stoi(tempSize);   //Convert the string from getline to a string, store it as the size.
    adj_list.resize(size);        //Set the size of the list equal to the newly read in size.

    while(!inputClosed)
    {
        std::list<int> vertexEdges; //Temporary list to be pushed into the adjacency vector once populated.
        std::string tempLine;
        std::getline(file, tempLine); //Reads file line by line and stores in tempLine.
        
        if(tempLine.length() != 0) //Ensure the input isn't blank.
        {
            tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), [](char &C){return std::isspace(C, std::locale::classic());}), tempLine.end());
            //Remove whitespace from the string for easy computation.

            labels.push_back(tempLine.front()); //Add the first char of the line string which holds the vertex variable name.
            int labelIndex = (tempLine.front() - 65); //Convert the vertex variable char to an alphabetical index number.

            for(auto &entry : tempLine) //Search the entire line string.
            {
                if(entry == '1') //If the edge is shared.
                {
                    vertexEdges.push_back(1);
                }
                else if(entry == '0') //If there is no shared edge.
                {
                    vertexEdges.push_back(0);
                }
            }
            adj_list[labelIndex] = vertexEdges; //Add the populated list to the correct index corresponding to the variable letter.
        }

        else
        {
            inputClosed = true; //Signals that there is no more input to process.
        }
    }
    file.close(); //Close the opened file.
}

/**
 * @brief Graph Destructor.
 * 
 * @note Redundant.
 * 
 */
Graph::~Graph()
{

}

/**
 * @brief Get graph size.
 * 
 * Return the size of the simple graph.
 * 
 * @return int representing the sise of the simple graph.
 */
int Graph::Getsize() const 
{ 
    return size;
}

/**
 * @brief Traverse the graph.
 * 
 * Traverse through the simple graph, calling the depth-first search algorithim to record history, then print that history.
 * 
 */
void Graph::Traverse() 
{
    std::string convertedIndex; //String to hold index positions converted to letters.
    previousVertex = 0;
    Depthfirst(previousVertex); //Call depth-first algoritihm.

    std::cout << std::endl << "------- traverse of graph ------" << std::endl;

    for(auto &vertex : traversePath) //For each vertex in the path, convert the index to a letter and print it.
    {
        convertedIndex = vertex + 65;
        std::cout << convertedIndex << " ";
    }

    std::cout << std::endl;

    for(size_t i = 2; i < traverseHistory.size(); ++i)  //For each vertex in the traversal history, convert the index to a letter and print it.
    {
        if(i % 2) //If the current vertex is the second in the edge pair.
        {
            convertedIndex = traverseHistory[i] + 65;
            std::cout << convertedIndex << ") ";
        }

        else //If the current vertex is the first in the edge pair.
        {
            convertedIndex = traverseHistory[i] + 65;
            std::cout << "(" << convertedIndex << ", ";
        }
    }
    
    std::cout << std::endl << "--------- end of traverse -------" << std::endl << std::endl;
}

/**
 * @brief 
 * 
 */
void Graph::Print() const 
{
    int lineCount = 1; //Set to 1 to skip the unnecessary header column's input to the vector.

    std::cout << std::endl << "Number of vertices in the graph: " << Getsize() << std::endl;
    std::cout << std::endl << "-------- graph -------" << std::endl;

    for(auto &list : adj_list) //For each line of the adjacency list.
    {
        std::cout << labels[lineCount] << ": "; //Print the vertex label for that row.
        int edgeIndex = (labels.front() - 65); //Convert the vertex label to an index number.
        bool foundEdge = false; //Used for print simplicity, skips commas for the first edge of each line.

        for(auto &entry : list) //For each edge in the list of edges for this vertex.
        {
            std::string convertedIndex;
            if(entry == 1) //If there is a shared edge.
            {
                if(foundEdge)
                {
                     std::cout << ", ";
                }
                convertedIndex = edgeIndex + 65; //Conver the index number to an alphabetical letter.
                std::cout << convertedIndex;
                foundEdge = true;
            }
            ++edgeIndex; //Increment the letter index.
        }
        std::cout << std::endl;
        ++lineCount; //Increment the line index.
    }
    std::cout << "------- end of graph ------" << std::endl;
}