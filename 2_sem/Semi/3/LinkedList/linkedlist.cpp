#include "linkedlist.h"

List::~List()
{
	if((head == nullptr) && (tail == nullptr))
		return;
	ListItem* cur = head;
	while(cur != nullptr){
		head = cur->next;
		delete cur;
		cur = head;
	}	
}

void List::pushBack(Data d)
{
	ListItem* itm = new ListItem;
	itm->data = d;
	itm->prev = tail;
	
	if(head == nullptr && tail == nullptr){
		heaf = itm;
		tail = itm;
		itm->next = nullptr;
	}
	
	tail->next = itm;
	itm->next = nullptr;
	tail = itm;
}

void List::popFront()
{
	if((head == nullptr) && (tail == nullptr)){
		std::cout << "You're fucking idiot, dude" << std::endl;
	}
	if(head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
}

void List::show()
{
	ListItem* cur = head
	while(cur != nullptr){
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}

