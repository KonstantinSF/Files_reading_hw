#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>
using namespace std; 

void main()
{
	setlocale(LC_ALL, ""); 
	int num_of_lines=0; 

	std::fstream fin("201 RAW.txt"); 
	if (fin.is_open())
	{
	string* IP_address = new string[num_of_lines]; //each of elements is String, not a char!!!
	string* MAC = new string[num_of_lines]; 
		std::string buffer;
		for (int i = 0; !fin.eof(); i++, num_of_lines++)
		{
			std::getline(fin, buffer);
		}
		fin.seekg(0, fin.end);//курсор в конец
		int length = fin.tellg();//возвращает номер позиции
		fin.seekg(0, fin.beg);//курсор в начало
		//cout << length << endl; //490

		while (!fin.eof())
		{
			for (int i = 0; i < num_of_lines; i++)
			{
				std::getline(fin, IP_address[i], ' ');
				std::getline(fin, MAC[i]);
				MAC[i].erase(0, 8); 
				/*int pos = fin.tellg(); pos += 24; 
				fin.seekg(pos); */
				cout << IP_address[i] << endl;
				cout << MAC[i] << endl; 
			}
		}
		/*cout << IP_address[0].length();
		cout << MAC[0].length();
		cout << MAC[0][1] << endl; */
		fin.close(); 
	delete[] IP_address;
	delete[] MAC; 
	}
	else cerr << "File not found :(" << endl; 

	//std::string filename = "2.txt";
	//std::fstream fout; //cteate a stream
	//fout.open("2.txt");//open stream с ф-ей перезаписывания
	//fout << 1234564;//write in a stream
	//fout.close(); //close the stream
	//std::string command = "notepad" + filename;
	//system(command.c_str());



}