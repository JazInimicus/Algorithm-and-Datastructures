#include <iostream>
#include "binarysearchtree.h"
#include "binarysearchtree.cpp"

int main()
{
	BST* Baum = new BST();

	Baum->insert(5);
	Baum->insert(3);
	Baum->insert(7);
	Baum->insert(1);
	Baum->insert(4);
	Baum->insert(6);
	Baum->insert(10);
	Baum->insert(2);
	Baum->insert(9);
	Baum->insert(11);
	Baum->insert(8);

	Baum->printBST();

	delete Baum;

	system("PAUSE");
	return 0;
}