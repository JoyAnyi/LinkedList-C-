#include <iostream>
using namespace std;

struct Node {
public:
	int data;
	Node* next;

	Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
	Node* head;
	Node* newNode;
	Node* temp;

public:
	LinkedList() {
		head = nullptr;
	}

	void insert(int val) {
		newNode = new Node(val);
		if(head==nullptr) {
			head = newNode;
			return;
		} else {
			temp = head;
			while(temp->next !=nullptr) {
				temp=temp->next;
			}
			temp->next=newNode;
		}
	}
	void display() {
		temp = head;
		while(temp !=nullptr) {
			cout<<temp->data<<"->";
			temp=temp->next;
		}

		cout<<"NUll"<<endl;
	}

	void removeFirst() {
		if(head == nullptr) {
			cout<<"The list is empty nothing to remove"<<"\n";
			return;
		}
		temp = head;
		head = head->next;
		delete temp;
	}

	void reverse() {
		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;
		while(current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
};
int main() {
	LinkedList list;
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(50);
	list.insert(60);
	list.display();
	cout<<"List before delete"<<"\n";
	list.removeFirst();
	cout<<"List after delete";
	list.display();
	list.reverse();
	list.display();
	return 0;
}
