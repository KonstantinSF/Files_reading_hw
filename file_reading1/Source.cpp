#include<iostream>
#include<fstream>
#include<string>

using namespace std; 

void main()
{
	setlocale(LC_ALL, ""); 
	int num_of_lines = 0; 
	std::ifstream fin("201 RAW.txt"); 
	if (fin.is_open())
	{
		std::string buffer; 
		for (int i = 0; !fin.eof(); i++, num_of_lines++) std:: getline(fin, buffer);
		cout << num_of_lines << endl; 
	}
	else cerr << "File not found:(" << endl; 

}