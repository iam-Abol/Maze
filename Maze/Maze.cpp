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
class Stack{
	Position *head;
	int size;
	
public:
	Stack(){
		head = new Position;
		size = 0;
	}
	~Stack(){
		delete head;
	}
	void print(){
		if (size == 0)
			std::cout << "- - -> STACK IS EMPTY ! <- - - " << std::endl;
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
	Stack s;
	s.print();

	return 0;
}

