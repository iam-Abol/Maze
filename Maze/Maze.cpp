#include "stdafx.h"
#include <iostream>
#include <thread>
class Position{
public:
	int i, j;
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
	void push(Position *newPosition){
		if (size == 0){
			size++;
			head = newPosition;
		}
		else{
			Position* temp = head;
			while (temp->next){
				temp = temp->next;
			}
			temp->next = newPosition;
			size++;
		}
	}
	void pop(){
		if (size == 1){
			head = NULL;
			size = 0;
		}
		else if (size > 1){
			Position *temp = head;
			while (temp->next->next != NULL){
				temp = temp->next;

			}
			size--;
			temp->next = NULL;
		}

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
struct Char
{
	char data;
	bool isvisited;
};
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

