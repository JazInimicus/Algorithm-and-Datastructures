#include <iostream>
#include "binarysearchtree.h"
#include "binarysearchtree.cpp"
#include <queue>

int main()
{
	BST* Baum = new BST();
	BST* Baum2 = new BST();

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

	Baum2->insert(6);
	Baum2->insert(2);
	Baum2->insert(9);
	Baum2->insert(1);
	Baum2->insert(4);
	Baum2->insert(7);
	Baum2->insert(3);
	Baum2->insert(5);
	Baum2->insert(8);

	//Jay Test
	// Baum->insert2(5);
	// Baum->insert2(3);
	// Baum->insert2(7);
	// Baum->insert2(1);
	// Baum->insert2(4);
	// Baum->insert2(6);
	// Baum->insert2(10);
	// Baum->insert2(2);
	// Baum->insert2(9);
	// Baum->insert2(11);
	// Baum->insert2(8);

	//Baum->printBST();
	//Baum2->printBST();

	//std::cout << std::endl << "Tree height: " << Baum2->getBSTHeight() << std::endl;


	for(int i = 0; i <= Baum2->getBSTHeight(); i++)
	{
		Baum2->printNiveau(i);
	}

	

	//Jay Test
	//Baum->printBST2();

	delete Baum;
	delete Baum2;

	//system("PAUSE");
	return 0;
}