//#include<iostream>
//using namespace std;
//
//class city_info
//{
//private:
//	char name[30] = { "\0" };//城市名字
//	int population = 0;//人口数量
//	int farm = 0;//农田数量
//	int campus = 0;//书院
//	int gain = 0;//粮食
//	int tech = 0;//科技点产出
//public:
//	void change_name(char* new_name);
//	void add_population(int new_population);
//	void add_farm(int new_farm);
//	void build_campus();
//	void calculate();
//	void output();
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
//		else if (strcmp(trans_str, "quit") == 0)
//		{
//			break;
//		}
//
//		else if (strcmp(trans_str, "build") == 0)
//		{
//			char category[8] = { "\0" };
//			sscanf_s(instr, "%s %s", trans_str, (unsigned)_countof(trans_str), category, (unsigned)_countof(category));
//			if (strcmp(category, "campus") == 0)
//			{
//				city.build_campus();
//			}
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
//void city_info::calculate()
//{
//	gain = farm * 4 - population * 2;
//	tech = campus * 4;
//}
//
//void city_info::output()
//{
//	cout << name << " " << population << " "<< gain <<" "<< tech << " " << endl;
//}