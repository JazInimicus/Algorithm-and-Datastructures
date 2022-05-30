#pragma once

class Treenode {
public:
	int item; // Daten
	int height; // H�he des Knoten
	Treenode* left; // linker Nachfolgeknoten
	Treenode* right; // rechter Nachfolgeknoten
};