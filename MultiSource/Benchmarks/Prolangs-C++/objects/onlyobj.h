// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  Written by Ashok Sreenivasan, TRDDC, Pune, India.  1993.  May be
//  distributed freely, provided this comment is displayed at the top.
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#ifndef __OBJ__

extern "C" {
int strlen(char *str1);
int strcmp(char *str1, char *str2);
char *strcpy(char *str1, char *str2);
char *strncpy(char *str1, char *str2, int i);
char *strcat(char *str1, char *str2);
}

class Object
{
	public :

// Constructor - Dummy, useful for breakpoints !

		Object () {}

// Destructor - also dummy but also virtual

		virtual ~Object () {}

//	(In)Equality operators

		virtual int operator == (Object &) = 0;
		int operator != (Object &o) { return !(*this == o); }

// Type enquiry function

		virtual char *Type () { return "Object"; }
};

typedef Object *Objp;

#define __OBJ__
#endif
