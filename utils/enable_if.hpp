/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:58:46 by anremiki          #+#    #+#             */
/*   Updated: 2022/11/18 14:57:29 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include "is_integral.hpp"

namespace ft {

template <bool Cond, class T = void>
struct	enable_if {
};

template <class T>
struct	enable_if<true, T> {
	typedef T type;
};

}


#endif
