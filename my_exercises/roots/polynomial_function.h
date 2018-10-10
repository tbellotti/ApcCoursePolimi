#ifndef __POLYNOMIAL_FUNCTION_H__
#define __POLYNOMIAL_FUNCTION_H__

#include <iostream>
#include <vector>
#include <math.h>
#include "root_finding.h"

class Polynomial_Function 
{

private:
    std::vector <real> coefficients; // Here we have the coefficient

public:
    Polynomial_Function(std::vector <real> & new_coefficients);
    real evaluate (const real point) const;
    void print ();
    Polynomial_Function derivative ();
};

#endif
