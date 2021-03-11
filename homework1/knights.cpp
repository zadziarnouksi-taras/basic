#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
Enter 4 integers. These are the coordinates of the two knights on the chessboard. 
Do they beat each other?
*/

const string HORIZ_POS = "horizontal";
const string VERT_POS = "vertical";
const string FIRST = "first";
const string SECOND = "second"; 


bool check(int x1, int x2, int z1, int z2);
void print(string position, string chessPieceNum);

int main()
{
	int x1, x2, z1, z2;

	print(HORIZ_POS,FIRST);
	cin >> x1;
	print(VERT_POS,FIRST);
	cin >> z1;
	print(HORIZ_POS,SECOND);
	cin >> x2;
	print(VERT_POS,SECOND);
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

bool check(int x1, int x2, int z1, int z2)
{
	if((abs(x1-x2)==1 and abs(z1-z2)==2) 
		or (abs(z1-z2)==1 and abs(x1-x2)==2) )
	{
		return true;	
	}
	return false;
}

void print(string position, string chessPieceNum)
{
	cout << "Enter the " << position << 
	 " position of the " << chessPieceNum << " chess piece: ";
}