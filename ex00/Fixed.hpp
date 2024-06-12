/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:28 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/12 14:35:20 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int m_fixed_point_nb;
  static const int m_fractional_bits = 8;

 public:
  Fixed();                               // デフォルトコンストラクタ
  Fixed(const Fixed& other);             // コピーコンストラクタ
  Fixed& operator=(const Fixed& other);  // コピー代入演算子
  ~Fixed();                              // デストラクタ

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
