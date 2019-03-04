#include "CityGraph.h"
#include "CsvParser.h"
#include <iostream>

int main(void)
{
	unordered_map<string, unordered_map<string, int>> completeMap;
	CityGraph graph{};
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

	vector<string> currentHouse = deliveryMap[0];
	auto routes = graph.computeMinimumSpanningTree(currentHouse[0]);
	
	// compute minimum spanning trees returns a vector of Edges
	// sum cost of edges
	Edge currentEdge;
	int routeTime = 0;
	for (int s = 0; s < routes.size(); s++)
	{
		currentEdge = routes[s];
		routeTime += currentEdge.weight;
	}

	cout << "Total travel time: " << routeTime << " minutes" << endl;
	// calculate total time it will take

 
	return 0;
}