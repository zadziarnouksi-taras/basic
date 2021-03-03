#include <iostream>
#include <cmath>

using namespace std;

/*
Enter 4 integers. These are the coordinates of the two knights on the chessboard. 
Do they beat each other?
*/

bool check(int x1, int x2, int z1, int z2)
{
	if((abs(x1-x2)==1 and abs(z1-z2)==2) 
		or (abs(z1-z2)==1 and abs(x1-x2)==2) )
	{
		return true;	
	}
	return false;
}


int main(void)
{
	int x1, x2, z1, z2;
	cout << "Enter the horizontal position of the first chess piece: ";
	cin >> x1;
	cout << "Enter the vertical position of the first chess piece: ";
	cin >> z1;
	cout << "Enter the horizontal position of the second chess piece: ";
	cin >> x2;
	cout << "Enter the vertical position of the second chess piece: ";
	cin >> z2;

	if (check(x1,x2,z1,z2))
	{
		cout << "Beat each other." << endl;
	}else 
	{
		cout << "NO beat each other." << endl;
	}
return 0;
}

