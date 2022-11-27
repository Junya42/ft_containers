#ifdef STL
    #define NM std
#else
    #define NM ft
#endif

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

#include <sys/time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include "../vector.hpp"
#include "../stack.hpp"
#include <stack>

long long getCurrentTime( void ) 
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}


int main( void )
{
	NM::stack<int> stack;

	std::cout << RED << "STACK BENCHMARK" << WHITE << std::endl << std::endl;

	std::cout << "[PUSH] 1 000 000 values" << std::endl;

	long long start = getCurrentTime();

    for ( int i = 0 ; i < 1000000 ; i++ )
    {
        stack.push(i);
    }
	std::cout << GREEN << getCurrentTime() - start << "ms" << WHITE << std::endl;

	std::cout << "[POP]" << std::endl;
	start = getCurrentTime();
    for ( int i = 0 ; i < 1000000 ; i++ )
    {
        stack.pop();
    }
	std::cout << GREEN << getCurrentTime() - start << "ms" << WHITE << std::endl << std::endl << std::endl;
	
    return 0;
}
