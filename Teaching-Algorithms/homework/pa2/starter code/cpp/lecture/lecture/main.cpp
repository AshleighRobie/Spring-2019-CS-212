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
	unordered_map<string, string> mapCode;
	unordered_map<StringGraphNode*, unordered_map<string, int>> CampusMap;
	CampusGraph graph{};

	// parses through mapc code values
	CsvStateMachine campusCode{ "mapCodes.csv" };
	vector<vector<string>> codes = campusCode.processFile();

	vector<string> currentCode;
	for (int i = 0; i < codes.size(); i++)
	{
		currentCode = codes[i];
		mapCode[currentCode[0]] = currentCode[1];
	}

	// parses through distance data
	CsvStateMachine distanceData{ "distances.csv" };
	vector<vector<string>> data = distanceData.processFile();
	
	// adds all vertices
	vector<string> currentDataItem;
	for (int path = 0; path < data.size(); path++)
	{
		currentDataItem = data[path];

		graph.addVertex(currentDataItem[0]);
		graph.addVertex(currentDataItem[1]);
	}

	// adds the path times
	for (int path = 0; path < data.size(); path++)
	{
		currentDataItem = data[path];
		int pathTime = stoi(currentDataItem[2]);
		graph.connectVertex(currentDataItem[0], currentDataItem[1], pathTime, false);

	}

	// asks the user for starting location and destination
	int travel_seconds, travel_minutes;
	string start_loc = "";
	string end_loc = "";

	cout << "**HSU Transit Time Calculator**" << endl;
	cout << "Enter starting location: ";
	cin >> start_loc;

	// calculates all the possible path times from that starting location
	auto distances = graph.computeShortestPath(mapCode[start_loc]);

	cout << "Enter destination: ";
	cin >> end_loc;

	// access the time it takes to destination
	travel_seconds = distances.at(mapCode[end_loc]);
	travel_minutes = travel_seconds / 60;
	
	cout << "Estimated travel time: About " << travel_minutes << " minutes" << endl; // return the shortest time


	return 0;
}