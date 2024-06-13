/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:30 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/13 17:22:19 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* 浮動小数点数と固定小数点数

固定小数点数は，
・浮動小数点数に固定ビットだけ右シフトしたものとして格納される．
・使用する前には，右シフトしただけ左シフトさせる．

今回の場合，浮動小数点数42.42fは，
・固定小数点数に格納されるとき，8bit右シフトする．m_fixed_point_nb = roundf(42.42f * (1 << 8));
・使用する際には，8bit左シフトする．(float)m_fixed_point_nb / (1 << 8);

 */
int main(void) {
    Fixed a;                                                            //  ①Default constructor called
    Fixed const b(10);                                                  //  ②Int constructor called
    Fixed const c(42.42f);                                              //  ③Float constructor called
    Fixed const d(b);                                                   //  ④Copy constructor called ⑤Copy assignment operator called

    a = Fixed(1234.4321f);                                              //  ⑥Float constructor called ⑦Copy assignment operator called ⑧Destructor called

    std::cout << "a is " << a << std::endl;                             //  ⑨a is 1234.43
    std::cout << "b is " << b << std::endl;                             //  ⑩b is 10
    std::cout << "c is " << c << std::endl;                             //  ⑪c is 42.4219
    std::cout << "d is " << d << std::endl;                             //  ⑫d is 10

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;    //  ⑬a is 1234 as integer
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;    //  ⑭b is 10 as integer
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;    //  ⑮c is 42 as integer
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;    //  ⑯d is 10 as integer

    return 0;                                                           //  ⑰Destructor called ⑱Destructor called ⑲Destructor called ⑳Destructor called

}

/* 出力結果

$> ./a.out
①Default constructor called
②Int constructor called
③Float constructor called
④Copy constructor called
⑤Copy assignment operator called
⑥Float constructor called
⑦Copy assignment operator called
⑧Destructor called
⑨a is 1234.43
⑩b is 10
⑪c is 42.4219
⑫d is 10
⑬a is 1234 as integer
⑭b is 10 as integer
⑮c is 42 as integer
⑯d is 10 as integer
⑰Destructor called
⑱Destructor called
⑲Destructor called
⑳Destructor called
$>

*/
