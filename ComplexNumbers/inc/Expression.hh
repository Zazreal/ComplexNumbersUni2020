#pragma once

#include "Complex.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator
{
    kAddition = 0,
    kSubtraction = 1,
    kMultiplication = 2,
    kDivision = 3
};

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct Expression
{
    Complex arg1; // Pierwszy argument wyrazenia arytmetycznego
    Operator op;  // Opertor wyrazenia arytmetycznego
    Complex arg2; // Drugi argument wyrazenia arytmetycznego
};

/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

void Display(Expression& expr);
Complex Solve();
