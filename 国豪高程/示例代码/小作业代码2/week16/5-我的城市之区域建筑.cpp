//#include<iostream>
//using namespace std;
//
//class city_info
//{
//private:
//	char name[30] = { "\0" };//城市名字
//	double tech = 0;//科技点产出
//	int population = 0;//人口数量
//	int farm = 0;//农田数量
//	int campus = 0;//书院
//	int library = 0;
//	int university = 0;
//	int lab = 0;
//	int gain = 0;//粮食
//	bool A = false;
//	bool B = false;
//	bool C = false;
//	
//public:
//	void change_name(char* new_name);
//	void add_population(int new_population);
//	void add_farm(int new_farm);
//	void build_campus();
//	void build_library();
//	void build_university();
//	void build_lab();
//	void calculate();
//	void output();
//	void set(char type);
//};
//
//int main()
//{
//	class city_info city;
//	char inition[100];//初始化指令
//	char name[30] = { "\0" };
//	int population = 0;
//	int farm = 0;
//
//	//完成初始化操作
//	cin.getline(inition, 100);
//	sscanf_s(inition, "%s %d %d", name, (unsigned)_countof(name), &population, &farm);
//	city.change_name(name);//初始化城市名
//	city.add_population(population);//初始化的人口和农田
//	city.add_farm(farm);
//
//	while (true)
//	{
//		char instr[100] = { "\0" };
//		char trans_str[15] = { "\0" };
//
//		cin.getline(instr, 100);
//		sscanf_s(instr, "%s", trans_str, (unsigned)_countof(trans_str));
//
//		if (strcmp(trans_str, "population") == 0)
//		{
//			int population;
//			sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &population);
//			city.add_population(population);
//		}
//
//		else if (strcmp(trans_str, "farm") == 0)
//		{
//			int farm;
//			sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &farm);
//			city.add_farm(farm);
//		}
//
//		else if (strcmp(trans_str, "set") == 0)
//		{
//			char type;
//			sscanf_s(instr, "%s %c", trans_str, (unsigned)_countof(trans_str), &type,1);
//			city.set(type);
//		}
//
//		else if (strcmp(trans_str, "build") == 0)
//		{
//			char category[15] = { "\0" };
//			sscanf_s(instr, "%s %s", trans_str, (unsigned)_countof(trans_str), category, (unsigned)_countof(category));
//			if (strcmp(category, "campus") == 0)
//			{
//				city.build_campus();
//			}
//
//			else if (strcmp(category, "library") == 0)
//			{
//				city.build_library();
//			}
//
//			else if (strcmp(category, "university") == 0)
//			{
//				city.build_university();
//			}
//
//			else if (strcmp(category, "lab") == 0)
//			{
//				city.build_lab();
//			}
//		}
//
//		else if (strcmp(trans_str, "quit") == 0)
//		{
//			break;
//		}
//		city.calculate();
//		city.output();
//	}
//	return 0;
//}
//
//void city_info::change_name(char* new_name)
//{
//	strcpy_s(name, new_name);
//}
//
//void city_info::add_population(int new_population)
//{
//	if (population + new_population > 0)
//	{
//		population += new_population;
//	}
//
//	else
//	{
//		population = 0;
//	}
//}
//
//void city_info::add_farm(int new_farm)
//{
//	if (farm + new_farm > 0)
//	{
//		farm += new_farm;
//	}
//
//	else
//	{
//		farm = 0;
//	}
//}
//
//void city_info::build_campus()
//{
//	if (campus == 0)
//	{
//		campus++;
//	}
//}
//
//void city_info::build_library()
//{
//	if (campus == 1)
//	{
//		library++;
//	}
//}
//
//void city_info::build_university()
//{
//	if (library == 1)
//	{
//		university++;
//	}
//}
//
//void city_info::build_lab()
//{
//	if ( university == 1)
//	{
//		lab++;
//	}
//}
//
//void city_info::set(char type)
//{
//	if (type == 'A')
//	{
//		A = true;
//		B = false;
//		C = false;
//	}
//
//	else if (type == 'B')
//	{
//		A = false;
//		B = true;
//		C = false;
//	}
//
//	else if (type == 'C')
//	{
//		A = false;
//		B = false;
//		C = true;
//	}
//}
//
//void city_info::calculate()
//{
//	gain = farm * 4 - population * 2;
//	if (population > 10 && lab == 1 )
//	{
//		tech = campus * 4 + library * 4 + university * 8 + lab * 16 + population * (0.5 * library + university + lab) + 2 * lab * (population - 10);
//	}
//
//	else
//	{
//		tech = campus * 4 + library * 4 + university * 8 + lab * 16 + population * (0.5 * library + university + lab);
//	}
//
//	if (A)
//	{
//		tech += 10 * (library + university + lab);
//	}
//
//	else if (B)
//	{
//		tech += 2 * population;
//	}
//
//	else if (C)
//	{
//		if (gain > 0)
//		{
//			tech += gain;
//
//		}
//	}
//}
//
//void city_info::output()
//{
//	cout << name << " " << population << " " << gain << " " << tech << " " << endl;
//}