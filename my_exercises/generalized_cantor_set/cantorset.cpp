#include "cantorset.h"
#include <fstream>

void CantorSet::print() const
{
	cout<<"Partial Cantor set with epsilon = "<<epsilon<<endl<<endl;
	for (auto it = subsets.cbegin(); it != subsets.cend(); ++it)	{
		it->print();		
	}
}

void CantorSet::oneDivision()	{
	vector<Segment> new_subsets;


	for (auto it = subsets.cbegin(); it != subsets.cend(); it++)	{

		new_subsets.push_back(Segment(it->getBegin(), it->getMiddle()- it->getLength()*epsilon/6.0));
		new_subsets.push_back(Segment(it->getMiddle() + it->getLength()*epsilon/6.0, it->getEnd()));
	}

	
	this->subsets = new_subsets;
}

void CantorSet::someDivisions(unsigned int num_divisions)	
{
	for (unsigned int i = 0; i < num_divisions; ++i)	{
		this->oneDivision();
	}

}
	

void createCantorSetTikz (std::string filename, unsigned int n_iter, double my_eps, double spacing)
{

	const double factor = 12.0;

	// Creating the output stream
	std::ofstream draw_file;
	draw_file.open (filename+".tex");

	// Just some content to use tikZ
	draw_file<<"\\documentclass[10pt, a4paper]{article}"<<endl;
	draw_file<<"\\usepackage{amsmath}"<<"\\usepackage{tikz}"<<endl<<"\\begin{document}"<<"\\textbf{Generalized Cantor Set} with $\\epsilon = $"<<my_eps<<endl<<endl<<"\\begin{tikzpicture}"<<endl;

 	// Creating the base segment for the set. 
	double y = 0.0; // y-cordinate to increment according to spacing at each iteration.
	CantorSet my_set(my_eps, 0.0, 1.0);

	for (unsigned int c_it = 0; c_it < n_iter; ++c_it)	{
		
		for (auto it = my_set.subsets.cbegin(); it != my_set.subsets.cend(); ++it)	{
			draw_file<<"\\draw [line width=2.0mm] ("<<factor*(it->getBegin())<<","<<y<<") -- ("<<factor*(it->getEnd())<<","<<y<<");"<<endl;	
		}
		my_set.oneDivision();
		y += spacing;		

	}	


	// To finish the file.
	draw_file<<"\\end{tikzpicture}"<<endl<<"\\end{document}"<<endl;	


	// CLosing the file stream
	draw_file.close();
}	

// Testing routine
int main ()
{
	CantorSet my_c_set (1.0, 0.0, 1.0);
	//my_c_set.print();	

	//my_c_set.oneDivision();

	//my_c_set.print();

	my_c_set.someDivisions(10);
	my_c_set.print();

	string fname("cantorset");
	createCantorSetTikz (fname, 14, 0.6, 0.3);


	string call = "pdflatex "+fname+".tex";
	system(call.c_str());
	return 0;
	
}



