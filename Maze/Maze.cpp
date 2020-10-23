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
	int isEmpty(){
		if (size == 0)
			return true;
		else
			return false;
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
		Position *start = new Position(0, 0);
		maze[0][0].isVisited = true;
		solution.push(start);
		bool shouldBreak = false;
		for (int i = solution.top()->i; solution.top()->i != size - 1 && solution.top()->j != size - 1;){
			for (int j = solution.top()->j;;){
				if (j + 1 < size && maze[i][j + 1].data == '0' && maze[i][j + 1].isVisited == false){
					Position* newPosition = new Position(i, j + 1);
					solution.push(newPosition);
					maze[i][j + 1].isVisited = true;
				}
				else if (i + 1 < size && maze[i + 1][j].data == '0'&&maze[i + 1][j].isVisited == false){
					Position* newPosition = new Position(i + 1, j);
					solution.push(newPosition);
					maze[i + 1][j].isVisited = true;
				}
				else if (i + 1 < size && j + 1 < size &&maze[i + 1][j + 1].data == '0'&&maze[i + 1][j + 1].isVisited == false){
					Position* newPosition = new Position(i + 1, j + 1);
					solution.push(newPosition);
					maze[i + 1][j + 1].isVisited = true;
				}
				else if (i - 1 >= 0 && j + 1 < size&&maze[i - 1][j + 1].data == '0'&&maze[i - 1][j + 1].isVisited == false){
					Position* newPosition = new Position(i - 1, j + 1);
					solution.push(newPosition);
					maze[i - 1][j + 1].isVisited = true;
				}
				else  if (j - 1 >= 0 && maze[i][j - 1].data == '0'&&maze[i][j - 1].isVisited == false){
					Position* newPosition = new Position(i, j - 1);
					solution.push(newPosition);
					maze[i][j - 1].isVisited = true;
				}
				else if (i - 1 >= 0 && maze[i - 1][j].data == '0'&&maze[i - 1][j].isVisited == false){
					Position* newPosition = new Position(i - 1, j);
					solution.push(newPosition);
					maze[i - 1][j].isVisited = true;
				}
				else if (i - 1 >= 0 && j - 1 >= 0 && maze[i - 1][j - 1].data == '0'&&maze[i - 1][j - 1].isVisited == false){
					Position* newPosition = new Position(i - 1, j - 1);
					solution.push(newPosition);
					maze[i - 1][j - 1].isVisited = true;
				}
				else if (i + 1 < size&&j - 1 >= 0 && maze[i + 1][j - 1].data == '0'&&maze[i + 1][j - 1].isVisited == false){
					Position* newPosition = new Position(i + 1, j - 1);
					solution.push(newPosition);
					maze[i + 1][j - 1].isVisited = true;
				}
				else{
					solution.pop();
				}
				i = solution.top()->i;
				j = solution.top()->j;
				if (i == size - 1 && j == size - 1){
					shouldBreak = true;
					break;
				}

			}
			if (shouldBreak)
				break;

		}

		solution.print();


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

