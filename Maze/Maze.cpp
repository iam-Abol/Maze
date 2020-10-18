#include "stdafx.h"
#include <iostream>
class Position{
public:
	int i , j;
	Position *next;
	Position(){
	
	}
	Position(int i, int j) :i(i), j(j){};
	~Position(){
		delete next;
	}
};
class stack{
	Position *head;
	int size;
	
public:
	stack(){
		head = new Position;
		size = 0;
	}
	~stack(){
		delete head;
	}
	void print(){
		if (size == 0)
			std::cout << " - - -> STACK IS EMPTY ! <- - - " << std::endl;
		else{
			Position *temp = head;
			while (temp){
				std::cout << temp->i << " - " << temp->j << std::endl;
				temp = temp->next;
			}
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

