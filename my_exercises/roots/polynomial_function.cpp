#include "polynomial_function.h"


Polynomial_Function::Polynomial_Function(std::vector <real> & new_coefficients)   
{
    coefficients = new_coefficients;
}

double Polynomial_Function::evaluate (const real point) const
{
    // We have:
    // P(x)  = coef[0] + coef[1]*x + coef[2]*x*x + .... 
    size_t degree = coefficients.size();
    unsigned int curr_degree = 0;
    real result = 0.0;
    for (auto curr_coeff : coefficients)    {
        result += curr_coeff*pow(point, curr_degree);
        curr_degree++;
    }

    return result;
}

void Polynomial_Function::print ()  
{
    unsigned int curr_degree = 0;
    std::cout<<"P(X) = ";
    for (auto curr_coeff : coefficients)   {
        std::cout<<"+ "<<curr_coeff<<" * X^"<<curr_degree;
        curr_degree++;
    }
    std::cout<<std::endl;
}

Polynomial_Function Polynomial_Function::derivative () const
{
    std::vector <real> derivative_coefficients;
    unsigned int curr_degree = 0;
    for (auto curr_coeff : coefficients)   {
        derivative_coefficients.push_back(((real) curr_degree)*curr_coeff);
        curr_degree++;
    }

    return Polynomial_Function(derivative_coefficients);
}
