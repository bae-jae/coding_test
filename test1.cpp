#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		string answer = "";
		cin >> answer;

		//1단계
		string firstCand = "";
		for(int i = 0; i < answer.size(); ++i)
		{
			if(isalpha(answer[i]) == 0)
				firstCand.push_back(answer[i]);
			else
			{
				firstCand.push_back(tolower(answer[i]));
			}
		}

		cout << "1" <<  firstCand << endl;

		string sec;
		for(int i = 0; i < firstCand.size(); ++i)
		{
			if(isalpha(firstCand[i]) == 0)
			{
				char tar = firstCand[i];

				if(tar == '-' || tar == '_' || tar == '.')
					sec.push_back(firstCand[i]);

				if(isdigit(tar) != 0)
				{
					sec.push_back(tar);
				}
			}
			else
				sec.push_back(firstCand[i]);
		}

		cout <<" 2" <<  sec << endl;

		string thrid;
		for(int i = 0; i < sec.size(); ++i)
		{
			if(sec[i] == '.')
			{
				thrid.push_back(sec[i]);

				for(int j = i + 1; j < sec.size(); ++j)
				{
					if(sec[j] != '.')
						break;

					i = j;
				}
			}
			else
			{
				thrid.push_back(sec[i]);
			}
		}

		cout << thrid << endl;

		string four;

		for(int i = 0; i < thrid.size(); ++i)
		{
			if(i == 0 || i == thrid.size() - 1)
			{
				if(thrid[i] != '.')
					four.push_back(thrid[i]);
			}
			else
				four.push_back(thrid[i]);
		}

		cout << four << endl;

		string five = four;
		if(five.size() == 0)
			five = "a";

		cout << five << endl;

		string six;
		if(five.size() >= 16)
		{
			for(int i = 0; i < 15; ++i)
			{
				six.push_back(five[i]);
			}

			for(int i = six.size() - 1; i >= 0; --i)
			{
				if(six[i] == '.')
					six.pop_back();
				else
					break;
			}
		}
		else
			six = five;

		cout << "6" << six << endl;

		string seven = six;

		if(six.size() <= 2)
		{
			char tar = six[six.size() - 1];


			while(seven.size() < 3)
				seven.push_back(tar);
		}

		cout << "ans " << seven << endl;
	}
}
