#include "polynomial_function.h"
#include "bisection.h"
// #include <vector>

int main ()
{
    std::vector<double> test_coefficients {1., 2., 3.}; // This is P(X) = 1 + 2*X + 3*X^2
    Polynomial_Function test_poly (test_coefficients);

    test_poly.print();
    Polynomial_Function test_poly_derivative = test_poly.derivative();
    test_poly_derivative.print();

    std::cout<<"P(2) = "<<test_poly.evaluate(2)<<"  P'(2) = "<<test_poly_derivative.evaluate(2)<<std::endl;

    std::cout<<std::endl<<std::endl<<"Testing BISECTION"<<std::endl;

    std::vector <real> my_coeff {-1., -1.0, 1.0};
    Polynomial_Function my_poly (my_coeff);
    my_poly.print();

    Bisection my_method_bs (my_poly, 1.5, 3, 0.0001, BOTH, 200);

    int n_it;
    real result = my_method_bs.find_root(n_it);

    std::cout<<"Solution = "<<result<<"  found in "<<n_it<<" iterations"<<std::endl;


}
