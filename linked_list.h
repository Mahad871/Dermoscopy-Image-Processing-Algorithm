#include<iostream>
#include<conio.h>

using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(T d, Node* n)
	{
		setData(d);
		setNext(n);
	}

	Node(T d)
	{
		setData(d);
		next = NULL;

	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(Node* n)
	{
		next = n->next;

	}

	T getData()
	{
		return data;
	}

	Node* getNext()
	{
		return this->next;
	}

};

template <class T>
class SLinkedList {

public:

	Node<T>* head;


	SLinkedList()
	{
		head = NULL;
	}

	void insert(T d) {

		Node<T>* nod = new Node <T>(d);
		Node<T>* temp;
		temp = head;

		while (1)
		{
			if (head == NULL) {

				head = nod;
				break;

			}
			else if (temp->next == NULL) {
				temp->next = nod;
				break;
			}
			else
			{
				temp = temp->next;

			}

		}


	}


	void insertAtHead(T d) {

		Node<T>* nod = new Node <T>(d);
		nod->next = head;
		head = nod;

	}

	bool InsertAtIndex(T d, int ind) {


		Node<T>* nod = new Node <T>(d);
		Node<T>* temp;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i == ind) {
				nod->next = temp->next;
				temp->next = nod;
				return true;

			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}


	}

	int search(T d) {

		Node<T>* temp;
		temp = head;

		int i = 0;
		for (i = 0; 1; i++)
		{

			if (temp->data == d) {
				return i;
			}

			if (temp->next == NULL) {
				return -1;
			}
			else
			{
				temp = temp->next;

			}

		}
		return -1;

	}

	bool update(int ind, T d) {

		Node<T>* temp;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i == ind) {
				temp->data = d;
				return true;
			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}

	}


	bool remove(int ind) {

		Node<T>* temp;
		Node<T>* del;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i + 1 == ind) {
				del = temp->next;
				temp->next = temp->next->next;

				delete del;
				return true;

			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}

	}

	void print() {

		Node<T>* temp;
		temp = head;

		int i = 0;
		cout << "\n( ";
		for (i = 0; 1; i++)
		{

			cout << temp->data << ",";
			if (temp->data == -1) {
				cout << endl;
			}

			if (temp->next == NULL) {
				break;
			}
			else
			{
				temp = temp->next;

			}
			


		}

		cout << "\b ) ";

	}

	void mergeLists(SLinkedList obj2) {

		SLinkedList list;

		Node<T>* l1;
		l1 = head;
		Node<T>* l2;
		l2 = obj2.head;

		T arr[8] = { 0 };


		for (int i = 0; i < 4; i++)
		{
			arr[i] = l1->data;
			l1 = l1->next;


		}
		for (int i = 4; i < 8; i++)
		{
			arr[i] = l2->data;
			l2 = l2->next;


		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = i + 1; j < 8; j++)
			{
				if (arr[i] > arr[j]) {
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}


		}

		for (int i = 0; i < 8; i++)
		{
			cout << arr[i];


		}

		for (int i = 0; i < 8; i++)
		{

			list.insert(arr[i]);

		}

		this->head = list.head;


	}



};