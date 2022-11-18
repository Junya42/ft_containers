/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vec.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/11/17 14:48:05 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "vector.hpp"
#include <vector>

//NM::vector<int> tmp(10, 42);
//NM::vector< NM::vector<int> > v2(10, tmp);

void test_constructor( void )
{
	std::cout << RED << " TEST_CONSTRUCTOR " << WHITE << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << " DEFAULT CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::vector<NM::vector<int> > v1;
	std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl;

	std::cout << YELLOW << " FILL CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::vector<int> tmp(10, 42);
	std::cout << YELLOW << " FILL CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::vector<int> v2(tmp);
	std::cout << YELLOW << " FILL CONSTRUCTOR " << WHITE << std::endl << std::endl;
	std::cout << "v2 size : " << v2.size() << " | v1 capacity : " << v2.capacity() << " | is v1 empty ? : " << v2.empty() << std::endl;

	std::cout << YELLOW << " RANGE CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::vector<NM::vector<int> > v3(v2.begin(), v2.end());
	std::cout << "v3 size : " << v3.size() << " | v1 capacity : " << v3.capacity()  << " | is v1 empty ? : " << v3.empty() << std::endl;

	std::cout << YELLOW << " COPY CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::vector<NM::vector<int> > v4(v3);
	std::cout << "v4 size : " << v4.size() << " | v1 capacity : " << v4.capacity() << " | is v1 empty ? : " << v4.empty() << std::endl;
	std::cout << std::endl;
}

