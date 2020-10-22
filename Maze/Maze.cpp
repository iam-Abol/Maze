#include "stdafx.h"
#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>
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
private:
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
	Position *top(){
		if (size == 1)
			return head;
		else{
			Position *temp = head;
			while (temp->next){
				temp = temp->next;
			}
			return temp;
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
	bool isVisited=false;
};
class Maze{
private:
	Char** maze;
	int size;
public:
	Maze(std::string path ){
		std::fstream read(path);
		
		read >> size;
		std::cout << size;
		maze = new Char*[size];
		for (int i = 0; i < size; i++){
			maze[i] = new Char[size];
		}
		
	}
	~Maze(){
		for (int i = 0; i < size; i++)
			delete[] maze[i];
		delete[] maze;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Maze m("maze.txt");
	
	return 0;
}

