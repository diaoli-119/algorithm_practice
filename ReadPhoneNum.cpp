#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::cout;

void readFile(string filePath)
{
	ifstream file(filePath);
	string line;
	std::vector<string> vec;
	while (std::getline(file, line))
	{
		if (line.find("#") != line.npos) continue;
		else if ((line.find(" ") != line.npos) && (line.find(") ") == line.npos)) continue;
		vec.push_back(line);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << std::endl;
	}
	return;
}