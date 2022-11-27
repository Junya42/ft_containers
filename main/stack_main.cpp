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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include "../vector.hpp"
#include "../stack.hpp"
#include <stack>

void test_constructor( void )
{
    std::cout << RED << " TEST_CONSTRUCTOR " << WHITE << std::endl << std::endl << std::endl;

    std::cout << YELLOW << " DEFAULT CONSTRUCTOR" << WHITE << std::endl;
    
    NM::stack<int> stack;
    std::cout << "stack size : " << stack.size() << " | is stack empty ? : " << stack.empty() << std::endl << std::endl;

    std::cout << YELLOW << " DEFAULT CONSTRUCTOR WITH CUSTOM CONTAINERS " << WHITE << std::endl;

    NM::stack<int, std::list<int> > stack2;

    std::cout << "stack2 size : " << stack2.size() << " | is stack2 empty ? : " << stack2.empty() << std::endl << std::endl;

    std::cout << std::endl;
    
}

void    test_operator( void )
{
    std::cout << RED << " TEST_OPERATOR" << WHITE << std::endl << std::endl << std::endl;
    NM::stack<int> stack1;
    NM::stack<int> stack2;

    stack1.push(1);
    stack1.push(42);
    stack1.push(100000);
    stack1.push(72);

    stack2.push(78);
    stack2.push(104);
    stack2.push(10);
    stack2.push(12);

    if ( stack1 == stack2 )
        std::cout << " Stack1 == Stack2 " << std::endl;
    if ( stack1 != stack2 )
        std::cout << " Stack1 != Stack2 " << std::endl;
    if ( stack1 > stack2 )
        std::cout << " Stack1 > Stack2 " << std::endl;
    if ( stack1 >= stack2 )
        std::cout << " Stack1 >= Stack2 " << std::endl;
    if ( stack1 <= stack2 )
        std::cout << " Stack1 <= Stack2 " << std::endl;
    if ( stack1 < stack2 )
        std::cout << " Stack1 < Stack2 " << std::endl;

    std::cout << std::endl;
}

void    test_few_things( void )
{
    std::cout << RED << " TEST_FEW_THINGS" << WHITE << std::endl << std::endl << std::endl;
    NM::stack<int> stack1;
    NM::stack<int> stack2;

    stack1.push(12124);
    stack1.push(4442);
    stack1.push(124500000);
    stack1.push(72);

    std::cout << "stack1 size : " << stack1.size() << " | is stack1 empty ? : " << stack1.empty() << std::endl << std::endl;

    stack2.push(78);
    stack2.push(104);
    stack2.push(10);
    stack2.push(12);

    std::cout << "stack2 size : " << stack2.size() << " | is stack2 empty ? : " << stack2.empty() << std::endl << std::endl;


    std::cout << "stack1 top element  : " << stack1.top() << std::endl;
    std::cout << "stack2 top element  : " << stack2.top() << std::endl;
    
    stack1.pop();
    stack2.pop();

    std::cout << "stack1 top element after pop  : " << stack1.top() << std::endl;
    std::cout << "stack2 top element after pop : " << stack2.top() << std::endl;

    std::cout << std::endl;
}

void    test_portativity( void )
{
    std::cout << RED << " CONSTRUCTING STACK WITH DIFFERENTS CONTAINERS " << WHITE << std::endl << std::endl << std::endl;

    NM::stack<int, std::vector<int> > stackv;
    std::cout << YELLOW << " Vector stack success ! " << WHITE << std::endl;
    NM::stack<int, std::list<int> > stackl;
    std::cout << YELLOW << " List stack success ! " << WHITE << std::endl;
    NM::stack<int, std::deque<int> > stackd;
    std::cout << YELLOW << " deque stack success ! " << WHITE << std::endl;
}

int main( void )
{
    test_constructor();
    test_operator();
    test_few_things();
    test_portativity();
    return 0;
}
