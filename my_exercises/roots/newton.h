#ifndef __NEWTON_H__
#define __NEWTON_H__

#include "polynomial_function.h"
#include "root_finding.h"

class Newton
{

private:
    Polynomial_Function target_function; // Function for which we want to solve F(x) = 0.
    Polynomial_Function jacobian;   // Deriivative of the tarhet function: F'.
    real guess = 0.;    // Initial guess for the solution
    const real tol = 0.;
    unsigned int max_it = 0;
    criterion convergence_criterion = BOTH;
    bool convergence (const real increment, const real residual, const real tol, criterion crt) const;

public:
    Newton(const Polynomial_Function &  new_target, const real my_guess, const real new_tol, const criterion ct, int it)
            : target_function (new_target),  jacobian(new_target.derivative()), guess(my_guess), tol(new_tol), convergence_criterion (ct), max_it(it) {}
    
    real find_root (int & n_it); // In the professor implementation, 
                                 // it is a const, but I do want  to play 
                                // with the memeber of the class to run the bisection algorithm.
};

#endif

