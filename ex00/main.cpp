/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:30 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/12 14:37:11 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
  Fixed a;                                  //  ①Default constructor called
  Fixed b(a);                               //  ②Copy constructor called ③Copy assignment operator called ④getRawBits member function called
  Fixed c;                                  //  ⑤Default constructor called

  c = b;                                    //  ⑥Copy assignment operator called ⑦getRawBits member function called

  std::cout << a.getRawBits() << std::endl; //  ⑧getRawBits member function called ⑨0
  std::cout << b.getRawBits() << std::endl; //  ⑩getRawBits member function called ⑪0
  std::cout << c.getRawBits() << std::endl; //  ⑫getRawBits member function called ⑬0

  return 0;                                 //  ⑭Destructor called ⑮Destructor called ⑯Destructor called
}


/* 出力結果

$> ./a.out
①Default constructor called
②Copy constructor called
③Copy assignment operator called
④getRawBits member function called
⑤Default constructor called
⑥Copy assignment operator called
⑦getRawBits member function called
⑧getRawBits member function called
⑨0
⑩getRawBits member function called
⑪0
⑫getRawBits member function called
⑬0
⑭Destructor called
⑮Destructor called
⑯Destructor called
$>

*/
