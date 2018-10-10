#ifndef ROOT_FINDING_H
#define ROOT_FINDING_H

#include <iostream>
#include <cmath>
#include <limits>

//! Type for real numbers
typedef double real;

//! Type for convergence check
enum criterion {
  INCREMENT, //! Check the difference between subsequent iterates
  RESIDUAL,  //! Check the residual
  BOTH       //! Check both conditions
};

#endif