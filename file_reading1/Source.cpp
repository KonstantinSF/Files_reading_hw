#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

#define READ_FROM_BASE_FILE
//#define WRITE_CHANGE_PLACES
//#define WRITE_HOSTS

void main()
{
	setlocale(LC_ALL, "");

#ifdef READ_FROM_BASE_FILE
	int num_of_lines = 0;
	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		std::string buffer;
		for (int i = 0; !fin.eof(); i++, num_of_lines++) std::getline(fin, buffer);
		fin.clear(); fin.seekg(0, fin.beg);
	}
	else cerr << "File not found:(" << endl;

	std::string* IP = new string[num_of_lines];
	std::string* MAC = new string[num_of_lines];
	//cout << num_of_lines << endl;
	//fin.seekg(0, fin.end);//курсор в конец
	//int length = fin.tellg();//возвращает номер позиции
	//fin.seekg(0, fin.beg);//курсор в начало
	//cout << length << endl; //490 

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			for (int i = 0; i < num_of_lines; i++)
			{
				std::getline(fin, IP[i], ' ');
				std::getline(fin, MAC[i]);
				MAC[i].erase(0, 8); //delete from begin 8 digits
#ifndef CHECK_READING
				cout << IP[i] << endl;
				cout << MAC[i] << endl;
#endif // !CHECK_READING
			}
		}
		fin.close();
	}
	else cerr << "File not found:(" << endl;
#endif // READ_FROM_BASE_FILE
	
#ifdef CHECK_GLOBAL
	cout << IP[11] << endl;
	cout << MAC[11] << endl;
#endif // CHECK_GLOBAL

#ifdef WRITE_CHANGE_PLACES
	std::string filename = "201 ready.txt"; //консоль не создает файл!!!
	std::fstream fout;
	fout.open("201 ready.txt");
	for (int i = 0; i < num_of_lines; i++) fout << MAC[i] << "        " << IP[i] << "\n";
	fout.close();
	system("notepad 201 ready.txt"); //запрос о создании файла идет отсюда(  
#endif // WRITE_CHANGE_PLACES

#ifdef WRITE_HOSTS
	std::string filename2 = "201.dhcp.txt";
	std::fstream fout2;
	fout2.open("201.dhcp.txt");
	for (int i = 0; i < num_of_lines; i++)
	{
		fout2 <<
			"host 201-" << i + 1 << "\n" <<
			"{\n" <<
			"hardware ethernet\t" << MAC[i] << ";\n" <<
			"fixed-address\t\t" << IP[i] << ";\n" <<
			"}\n";
	}
	fout2.close();
	system("notepad 201.dhcp.txt");
#endif // WRITE_HOSTS

delete[] IP;
delete[] MAC;
}