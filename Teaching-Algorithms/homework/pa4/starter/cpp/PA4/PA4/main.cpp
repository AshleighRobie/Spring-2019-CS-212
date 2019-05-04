#include <iostream>
#include <unordered_map>
#include <cmath>
#include <string>
#include <queue>
#include "CsvParser.h"
#include "TreeNode.h"
#include "DecisionTree.h"

/*
	Ashleigh Robie
	HSU ID: 0129-02549
	Completion Time: 5 hours
	Collaborated with: Xavier, Emma, Zahory
*/
using namespace std;

void traverseTree(TreeNode* root)
{
	root->children;
}

TreeNode* option1(string input_csv, int column)
{
	CsvStateMachine parser{ input_csv };
	vector<vector<string>> data = parser.processFile();
	vector<string> header = data[0];

	return buildTree(data, header, column);	
}
void option2_helper(TreeNode* root, queue<pair<string, TreeNode*>>& nodes)
{
	// pushes all children in
	unordered_map <string, TreeNode*> current = root->children;
	for (auto kvp : current)
	{
		nodes.push(make_pair(kvp.first, kvp.second));
	}

	for (auto kvp : current)
	{
		// call recursively
		option2_helper(kvp.second, nodes);
	}
}

void option2(TreeNode* root)
{
	string user_output_file = " ";
	cout << "Enter output file: ";
	cin >> user_output_file;
	ofstream output_file{ user_output_file };
	queue<pair<string, TreeNode*>> output;

	// sets top of tree to "NULL" and root
	output.push(make_pair("NULL", root));
	option2_helper(root, output);

	while (output.size() > 0)
	{
		pair<string, TreeNode*> current = output.front();
		output.pop();
		
		// connection | child | # children
		output_file << current.first << "|" << current.second->value << "|" << current.second->children.size() << endl;
	}

	output_file.close();
}

void option3(string input_csv, int column, TreeNode* root)
{
	CsvStateMachine parser{ input_csv };
	vector<vector<string>> data = parser.processFile();
	vector<string> header = data[0];
	header.push_back("Predictions");

	vector<string> predictor;
	unordered_map<string, TreeNode*> current = root->children;
	for (int i = 1; i < data.size(); i++)
	{
		predictor = data[i];
		for (auto kvp : current)
		{
			for (int x = 0; x < predictor.size(); x++)
			{
				if (kvp.first == predictor[x])
				{
					// call recursively?
				}
			}
		}
	}
}

int main(void)
{

	string file_name = " ";
	int user_option = 0;

	cout << "*** Decision Tree Menu ***" << endl;
	cout << "Enter csv file: ";
	cin >> file_name;


	do{

		cout << " *** Option Menu *** " << endl;
		cout << "1 | build tree from file \n2 | write tree to file \n3 | predict outcome \n4 | read tree from file" << endl;
		cout << "0 | exit" << endl;
		cout << "Option #: ";
		cin >> user_option;
		cout << " ******************* " << endl;

		// build tree 
		if (user_option == 1)
		{
			int user_outcome_variable = 0;
			cout << "Enter Outcome Column Number: ";
			cin >> user_outcome_variable;

			option1(file_name, user_outcome_variable);
		}

		// write built tree to file
		else if (user_option == 2)
		{
			int user_outcome_variable = 0;
			cout << "Enter Outcome Column Number: ";
			cin >> user_outcome_variable;

			TreeNode* root = option1(file_name, user_outcome_variable);
			option2(root);
		}

		// predict outcome from the tree built, and send to file
		else if (user_option == 3)
		{
			int user_outcome_variable = 0;
			cout << "Enter outcome column number: ";
			cin >> user_outcome_variable;

			
	
		}
		else if (user_option == 4)
		{

		}
		else if(user_option == 0)
		{
			break;
		}
	} while (user_option != 0 || user_option != 1 || user_option != 2 || user_option != 3 || user_option != 4);


	//// outcome_col is 4, not 5 b/c matrix is zero-based index
	//TreeNode* root = buildTree(data, header, outcome_col);
	//write_to_file(root);
	//csv_output(header, root, data, 4);
	//vector<string> row = getRow(data, 1, 4);

	//// 4
	//string tree_file;
	////cout<< "File containing tree: " << endl;
	////cin >> tree_file;
	////CsvStateMachine parser1{tree_file};
	//CsvStateMachine parser1{ "output.txt" };
	//vector<vector<string>> tree_data = parser1.processFile();
	//read_tree_from_file(tree_data);

   //AC NOTE: very slow.  Consider using STL move to move
   //array elements 1...size() to another structure
    

   return 0;
}