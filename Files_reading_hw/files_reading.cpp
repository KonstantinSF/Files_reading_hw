#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void main()
{
	setlocale(LC_ALL, ""); 
	int num_of_addresses=0; 

	std::fstream fin("201 RAW.txt"); 
	if (fin.is_open())
	{
		std::string buffer;
		for (int i = 0; !fin.eof(); i++, num_of_addresses++)
		{
			std::getline(fin, buffer);
		}

		fin.seekg(0, fin.end);//курсор в конец
		int length = fin.tellg();//возвращает номер позиции
		fin.seekg(0, fin.beg);//курсор в начало
		//cout << length << endl; //490

		string* IP_address = new string[num_of_addresses]; 

		while (fin.tellg()<490)
		{
			for (int i = 0; i < num_of_addresses; i++)
			{
				std::getline(fin, IP_address[i], ' ');
				int pos = fin.tellg(); pos += 24; 
				fin.seekg(pos); 
				cout << IP_address[i] << endl;
			}
		}
		delete [] IP_address;
		fin.close(); 
	cout << IP_address[1] << endl; 
	}
	else cerr << "File not found :(" << endl; 
}