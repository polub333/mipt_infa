#include <cassert>
#include <iostream>
#include <cassert>

using namespace std;

struct JumpList { JumpList *next, *jump; unsigned id; };

void erase_jump_list(JumpList *head) {
    if (nullptr == head) return;
    erase_jump_list(head->next);
    delete head;
}

JumpList* deserialize(unsigned *begin, unsigned *end);

JumpList* deserialize(unsigned *begin, unsigned *end)
{
	auto it = begin;
	JumpList* prev;
	JumpList* node = new JumpList;
	node->id = *it;
	JumpList* beg = node;
	it+=2;
	while(it != end){
		prev = node;
		node = new JumpList;
		node->id = *it;
		node->next = nullptr;
		prev->next = node;
		it+=2;
	}
	it = begin;
	node = beg;
	while(node != nullptr){
		++begin;

		JumpList* toj = node;
		for(unsigned int i=0;i<*begin;++i){
			toj = toj->next;
		}

		if(toj == node){
			node->jump = nullptr;
		}
		else{
			node->jump = toj;
		}
		++begin;
		node = node->next;

	}
	//delete prev;
	//delete node;			cout<<2<<" ";

	return beg;
	
}

int main() {
    unsigned dscr[12] = {1, 3, 2, 3, 3, 3, 4, 0, 5, 0, 6, 0};
    auto head = deserialize(dscr, dscr + 12);
    
    /*
	while(head != nullptr){
    	cout<<head->id<<endl;
    	head = head->next;
	}
	*/
    
	
	
	{
        auto tmp = head; unsigned cnt = 0;
        while (nullptr != tmp) {
            assert(tmp->id == dscr[cnt]);
            assert(tmp->jump == nullptr or tmp->jump->id == dscr[cnt + 2 * dscr[cnt + 1]]);
            tmp = tmp->next;
            cnt += 2;
        }
    }
    erase_jump_list(head);
    
    return 0;
}
