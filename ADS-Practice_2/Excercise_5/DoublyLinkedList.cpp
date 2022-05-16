#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>


void DoublyLinkedList::insert(int key)
{
	Node* newNode = new Node(key);
	newNode->next = head;
	newNode->prev = nullptr;
	if (head != nullptr) head->prev = newNode;
	head = newNode;
}

/**
 *	Diese Funktion löscht einen Knoten aus der doppelt verketteten Liste
 *  und passt gleichzeit die Pointer auf Vorgänger und Nachfolger an.
 *
 */
void DoublyLinkedList::erase(Node* delNode)
{
	/*
		TODO: Übung 2 - Aufgabe 5
	*/

	//Listenmitte
	/*if (delNode->next != nullptr && delNode->prev != nullptr)
	{
		delNode->prev->next = delNode->next;
		delNode->next->prev = delNode->prev;
	}*/

	//Wenn nicht Listenanfang
	if (delNode->prev != nullptr)
	{
		delNode->prev->next = delNode->next;
	}

	//Wenn Listenanfang
	else
	{
		head = delNode->next;
	}

	//Wenn nicht Listenende
	if (delNode->next != nullptr)
	{
		delNode->next->prev = delNode->prev;
	}

	////listenanfang
	//else if (delNode->prev == nullptr)
	//{
	//	delNode->next->prev = delNode;
	//}

	////listenende
	//else if (delNode->next == nullptr)
	//{
	//	delNode->prev->next = delNode;
	//}

	

	delete delNode;
}

/**
 *	Löschen eines Knoten aus der doppelt verketteten Liste
 *
 *	Diese Funktion sucht den Knoten in der Liste, der gelöscht werden soll.
 *	Das eigentliche Löschen geschieht in der privaten Funktion erase(Node* ..)
 *
 */
bool DoublyLinkedList::erase(int key)
{
	/*
		TODO: Übung 2 - Aufgabe 5
	*/

	if (!search(key)) 
	{
		std::cout << "Knoten nicht vorhanden!" << std::endl;
		return false;
	}

	else
	{
		auto del = head;
		while (del != nullptr && del->key != key)
		{
			del = del->next;
		}
		erase(del);
	}
	

	return false;
}

bool DoublyLinkedList::search(int key)
{
	auto node = head;
	while (node != nullptr && node->key != key) node = node->next;
	if (node == nullptr) return false;	// Element nicht in der Liste
	return true;						// Element in Liste enthalten
}

DoublyLinkedList::DoublyLinkedList() :
	head{ nullptr }
{
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (head != nullptr) {
		Node* node = head;
		head = head->next;
		delete node;
	}
}

void DoublyLinkedList::print() {
	std::cout << "List( ";
	auto node = head;
	while (node != nullptr) {
		std::cout << node->key << " ";
		node = node->next;
	}
	std::cout << ")" << std::endl;
}

void DoublyLinkedList::insertionSort() {
	Node* node = head;
	Node* minNode = head;

	// iterieren über die gesamte Liste
	while (node->next != nullptr) {

		Node* tmp_node = node;			// Zeiger auf letztes Element des sortierten Bereichs
		Node* tmp_next = node->next;	// Zeiger auf das erste Elemente im unsortierten Bereich


		if (tmp_node->key < tmp_next->key) {
			// Sortierung bereits von tmp_node und tmp_next korrekt
			// --> weiter zum nächsten Element
			node = node->next;
		}
		else {
			// tmp_next ist an der falschen Position
			// so lange um ein Element nach links verschieben, bis die Sortierung stimmt
			while (tmp_node != nullptr && tmp_next->key < tmp_node->key) {
				// tempräres Elemente - benötigt beim swappen der Elemente
				auto tmp_next_next = tmp_next->next;
				// Vertauschen der Elemente und Anpassen 
				tmp_next->prev = tmp_node->prev;
				tmp_next->next = tmp_node;
				tmp_node->prev = tmp_next;
				tmp_node->next = tmp_next_next;
				// Anpassen der Vorgänger/Nachfolger-Referenzen
				if (tmp_next_next != nullptr) tmp_next_next->prev = tmp_node;
				if (tmp_next->prev != nullptr) tmp_next->prev->next = tmp_next;
				// Element für nächsten Schleifendurchgang wählen
				tmp_node = tmp_next->prev;
			}
			// Head auf das 
			if (tmp_next != nullptr && tmp_next->key < minNode->key) minNode = tmp_next;
		}
	}
	head = minNode;
}


//Task 6
void DoublyLinkedList::selectionSort()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	Node* node = head;

	while (node->next != nullptr)
	{
		Node* minNode = node;
		int minKey = node->key;

		for (auto current = node->next; current != nullptr; current = current->next)
		{
			if (minKey >= current->key)
			{
				minNode = current;
			}
		}

		auto node2 = node->next;

		//Try 1
		//node->next = minNode->next;
		//node->prev = minNode->prev;
		//minNode->next = node2->next;
		//minNode->prev = node2->prev;

		//Try 2
		/*node->prev = minNode->prev;
		node->next = minNode;
		minNode->prev = node;
		minNode->next = node2->next;

		if (node2 != nullptr)
		{
			node2->prev = minNode;
		}

		if (node->prev != nullptr)
		{
			node->prev->next = node;
		}

		minNode = node->prev;*/



		//std::swap(node->key, minNode->key);


		node = node->next;
		if (node == nullptr)
		{
			break;
		}
	}

}

void DoublyLinkedList::sortList() {
	Node* current = nullptr;
	Node* index = nullptr;
	int temp;
	//Check whether list is empty  
	if (head == nullptr) {
		return;
	}
	else {
		//Current will point to head  
		for (current = head; current->next != nullptr; current = current->next) {
			//Index will point to node next to current  
			for (index = current->next; index != nullptr; index = index->next) {
				//If current's data is greater than index's data, swap the data of current and index  
				if (current->key > index->key) {
					temp = current->key;
					current->key = index->key;
					index->key = temp;
				}
			}
		}
	}
}