/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:25 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/13 16:36:23 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_fixed_point_nb(0) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::Fixed(int inb) {
  // int型数値をm_fractional_bits(8ビット)左シフトさせる
  m_fixed_point_nb = inb * (1 << m_fractional_bits);
}

Fixed::Fixed(float fnb) {
  // float型浮動小数点数をm_fractional_bits(8ビット)左シフトさせる
  // roundf()で浮動小数点数を最も近い整数に変換する
  m_fixed_point_nb = roundf(fnb * (1 << m_fractional_bits));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->m_fixed_point_nb = other.getRawBits();
  }
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed &other) const {
  return this->m_fixed_point_nb > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
  return this->m_fixed_point_nb < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->m_fixed_point_nb >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->m_fixed_point_nb <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
  return this->m_fixed_point_nb == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->m_fixed_point_nb == other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

/**前置インクリメント
 * 1．オブジェクトの値をインクリメントする
 * 2．インクリメント後のオブジェクトを返す
 */
Fixed &Fixed::operator++() {
  this->m_fixed_point_nb++;
  Fixed &after_increment = *this;
  return after_increment;
}

/**後置インクリメント
 * 1．インクリメント前のオブジェクトを返す
 * 2．オブジェクトの値をインクリメントする
 * *引数に取られたint型は，後置インクリメントが前置──と区別して識別されるようにするためのもの．
 * *int型の引数は，一般的には，引数の受け渡しには使用されない
 */
Fixed Fixed::operator++(int) {
  Fixed before_increment = *this;
  this->m_fixed_point_nb++;
  return before_increment;
}

/**前置デクリメント
 * 1．オブジェクトの値をデクリメントする
 * 2．デクリメント後のオブジェクトを返す
 */
Fixed &Fixed::operator--() {
  this->m_fixed_point_nb--;
  Fixed &after_decrement = *this;
  return after_decrement;
}

/**後置デクリメント
 * 1．デクリメント前のオブジェクトを返す
 * 2．オブジェクトの値をデクリメントする
 * *引数に取られたint型は，後置デクリメントが前置──と区別して識別されるようにするためのもの．
 * *int型の引数は，一般的には，引数の受け渡しには使用されない
 */
Fixed Fixed::operator--(int) {
  Fixed before_decrement = *this;
  this->m_fixed_point_nb--;
  return before_decrement;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a > b ? a : b;
}

int Fixed::getRawBits(void) const { return this->m_fixed_point_nb; }

void Fixed::setRawBits(int const raw) { this->m_fixed_point_nb = raw; }

// 固定小数点数を浮動小数点数に変換する
float Fixed::toFloat(void) const {
  // m_fractional_bits(8ビット)だけ左シフトしていた分，元に戻す
  return (float)m_fixed_point_nb / (1 << m_fractional_bits);
}

// 固定小数点数を整数に変換する
int Fixed::toInt(void) const {
  // m_fractional_bits(8ビット)だけ左シフトしていた分，元に戻す
  return (int)m_fixed_point_nb / (1 << m_fractional_bits);
}
