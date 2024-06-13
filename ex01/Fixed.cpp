/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshota <tobeshota@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:50:25 by tobeshota         #+#    #+#             */
/*   Updated: 2024/06/13 11:09:20 by tobeshota        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_fixed_point_nb(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::Fixed(int inb) {
  std::cout << "Int constructor called" << std::endl;
  // int型数値をm_fractional_bits(8ビット)左シフトさせる
  m_fixed_point_nb = inb * (1 << m_fractional_bits);
}

Fixed::Fixed(float fnb) {
  std::cout << "Float constructor called" << std::endl;
  // float型浮動小数点数をm_fractional_bits(8ビット)左シフトさせる
  // roundf()で浮動小数点数を最も近い整数に変換する
  m_fixed_point_nb = roundf(fnb * (1 << m_fractional_bits));
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->m_fixed_point_nb = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return this->m_fixed_point_nb;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->m_fixed_point_nb = raw;
}

// 固定小数点数を浮動小数点数に変換する
float Fixed::toFloat(void) const
{
  // m_fractional_bits(8ビット)だけ左シフトしていた分，元に戻す
  return (float)m_fixed_point_nb / (1 << m_fractional_bits);
}

// 固定小数点数を整数に変換する
int Fixed::toInt(void) const
{
  // m_fractional_bits(8ビット)だけ左シフトしていた分，元に戻す
  return (int)m_fixed_point_nb / (1 << m_fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
  out << fixed.toFloat();
  return out;
}
