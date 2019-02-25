#include "CampusGraph.h";
#include "CsvParser.h"
#include <iostream>;

using namespace std;

double findTime(CampusGraph map,  string start_location, string end_location)
{
	unordered_map<string, int> distances;
	distances = map.computeShortestPath(start_location);
	bool is_found = false;
	string key;
	distances.find(start_location);
	//if(is_found == true)

	return 0;
}

unordered_map<StringGraphNode*, string*> buildMap()
{
	unordered_map<StringGraphNode*, string*> map;

	return map;
	// may delete later... 
}

int main(void)
{
	CampusGraph CampusCodesMap;
	unordered_map<string, StringGraphNode*> mapCode;
	unordered_map<StringGraphNode*, unordered_map<string, int>> CampusMap;

	// parses through distance data
	CsvStateMachine distanceData{ "distances.csv" };
	vector<vector<string>> distances = distanceData.processFile();

	for (auto path : distances)
	{
		vector<string> currentDataItem = path;
		unordered_map<string, int> pathWeights;
		StringGraphNode* startLocation;

		startLocation = new StringGraphNode(currentDataItem[0]);
		int pathTime = stoi(currentDataItem[2]);
		pathWeights[currentDataItem[1]] = pathTime;
		CampusMap[startLocation] = pathWeights;
		
	}

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

	CampusGraph CampusPaths;
	// building campus map
	// set values to values in a String Graph Node

	CampusPaths.addVertex(A_NodePointer);
	CampusPaths.addVertex(B_NodePointer);
	CampusPaths.addVertex(C_NodePointer);
	CampusPaths.addVertex(D_NodePointer);
	CampusPaths.addVertex(E_NodePointer);
	CampusPaths.addVertex(F_NodePointer);
	CampusPaths.addVertex(G_NodePointer);
	CampusPaths.addVertex(H_NodePointer);
	CampusPaths.addVertex(I_NodePointer);
	CampusPaths.addVertex(J_NodePointer);
	CampusPaths.addVertex(K_NodePointer);
	CampusPaths.addVertex(L_NodePointer);
	CampusPaths.addVertex(M_NodePointer);
	CampusPaths.addVertex(N_NodePointer);
	CampusPaths.addVertex(O_NodePointer);
	CampusPaths.addVertex(P_NodePointer);
	CampusPaths.addVertex(Q_NodePointer);
	CampusPaths.addVertex(R_NodePointer);
	CampusPaths.addVertex(S_NodePointer);
	CampusPaths.addVertex(T_NodePointer);
	CampusPaths.addVertex(U_NodePointer);
	CampusPaths.addVertex(V_NodePointer);
	CampusPaths.addVertex(W_NodePointer);
	CampusPaths.addVertex(X_NodePointer);
	CampusPaths.addVertex(Y_NodePointer);
	CampusPaths.addVertex(Z_NodePointer);
	CampusPaths.addVertex(A2_NodePointer);
	CampusPaths.addVertex(B2_NodePointer);
	CampusPaths.addVertex(C2_NodePointer);
	CampusPaths.addVertex(D2_NodePointer);
	CampusPaths.addVertex(E2_NodePointer);
	CampusPaths.addVertex(F2_NodePointer);
	CampusPaths.addVertex(G2_NodePointer);
	CampusPaths.addVertex(H2_NodePointer);
	CampusPaths.addVertex(I2_NodePointer);
	CampusPaths.addVertex(J2_NodePointer);
	CampusPaths.addVertex(K2_NodePointer);
	CampusPaths.addVertex(L2_NodePointer);
	CampusPaths.addVertex(M2_NodePointer);
	CampusPaths.addVertex(N2_NodePointer);
	CampusPaths.addVertex(O2_NodePointer);
	CampusPaths.addVertex(P2_NodePointer);
	CampusPaths.addVertex(Q2_NodePointer);
	CampusPaths.addVertex(R2_NodePointer);
	CampusPaths.addVertex(S2_NodePointer);
	CampusPaths.addVertex(T2_NodePointer);



	////user enters start_pos and end_pos
	//string start_loc = "";
	//string end_loc = "";
	//cout << "**HSU Transit Time Calculator**" << endl;
	//cout << "Enter starting location: ";
	//cin >> start_loc;
	//cout << "Enter destination: ";
	//cin >> end_loc;
	//cout << "Estimated travel time: "; // return the shortest time




	
	// creating the campus map
	// parse through distances.csv file


	//CampusGraph graph{};
	//graph.addVertex("a");
	//graph.addVertex("b");
	//graph.addVertex("c");
	//graph.connectVertex("a", "b", 3, true);
	//graph.connectVertex("a", "c", 15);
	//graph.connectVertex("b", "c", 7, true);
	//auto distances = graph.computeShortestPath("a");
	return 0;
}