#include <iostream>

int main()
{
	int64_t* p = new int64_t;
	std::cout << *p << " " << p << " " << &p << std::endl;
	delete p;
	
	int64_t* v = new int64_t[20];
	for (int i = 0; i < 10; ++i){
		*(v+i) = i;
	}
	
	for (int i = 0; i < 10; ++i){
		std::cout << *(v+i) << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
