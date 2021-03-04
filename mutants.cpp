#include <iostream>

using namespace std;

/*
mutants.cpp: At night Minsk was attacked by 'm' mutants. They multiply by 'p' percent every night. 
Every day the municipal services of Minsk kill 'n' mutants. In how many days will the workers 
celebrate the victory over the mutants?
*/

int main()
{
	int m, p, n, day = 1;

	cout << "Type the number of monsters and press enter: ";
	cin >> m;
	cout << "Enter the percentage by which they breed every night: ";
	cin >> p;
	cout << "Enter the number of monsters that the worker is killed per day: ";
	cin >> n;

	while(day < 365){
		if(m <= n){
			cout <<"Workers destroyed monsters in " << day << " day(s)." << endl;
			return 0;
		}
		m -= n;
		m = m + (m*p/100);
		day++;
	}
	cout << "A year has passed. I'm afraid no one survived..." << endl;
	return 0;
}