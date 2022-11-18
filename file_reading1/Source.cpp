#include<iostream>
#include<fstream>
#include<string>

using namespace std; 
void main()
{
	setlocale(LC_ALL, "");

	int num_of_lines=0;
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
#ifdef CHECK_READING
					cout << IP[i] << endl;
					cout << MAC[i] << endl;
#endif // !CHECK_READING
				}
			}
			fin.close();
		}
	else cerr << "File not found:(" << endl;
	
#ifdef CHECK_GLOBAL
	cout << IP[11] << endl;
	cout << MAC[11] << endl;
#endif // CHECK_GLOBAL

	std::string filename="201 ready.txt"; //консоль не создает файл!!!
	std::fstream fout; 
	fout.open("201 ready.txt"); 


	fout.close();
	system("notepad 201 ready.txt"); //запрос о создании файла идет отсюда



delete[] IP;
delete[] MAC;
}