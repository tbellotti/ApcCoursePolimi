#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

class Segment	
{

private:
	double a = 0.0;	// Left-end of the segment
	double b = 0.0;	// Right-end of the segment

public:
	// Constructors
	Segment(); //  Default constructor.
	Segment(double new_a, double new_b);


	// Other functions
	inline double getBegin() const { return a; };
	inline double getEnd() const { return b; };
	inline double getLength() const { return b-a; };
	inline double getMiddle() const { return 0.5*(b-a); };
	
	void print() const;
};


#endif
