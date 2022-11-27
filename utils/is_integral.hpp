/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:05:20 by anremiki          #+#    #+#             */
/*   Updated: 2022/11/18 15:33:47 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

template <class T, T v>
	struct	integral_constant {
		typedef T value_type;
		static bool const	value = v;
	};

template <class T>
	struct	is_integral: integral_constant<bool, false> {
	};

template <>
	struct	is_integral<bool>: integral_constant<bool, true> {
	};
template <>
	struct	is_integral<char>: integral_constant<char, true> {
	};
template <>
	struct	is_integral<wchar_t>: integral_constant<wchar_t, true> {
	};
template <>
	struct	is_integral<signed char>: integral_constant<signed char, true> {
	};
template <>
	struct	is_integral<short int>: integral_constant<short int, true> {
	};
template <>
	struct	is_integral<int>: integral_constant<int, true> {
	};
template <>
	struct	is_integral<long int>: integral_constant<long int, true> {
	};
template <>
	struct	is_integral<long long int>: integral_constant<long long int, true> {
	};
template <>
	struct	is_integral<unsigned char>: integral_constant<unsigned char, true> {
	};
template <>
	struct	is_integral<unsigned short int>: integral_constant<unsigned short int, true> {
	};
template <>
	struct	is_integral<unsigned int>: integral_constant<unsigned int, true> {
	};
template <>
	struct	is_integral<unsigned long int>: integral_constant<unsigned long int, true> {
	};
template <>
	struct	is_integral<unsigned long long int>: integral_constant<unsigned long long int, true> {
	};
}

#endif
