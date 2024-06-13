/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:28 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/13 19:17:48 by toshota          ###   ########.fr       */
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
  ~Fixed();                              // デストラクタ

  /* 自身を返す演算子では，これを実現するために，値返しでなく参照返しが用いられる */
  Fixed& operator=(const Fixed& other);  // コピー代入演算子
  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed &operator++();                   //  前置インクリメント
  Fixed operator++(int);                 //  後置インクリメント
  Fixed &operator--();                   //  前置デクリメント
  Fixed operator--(int);                 //  後置デクリメント

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

  float toFloat(void) const;
  int toInt(void) const;
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
