#include "stdafx.h"
#include <iostream>
class Position{
public:
	int i , j;
	Position *next;

	Position(int i, int j) :i(i), j(j){};
	~Position(){
		delete next;
	}
};
class stack{
	Position *head;
	int size;
	
public:
	
};
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

