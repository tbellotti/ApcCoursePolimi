#ifndef _CANTORSET_H
#define _CANTORSET_H

#include <vector>
#include <string>
#include "segment.h"

using std::vector;
using std::string;

class CantorSet
{

friend void createCantorSetTikz (std::string filename, unsigned int n_iter, double my_eps, double spacing);

private:
	double epsilon = 0.;
	vector <Segment> subsets;
public:
	
	// Constructors 
	CantorSet() = default;
	CantorSet(double my_eps) : epsilon(my_eps) {}
	CantorSet(double my_eps, double a, double b) : epsilon(my_eps) { subsets.push_back(Segment(a,b)); }
	CantorSet(double a, double b) { subsets.push_back(Segment(a,b)); }

	// Other functions
	// void printToFile(string filename) const;
	void oneDivision();
	void someDivisions(unsigned int num_divisions);
	void print() const;
};



#endif


