#include <iostream>
#include <iomanip>
#include "..\inc\Expression.hh"
#include "..\inc\Database.hh"


int main(int argc, char **argv)
{
	
    if (argc < 2)
    {
      std:: cout << std::endl;
      std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
      std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
      std::cout << std::endl;
        return 1;
    }

    Database base = {nullptr, 0, 0};

    if (Init(&base, argv[1]) == false)
    {
        std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << " Start testu arytmetyki zespolonej: " << argv[1] <<std::endl;
    std::cout << std::endl;

	
	Complex input, odp;
    Expression expression;
	int iter1 = 0, iter2 = 0, iter3 = 0;
    while (GetNextQuestion(&base, &expression))
    {
		Display(expression);
		switch (expression.op)
		{
		case Operator::kAddition: odp = expression.arg1 + expression.arg2; break;
		case Operator::kSubtraction: odp = expression.arg1 - expression.arg2; break;
		case Operator::kMultiplication: odp = expression.arg1 * expression.arg2; break;
		case Operator::kDivision: odp = expression.arg1 / expression.arg2; break;
		}
		input = Solve();
		if (odp == input)
		{
			std::cout << "Poprawna odpowiedz" << std::endl;
			iter1++;
			iter3++;
		}
		else
		{
			std::cout << "Zla odpowiedz, prawidlowy wynik to: " << odp << std::endl;
			iter2++;
			iter3++;
		}
    }
	std::cout << std::endl;
	std::cout << " Koniec testu" << std::endl;
	std::cout << std::endl;
	std::cout << "Ilosc poprawnych odpowiedzi: " << iter1 << std::endl;
	std::cout << "Ilosc blednych odpowiedzi: " << iter2 << std::endl;
	std::cout << "Wynik procentowy poprawnych odpowiedzi: "<< std::setprecision(2) 
		<< iter1 / iter3 * 100 << "%" << std::endl;
	std::cout << "Input something";
	char c;
	std::cin >> c;
	return 0;
}
