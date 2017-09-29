//Elliot Maude
//DCF Bit stuffing

#include <iostream>

using namespace std;

int main()
{
	int bits[15] = { 0,1,1,1,1,1,1,0,1,1,1,1,1,1,0};
	int size = 15;
	int frame = 01111110;

	cout << "Before Stuffing: ";
	for (int i = 0; i < size; i++)
	{
		cout << bits[i];
	}
	cout << " --" << size << "Characters" << endl;

	int sBits[17] = { 0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0 };
	size = 17;

	cout << "After Stuffing:  ";
	for (int i = 0; i < size; i++)
	{
		cout << sBits[i];
	}
	cout << " --" << size << "Characters" << endl;
	cout << "After Framing: " << frame << bits << frame << endl;
	int temp;
	cin >> temp;
	return 0;
}