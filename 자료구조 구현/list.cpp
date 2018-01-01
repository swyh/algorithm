#include <iostream>
using namespace std;

struct information {
	int name;
};

class node {
private:
	node* prev;
	node* next;
	struct information info;
public:
	node() {
		prev = NULL;
		next = NULL;
	}
	node* getPrev() {
		return prev;
	}
	node* getNext() {
		return next;
	}
	struct information getInfo() {
		return info;
	}

	void setPrev(node* prev) {
		this->prev = prev;
	}
	void setNext(node* next) {
		this->next = next;
	}
	void setInfo(struct information info) {
		this->info = info;
	}
};

class List {
private:
	node* begin;
	node* end;
public:
	List() {
		begin = NULL;
		end = NULL;
	}

	node* getBegin() {
		return begin;
	}
	void setBegin(node* begin) {
		this->begin = begin;
	}
	node* getEnd() {
		return end;
	}
	void setEnd(node* end) {
		this->end = end;
	}
	void insert(struct information info) {
		node* newNode = new node;
		newNode->setInfo(info);

		if (begin == NULL) {
			begin = newNode;
			end = newNode;
		}
		else {
			end->setNext(newNode);
			newNode->setPrev(end);
			end = newNode;
		}
	}
	void print() {
		for (node* iter = begin; iter != NULL; iter = iter->getNext()) {
			printf("name : %d\n", iter->getInfo().name);
		}
	}

};

int main() {
	List list;
	int select = 1;
	int name;
	struct information info;
	while (select) {
		cout << "1. insert 2.print\n";
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "insert your name : ";
			cin >> name;
			info.name = name;
			list.insert(info);
			break;
		case 2:
			list.print();
			break;
		default:
			break;
		}
	}
	return 0;
}
