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
		//cout << num_of_lines << endl;
		//fin.seekg(0, fin.end);//курсор в конец
		//int length = fin.tellg();//возвращает номер позиции
		//fin.seekg(0, fin.beg);//курсор в начало
		//cout << length << endl; //490 
		fin.clear(); fin.seekg(0, fin.beg); 
		std::string* IP = new string[num_of_lines]; 
		std::string* MAC = new string[num_of_lines]; 
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				for (int i = 0; i < num_of_lines; i++)
				{
					std::getline(fin, IP[i], ' '); 
					std::getline(fin, MAC[i]); 
					MAC[i].erase(0, 8); //delete from begin 8 digits
#ifdef CHECK_READING
					cout << IP[i] << endl;
					cout << MAC[i] << endl;
#endif // CHECK_READING
				}
			}
			fin.close(); 
		}
		delete[] IP; 
		delete[] MAC; 

	}
	else cerr << "File not found:(" << endl; 
}