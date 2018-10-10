#ifndef __BISECTION_H__
#define __BISECTION_H__

#include "polynomial_function.h"
#include "root_finding.h"

class Bisection
{

private:
    Polynomial_Function target_function; // Function for which we want to solve F(x) = 0.
    real inf_lim = 0.;
    real sup_lim = 0.;
    const real tol = 0.;
    unsigned int max_it = 0;
    criterion convergence_criterion = BOTH;
    bool convergence (const real increment, const real residual, const real tol, criterion crt) const;

public:
    Bisection(const Polynomial_Function & new_target, const real x_min, const real x_max, const real new_tol, const criterion ct, int it)
            : target_function (new_target), inf_lim(x_min), sup_lim(x_max), tol(new_tol), convergence_criterion (ct), max_it(it) {}
    
    real find_root (int & n_it); // In the professor implementation, 
                                 // it is a const, but I do want  to play 
                                // with the memeber of the class to run the bisection algorithm.
};

#endif

