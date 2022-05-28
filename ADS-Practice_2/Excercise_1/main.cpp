#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

// �bungsblatt 2 Aufgabe 1

// Client-Programm
int main() {

	/*
	 TODO
	 Bitte bearbeiten die mit TODO markierren Methoden der
	 Klasse Queue in der Datei Queue.cpp
	 */

	Queue Qewe(6);

	Qewe.enqueue(4);
	Qewe.enqueue(1);
	Qewe.enqueue(3);
	Qewe.dequeue();
	Qewe.enqueue(8);
	Qewe.dequeue();

	//Queue is full
	/*Qewe.enqueue(8);
	Qewe.enqueue(4);
	Qewe.enqueue(5);
	Qewe.enqueue(3);*/

	
	//Queue is empty
	Qewe.dequeue();
	Qewe.dequeue();


	Qewe.printAll();

	Qewe.isEmpty();
	Qewe.isFull();


	return 0;
}