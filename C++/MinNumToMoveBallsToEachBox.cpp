#include <string>
#include <iostream>
#include <vector>
using std::string;

std::vector<int> MinNumToMoveBallsToEachBox(string &boxes)
{
    int len = boxes.length();
    std::vector<int> vecSteps(len);
    int steps;
    for (int m = 0; m < len; m++)
    {
        steps = 0;
        for (int i = 0; i < m; i++)
        {
            if (boxes[i] == '1')
                steps += m - i;
        }
        for (int i = len; i > m; i--)
        {
            if (boxes[i] == '1')
                steps += i - m;
        }
        vecSteps[m] = steps;
    }
    return vecSteps;
}

void callMinNumToMoveBallsToEachBox()
{
	string boxes = "1101";
	std::vector<int> retVec = MinNumToMoveBallsToEachBox(boxes);
	for (int i = 0; i < retVec.size(); i++)
		std::cout << retVec[i] << std::endl;
}