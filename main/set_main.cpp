#ifdef STL
    #define NM std
#else
    #define NM ft
#endif

#define BLACKK  "\033[1m\033[30m"
#define REDD    "\033[1m\033[31m"
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
#include "../set.hpp"
#include <set>

namespace ft
{
    template < class T >
    struct greater
    {
        bool operator()( const T & a, const T & b ) const
        {
            return a > b;
        }
    };
}

void test_constructor( void )
{
    std::cout << REDD << " TEST_CONSTRUCTOR " << WHITE << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << " EMPTY CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::set<int> set1;
	std::cout << "set1 size : " << set1.size()  << " | is set1 empty ? : " << set1.empty() << std::endl;
    std::cout << std::endl;

	std::cout << YELLOW << " RANGE CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::set<int> tmp; tmp.insert(10); tmp.insert(16540); tmp.insert(6610); tmp.insert(14560);
	NM::set<int> set2(tmp.begin(), tmp.end());
	std::cout << "set2 size : " << set2.size()  <<  " | is set2 empty ? : " << set2.empty() << std::endl;
    std::cout << std::endl;

	std::cout << YELLOW << " COPY CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::set<int> set3(set2);
	std::cout << "set3 size : " << set3.size()  << " | is set3 empty ? : " << set3.empty() << std::endl;
	std::cout << std::endl;
}

