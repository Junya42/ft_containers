#include <array>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <vector>
#include "../map.hpp"
#include "../stack.hpp"
#include "../vector.hpp"
#include <sys/time.h>

#ifdef STL
	#define NM std
#else
	#define NM ft
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT 500

template<typename T>
class MutantStack : public NM::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<T>& src) { *this = src; }
		MutantStack<T>& operator=(const MutantStack<T>& rhs) 
		{
			this->c = rhs.c;
			return *this;
		}
		~MutantStack() {}

		typedef typename NM::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

long long getCurrentTime( void ) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	std::cout << std::endl;
	#ifdef STL
		std::cout << "\033[1;31m	STL version\033[0m" << std::endl;
	#else
		std::cout << "\033[1;31m	FT version\033[0m" << std::endl;
	#endif
	const int seed = atoi(argv[1]);
	srand(seed);

	long long start = getCurrentTime();

	NM::vector<std::string> vector_str;
	NM::vector<int> vector_int;
	NM::stack<int> stack_int;
	NM::vector<Buffer> vector_buffer;
	NM::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	NM::map<int, int> map_int;

	std::cout << "start" << std::endl;
	for (int i = 0; i < COUNT; i++)
	{
		//std::cout << i << " / " << COUNT << std::endl;
		vector_buffer.push_back(Buffer());
	}
	std::cout << "after vector buffer push back" << std::endl;
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::cout << "after vector buffer []" << std::endl;

	NM::vector<Buffer>().swap(vector_buffer);
	std::cout << "after vector swap" << std::endl;

	try
	{
		std::cout << "before vector at" << std::endl;
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
		std::cout << "after vector at" << std::endl;
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	std::cout << "before map int insert pair" << std::endl;
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(NM::make_pair(rand() % COUNT, rand() % 100));
	}
	std::cout << "after map int insert pair" << std::endl;

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand() % COUNT;
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		NM::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << "Total time: \033[1;32m" << getCurrentTime() - start << "ms\033[0m" << std::endl;
	return (0);
}
