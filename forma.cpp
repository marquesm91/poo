#include "forma.h"

ostream& operator <<(ostream& os, const Forma& f)
{
	f.le(os);
	return os;
}

istream& operator >>(istream& is, Forma& f)
{
	f.escreve(is);
	return is;
}

linhas::linhas() : max_coord(2)
{
	
	cout << "construtor linhas\n";
	
	cin >> *this;
}

void linhas::le(ostream& os) const
{ 
	os << "Line coordinates:\n";
	for (int i = 0; i < max_coord; i++)
		os << "c" << i << " = (" << c[i].x << "," << c[i].y << "," << c[i].z << ")\n";
};

void linhas::escreve(istream& is)
{
	string input;
    
    if (&is == &std::cin)
    {
        /* With 2 coordinates we can make a line */ 
	    for (int i = 0; i < max_coord; i++)
	    {
		    input.clear();
		    is >> input;
		    
    		c[i].x = (input[0] - '0') % 48;
    		c[i].y = (input[2] - '0') % 48;
    		c[i].z = (input[4] - '0') % 48;
	    }
    }
    else /* search for LINE on file */
    {
        is >> input;
        
    }
	
};