/*void test_iterator( void )
{
	std::cout << RED << " TEST_ITERATOR " << WHITE << std::endl << std::endl;
	
	NM::vector<int> v1(10, 42);
	v1.insert(v1.begin() + 3, 4, 78);

	std::cout << YELLOW << " ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::vector<int>::iterator it = v1.begin();
		NM::vector<int>::iterator ite = v1.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << YELLOW << " CONST ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::vector<int>::const_iterator it = v1.begin();
		NM::vector<int>::const_iterator ite = v1.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << YELLOW << " REVERSE ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::vector<int>::reverse_iterator it = v1.rbegin();
		NM::vector<int>::reverse_iterator ite = v1.rend();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_insert( void )
{
	std::cout << RED << " TEST_INSERT " << WHITE << std::endl << std::endl << std::endl;
	NM::vector<std::string> v1;
	NM::vector<std::string> v2;
	
	std::cout << YELLOW << " INSERT SINGLE ELEMENT " << WHITE << std::endl << std::endl;
	{
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl << std::endl;
		NM::vector<std::string>::iterator ret;
		v1.insert(v1.begin(), "lorem ipsum");
		v1.insert(v1.begin(), "Neque porro quisquam");
		ret = v1.insert(v1.begin(), "Quisque eleifend");
		
		std::cout << " RETURN VALUE : " << *ret << std::endl << std::endl;
	
		NM::vector<std::string>::iterator it = v1.begin();
		NM::vector<std::string>::iterator ite = v1.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl;
	}
	std::cout << YELLOW << " INSERT SINGLE ELEMENT " << WHITE << std::endl << std::endl;
	{
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl << std::endl;
		v1.insert(v1.begin(), 10, "lorem ipsum");
		v1.insert(v1.begin(), 7, "Neque porro quisquam");
		v1.insert(v1.begin(), 0, "Quisque eleifend");
		NM::vector<std::string>::iterator it = v1.begin();
		NM::vector<std::string>::iterator ite = v1.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl;
	}
	std::cout << YELLOW << " INSERT RANGE " << WHITE << std::endl << std::endl;
	{
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl << std::endl;
		v1.insert(v1.begin(), 4, "lorem ipsum");
		v1.insert(v1.begin(), 2, "Neque porro quisquam");
		v1.insert(v1.begin(), 0, "Quisque eleifend");
		v2.insert(v2.begin(), v1.begin(), v1.end());
		NM::vector<std::string>::iterator it = v2.begin();
		NM::vector<std::string>::iterator ite = v2.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " "; 
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity()  << " | is v1 empty ? : " << v1.empty() << std::endl;
	}
}

void test_erase( void )
{
	std::cout << RED << " TEST_ERASE " << WHITE << std::endl << std::endl << std::endl;

	NM::vector<std::string> v1(1, "lol");
	v1.insert(v1.begin(), "mdr");
	v1.insert(v1.begin(), "xptdr");
	v1.insert(v1.begin(), "ptdr");
	
	std::cout << YELLOW << " ERASE SINGLE ELEMENT " << WHITE << std::endl << std::endl;
	{
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity() << " | is v1 empty ? : " << v1.empty() << std::endl << std::endl;
		NM::vector<std::string>::iterator ret;
		std::cout << RED << "BEFORE : " << WHITE;
		NM::vector<std::string>::iterator it = v1.begin();
		NM::vector<std::string>::iterator ite = v1.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		
		ret = v1.erase(v1.begin() + 2);
		std::cout << " RETURN VALUE : " << *ret << std::endl << std::endl;
			
		std::cout << RED << "AFTER : " << WHITE;
		NM::vector<std::string>::iterator it2 = v1.begin();
		NM::vector<std::string>::iterator ite2 = v1.end();

		for ( ; it2 != ite2 ; it2++ )
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity()  << " | is v1 empty ? : " << v1.empty() << std::endl;
	}
	
	std::cout << YELLOW << " ERASE RANGE " << WHITE << std::endl << std::endl;
	{
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity()  << " | is v1 empty ? : " << v1.empty() << std::endl << std::endl;
		NM::vector<std::string>::iterator ret;
		std::cout << RED << "BEFORE : " << WHITE;
		NM::vector<std::string>::iterator it = v1.begin();
		NM::vector<std::string>::iterator ite = v1.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		
		ret = v1.erase(v1.begin(), v1.begin() + 2);
		std::cout << " RETURN VALUE : " << *ret << std::endl << std::endl;

		std::cout << RED << "AFTER : " << WHITE;
		NM::vector<std::string>::iterator it2 = v1.begin();
		NM::vector<std::string>::iterator ite2 = v1.end();

		for ( ; it2 != ite2 ; it2++ )
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "v1 size : " << v1.size() << " | v1 capacity : " << v1.capacity()  << " | is v1 empty ? : " << v1.empty() << std::endl;
	}
}

void	test_accesser( void )
{
	std::cout << RED << " TEST_ACCESER " << WHITE << std::endl << std::endl << std::endl;
	NM::vector<int> v1(10, 42);

	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.push_back(12);
	v1.push_back(2);

	std::cout << YELLOW << " ACCESSING WITH [] " << WHITE << std::endl << std::endl;
	std::cout << "[" << v1[1] << "]";
	std::cout << "[" << v1[v1.size()] << "]";
	std::cout << "[" << v1[v1.size() - 2] << "]";
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << " ACCESSING WITH AT " << WHITE << std::endl << std::endl;

	std::cout << "(" << v1.at(1) << ")";
	std::cout << "(" << v1.at(3) << ")";
	std::cout << "(" << v1.at(5) << ")";
	std::cout << std::endl << std::endl;


	std::cout << YELLOW << " ACCESSING FRONT" << WHITE << std::endl << std::endl;

	std::cout << "(" << v1.front() << ")";
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << " ACCESSING BACK" << WHITE << std::endl << std::endl;

	std::cout << "(" << v1.back() << ")";
	std::cout << std::endl << std::endl;
}

void go_crasy( void )
{
	std::cout << RED << " GO CRASYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY " << WHITE << std::endl << std::endl << std::endl;

	NM::vector<int> v1;

	std::cout << YELLOW << " ASSIGN FILL " << WHITE << std::endl << std::endl;
	v1.assign(10, 42);
	v1.pop_back();
	v1.pop_back();
	v1.push_back(12);
	v1.push_back(52);
	{
		std::cout << YELLOW << " STRAIGHT " << WHITE << std::endl;
		for ( NM::vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << YELLOW << " REVERSE " << WHITE << std::endl;
		for ( NM::vector<int>::reverse_iterator it = v1.rbegin() ; it != v1.rend() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout  << std::endl << YELLOW << " ASSIGN RANGE " << WHITE << std::endl << std::endl;
	NM::vector<int> v2;
	v2.assign(v1.begin(), v1.end());
	{
		std::cout << YELLOW << " STRAIGHT " << WHITE << std::endl;
		for ( NM::vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << YELLOW << " REVERSE " << WHITE << std::endl;
		for ( NM::vector<int>::reverse_iterator it = v2.rbegin() ; it != v2.rend() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout  << std::endl << YELLOW << " OPERATOR = " << WHITE << std::endl << std::endl;
	NM::vector<int> v3;

	v3 = v2;
	{
		std::cout << YELLOW << " STRAIGHT " << WHITE << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << YELLOW << " REVERSE " << WHITE << std::endl;
		for ( NM::vector<int>::reverse_iterator it = v3.rbegin() ; it != v3.rend() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout  << std::endl << YELLOW << " ERASING IN BEGIN AND INSERTING IN THE END " << WHITE << std::endl << std::endl;

	v3.erase(v3.begin());
	v3.insert(v3.end(), v1.begin(), v1.end());
	{
		std::cout << YELLOW << " STRAIGHT " << WHITE << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << YELLOW << " REVERSE " << WHITE << std::endl;
		for ( NM::vector<int>::reverse_iterator it = v3.rbegin() ; it != v3.rend() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout  << std::endl;
	if ( v1 == v3 )
		std::cout << " v1 == v3 " << std::endl;
	
	if ( v1 != v3 )
		std::cout << " v1 != v3 " << std::endl;

	if ( v1 > v3 )
		std::cout << " v1 > v3 " << std::endl;
	
	if ( v1 >= v3 )
		std::cout << " v1 >= v3 " << std::endl;
	
	if ( v1 < v3 )
		std::cout << " v1 < v3 " << std::endl;

	if ( v1 <= v3 )
		std::cout << " v1 <= v3 " << std::endl;

	std::cout  << std::endl << YELLOW << " CLEARING V3 AND SWAPPING IT WITH V1 " << WHITE << std::endl << std::endl;
	v3.clear();
	v3.swap(v1);
	{
		std::cout << YELLOW << " STRAIGHT " << WHITE << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << YELLOW << " REVERSE " << WHITE << std::endl;
		for ( NM::vector<int>::reverse_iterator it = v3.rbegin() ; it != v3.rend() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	if ( v1.empty() )
		std::cout << " V1 IS EMPTY " << std::endl;
	
	std::cout << "END TEST" << std::endl;
}
*/


int main( void )
{
	test_constructor();
	//test_iterator();
//	test_insert();
//	test_erase();
//	test_accesser();
//	go_crasy();
	return 0;
}
