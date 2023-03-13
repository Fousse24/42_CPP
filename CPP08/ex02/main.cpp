/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:40:19 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/06 16:49:52 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <stack>
#include <vector>
#include "MutantStack.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

/*
*	So, I decided to try rbegin() and rend(), as to make top() the actual begin();
*
*	The issue I have is that rend() does not work well at all with deferencing...
*	so my MutantStack.rend() will segfault it you do *<theStack>.rend().
*	
*	I tried to find a gracious solution, but I couldn't find something that felt natural.
*	My other colleagues used begin() and end() instead, but I feel like the result is not what is expected.
*/

template <typename T>
void	printElem(T const & elem)
{
	cout << elem << endl;
}

int	main( int argc, char **argv )
{
	MutantStack<int>			msInt;
	vector<int>					vInt;
	list<int>					lInt;
	list<int>::iterator			itLInt;
	vector<int>::iterator		itVInt;
	MutantStack<int>::iterator	itMsInt;
	MutantStack<string>			msStr;
	list<string>				lStr;
	
	
	int	n;
	int	size;

	if (argc != 2)
	{
		std::cerr << "Argument error: requires 1 argument only: an int which will be the size of our containers."  << endl;
		return (0);
	}
	srand(static_cast<unsigned int>(time(NULL)));
	try
	{
		//****** Stack, vector and list
		size = std::stoi(string(argv[1]));
		if (size < 0)
		{
			std::cerr << "Argument error: only a positive integer is accepted as argument" << endl;
			return 0;
		}
		for (int i = 0; i < size; i++)
		{
			n = (rand() % 500) - 250;
			msInt.push(i + 1);
			vInt.push_back(i + 1);
			lInt.push_back(i + 1);
		}
		cout << "\033[1;32mA MutantStack, a vector and a list are created with similar random content." << endl;
		cout << "It is then printed with a for_each using a functor that print the element.\033[0m" << endl << endl;
		
		cout << "\033[1;32mMUTANT STACK\033[0m" << endl;
		std::for_each(msInt.begin(), msInt.end(), printElem<int>);
		cout << endl << "\033[1;32mVECTOR\033[0m" << endl;
		std::for_each(vInt.begin(), vInt.end(), printElem<int>);
		cout << endl << "\033[1;32mLIST\033[0m" << endl;
		std::for_each(lInt.begin(), lInt.end(), printElem<int>);

		//****** Some manipulations
		if (1)
		{
			cout << endl << "\033[1;32mBEGIN()\033[0m" << endl;
			itLInt = lInt.begin();
			itMsInt = msInt.begin();
			itVInt	= vInt.begin();
			cout << "List *begin(): " << *itLInt << endl;
			cout << "Vector *begin(): " << *itVInt << endl;
			cout << "Mutant *begin(): " << *itMsInt << endl;
			// cout << endl << "\033[1;32mEND()\033[0m" << endl;
			// itLInt = lInt.end();
			// itMsInt = msInt.end();
			// itVInt	= vInt.end();
			// cout << "List *end(): " << *itLInt << endl;
			// cout << "Vector *end(): " << *itVInt << endl;
			// cout << "Mutant *end(): " << *itMsInt << endl;
		}
		else
			cout << "\033[1;31mA SIZE BIGGER THAN 0 IS REQUIRED TO SAFELY TEST BEGIN()\033[0m" << endl;
		if (size >= 2)
		{
			cout << endl << "\033[1;32mCOPY AND ASSIGNMENT TESTING\033[0m" << endl;
			list<int>			lIntCopy(lInt);
			MutantStack<int>	msIntCopy(msInt);

			itLInt = lIntCopy.begin();
			itMsInt = msIntCopy.begin();
			cout << "Mutant *begin(): " << *itMsInt << endl;
			cout << "Copied List *begin(): " << *itLInt << endl << endl;

			msIntCopy.pop();
			lIntCopy.pop_front();
			itLInt = lIntCopy.begin();
			itMsInt = msIntCopy.begin();
			if (itMsInt != msInt.end())
			{
				cout << "Mutant *begin(): " << *itMsInt << endl;
			}
			cout << "Copied List *begin() after pop: " << *itLInt << endl << endl;
			
			itLInt = lInt.begin();
			itMsInt = msInt.begin();
			cout << "Mutant *begin(): " << *itMsInt << endl;
			cout << "List *begin(): " << *itLInt << endl;
		}
		else
			cout << "\033[1;31mA SIZE BIGGER THAN 1 IS REQUIRED TO SAFELY TEST COPIES AND POP()\033[0m" << endl;
		
	}

	catch(const std::exception& e)
	{
		std::cerr << "Argument error: requires 1 argument only: " << e.what() << endl;
		return (0);
	}

	msStr.push(string("norminette this "));
	msStr.push(string("I would "));
	msStr.push(string("For cookies, "));
	lStr.push_back(string("norminette this "));
	lStr.push_back(string("I would "));
	lStr.push_back(string("For cookies, "));
	
	cout << endl << "\033[1;32mA MutantStack and a list are created with similar random string content.\033[0m" << endl;
	cout << "\033[1;32mMUTANT STACK\033[0m" << endl;
	std::for_each(msStr.begin(), msStr.end(), printElem<string>);
	cout << endl << "\033[1;32mLIST\033[0m" << endl;
	std::for_each(lStr.begin(), lStr.end(), printElem<string>);

	cout << endl << "\033[1;32mCopy and assignment of the same MutantStack, pop(), and then printing both the original and copied content\033[0m" << endl;
	MutantStack<string>	msStrCopy(msStr);
	msStrCopy.pop();
	MutantStack<string>	msStrAssign = msStrCopy;
	msStrAssign.pop();
	cout << "\033[1;32mMUTANT STACK ORIGINAL\033[0m" << endl;
	std::for_each(msStr.begin(), msStr.end(), printElem<string>);
	cout << "\033[1;32mMUTANT STACK COPY\033[0m" << endl;
	std::for_each(msStrCopy.begin(), msStrCopy.end(), printElem<string>);
	cout << "\033[1;32mMUTANT STACK ASSIGN\033[0m" << endl;
	std::for_each(msStrAssign.begin(), msStrAssign.end(), printElem<string>);

	return 0;
}

//-----Subject test
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << "push(5) push(17) Top: " << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << "pop() size(): " << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	std::cout << std::endl << "push(3) push(5) push(737) push(0) it=begin ite=end ++it --it" << std::endl;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);

// 	list<int> l;
// 	l.push_back(5);
// 	l.push_back(17);
// 	std::cout << std::endl << "LIST" << std::endl << "push_back(5) push_back(17) Top: " << l.front() << std::endl;
// 	l.pop_front();
// 	std::cout << "pop() size(): " << l.size() << std::endl;
// 	l.push_back(3);
// 	l.push_back(5);
// 	l.push_back(737);
// 	//[...]
// 	l.push_back(0);
// 	list<int>::iterator lIt = l.begin();
// 	list<int>::iterator lIte = l.end();
// 	++lIt;
// 	--lIt;
// 	std::cout << std::endl << "push_back(3) push_back(5) push_back(737) push_back(0) lIt=begin lIte=end ++it --it" << std::endl;
// 	while (lIt != lIte)
// 	{
// 	std::cout << *lIt << std::endl;
// 	++lIt;
// 	}
// 	return 0;
// }
