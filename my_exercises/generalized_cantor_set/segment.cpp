#include "segment.h"

Segment::Segment()
{
	// Nothing to do.
}

Segment::Segment (double new_a, double new_b)	
{
	if (new_b < new_a)	{
		cerr<<"You cannot have b < a for a segment"<<endl;
	}
	else
	{
		a = new_a;
		b = new_b;
	}
}

void Segment::print() const
{
	cout<<"Segment : "<<a<<"|------"<<this->getLength()<<"------|"<<b<<endl; 
}

/*

// Test function
int main ()	
{
	Segment s1;
	Segment s2(0.0, 1.0);
	Segment s3(-1.32, 6.2134);

	Segment s2_h(s3.getBegin(), s3.getMiddle());
	s2_h.print();

	Segment s_err(s2.getMiddle(), s3.getBegin());
	s_err.print();

	return 0;
}

*/
