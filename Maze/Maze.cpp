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
	bool isVisited = false;
};
class Maze{
private:
	Char** maze;
	int size;
	Stack solution;
	
public:
	Maze(std::string path){
		std::fstream read(path);
		std::string line;
		read >> size;
		std::getline(read, line);
		std::cout << size << std::endl;
		maze = new Char*[size];
		for (int i = 0; i < size; i++){
			maze[i] = new Char[size];
		}

		
		for (int i = 0; i < size; i++){
			std::getline(read, line);
			int top = 0;
			std::cout << line << std::endl;
			for (int j = 0; j < line.size(); j++){
				if (line[j] != ' '){
					maze[i][top].data = line[j];
					top++;
				}
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				std::cout << maze[i][j].data;
			}
			std::cout << std::endl;

		}
		read.close();
	}
	void FindSolution(){

	}
	~Maze(){
		for (int i = 0; i < size; i++)
			delete[] maze[i];
		delete[] maze;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	// path = maze.txt or ... 
	std::cout << "Enter the path of txt file : " << std::endl;
	std::string path;
	std::cin >> path;
	Maze m(path);
	m.FindSolution();
	return 0;
}

