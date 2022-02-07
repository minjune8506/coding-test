#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	int complete;
	int start = 0;

	while (start < progresses.size())
	{
		complete = 0;
		if (progresses[start] >= 100)
		{
			while (progresses[start] >= 100 && start < progresses.size())
			{
				complete++;
				start++;
			}
			answer.push_back(complete);
		}
		else
		{
			for (int i = start ; i < progresses.size() ; i++)
				progresses[i] += speeds[i];
		}
	}
    return answer;
}

int main(void)
{
	vector<int> progresses;
	vector<int> speeds;

	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);
	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);

	solution(progresses, speeds);
}
