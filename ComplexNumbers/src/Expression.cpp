#include "..\inc\Expression.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Display(Expression& expr)
{
	std::cout << "Podaj Wynik operacji: ";
	std::cout << expr.arg1;
	switch (expr.op)
	{
	case Operator::kAddition: std::cout << " + "; break;
	case Operator::kSubtraction: std::cout << " - "; break;
	case Operator::kMultiplication: std::cout << " * "; break;
	case Operator::kDivision: std::cout << "/" ; break;
	}
	std::cout << expr.arg2 << " = " << std::endl;
}

Complex Solve()
{
	Complex input;
	std::cout << "Twoja odpowiedz: ";
	std::cin >> input;
	return input;
}
