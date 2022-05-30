#pragma once
#include"Treenode.h"

class BST {
private:
    Treenode* head;
    int computeHeight(Treenode* p); // rekursive Methode, 
    // berechnet die H�he zum 
    // Knoten p und gibt diese 
    // zur�ck 

    void deleteBST(Treenode* p); // l�scht den Teilbaum ab p
   
    // rekursive Methode zur Ausgabe aller Knoten zu einer H�he
    int printHeight(Treenode* node, int height);

public:
    BST();
    ~BST();
    void insert(int key);
    void insert2(int key);
    int getBSTHeight(); // Starterfunktion f�r die rekursive 
     // Methode und liefert die H�he des 
     // Baumes zur�ck 
    void printBST(); // Ausgabe des BST in Levelorder
    void printBST2();
    void printNiveau(int niveau); // Ausgabe aller Knoten zu einem Niveau
    void printHeight(int height); // Ausgabe aller Knoten zu einer H�he
};