#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

#define DELIMITER ' '

class List
{
		/* Data for each cell. On this case, just a integer*/
		typedef class Data
		{
			public:
				int item;
		
		}Data;
		
		/* Each cell of list */
		typedef class Cell
		{
			public:
				Data data;
				class Cell *next;

		}Cell;

		/* Pointers for first and last cells of list */
		Cell *first, *last;

	public:
		List();
		~List();
		bool HaveThisNumber(int, Cell *&);
		bool HaveThisNumber(int);
		bool Insert(int);
		bool Remove(int);
		bool WriteData(ostream &);
		bool ReadData(istream &);
};
