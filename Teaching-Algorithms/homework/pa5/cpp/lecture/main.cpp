#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "EditDistance.h"

/*
	Ashleigh Robie
	PA 5
	Hours spent: 8
	Collaborated With: Alvin Lu, Devin Rowland

*/

using namespace std;

int main(void)
{
	string fileToAutocorrect, userOutputFile, word;
	priority_queue<int, vector<int>, greater<int>> inOrderEditDistances;	
	int userChoice;
	vector<string> correctedVector;
	string wordToFix;
	vector<string> fixWordVector;
	
	/*cout << "Enter file to autocorrect: " << endl;
	cin >> fileToAutocorrect;*/
	ifstream inputText{ "sample1.txt" };
	
	// loading file to correct into character vector
	vector<char> characterVector;
	while (!inputText.eof())
	{
		char item = inputText.get();
		characterVector.push_back(item);
	}

	// push characters into word vector
	string item = "";
	string s;

	for (auto ch : characterVector)
	{
		if (ch != ' ' && ch != '\n')
		{
			if (ch == '.')
			{
				fixWordVector.push_back(item);
				s.push_back(ch);
				item = "";
			}
			else if (ch == ',')
			{
				fixWordVector.push_back(item);
				s.push_back(ch);
				item = "";
			}
			else if (ch == '!')
			{
				fixWordVector.push_back(item);
				s.push_back(ch);
				item = "";
			}
			else if (ch == '?')
			{
				fixWordVector.push_back(item);
				s.push_back(ch);
				item = "";
			}
			else if (ch == '\'')
			{
				fixWordVector.push_back(item);
				s.push_back(ch);
				item = "";

			}

			if (!s.empty())
			{
				fixWordVector.push_back(s);
				s = "";
			}
			else if (s.empty())
			{
				item.push_back(ch);
			}
		}

		else
		{
			fixWordVector.push_back(item);
			item = "";
			s = "";
		}
	}
	
	/*cout << "Enter output file: " << endl;
	cin >> userOutputFile; 
	*/

	unordered_map<int, vector<string>> result;


	ifstream wordFile{ "words.txt" };
	vector<string> vectorOfWords;
	string line;
	unordered_map<string, int> wordsInFile;
	
	while (!wordFile.eof())
	{
		//gets each line from the file and saves to unordered map
		getline(wordFile, line);
		wordsInFile[line] = 1;
	}
	
	string wordToCorrect;

	for (int i = 0; i < fixWordVector.size(); i++)
	{		
		for (auto word : wordsInFile)
		{
			// creating unordered map with vector of words with corresponding edit distances(as key)
			int editDistance = calculateEditDistance(fixWordVector[i], word.first);
			result[editDistance].push_back(word.first);
			wordToCorrect = fixWordVector[i];	
		}

		// if word is not file
		if (wordsInFile.find(wordToCorrect) == wordsInFile.end() ||
			wordToCorrect == "," && wordToCorrect == "." && wordToCorrect == "!" && 
			wordToCorrect == "," && wordToCorrect == "?" && wordToCorrect == "\n")
		{
			cout << "Unknown word: " << wordToCorrect << endl;

			// print out whole sentence as context
			cout << "Context:";
			for (int a = 0; a < fixWordVector.size(); a++)
			{
				if (fixWordVector[a] == "!" || fixWordVector[a] == "." || fixWordVector[a] == "." || fixWordVector[a] == "?")
				{
					cout << fixWordVector[a];
				}
				else
				{
					cout << " " << fixWordVector[a];
				}
				
			}
			cout << endl;

			ofstream datFile{ wordToCorrect + ".dat" };

			// loads the edit distances into priority queue
			for (auto editInt : result)
			{
				inOrderEditDistances.push(editInt.first);
			}

			// the unordered map key value to find the vector of those edit distances
			vector<string> wordSuggestions;
			int position = 0;
			vector<string> optionVector;

			cout << "1. None of the words below are correct" << endl;
	
			while (optionVector.size() < 10)
			{
				for (auto kvp : result)
				{
						// match kvp.first with the priority queue top
						if (inOrderEditDistances.top() == kvp.first)
						{
							wordSuggestions = kvp.second;

							for (int y = 0; y < wordSuggestions.size(); y++)
							{
								if (y < wordSuggestions.size() && optionVector.size() < 10)
								{
									cout << optionVector.size() + 2 << ". " << wordSuggestions[y] << endl;
									optionVector.push_back(wordSuggestions[y]);
									datFile << wordSuggestions[y] << endl;
								}
							}

							if (optionVector.size() < 10)
							{
								inOrderEditDistances.pop();
							}
						}
				}

			}

			// load correct word into file
			cout << "Enter correct word by corresponding number: ";
			cin >> userChoice;

			// replace incorrect word with user choice
			if (userChoice == 1)
			{
				string newWord;
				cout << "Type correct word: ";
				cin >> newWord;
				cout << endl;
				correctedVector.push_back(newWord);
			}
			else
			{
				correctedVector.push_back(optionVector[userChoice - 2]);
			}
		}
		// if word is in file
		else
		{
			correctedVector.push_back(fixWordVector[i]);
		}

		// clears the unordered map edit distances
		result.clear();
	}

	//creates corrected sentence output file
	ofstream outputFile{ userOutputFile };
	for (int x = 0; x < correctedVector.size(); x++)
	{
		if (correctedVector[x] == "!" || correctedVector[x] == "." || correctedVector[x] == "." || correctedVector[x] == "?")
		{
			outputFile << correctedVector[x];
		}
		else
		{
			outputFile << " " << correctedVector[x];
		}
	}
	outputFile.close();

   return 0;

}