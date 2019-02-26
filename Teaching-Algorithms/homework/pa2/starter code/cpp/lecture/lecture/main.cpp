#include "CampusGraph.h";
#include "CsvParser.h"
#include <iostream>;

/*
	Ashleigh Robie
	HSU ID: 0129-02549
	Completion Time: about 7 hours
	Individuals that I collaborated with: Xavier Damas, Zahory Velazquez
*/
using namespace std;


int main(void)
{
	CampusGraph CampusCodesMap;
	unordered_map<string, string> mapCode;

	// this is the resulting map from the csv file
	unordered_map<StringGraphNode*, unordered_map<string, int>> CampusMap;

	CsvStateMachine campusCode{ "mapCodes.csv" };
	vector<vector<string>> codes = campusCode.processFile();
	vector<string> currentCode;
	for (int i = 0; i < codes.size(); i++)
	{
		currentCode = codes[i];
		mapCode[currentCode[0]] = currentCode[1];
	}

	// parses through distance data
	// building Campus Map with path weights
	CsvStateMachine distanceData{ "distances.csv" };
	vector<vector<string>> data = distanceData.processFile();

	CampusGraph graph{};
	vector<string> currentDataItem;
	// adds all vertices
	for (int path = 0; path < data.size(); path++)
	{
		currentDataItem = data[path];

		graph.addVertex(currentDataItem[0]);
		graph.addVertex(currentDataItem[1]);
	}

	// adds the connections
	for (int path = 0; path < data.size(); path++)
	{
		currentDataItem = data[path];
		int pathTime = stoi(currentDataItem[2]);
		graph.connectVertex(currentDataItem[0], currentDataItem[1], pathTime, false);

	}


	string start_loc = "";
	string end_loc = "";
	cout << "**HSU Transit Time Calculator**" << endl;
	cout << "Enter starting location: ";
	cin >> start_loc;

	/*
		Given: start string from user
		- must match the key of mapCode
		- take that value and test it with graph{}

		Given: destination string from user
		- must match key of macCode
		- take that value and match it with the inner map of Graph{}
	*/
	// returns an unordered map <string, int>
	// to access kvp from mapCode, create for auto?
	// calculates all the possible path times from that starting location
	//auto distances = graph.computeShortestPath(mapCode[start_loc]);

	//cout << "Enter destination: ";
	//cin >> end_loc;


	//// access time it takes
	//int travel_time;
	//travel_time = distances.at(mapCode.at[end_loc]);
	//
	//
	//cout << "Estimated travel time: " << travel_time; // return the shortest time


	return 0;
}