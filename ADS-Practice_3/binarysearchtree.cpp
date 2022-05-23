#include <iostream>
#include "binarysearchtree.h"
#include "Treenode.h"

void BST::deleteBST(Treenode* p)
{
	Treenode* current = p; //current position
	
	while (head->right != nullptr && head->left != nullptr)
	{
		while (current->left != nullptr)
		{
			current = current->left;
		}
		if (current->right != nullptr)
		{
			current = current->right;
		}
		else
		{
			delete current;
			current = p;
		}
	}

	delete head;


}

BST::BST()
{
	this->head = new Treenode();
}

BST::~BST()
{
	deleteBST(head->right);
}

void BST::insert(int key)
{
	Treenode* node = new Treenode();
	node->item = key;

	//Tree empty
	if (head->right == nullptr)
	{
		head->right = node;
	}


	else
	{
		Treenode* current = head->right;

		while (true)
		{
			if (node->item <= current->item && current->left != nullptr)
			{
				if (current->left ==nullptr)
				{
					current->left = node;
					break;
				}
				else
				{
					current = current->left;
				}
			}
			if (node->item > current->item && current->right != nullptr)
			{
				if (current->right == nullptr)
				{
					current->right = node;
					break;
				}
				else
				{
					current = current->right;
				}
			}
			break;
		}
		current = node;
	}

}

void BST::printBST()
{
	int Level = 0;
	Treenode* current = head->right;

	std::cout << "Niveau " << Level << ": ";
	std::cout << "(" << current->item << ")";


}
