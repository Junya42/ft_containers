/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:15:24 by anremiki          #+#    #+#             */
/*   Updated: 2022/11/18 15:30:58 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

int main() {

	std::cout << "VOID CONSTRUCTOR" << std::endl;

	std::vector<int> s1;
	ft::vector<int> f1;

	std::cout << "FILL CONSTRUCTOR" << std::endl;

	std::vector<int> s2(3,10);
	ft::vector<int> f2(3,10);

	std::cout << "RANGE CONSTRUCTOR" << std::endl;

	std::vector<int> s3(s2.begin(), s2.end());
	ft::vector<int> f3(s2.begin(), s2.end());
}
