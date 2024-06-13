/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:28 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/13 11:08:50 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
 private:
  int m_fixed_point_nb;                  //固定小数点数
  static const int m_fractional_bits = 8;//少数ビット

 public:
  Fixed();                               // デフォルトコンストラクタ
  Fixed(const Fixed& other);             // コピーコンストラクタ
  Fixed(int inb);                        // 整数の引数をとるコンストラクタ
  Fixed(float fnb);                      // 浮動小数点数の引数をとるコンストラクタ
  Fixed& operator=(const Fixed& other);  // コピー代入演算子
  ~Fixed();                              // デストラクタ
  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
