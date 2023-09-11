#pragma once
#include <iostream>
/*!
 *  Plik zawiera definicje struktury Complex oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct Complex
{
	double re; /*! Pole repezentuje czesc rzeczywista. */
	double im; /*! Pole repezentuje czesc urojona. */
	Complex();
	Complex(double x,double y);
	~Complex();
	Complex operator+(Complex& other);
	Complex operator-(Complex& other);
	Complex operator*(Complex& other);
	Complex operator/(Complex& other);
	Complex operator!(); //sprzezenie
	bool operator==(Complex& other);
};

std::istream& operator>>(std::istream& strea, Complex& com);
std::ostream& operator<<(std::ostream& stream, Complex& com);
