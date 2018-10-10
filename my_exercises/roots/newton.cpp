#include "newton.h"

bool Newton::convergence (const real increment, const real residual, const real tol, criterion crt) const
{
    switch(crt) {
        case INCREMENT :
            return (increment<tol);
        case RESIDUAL  :
            return (residual<tol);
        case BOTH      :
            return (increment<tol) && (residual<tol);
        default        :
            return false;
    }
}

real Newton::find_root (int & n_it) 
{

    n_it = 0;

    real curr_jacobian = jacobian.evaluate(guess);
    real curr_residual = target_function.evaluate(guess);
    real old_guess = guess;
    real incr = 2*tol;


    while ((n_it < max_it) && (!convergence(fabs(incr), fabs(curr_residual), tol, convergence_criterion)))    {
        if (!curr_jacobian) {
            std::cerr<<"The jacobian vanishes"<<std::endl;
            exit(1);
        }
        guess = guess - curr_residual/curr_jacobian;
        incr = guess - old_guess;
        curr_residual = target_function.evaluate(guess);
        curr_jacobian = jacobian.evaluate(guess);
        old_guess = guess;
        n_it++;
    }

    return guess;
}