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
}

unordered_map<StringGraphNode*, string*> buildMap()
{
	// may delete later... 
}

int main(void)
{
	//Example of how to parse a CSV file for graph building
	CsvStateMachine csm{ "data.csv" };
	vector<vector<string>> data = csm.processFile();

	unordered_map<string, StringGraphNode*> mapCode;
	unordered_map<StringGraphNode*, string*> CampusMap;
	CampusGraph CampusCodesMap;
	CampusCodesMap.setCampusGraph(mapCode);

	// does this automatically create the key value pair for GraphNode
	// how does inheritance work?
	// creates nodes based keys
	StringGraphNode CanyonNode = StringGraphNode("A");
	StringGraphNode CreekviewNode = StringGraphNode("B");
	StringGraphNode JollyGiantNode = StringGraphNode("C");
	StringGraphNode HillNode = StringGraphNode("D");
	StringGraphNode CypressNode = StringGraphNode("E");
	StringGraphNode FeuerwerkerNode = StringGraphNode("F");
	StringGraphNode NelsonsNode = StringGraphNode("G");
	StringGraphNode FoundersNode = StringGraphNode("H");
	StringGraphNode MillStreetNode = StringGraphNode("I");
	StringGraphNode UCquadNode = StringGraphNode("J");
	StringGraphNode StudentHealthNode = StringGraphNode("K");
	StringGraphNode LibraryNode = StringGraphNode("L");
	StringGraphNode VanMatreNode = StringGraphNode("M");
	StringGraphNode SiemensNode = StringGraphNode("N");
	StringGraphNode RedwoodBowlNode = StringGraphNode("O");
	StringGraphNode MusicANode = StringGraphNode("P");
	StringGraphNode UpperFieldNode = StringGraphNode("Q");
	StringGraphNode MusicArtNode = StringGraphNode("R");
	StringGraphNode LibraryHousesNode = StringGraphNode("S");
	StringGraphNode RWCNode = StringGraphNode("T");
	StringGraphNode TelonicherNode = StringGraphNode("U");
	StringGraphNode ArtANode = StringGraphNode("V");
	StringGraphNode BWHousesNode = StringGraphNode("W");
	StringGraphNode ArtLabNode = StringGraphNode("X");
	StringGraphNode GistNode = StringGraphNode("Y");
	StringGraphNode SciANode = StringGraphNode("Z");
	StringGraphNode SRCNode = StringGraphNode("A2");
	StringGraphNode KinesiologyNode = StringGraphNode("B2");
	StringGraphNode ForbesNode = StringGraphNode("C2");
	StringGraphNode ScienceNode = StringGraphNode("D2");
	StringGraphNode SBSNode = StringGraphNode("E2");
	StringGraphNode CollegeCreek1Node = StringGraphNode("F2");
	StringGraphNode HarryGriffithNode = StringGraphNode("G2");
	StringGraphNode CollegeCreek2Node = StringGraphNode("H2");
	StringGraphNode CEFNode = StringGraphNode("I2");
	StringGraphNode WildlifeNode = StringGraphNode("J2");
	StringGraphNode MarineWildlifeNode = StringGraphNode("K2");
	StringGraphNode GamePenNode = StringGraphNode("L2");
	StringGraphNode NaturalResourcesNode = StringGraphNode("M2");
	StringGraphNode FacilitiesNode = StringGraphNode("N2");
	StringGraphNode BoatNode = StringGraphNode("O2");
	StringGraphNode BSSNode = StringGraphNode("P2");
	StringGraphNode BSSLotBuildingNode = StringGraphNode("Q2");
	StringGraphNode ForestryNode = StringGraphNode("R2");
	StringGraphNode AnnexNode = StringGraphNode("S2");
	StringGraphNode SchatzEnergyNode = StringGraphNode("T2");

	// creates individual buildings
	CampusCodesMap.addVertex("ALDER");
	CampusCodesMap.addVertex("CEDAR");
	CampusCodesMap.addVertex("CHINQ");
	CampusCodesMap.addVertex("HEMLOCK");
	CampusCodesMap.addVertex("MADRN");
	CampusCodesMap.addVertex("MAPLE");
	CampusCodesMap.addVertex("PEPR");
	CampusCodesMap.addVertex("TANOK");
	CampusCodesMap.addVertex("CREEK");
	CampusCodesMap.addVertex("FERN");
	CampusCodesMap.addVertex("LAUREL");
	CampusCodesMap.addVertex("JUNIP");
	CampusCodesMap.addVertex("WILLOW");
	CampusCodesMap.addVertex("JGC");
	CampusCodesMap.addVertex("REDWO");
	CampusCodesMap.addVertex("SUNST");
	CampusCodesMap.addVertex("CYPRS");
	CampusCodesMap.addVertex("FWH");
	CampusCodesMap.addVertex("NHE");
	CampusCodesMap.addVertex("NHW");
	CampusCodesMap.addVertex("FH");
	CampusCodesMap.addVertex("BRH");
	CampusCodesMap.addVertex("HAH");
	CampusCodesMap.addVertex("LAPT");
	CampusCodesMap.addVertex("BOOK");
	CampusCodesMap.addVertex("UC");
	CampusCodesMap.addVertex("HC");
	CampusCodesMap.addVertex("LIB");
	CampusCodesMap.addVertex("VMH");
	CampusCodesMap.addVertex("SH");
	CampusCodesMap.addVertex("RB");
	CampusCodesMap.addVertex("RB");
	CampusCodesMap.addVertex("UPF");
	CampusCodesMap.addVertex("ARTB");
	CampusCodesMap.addVertex("MUSB");
	CampusCodesMap.addVertex("BALH");
	CampusCodesMap.addVertex("HH");
	CampusCodesMap.addVertex("RWC");
	CampusCodesMap.addVertex("TH");
	CampusCodesMap.addVertex("ARTA");
	CampusCodesMap.addVertex("BHH");
	CampusCodesMap.addVertex("WH");
	CampusCodesMap.addVertex("CERAM");
	CampusCodesMap.addVertex("SCLPT");
	CampusCodesMap.addVertex("GH");
	CampusCodesMap.addVertex("SCIA");
	CampusCodesMap.addVertex("SRC");
	CampusCodesMap.addVertex("KA");
	CampusCodesMap.addVertex("FGYM");
	CampusCodesMap.addVertex("SCIB");
	CampusCodesMap.addVertex("SCIC");
	CampusCodesMap.addVertex("SCID");
	CampusCodesMap.addVertex("SCIE");
	CampusCodesMap.addVertex("SBS");
	CampusCodesMap.addVertex("DELNO");
	CampusCodesMap.addVertex("SHAST");
	CampusCodesMap.addVertex("CDL");
	CampusCodesMap.addVertex("HGH");
	CampusCodesMap.addVertex("MENDO");
	CampusCodesMap.addVertex("TRIN");
	CampusCodesMap.addVertex("CEF");
	CampusCodesMap.addVertex("WDFS");
	CampusCodesMap.addVertex("WGP");
	CampusCodesMap.addVertex("MWCC");
	CampusCodesMap.addVertex("NR");
	CampusCodesMap.addVertex("FM");
	CampusCodesMap.addVertex("SR");
	CampusCodesMap.addVertex("BOAT");
	CampusCodesMap.addVertex("BSS");
	CampusCodesMap.addVertex("NAF");
	CampusCodesMap.addVertex("BH");
	CampusCodesMap.addVertex("MCOM");
	CampusCodesMap.addVertex("MWH");
	CampusCodesMap.addVertex("TOD");
	CampusCodesMap.addVertex("WWH");
	CampusCodesMap.addVertex("FR");
	CampusCodesMap.addVertex("ANEX");
	CampusCodesMap.addVertex("SERC");

	// connects the map key values and the buildings
	CampusCodesMap.connectVertex("A", "ALDER", 0, false);
	CampusCodesMap.connectVertex("A", "CEDAR", 0, false);
	CampusCodesMap.connectVertex("A", "CHINQ", 0, false);
	CampusCodesMap.connectVertex("A", "HEMLOCK", 0, false);
	CampusCodesMap.connectVertex("A", "MADRN", 0, false);
	CampusCodesMap.connectVertex("A", "MAPLE", 0, false);
	CampusCodesMap.connectVertex("A", "PEPR", 0, false);
	CampusCodesMap.connectVertex("A", "TANOK", 0, false);
	CampusCodesMap.connectVertex("B", "CREEK", 0, false);
	CampusCodesMap.connectVertex("B", "FERN", 0, false);
	CampusCodesMap.connectVertex("B", "LAUREL", 0, false);
	CampusCodesMap.connectVertex("B", "JUNIP", 0, false);
	CampusCodesMap.connectVertex("B", "WILLOW", 0, false);
	CampusCodesMap.connectVertex("C", "JGC", 0, false);
	CampusCodesMap.connectVertex("D", "REDWO", 0, false);
	CampusCodesMap.connectVertex("D", "SUNST", 0, false);
	CampusCodesMap.connectVertex("E", "CYPRS", 0, false);
	CampusCodesMap.connectVertex("F", "FWH", 0, false);
	CampusCodesMap.connectVertex("G", "NHE", 0, false);
	CampusCodesMap.connectVertex("G", "NHW", 0, false);
	CampusCodesMap.connectVertex("H", "FH", 0, false);
	CampusCodesMap.connectVertex("I", "BRH", 0, false);
	CampusCodesMap.connectVertex("I", "HAH", 0, false);
	CampusCodesMap.connectVertex("I", "LAPT", 0, false);
	CampusCodesMap.connectVertex("J", "BOOK", 0, false);
	CampusCodesMap.connectVertex("J", "UC", 0, false);
	CampusCodesMap.connectVertex("K", "HC", 0, false);
	CampusCodesMap.connectVertex("L", "LIB", 0, false);
	CampusCodesMap.connectVertex("M", "VMH", 0, false);
	CampusCodesMap.connectVertex("N", "SH", 0, false);
	CampusCodesMap.connectVertex("O", "RB", 0, false);
	CampusCodesMap.connectVertex("P", "RB", 0, false); 
	CampusCodesMap.connectVertex("Q", "UPF", 0, false);
	CampusCodesMap.connectVertex("R", "ARTB", 0, false);
	CampusCodesMap.connectVertex("R", "MUSB", 0, false);
	CampusCodesMap.connectVertex("S", "BALH", 0, false);
	CampusCodesMap.connectVertex("S", "HH", 0, false);
	CampusCodesMap.connectVertex("T", "RWC", 0, false);
	CampusCodesMap.connectVertex("U", "TH", 0, false);
	CampusCodesMap.connectVertex("V", "ARTA", 0, false);
	CampusCodesMap.connectVertex("W", "BHH", 0, false);
	CampusCodesMap.connectVertex("W", "WH", 0, false);
	CampusCodesMap.connectVertex("X", "CERAM", 0, false);
	CampusCodesMap.connectVertex("X", "SCLPT", 0, false);
	CampusCodesMap.connectVertex("Y", "GH", 0, false);
	CampusCodesMap.connectVertex("Z", "SCIA", 0, false);
	CampusCodesMap.connectVertex("A2", "SRC", 0, false);
	CampusCodesMap.connectVertex("B2", "KA", 0, false);
	CampusCodesMap.connectVertex("C2", "FGYM", 0, false);
	CampusCodesMap.connectVertex("D2", "SCIB", 0, false);
	CampusCodesMap.connectVertex("D2", "SCIC", 0, false);
	CampusCodesMap.connectVertex("D2", "SCID", 0, false);
	CampusCodesMap.connectVertex("D2", "SCIE", 0, false);
	CampusCodesMap.connectVertex("E2", "SBS", 0, false);
	CampusCodesMap.connectVertex("F2", "DELNO", 0, false);
	CampusCodesMap.connectVertex("F2", "SHAST", 0, false);
	CampusCodesMap.connectVertex("G2", "CDL", 0, false);
	CampusCodesMap.connectVertex("G2", "HGH", 0, false);
	CampusCodesMap.connectVertex("H2", "MENDO", 0, false);
	CampusCodesMap.connectVertex("H2", "TRIN", 0, false);
	CampusCodesMap.connectVertex("I2", "CEF", 0, false);
	CampusCodesMap.connectVertex("J2", "WDFS", 0, false);
	CampusCodesMap.connectVertex("K2", "MWCC", 0, false);
	CampusCodesMap.connectVertex("L2", "WGP", 0, false);
	CampusCodesMap.connectVertex("M2", "NR", 0, false);
	CampusCodesMap.connectVertex("N2", "FM", 0, false);
	CampusCodesMap.connectVertex("N2", "SR", 0, false);
	CampusCodesMap.connectVertex("O2", "BOAT", 0, false);
	CampusCodesMap.connectVertex("P2", "BSS", 0, false);
	CampusCodesMap.connectVertex("P2", "NAF", 0, false);
	CampusCodesMap.connectVertex("Q2", "BH", 0, false);
	CampusCodesMap.connectVertex("Q2", "MCOM", 0, false);
	CampusCodesMap.connectVertex("Q2", "MWH", 0, false);
	CampusCodesMap.connectVertex("Q2", "TOD", 0, false);
	CampusCodesMap.connectVertex("Q2", "WWH", 0, false);
	CampusCodesMap.connectVertex("R2", "FR", 0, false);
	CampusCodesMap.connectVertex("S2", "ANEX", 0, false);
	CampusCodesMap.connectVertex("T2", "SERC", 0, false);


	//user enters start_pos and end_pos
	string start_loc = "";
	string end_loc = "";
	cout << "**HSU Transit Time Calculator**" << endl;
	cout << "Enter starting location: ";
	cin >> start_loc;
	cout << "Enter destination: ";
	cin >> end_loc;
	cout << "Estimated travel time: "; // return the shortest time




	



	CampusGraph graph{};
	graph.addVertex("a");
	graph.addVertex("b");
	graph.addVertex("c");
	graph.connectVertex("a", "b", 3, true);
	graph.connectVertex("a", "c", 15);
	graph.connectVertex("b", "c", 7, true);
	auto distances = graph.computeShortestPath("a");
	return 0;
}