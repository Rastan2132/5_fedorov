#include "Header.h"

int main()
{
	bool work = 1;
	short urz_num, p_num;
	Uzond* program{ nullptr };

	vector<string> NAMES = { "Alexander","Maxim","Dmitry","Sergei","Ivan","Anna","Maria","Olga","Elena","Natalia" };
	vector<string> SURNAMES = { "Ivanov","Petrov","Sidorov","Smirnov","Kuznetsov","Ivanova","Petrova","Sidorova","Smirnova","Kuznetsova" };
	vector<string>NAMES_of_Uzond = { "Urzad_Pracy","Urzad_Spraw","Urzad_Skarbowy","Urzad_s._cywilnego" };

	if (chek_file("Uzonds.txt") == 0)
	{
		short size = rand() % 10 + 1;
		short size_of_peopl = rand() % 10 + 1;
		program = create(size, size_of_peopl, NAMES_of_Uzond, NAMES, SURNAMES);

		program->set_size(size);
		program->set_size_Of_arr_peopls(size_of_peopl);
	}
	else
	{
		std::ifstream file("Uzonds.txt");
		program >> file;
		file.close();
	}


	if (program->get_size() < 0)
	{
		error();
		program->set_size(0);
	}

	ShowCursor(0);
	do
	{
		show(program);
		switch (_getch())
		{
		case (113):
			work = false;
			break;
		case (97):
			add(program, NAMES, SURNAMES, NAMES_of_Uzond);
			break;
		case (100):
			dell(program);
			break;
		case (101):
			do {
				cout << "wprowadz numer urzendu i numer osoby" << endl;
				cin >> urz_num >> p_num;
				if (urz_num > 0 && p_num > 0 && urz_num <= program->get_size() && p_num <= program->get_size_Of_arr_peopls())
					break;
				error();
			} while (true);
			edit(program, urz_num - 1, p_num - 1);
			break;
		case (115):
			program->sort(program);
			break;
		case (121):
			program->find(program);
			break;
		}
	} while (work);
	std::ofstream  file("Uzonds.txt");
	for (short i = 0; i < program->get_size(); i++) {
		file << program[i];
	}
	file.close();

}
