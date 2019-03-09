#include "CityGraph.h"
#include "CsvParser.h"
#include <iostream>

int main(void)
{
	unordered_map<string, unordered_map<string, int>> completeMap;
	CityGraph graph{};
	CityGraph Tier2graph{};
	string mapFile, deliveriesFile;
	cout << "***Route Planner***" << endl;
	cout << "Enter maps file: "; 
	cin >> mapFile;
	
	CsvStateMachine _mapfile{ mapFile };
	vector<vector<string>> _completeMap = _mapfile.processFile();

	// build map from txt 
	vector<string> currentPath;
	for (int i = 0; i < _completeMap.size(); i++)
	{
		currentPath = _completeMap[i];
		graph.addVertex(currentPath[0]);
		graph.addVertex(currentPath[1]);
	}

	for (int i = 0; i < _completeMap.size(); i++)
	{
		currentPath = _completeMap[i];
		graph.connectVertex(currentPath[0], currentPath[1], stoi(currentPath[2]), true);

	}

	cout << "Enter route file: ";
	cin >> deliveriesFile;
	CsvStateMachine _deliveriesfile{ deliveriesFile };
	vector<vector<string>> deliveryMap = _deliveriesfile.processFile();
	// calculate all possible route using MST algorithm

	vector<string> startHouse = deliveryMap[0];
	CityGraph MSTgraph = graph;
	auto routes = MSTgraph.computeMinimumSpanningTree(startHouse[0]);

	

	// ======== TIER 2 ==========
	unordered_map<string, int> distances{};
	int route_weight = 0;

	// reduce map then calculate shortest path
	// loads vertexes into single vector
	vector<string> deliveries;
	for (int v = 0; v < deliveryMap.size(); v++)
	{
		vector<string> current = deliveryMap[v];
		deliveries.push_back(current[0]);
	}

	// calculate shortest path from 
	for (int c = 0; c < deliveries.size(); c++)
	{
		distances = graph.computeShortestPath(deliveries[c]);

		for (auto kvp : distances)
		{
			if (kvp.first == deliveries[c+1])
			{
				Tier2graph.addVertex(kvp.first);
				route_weight = kvp.second;
				Tier2graph.connectVertex(deliveries[c], deliveries[c + 1], route_weight);
			}
		}
	}

	// ======== Tier 1 =========
	// compute minimum spanning trees returns a vector of Edges
	// sum cost of edges
	Edge currentEdge;
	int MSTrouteTime = 0;
	for (int s = 0; s < routes.size(); s++)
	{
		currentEdge = routes[s];
		MSTrouteTime += currentEdge.weight;
	}
	cout << "Total travel time for MST: " << MSTrouteTime << " minutes" << endl;

 
	return 0;
}