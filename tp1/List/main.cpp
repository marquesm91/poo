#include "list.h"

int main(int argc, char **argv)
{
	List list;
	ostream *os;
	istream *is;

	if(argc > 1) /* We have files on command line*/
	{
		ofstream outFile;
		ifstream inFile;

		inFile.open(argv[1]);
		outFile.open(argv[2]);

		if(!outFile.is_open())
		{
			cout << "Can't open file for writing!" << endl;
			return false;
		}
		if(!inFile.is_open())
		{
			cout << "Can't open file for reading!" << endl;
			return false;
		}

		os = &outFile;
		is = &inFile;

		/* Read from one file and write on another */

		list.ReadData(*is);
		list.WriteData(*os);
	}
	else
	{
		os = &cout;
		is = &cin;

		/* Some tests for cin/cout */

		list.Remove(1);

		for(int i = 0; i < 10; i++)
		{
			list.ReadData(*is);
			list.WriteData(*os);
		}

		list.Remove(1);
		list.Remove(2);
		list.Remove(3);
		list.Remove(4);
		list.Remove(5);
		list.Remove(6);
		list.Remove(7);
		list.WriteData(*os);
	}

	return 0;
}