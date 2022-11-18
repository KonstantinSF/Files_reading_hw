#include<iostream>
#include<fstream>
#include<string>

using namespace std; 
void main()
{
	setlocale(LC_ALL, "");
	std::string* IP_global = new string[100]{};
	std::string* MAC_global = new string[100]{};
	int num_of_lines=0;
	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		std::string buffer;
		for (int i = 0; !fin.eof(); i++, num_of_lines++) std::getline(fin, buffer);
		std::string* IP_local = new string[num_of_lines];
		std::string* MAC_local = new string[num_of_lines];
		//cout << num_of_lines << endl;
		//fin.seekg(0, fin.end);//курсор в конец
		//int length = fin.tellg();//возвращает номер позиции
		//fin.seekg(0, fin.beg);//курсор в начало
		//cout << length << endl; //490 
		fin.clear(); fin.seekg(0, fin.beg);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				for (int i = 0; i < num_of_lines; i++)
				{
					std::getline(fin, IP_local[i], ' ');
					std::getline(fin, MAC_local[i]);
					MAC_local[i].erase(0, 8); //delete from begin 8 digits
#ifdef CHECK_READING
					cout << IP_local[i] << endl;
					cout << MAC_local[i] << endl;
#endif // !CHECK_READING

					IP_global[i] = IP_local[i];
					MAC_global[i] = MAC_local[i];
				}
			}
			fin.close();
		}
		delete[] IP_local;
		delete[] MAC_local;
	}
	else cerr << "File not found:(" << endl;
	//for (int i = num_of_lines; i < 100; i++)delete IP[i];
	
	cout << IP_global[0] << endl;
	cout << MAC_global[0] << endl;
	
	delete[] IP_global;
	delete[] MAC_global;
}