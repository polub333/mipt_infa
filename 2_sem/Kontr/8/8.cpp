#include <sstream>
#include <iostream>

using namespace std;

struct BMine {
    unsigned income;   // ��������� ����� �� ���������� ��������� � ���� ����
    BMine *next_cham;  // ��������� �� ���������� � ��������� ����
};

unsigned max_income(BMine *mine, unsigned steps);

// ������� ������ ������ �� ����� 
BMine* read_mine(std::istream &is) {
    unsigned N;
    is >> N;
    BMine *mine = nullptr;
    for (unsigned cnt = 0; cnt != N; ++cnt) {
        auto cham = new BMine{0, nullptr};
        if (nullptr == mine) {
            cham->next_cham = cham;
        }
        else {
            cham->next_cham = mine->next_cham;
            mine->next_cham = cham;
        }
        mine = cham;
        is >> cham->income;
    }
    return mine;
}

// ������� ������������ ������
void erase_mine(BMine *mine) {
    BMine *current = mine;
    while (current != current->next_cham) {
        auto extract = current->next_cham;
        current->next_cham = current->next_cham->next_cham;
        delete extract;
    }
    delete current;
}

bool test() {
    std::stringstream mine_description("10 1 0 1 4 12 3 1 2 1 1 5");
    unsigned const number_of_steps = 5u;
    unsigned const expected = 22u;
    auto mine = read_mine(mine_description);
    auto actual = max_income(mine, number_of_steps);
    erase_mine(mine);
    return actual == expected;  
}

unsigned max_income(BMine* mine, unsigned steps)
{
	unsigned int res = 0;
	BMine* b = mine;
	BMine* e = mine;

	bool flag = true;
	unsigned int st=1;
	unsigned int cur = e->income;
	do{
		if(st < steps){
			e = e->next_cham;

			cur += e->income;
			++st;
		}
		else{
			if(cur > res){
				res = cur;
				//cout << res << " ";
			}
			e = e->next_cham;
			cur += e->income;
			cur -= b->income;
			
			b = b->next_cham;
			flag = false;
		}
	} while(b != mine || flag);
	//cout<<res<<endl;
	
	return res;
}

int main()
{
	cout<<test()<<endl;
	return 0;
}
