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
	Segment() = default; //  Default constructor.
	Segment(double new_a, double new_b) : a(new_a), b(new_b)
		{
			if (new_a > new_b)	{
				cerr<<"You cannot have b < a for a segment"<<endl;	
				a = 0.0;
				b = 0.0;
			}
		};


	// Other functions
	inline double getBegin() const { return a; };
	inline double getEnd() const { return b; };
	inline double getLength() const { return (b-a); };
	inline double getMiddle() const { return 0.5*(a+b); };
	
	void print() const;
};


#endif
