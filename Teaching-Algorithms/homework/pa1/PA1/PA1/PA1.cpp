#include "PA1.h"

//Ashleigh test commit

//PA #1 TOOD: Generates a Huffman character tree from the supplied text
HuffmanTree<char>* PA1::huffmanTreeFromText(vector<string> data)
{
	//Builds a Huffman Tree from the supplied vector of strings.
	//This function implement's Huffman's Algorithm as specified in the
	//book.

	//In order for your tree to be the same as mine, you must take care 
	//to do the following:
	//1.	When merging the two smallest subtrees, make sure to place the 
	//      smallest tree on the left side!

	//store frequencies in hashtable
	unordered_map<char, int> frequencies{};
	for (auto word : data)
	{
		for (auto ch : word)
		{
			//alter freq distribution
			frequencies[ch]++;
		}
	}

	// put into trees
	//maintains huffman tree forest 
	priority_queue < HuffmanTree<char>*, vector<HuffmanTree<char>*>, TreeComparer> forest{};

	//loop through frequency distributions
	for (auto kvp : frequencies)
	{
		//kvp first char, kvp second frequency(weight)
		forest.push(new HuffmanTree<char>(kvp.first, kvp.second));
	}

	//merge two trees
	while (forest.size() > 1)
	{
		HuffmanTree<char>*smaller = forest.top();
		forest.pop();
		HuffmanTree<char>*larger = forest.top();
		forest.pop();

		//merge two trees
		forest.push(new HuffmanTree<char>{ smaller,larger });
	}

	//TODO: shouldn't return nullptr
	return forest.top(); // return tree
}

//PA #1 TODO: Generates a Huffman character tree from the supplied encoding map
//NOTE: I used a recursive helper function to solve this!
HuffmanTree<char>* PA1::huffmanTreeFromMap(unordered_map<char, string> huffmanMap)
{
	//Generates a Huffman Tree based on the supplied Huffman Map. Recall that a 
	//Huffman Map contains a series of codes(e.g. 'a' = > 001).Each digit(0, 1) 
	//in a given code corresponds to a left branch for 0 and right branch for 1.

	HuffmanNode<char>* _root = new HuffmanInternalNode<char>{ nullptr, nullptr };
	HuffmanInternalNode<char>* current;

	string path = "0110";
	char value = 'x';

	for (int i = 0; i < path.length() - 1; i++)
	{
		char ch;
		if (ch == '0')
		{
			if (current->getLeftChild() == nullptr)
			{
				current->setLeftChild(new HuffmanInternalNode<char>{ nullptr,nullptr });
			}

			current = dynamic_cast<HuffmanInternalNode<char>*>(current->getLeftChild());
		}

		else
		{
			if (current->getRightChild() == nullptr)
			{
				current->setRightChild(new HuffmanInternalNode<char>{ nullptr,nullptr });
			}

			current = dynamic_cast<HuffmanInternalNode<char>*>(current->getRightChild());
		}

	}

	char last_ch = {path.length() - 1};

	if (last_ch == '0')
	{
		current->setLeftChild(new HuffmanLeafNode<char>{ value,1 });
	}
	else
	{
		current->setRightChild(new HuffmanLeafNode<char>{ value,1 });
	}


	return nullptr;
}

void huffmanEncodingMapFromTreeHelper(unordered_map<char, string>&map,
	HuffmanNode<char>*node, string encoding)
{
	if (node->isLeaf() == false)
	{
		//make recursive calls
		// more dynamic casts: from generic node into an internal node
		HuffmanInternalNode<char>*root = dynamic_cast<HuffmanInternalNode<char>*>(node);
		huffmanEncodingMapFromTreeHelper(map, root->getLeftChild(), encoding + "0");
		huffmanEncodingMapFromTreeHelper(map, root->getRightChild(), encoding + "1");
	}
	else
	{
		// is leaf
		// this converts node, which is a Huffman node into a leaf node
		// syntax:                   convert      want			          what we want to convert
		HuffmanLeafNode<char>*root = dynamic_cast<HuffmanLeafNode<char>*>(node);
		map[root->getValue()] = encoding;
		return;
	}
}


//PA #1 TODO: Generates a Huffman encoding map from the supplied Huffman tree
//NOTE: I used a recursive helper function to solve this!
unordered_map<char, string> PA1::huffmanEncodingMapFromTree(HuffmanTree<char> *tree)
{
	// pre order walk of the tree!
	// will need to do dynamic_casting

	HuffmanNode<char> *node = tree->getRoot();
	if (node->isLeaf() == true)
	{
		HuffmanLeafNode<char> *leaf = dynamic_cast<HuffmanLeafNode<char> *>(node);
		leaf = (HuffmanLeafNode<char> *)node;
	}

	unordered_map<char, string> result{};
	huffmanEncodingMapFromTreeHelper(result, tree->getRoot(), "");
	return result;
}

//PA #1 TODO: Writes an encoding map to file.  Needed for decompression.
void PA1::writeEncodingMapToFile(unordered_map<char, string> huffmanMap, string file_name)
{
	//Writes the supplied encoding map to a file.  My map file has one 
	//association per line (e.g. 'a' and 001 would yield the line "a001")
}

//PA #1 TODO: Reads an encoding map from a file.  Needed for decompression.
unordered_map<char, string> PA1::readEncodingMapFromFile(string file_name)
{
	//Creates a Huffman Map from the supplied file.Essentially, this is the 
	//inverse of writeEncodingMapToFile.  
	// turn back in to key,value pair
	unordered_map<char, string> result{};
	return result;
}

//PA #1 TODO: Converts a vector of bits (bool) back into readable text using the supplied Huffman map
string PA1::decodeBits(vector<bool> bits, unordered_map<char, string> huffmanMap)
{
	//Uses the supplied Huffman Map to convert the vector of bools (bits) back into text.
	//To solve this problem, I converted the Huffman Map into a Huffman Tree and used 
	//tree traversals to convert the bits back into text.
	// call build tree from map
	ostringstream result{};
	return result.str();
}

//PA #1 TODO: Using the supplied Huffman map compression, converts the supplied text into a series of bits (boolean values)
vector<bool> PA1::toBinary(vector<string> text, unordered_map<char, string> huffmanMap)
{
	// take each char and make it equal to binary representation
	vector<bool> result{};
	return result;
}