void    test_iterator( void )
{
    std::cout << REDD << " TEST_ITERATOR " << WHITE << std::endl << std::endl;
	
	NM::set<int> set;
    set.insert(10);
    set.insert(42);
    set.insert(51);
    set.insert(948);
    set.insert(894984);
    set.insert(729);

	std::cout << YELLOW << " ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << YELLOW << " CONST ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::set<int>::const_iterator it = set.begin();
		NM::set<int>::const_iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << YELLOW << " REVERSE ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::set<int>::reverse_iterator it = set.rbegin();
		NM::set<int>::reverse_iterator ite = set.rend();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void    test_insert( void )
{
    std::cout << REDD << " TEST_INSERT " << WHITE << std::endl;

    NM::set<int> set;

    std::cout << YELLOW << " SINGLE ELEMENT INSERT " << WHITE << std::endl << std::endl;

    std::cout << "set size : " << set.size() << " | is set empty ? : " << set.empty() << std::endl << std::endl;
    set.insert(10);
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "set size : " << set.size() << " | is set empty ? : " << set.empty() << std::endl;

    std::cout << YELLOW << " SINGLE ELEMENT WITH HINT INSERT " << WHITE << std::endl << std::endl;

    std::cout << "set size : " << set.size()  << " | is set empty ? : " << set.empty() << std::endl << std::endl;
    set.insert(set.begin(), 72);
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "set size : " << set.size() << " | is set empty ? : " << set.empty() << std::endl;

    std::cout << YELLOW << " RANGE INSERT " << WHITE << std::endl << std::endl;

    std::cout << "set size : " << set.size()  << " | is set empty ? : " << set.empty() << std::endl << std::endl;
    NM::set<int> tmp; tmp.insert(10); tmp.insert(16540); tmp.insert(6610); tmp.insert(14560);
    set.insert(tmp.begin(), tmp.end());
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "set size : " << set.size()  << " | is set empty ? : " << set.empty() << std::endl;
    std::cout << std::endl;
	std::cout << std::endl;
}

void    test_erase( void )
{   
    std::cout << REDD << " TEST_ERASE " << WHITE << std::endl << std::endl;

    NM::set<int> set; set.insert(75); set.insert(42); set.insert(75456); set.insert(665442);set.insert(75654); set.insert(46542);

    std::cout << YELLOW << " SINGLE ELEMENT HINT ERASE " << WHITE << std::endl << std::endl;

    std::cout << "set size : " << set.size() << " | is set empty ? : " << set.empty() << std::endl << std::endl;
    set.erase(set.begin());
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "set size : " << set.size()  << " | is set empty ? : " << set.empty() << std::endl << std::endl;

    std::cout << YELLOW << " SINGLE ELEMENT ERASE " << WHITE << std::endl << std::endl;

    std::cout << "set size : " << set.size() << " | is set empty ? : " << set.empty() << std::endl << std::endl;
    set.erase(42);
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "set size : " << set.size()  << " | is set empty ? : " << set.empty() << std::endl  << std::endl;

    std::cout << YELLOW << " RANGE ERASE " << WHITE << std::endl << std::endl;

    NM::set<int>::iterator it = set.begin();

    it++; it++; it++;

    std::cout << "set size : " << set.size()  << " | is set empty ? : " << set.empty() << std::endl << std::endl;
    set.erase(it, set.end());
	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "set size : " << set.size() << " | is set empty ? : " << set.empty() << std::endl;
    std::cout << std::endl;
}

void    test_operator( void )
{
    std::cout << YELLOW << " TESTING set FIND " << WHITE << std::endl << std::endl;

    NM::set<int> set;

    set.insert(78); set.insert(76528); set.insert(71238); set.insert(765468); set.insert(765468); set.insert(76546548);

    {
        NM::set<int>::iterator it;
        NM::set<int>::const_iterator cit;

        it = set.find(76528);
        cit = set.find(76528);

        std::cout << "normal : ";
        std::cout << "[" << *it << "]" << std::endl;
        std::cout << "const : ";
        std::cout << "[" << *cit << "]" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << YELLOW << " TESTING set COUNT " << WHITE << std::endl << std::endl;
    {
        std::cout << " Count : " << set.count(123);
        std::cout << " Count : " << set.count(78);
    }
    std::cout << std::endl;
    
    std::cout << YELLOW << " TESTING set LOWER_BOUND " << WHITE << std::endl << std::endl;

    {
        NM::set<int>::iterator it;
        NM::set<int>::const_iterator cit;

        it = set.lower_bound(76546548);
        cit = set.lower_bound(76546548);

        std::cout << "normal : ";
        std::cout << "[" << *it << "]" << std::endl;
        std::cout << "const : ";
        std::cout << "[" << *cit << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << " TESTING set UPPER_BOUND " << WHITE << std::endl << std::endl;

    {
        NM::set<int>::iterator it;
        NM::set<int>::const_iterator cit;

        it = set.upper_bound(78);
        cit = set.upper_bound(78);

       std::cout << "normal : ";
        std::cout << "[" << *it << "]" << std::endl;
        std::cout << "const : ";
        std::cout << "[" << *cit << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << " TESTING set EQUAL_RANGE " << WHITE << std::endl << std::endl;
    NM::pair<NM::set<int>::iterator, NM::set<int>::iterator> pair;
    NM::pair<NM::set<int>::const_iterator, NM::set<int>::const_iterator> const_pair;
    {
        pair = set.equal_range(78);
        const_pair = set.equal_range(78);

        std::cout << "normal : ";
        std::cout << *(pair.first) << " [" << *(pair.second) << "] : " << std::endl;
        std::cout << "const : ";
        std::cout << *(const_pair.first) << " [" << *(const_pair.second) << "] : " << std::endl;
    }
    std::cout << std::endl;
}

void    	go_crasy( void )
{

    std::cout << REDD << " GO_CRASY " << WHITE << std::endl << std::endl;


    std::cout << YELLOW << " TESTING SWAP " << WHITE << std::endl << std::endl;
    
    NM::set<int> set;
    NM::set<int> set2;

    set.insert(10); set.insert(10000); set.insert(10000000); set.insert(1075780); set.insert(100000); set.insert(100000);

    set2.insert(20); set2.insert(20000); set2.insert(20000000); set2.insert(20450000); set2.insert(200000); set2.insert(2000000);

    std::cout << YELLOW << " set1 CONTENT  " << WHITE << std::endl << std::endl;
    {
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << std::endl;
    std::cout << YELLOW << " set2 CONTENT  " << WHITE << std::endl << std::endl;
    {
		NM::set<int>::iterator it = set2.begin();
		NM::set<int>::iterator ite = set2.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << std::endl;
    std::cout << YELLOW << " SWAPPING " << WHITE << std::endl << std::endl;
    NM::swap(set, set2);
    std::cout << YELLOW << " set1 CONTENT  " << WHITE << std::endl << std::endl;
    {
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << std::endl;
    std::cout << YELLOW << " set2 CONTENT  " << WHITE << std::endl << std::endl;
    {
		NM::set<int>::iterator it = set2.begin();
		NM::set<int>::iterator ite = set2.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << std::endl;

    std::cout << YELLOW << " TESTING SET WITH A CUSTOM KEY COMPARE  " << WHITE << std::endl << std::endl;

    NM::set<int, ft::greater<int> > set3;

    set3.insert(1421);
    set3.insert(5414);
    set3.insert(323214);
    set3.insert(6314);
    set3.insert(2331214);
    set3.insert(321314);

    std::cout << YELLOW << " CUSTOM SET CONTENT  " << WHITE << std::endl << std::endl;
    {
		NM::set<int>::iterator it = set3.begin();
		NM::set<int>::iterator ite = set3.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << std::endl;

    std::cout << YELLOW << " STANDARD SET CONTENT  " << WHITE << std::endl << std::endl;

    NM::set<int> set4;

    set4.insert(1421);
    set4.insert(5414);
    set4.insert(323214);
    set4.insert(6314);
    set4.insert(2331214);
    set4.insert(321314);
    {
		NM::set<int>::iterator it = set4.begin();
		NM::set<int>::iterator ite = set4.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << "[" << *it << "]";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << std::endl;

    std::cout << YELLOW << " SEARCHING ELEMENT IN THE CUSTOM set  " << WHITE << std::endl << std::endl;

    std::cout << "Searching for the Key1 [" << *(set3.find(1421))  << "]" << std::endl;
    std::cout << "Searching for the lower_bound [" << *(set3.lower_bound(55414)) << "]" << std::endl;
    std::cout << "Searching for the upper_bound [" << *(set3.upper_bound(55414))  << "]" << std::endl;
    std::cout << "Searching for the Key1 Counter [" << set3.count(55414)  << "]" << std::endl;

    std::cout << YELLOW << " SEARCHING ELEMENT THATS DOESNT EXIST IN THE CUSTOM set  " << WHITE << std::endl << std::endl;

    std::cout << "Searching for a non existable value " << std::endl;
    if (set3.find(0) == set3.end())
        std::cout << " This find doesnt exist ! " << std::endl;
    std::cout << "Searching for non existable lower_bound " << std::endl;
    if (set3.find(0) == set3.end())
        std::cout << " This lower bound doesnt exist ! " << std::endl;
    std::cout << "Searching for the  non existable upper_bound " << std::endl;
    if (set3.upper_bound(0) == set3.end())
        std::cout << " This upper bound doesnt exist ! " << std::endl;
    std::cout << "Searching for the non existable Counter [" << set3.count(0)  << "]" << std::endl;

    std::cout << "END TEST " << std::endl;
}

int main( void )
{
    test_constructor();
	test_iterator();
	test_insert();
	test_erase();
    test_operator();
	go_crasy();
    
    return 0;
}
