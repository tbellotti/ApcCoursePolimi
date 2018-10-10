#include "bisection.h"

bool Bisection::convergence (const real increment, const real residual, const real tol, criterion crt) const
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

real Bisection::find_root(int & n_it)
{
    n_it = 0; // I set the number of iterations in case the user of the class forgets it.


    if (target_function.evaluate(inf_lim) * target_function.evaluate(sup_lim) >= 0.)    {
        std::cerr<<"The function has the same sign at both provided endpoints"<<std::endl;
		return - std::numeric_limits<double>::infinity();
    }

    real mid_point = 0.5*(inf_lim + sup_lim); // just to have it outside the while scope. 
    real res = target_function.evaluate(mid_point); 
    real incr  = sup_lim - inf_lim; 

    while ((n_it < max_it) && (!convergence(incr, fabs(res) , tol, convergence_criterion)))   {
    //while (n_it < 20)   {   
        if (target_function.evaluate(inf_lim) * res < 0)    {
            sup_lim = mid_point;
        }
        else    {
            inf_lim = mid_point;
        }

        //std::cout<<"Interval = ["<<inf_lim<<", "<<sup_lim<<"]  "<<"Midpoint = "<<mid_point<<"  Residual = "<<res<<" Length interv = "<<incr<<std::endl;
        
        mid_point = 0.5*(inf_lim + sup_lim); // Computing the new mid-point
        res   = target_function.evaluate(mid_point); // Computing the residual
        incr *= 0.5;    // Computing the length of the new search interval.

        n_it ++ ;   
    }

    return mid_point;
}


