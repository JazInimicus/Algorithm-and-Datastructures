#include <iostream>
#include "binarysearchtree.h"
#include "Treenode.h"
#include <queue>

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
	std::queue<int> QNiveau; //Integer-Niveau vom Knoten aus der ersten Queue
	std::queue<Treenode*> QNode; //Referenzen der Knoten erhalten
	int currniveau = 0;
	Treenode* current = head->right; //aktueller Knoten

	//Fall: Baum ist leer (head->irght == nullptr)
	if(head->right == nullptr)
	{
		std::cout << "Empty Tree" << std::endl;
	}

	else if(head->right != nullptr)
	{
		QNode.push(current);
		QNiveau.push(currniveau);

		//Niveauchange
		int prevNiveau = -1;

		while(!QNode.empty())
		{
			current = QNode.front(); //Erstes Element nehmen
			QNode.pop(); //Erstes Element löschen
			currniveau = QNiveau.front();
			QNiveau.pop();

			if(prevNiveau != currniveau)
			{
				std::cout << "Niveau " <<  currniveau << ": ";
				prevNiveau = currniveau;
			}
			
			std::cout << "(" << current->item << ")";
			
			if(current->left != nullptr)
			{
				QNode.push(current->left);
				QNiveau.push(currniveau + 1);
			}

			if(current->right != nullptr)
			{
				QNode.push(current->right);
				QNiveau.push(currniveau + 1);
			}


			//QNiveau.push(currniveau++);

			std::cout << std::endl;

		}
	}


	//std::cout << "Niveau " << niveau << ": ";
	

	return;
}

void BST::printBST2()
{
  std::queue<int> niveauQ; //Niveau der Knoten
  std::queue<Treenode*> nodeQ; //KInoten referencen
  int cNiveau = 0; //aktuelles Niveau
  Treenode* curr = head->right; //aktueller Knoten

  //Fall: Baum ist leer (head->right == nullptr) -> keine Ausgabe

  if (head->right == nullptr) {
    std::cout << "Baum ist leer." << std::endl;
  }

  else if (head->right != nullptr) {//nicht leer
    nodeQ.push(curr);
    niveauQ.push(cNiveau);

    //niveuawechsel
    int prevNiveau = -1;

    while (!nodeQ.empty()) { //solange nodes in queue
      curr = nodeQ.front(); //erstes element nehmen
      nodeQ.pop(); //element aus Queue loeschen
      cNiveau = niveauQ.front();
      niveauQ.pop();

      if (prevNiveau != cNiveau) { //Ausgabe bei Niveauwechsel
        std::cout << "Niveau " << cNiveau << ": ";
        prevNiveau = cNiveau;
      }

      std::cout << "(" << curr->item << ")";

      if (curr->left != nullptr) { //wenn vorhanden einfuegen
        nodeQ.push(curr->left);
      }

      if (curr->right != nullptr) {
        nodeQ.push(curr->right);
      }

      niveauQ.push(cNiveau++);
	  std::cout << std::endl;
    }
  }
  return;
}
