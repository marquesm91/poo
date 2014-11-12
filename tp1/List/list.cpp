#include "list.h"

List::List()
{
	first = (Cell *) malloc(sizeof(Cell)); /* Head cell */
	last = first;
	first->next = NULL;
}

List::~List()
{	
	Cell *iterator;

	while(first != NULL)
	{
		iterator = first;
		first = first->next;
		free(iterator);
	}
	
}

bool List::ReadData(istream &is)
{
	string numbers;

	if(is == cin)
	{
		getline(is, numbers);
		if (numbers.begin() != numbers.end())
		{
			string::const_iterator iterator = numbers.begin();
			string::const_iterator end = numbers.end();
			int first_ch = 0;
			int last_ch = 0;

			while(true) /* True until iterator find end */
			{
				string::value_type ch = (*iterator);
				if(ch == ' ' && (last_ch - first_ch) > 0)
				{
					string number = numbers.substr(first_ch,last_ch);
					Insert(atoi(number.c_str()));
					first_ch = last_ch + 1; /* Point to start of next substring jumping the space */
				}
				else if(end == iterator) /* Case for last number of string numbers*/
				{
					string number = numbers.substr(first_ch,(last_ch)); /* get the last one */
					Insert(atoi(number.c_str()));
					break;
				}

				iterator++;
				last_ch++;
			}
		}
		else
		{
			cout << "Can't insert an empty string on list!" << endl; 
			return false;
		}
	}
	else
	{
		while(!is.eof())
		{
			getline(is, numbers, DELIMITER);
			Insert(atoi(numbers.c_str()));
		}
	}

	return true;
}

bool List::WriteData(ostream &os)
{
	Cell *iterator;

	iterator = first;

	while(iterator->next != NULL)
	{
			os << iterator->next->data.item << " ";
			iterator = iterator->next;
	}

	os << endl;

	return true;
}

bool List::HaveThisNumber(int number)
{
	Cell *iterator;

	iterator = first;

	while(iterator->next != NULL)
	{
		if(iterator->next->data.item == number)
			return true;
		else
			iterator = iterator->next;
	}

	return false;
}

bool List::HaveThisNumber(int number, Cell *&iterator)
{
	while(iterator->next != NULL)
	{
		if(iterator->next->data.item == number)
			return true;
		else
			iterator = iterator->next;
	}

	return false;
}

bool List::Insert(int number)
{
	Cell *iterator;

	iterator = first;

	/* Verify if number exist on list*/
	if(HaveThisNumber(number))
	{
		cout << "Number " << number << " already exists on list to insert" << endl;
		return false; /* Can't insert, return false */
	}
	else
	{
		if(iterator->next == NULL) /* Case of empty list (just Head Cell) */
		{
			iterator->next = (Cell *) malloc(sizeof(Cell));
			last = iterator->next;
			last->data.item = number;
			last->next = NULL;
			return true;
		}
		else if(number < first->next->data.item) /* Case for first cell */
		{
			Cell *newCell;
			newCell = (Cell *) malloc(sizeof(Cell));
			newCell->data.item = number;
			newCell->next = first->next;
			first->next = newCell;
			return true;
		}
		else /* other cases */
		{
			while(true)
			{
				iterator = iterator->next;
				
				if(iterator->next == NULL) /* Case for last cell */
				{
					iterator->next = (Cell *) malloc(sizeof(Cell));
					last = iterator->next;
					last->next = NULL;

					if(number > iterator->data.item) /* Last cell has a lower number */
					{
						last->data.item = number;
						return true;
					}
					else /* Last cell has a greater number */
					{
						last->data.item = iterator->data.item;
						iterator->data.item = number;
						return true;
					}
				}
				else if(number > iterator->data.item && number < iterator->next->data.item) /* Cases to insert on middle of list */
				{
					Cell *newCell;
					newCell = (Cell *) malloc(sizeof(Cell));
					newCell->data.item = number;
					newCell->next = iterator->next;
					iterator->next = newCell;
					return true;
				}
			}
		}
	}
}

bool List::Remove(int number)
{
	Cell *iterator;
	Cell *toBeRemoved;

	iterator = first;

	/* Verify if number exist on list*/
	if(!HaveThisNumber(number, iterator))
	{
		cout << "Number " << number << " doesn't exists on list to remove" << endl;
		return false; /* Can't remove, return false */
	}
	else
	{
		toBeRemoved = iterator->next;
		iterator->next = toBeRemoved->next;
		free(toBeRemoved);
		return true;
	}
}