#include "CampusGraph.h";
#include "CsvParser.h";
#include "GraphNode.h";
#include "StringGraphNode.h";
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// create look up map
unordered_map <string, string>map_codes;
unordered_map <string, StringGraphNode*>campus_map;

int main(void)
{
   CampusGraph graph{};
   graph.addVertex("a");
   graph.addVertex("b");
   graph.addVertex("c");
   graph.connectVertex("a", "b", 3, true);
   graph.connectVertex("a", "c", 10);
   graph.connectVertex("b", "c", 5, true);
   graph.computeShortestPath("a");

   return 0;
}