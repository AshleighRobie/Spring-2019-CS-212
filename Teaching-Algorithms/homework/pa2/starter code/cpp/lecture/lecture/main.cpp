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
	unordered_map<string, StringGraphNode*> mapCode;

	// this is the resulting map from the csv file
	unordered_map<StringGraphNode*, unordered_map<string, int>> CampusMap;

	CampusCodesMap.setCampusGraph(mapCode);

	StringGraphNode* A_NodePointer = new StringGraphNode("A");
	StringGraphNode* B_NodePointer = new StringGraphNode("B");
	StringGraphNode* C_NodePointer = new StringGraphNode("C");
	StringGraphNode* D_NodePointer = new StringGraphNode("D");
	StringGraphNode* E_NodePointer = new StringGraphNode("E");
	StringGraphNode* F_NodePointer = new StringGraphNode("F");
	StringGraphNode* G_NodePointer = new StringGraphNode("G");
	StringGraphNode* H_NodePointer = new StringGraphNode("H");
	StringGraphNode* I_NodePointer = new StringGraphNode("I");
	StringGraphNode* J_NodePointer = new StringGraphNode("J");
	StringGraphNode* K_NodePointer = new StringGraphNode("K");
	StringGraphNode* L_NodePointer = new StringGraphNode("L");
	StringGraphNode* M_NodePointer = new StringGraphNode("M");
	StringGraphNode* N_NodePointer = new StringGraphNode("N");
	StringGraphNode* O_NodePointer = new StringGraphNode("O");
	StringGraphNode* P_NodePointer = new StringGraphNode("P");
	StringGraphNode* Q_NodePointer = new StringGraphNode("Q");
	StringGraphNode* R_NodePointer = new StringGraphNode("R");
	StringGraphNode* S_NodePointer = new StringGraphNode("S");
	StringGraphNode* T_NodePointer = new StringGraphNode("T");
	StringGraphNode* U_NodePointer = new StringGraphNode("U");
	StringGraphNode* V_NodePointer = new StringGraphNode("V");
	StringGraphNode* W_NodePointer = new StringGraphNode("W");
	StringGraphNode* X_NodePointer = new StringGraphNode("X");
	StringGraphNode* Y_NodePointer = new StringGraphNode("Y");
	StringGraphNode* Z_NodePointer = new StringGraphNode("Z");
	StringGraphNode* A2_NodePointer = new StringGraphNode("A2");
	StringGraphNode* B2_NodePointer = new StringGraphNode("B2");
	StringGraphNode* C2_NodePointer = new StringGraphNode("C2");
	StringGraphNode* D2_NodePointer = new StringGraphNode("D2");
	StringGraphNode* E2_NodePointer = new StringGraphNode("E2");
	StringGraphNode* F2_NodePointer = new StringGraphNode("F2");
	StringGraphNode* G2_NodePointer = new StringGraphNode("G2");
	StringGraphNode* H2_NodePointer = new StringGraphNode("H2");
	StringGraphNode* I2_NodePointer = new StringGraphNode("I2");
	StringGraphNode* J2_NodePointer = new StringGraphNode("J2");
	StringGraphNode* K2_NodePointer = new StringGraphNode("K2");
	StringGraphNode* L2_NodePointer = new StringGraphNode("L2");
	StringGraphNode* M2_NodePointer = new StringGraphNode("M2");
	StringGraphNode* N2_NodePointer = new StringGraphNode("N2");
	StringGraphNode* O2_NodePointer = new StringGraphNode("O2");
	StringGraphNode* P2_NodePointer = new StringGraphNode("P2");
	StringGraphNode* Q2_NodePointer = new StringGraphNode("Q2");
	StringGraphNode* R2_NodePointer = new StringGraphNode("R2");
	StringGraphNode* S2_NodePointer = new StringGraphNode("S2");
	StringGraphNode* T2_NodePointer = new StringGraphNode("T2");


	// creates individual buildings
	mapCode = {
		{"ALDER", A_NodePointer},
		{"CEDAR", A_NodePointer},
		{"CHINQ", A_NodePointer},
		{"HEMLOCK", A_NodePointer},
		{"MADRN", A_NodePointer},
		{"MAPLE", A_NodePointer},
		{"PEPR", A_NodePointer},
		{"TANOK", A_NodePointer},
		{"CREEK", B_NodePointer},
		{"FERN", B_NodePointer},
		{"LAUREL", B_NodePointer},
		{"JUNIP", B_NodePointer},
		{"WILLOW", B_NodePointer},
		{"JGC", C_NodePointer},
		{"REDWO", D_NodePointer},
		{"SUNST", D_NodePointer},
		{"CYPRS", E_NodePointer},
		{"FWH", F_NodePointer},
		{"NHE", G_NodePointer},
		{"NHW", G_NodePointer},
		{"FH", H_NodePointer},
		{"BRH", I_NodePointer},
		{"HAH", I_NodePointer},
		{"LAPT", I_NodePointer},
		{"BOOK", J_NodePointer},
		{"UC", J_NodePointer},
		{"HC", K_NodePointer},
		{"LIB", L_NodePointer},
		{"VMH", M_NodePointer},
		{"SH", N_NodePointer},
		{"RB", O_NodePointer},
		{"MUSA", P_NodePointer},
		{"UPF", Q_NodePointer},
		{"ARTB", R_NodePointer},
		{"MUSB", R_NodePointer},
		{"BALH", S_NodePointer},
		{"HH", S_NodePointer},
		{"RWC", T_NodePointer},
		{"TH", U_NodePointer},
		{"ARTA", V_NodePointer},
		{"BHH", W_NodePointer},
		{"WH", W_NodePointer},
		{"CERAM", X_NodePointer},
		{"SCLPT", X_NodePointer},
		{"GH", Y_NodePointer},
		{"SCIA", Z_NodePointer},
		{"SRC", A2_NodePointer},
		{"KA", B2_NodePointer},
		{"FGYM", C2_NodePointer},
		{"SCIB", D2_NodePointer},
		{"SCIC", D2_NodePointer},
		{"SCID", D2_NodePointer},
		{"SCIE", D2_NodePointer},
		{"SBS", E2_NodePointer},
		{"DELNO", F2_NodePointer},
		{"SHAST", F2_NodePointer},
		{"CDL", G2_NodePointer},
		{"HGH", G2_NodePointer},
		{"MENDO", H2_NodePointer},
		{"TRIN", H2_NodePointer},
		{"CEF", I2_NodePointer},
		{"WDFS", J2_NodePointer},
		{"WGP", K2_NodePointer},
		{"MWCC", L2_NodePointer},
		{"NR", M2_NodePointer},
		{"FM", N2_NodePointer},
		{"SR", N2_NodePointer},
		{"BOAT", O2_NodePointer},
		{"BSS", P2_NodePointer},
		{"NAF", P2_NodePointer},
		{"BH", Q2_NodePointer},
		{"MCOM", Q2_NodePointer},
		{"MWH", Q2_NodePointer},
		{"TOD", Q2_NodePointer},
		{"WWH", Q2_NodePointer},
		{"FR", R2_NodePointer},
		{"ANEX", S2_NodePointer},
		{"SERC", T2_NodePointer}
	};

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
	auto distances = graph.computeShortestPath(mapCode.at[start_loc]);

	cout << "Enter destination: ";
	cin >> end_loc;

	// find the destination in the distances unordered_map
	for (auto kvp : distances)
	{

	}
	auto distances = graph.computeShortestPath(mapCode.at[end_loc]);

	// access the time it takes
	int travel_time = distances<mapCode.at[end_loc]>;
	
	
	cout << "Estimated travel time: "; // return the shortest time


	return 0;
}