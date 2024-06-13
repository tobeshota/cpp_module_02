/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:30 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/13 18:59:08 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void) {
//   Fixed a(3.14f);
//   Fixed b(2);

//   std::cout << "a       :\t" << a        << std::endl;
//   std::cout << "b       :\t" << b        << std::endl;
//   std::cout << "a + b   :\t" << a + b    << std::endl;
//   std::cout << "a - b   :\t" << a - b    << std::endl;
//   std::cout << "a * b   :\t" << a * b    << std::endl;
//   std::cout << "a / b   :\t" << a / b    << std::endl;
//   std::cout << "a++     :\t" << a++      << std::endl;
//   std::cout << "++a     :\t" << ++a      << std::endl;
//   std::cout << "a--     :\t" << a--      << std::endl;
//   std::cout << "--a     :\t" << --a      << std::endl;
//   std::cout << "(a == b):\t" << (a == b) << std::endl;
//   std::cout << "(a != b):\t" << (a != b) << std::endl;
//   std::cout << "(a < b) :\t" << (a < b)  << std::endl;
//   std::cout << "(a <= b):\t" << (a <= b) << std::endl;
//   std::cout << "(a > b) :\t" << (a > b)  << std::endl;
//   std::cout << "(a >= b):\t" << (a >= b) << std::endl;

// }

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;                 //  ①0
  std::cout << ++a << std::endl;               //  ②0.00390625
  std::cout << a << std::endl;                 //  ③0.00390625
  std::cout << a++ << std::endl;               //  ④0.00390625
  std::cout << a << std::endl;                 //  ⑤0.0078125
  std::cout << b << std::endl;                 //  ⑥10.1016
  std::cout << Fixed::max(a, b) << std::endl;  //  ⑦10.1016
  return 0;
}

/* 出力結果

$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>

*/
