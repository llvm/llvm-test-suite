// roadlet.cc

#include <iostream>
#include "roadlet.h"

void roadlet::init(char *n)      
{
    name = n; 
    for(int i=0;i<8;i++) 
	the_moves[i] = return_null; 
}


std::ostream& operator<<(std::ostream& o, roadlet r)
{
    o << "roadlet " << r.name;
    return (o);
}
