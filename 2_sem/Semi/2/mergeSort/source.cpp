#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>

using i64 = int64_t;
using Array = std::vector<i64>;

void insertionSort(Array::iterator b, Array::iterator e)
{
    int key;
    for (auto it = b + 1; it != e; ++it)
    {
        key = *it;
        auto j = it - 1;
        while (j >= b && *j > key)
        {
            *(j + 1) = *j;
            j = j - 1;
        }
        *(j + 1) = key;
    }
}
/*
void insertSort(Array::iterator b, Array::iterator e)
{
	
}
*/

void merge(Array::iterator l_begin, Array::iterator l_end,
		   Array::iterator r_begin, Array::iterator r_end,
		   Array::iterator out_it)
{
	while(l_begin != l_end && r_begin != r_end){
		if(*l_begin < *r_begin){
			*out_it = *l_begin;
			++l_begin;
		}
		else{
			*out_it = *r_begin;
			++r_begin;
		}
		++out_it;
	}
	
	while (l_begin != l_end){
		*out_it = *l_begin;
		++out_it;
		++l_begin;
	}
	
	while (r_begin != r_end){
		*out_it = *r_begin;
		++out_it;
		++r_begin;
	}
}

void mergeSortInternal(Array::iterator b, Array::iterator e, Array& buf, size_t n, bool optim)
{
	if (n <= 1)
		return;
	if (n == 2){
		if(*b > *(b+1))
			std::swap(*b, *(b+1));
		return;
	}
	if(optim && n < 16){
		insertionSort(b, e);
		return;
	}
	mergeSortInternal(b, b + n/2, buf, n/2, optim);
	mergeSortInternal(b + n/2, e, buf, n - n/2, optim);
	merge(b, b + n/2, b + n/2, e, buf.begin());
	
	for (size_t i = 0; i < n; ++i){
		*b = buf[i];
		++b;
	}
}

void mergeSort(Array::iterator b, Array::iterator e, bool optim)
{
	auto size = e - b;
	Array buf(size);
	mergeSortInternal(b, e, buf, size, optim);
}

double avg(const std::vector<double>& arr)
{
	double sum = 0;
	for (auto x : arr)
		sum += x;
	return sum / arr.size();
}

int main()
{
	std::random_device rd;
	std::mt19937 g(rd());
	
	std::fstream f1("time_without_optimization.txt", std::ios_base::out);
	
	std::vector<double> times(4);
	for (i64 n = 1; n < 1e6; n*=2){
		for (i64 tries = 0; tries < 4; ++tries){
			
			Array arr(n);
			for (int i = 0; i < n; ++i){
				arr[i] = i;
			}
			
			std::shuffle(arr.begin(), arr.end(), g);
			
			auto start = std::chrono::steady_clock::now();
			mergeSort(arr.begin(), arr.end(), false);
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> dur = end - start;
			
			times[tries] = dur.count();
		}
		double time = avg(times);
		f1 << n << " " << std::fixed << std::setprecision(15) << time << "\n";
	}
	
	f1.close();
	
	std::fstream f2("time_with_optimization.txt", std::ios_base::out);
	
	for (i64 n = 1; n < 1e6; n*=2){
		for (i64 tries = 0; tries < 4; ++tries){
			
			Array arr(n);
			for (int i = 0; i < n; ++i){
				arr[i] = i;
			}
			
			std::shuffle(arr.begin(), arr.end(), g);
			
			auto start = std::chrono::steady_clock::now();
			mergeSort(arr.begin(), arr.end(), true);
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> dur = end - start;
			
			times[tries] = dur.count();
		}
		double time = avg(times);
		f2 << n << " " << std::fixed << std::setprecision(15) << time << "\n";
	}
	
	f2.close();
	
	return 0;
}
