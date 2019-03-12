#include "CityGraph.h"
#include "CsvParser.h"
#include <iostream>

/*
	Ashleigh Robie
	HSU ID: 0129 - 02549
	Time: 5 hours
	Collaborated With: Zahory Velazquez

*/


using namespace std;

int main(void)
{
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

	// ======== Tier 1 =========
	vector<string> startHouse = deliveryMap[0];
	CityGraph MSTgraph = graph;
	auto routes = MSTgraph.computeMinimumSpanningTree(startHouse[0]);

	Edge currentEdge;
	int MSTrouteTime = 0;
	// sums cost of edges
	for (int s = 0; s < routes.size(); s++)
	{
		currentEdge = routes[s];
		MSTrouteTime += currentEdge.weight;
	}

	cout << "Total travel time for MST: " << MSTrouteTime << " minutes" << endl;


	// ======== TIER 2 ==========
	unordered_map<string, int> distances{};
	vector<string> housesOnRoute;
	vector<string> deliveries;
	string startOfRoute;
	int route_weight = 0;

	// loads deliveries into single vector & adds deliverie to graph
	for (int v = 0; v < deliveryMap.size(); v++)
	{
		vector<string> current = deliveryMap[v];
		deliveries.push_back(current[0]);
		Tier2graph.addVertex(current[0]);

		// calculates all shortest paths from current house
		distances = graph.computeShortestPath(current[0]);

		// iterates through unordered map
		for (auto kvp : distances)
		{
			for (int i = 0; i < deliveries.size(); i++)
			{
				// must be in delivery list & not itself
				if (kvp.first == deliveries.at(i) && kvp.first != current[0])
				{
					// builds new graph with path weight
					route_weight = kvp.second;
					Tier2graph.connectVertex(current[0], deliveries.at(i), route_weight, true);
					if (i == 0)
					{
						startOfRoute = current[0];
					}

				}
			}
		}
	}

	int reducedGraphTime = 0;
	auto reducedRoutes = Tier2graph.computeMinimumSpanningTree(deliveries.at(0));
	int currentWeight = 0;
	vector<string> route;
	Edge currentRouteWeight;

	// sums cost of edges
	for (int s = 0; s < reducedRoutes.size(); s++)
	{
		currentRouteWeight = reducedRoutes[s];
		reducedGraphTime += currentRouteWeight.weight;
	}

	cout << "Total travel time for reduced graph: " << reducedGraphTime << " minutes" << endl;

	// ====== Tier 3 =======
	// output the route 
	string currentHouse = "";
	string nextHouse = "";

	// loads route into a vector
	auto pathTaken = Tier2graph.computeShortestPath(startOfRoute);

	for (auto kvp : pathTaken)
	{
		route.push_back(kvp.first);
	}

	for (int x = 0; x < route.size() - 1; x++)
	{
		currentHouse = route.at(x);
		nextHouse = route.at(x + 1);
		cout << currentHouse << " -> " << nextHouse << endl;
	}

	return 0;
}