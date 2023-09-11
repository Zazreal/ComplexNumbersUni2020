#include "..\inc\Complex.hh"
#include <iostream>
#include <iomanip>
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dodawania,
 *    arg2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
std::ostream& operator<<(std::ostream& stream, Complex& com){
  
	stream << "(" << std::setprecision(1) << com.re << std::showpos << com.im
		<< "i)" << std::noshowpos;
  
  return stream;
}

std::istream& operator>>(std::istream& stream, Complex& com) {
	//Wersja wstepna
	std::cout << "(";
	stream >> com.re;
	stream >> std::showpos >> com.im >>std::noshowpos;
	std::cout << "i)" << std::endl;
	return stream;
}


Complex::Complex()
{
}

Complex::Complex(double x, double y): re(x), im(y)
{
}

Complex::~Complex(){}

Complex Complex::operator+(Complex& other)
{
	return Complex(this->re + other.re, this->im + other.im);
}

Complex Complex::operator-(Complex & other)
{
	return Complex(this->re - other.re, this->im - other.im);
}

Complex Complex::operator*(Complex & other)
{
	return Complex(this->re * other.re - this->im * other.im,
		this->im * other.re + this->re * other.im);
}

Complex Complex::operator/(Complex & other)
{
	Complex temp;
	Complex other2 = !other;
	temp = *this * other2;
	int mod = other.re * other.re + other2.im * other2.im;
	if (0 == mod)
	{
		std::cout << "BLAD: Nie Mozna dzielic przez 0" << std::endl;
		return Complex(0, 0);
	}
	return Complex(temp.re/mod , temp.im/mod);
}

Complex Complex::operator!()
{
	return Complex(this->re, -(this->im));;
}

bool Complex::operator==(Complex & other)
{
	if (this->re == other.re && this->im == other.im) return true;
	else return false;
}
