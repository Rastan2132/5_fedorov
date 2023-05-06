#pragma once
#include "Header.h"


Uzond::Users::Users(const Users& other) {
    Name = other.Name;
    Surname = other.Surname;
    Year = other.Year;
    piesel = other.piesel;
    sex = other.sex;

}
Uzond::Uzond()
{
    people = nullptr;
    Name = "";
    Numer = "";
    size_Of_arr_peopls = 0;
}

Uzond::Uzond(const Uzond& other) {
    Name = other.Name;
    Numer = other.Numer;
    size_Of_arr_peopls = other.size_Of_arr_peopls;
    if (size_Of_arr_peopls > 0) {
        people = new Users * [size_Of_arr_peopls];
        for (int i = 0; i < size_Of_arr_peopls; i++)
        {
            people[i] = new Users(*other.people[i]);
        }
    }
    else {
        people = nullptr;
    }
}
Uzond::~Uzond() {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
    }
}
void Uzond::setPeople(Users** people_) {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
    }
    size_Of_arr_peopls = size;
    if (size > 0) {
        people = new Users * [size];
        for (int i = 0; i < size; i++) {
            people[i] = new Users(*people_[i]);
        }
    }
    else {
        people = nullptr;
    }
}

void Uzond::createPeopleArray(int size_of_people, vector<string> arrOfNames, vector<string> arrOfSurnames) {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
        people = nullptr;
    }
    size_Of_arr_peopls = size_of_people;
    if (size_of_people > 0) {
        people = new Users * [size_of_people];
        for (int i = 0; i < size_of_people; i++) {
            string sex = rand_data(sex_);
            string name = arrOfNames[rand_data(sex)];
            string surname = arrOfSurnames[rand_data(sex)];
            string year = rand_data(year_);
            string piesel = rand_data(piesel_);
            people[i] = new Users(name, surname, year, piesel, sex);
        }
    }
}

Uzond::Users* Uzond::getPerson(int index) const {
    if (index < 0 || index >= size_Of_arr_peopls) {
        return nullptr;
    }
    return people[index];
}

void Uzond::removePerson(int index) {
    if (index < 0 || index >= size_Of_arr_peopls) {
        return;
    }
    Users** new_people = new Users * [size_Of_arr_peopls - 1];
    int j = 0;
    for (int i = 0; i < size_Of_arr_peopls; i++) {
        if (i != index) {
            new_people[j] = people[i];
            j++;
        }
        else {
            delete people[i];
        }
    }
    people = new_people;
}

void Uzond::addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames) {
    string sex = rand_data(sex_);
    string name = arrOfNames[rand_data(sex)];
    string surname = arrOfSurnames[rand_data(sex)];
    string year = rand_data(year_);
    string piesel = rand_data(piesel_);

    Users* person = new Users(name, surname, year, piesel, sex);
    Users** new_people = new Users * [size_Of_arr_peopls];
    new_people = people;
    new_people[size_Of_arr_peopls - 1] = person;
}

void Uzond::Users::show()
{

            cout<< MANIP << Name << " "
                << MANIP << Surname << " "
                << MANIP << Year << " "
                << MANIP << piesel << " "
                << MANIP << sex << " ";
    
        cout << endl << " ";

}

void Uzond::show_ones( int j)
{
    if (people[j] != nullptr) {
        cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " " << MANIP << people[j]->Name << " " << MANIP << people[j]->Surname << " " << MANIP << people[j]->Year << " " << MANIP << people[j]->piesel << " " << MANIP << people[j]->sex << " ";
    }
    cout << endl << endl;
}

void Uzond::edit(int index_1, string name, string surname, string year, string piesel, string sex) {

    Users* person = new Users(name, surname, year, piesel, sex);
    Users** new_people = new Users * [size_Of_arr_peopls];
    for (int i = 0; i < size_Of_arr_peopls; i++) {
        new_people[i] = people[i];
    }
    new_people[index_1] = person;

    delete[] people;
    people = new_people;
}



void Uzond::sort(short flag)
{

    switch (flag)
    {
    case 1:
            for (short i = 0; i < size_Of_arr_peopls; i++) {
                for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                    if (people[i]->Name.compare(people[j]->Name) > 0) {
                        swap(people[i]->Name, people[j]->Name);
                        swap(people[i]->Surname, people[j]->Surname);
                        swap(people[i]->sex, people[j]->sex);
                        swap(people[i]->piesel, people[j]->piesel);
                        swap(people[i]->Year, people[j]->Year);
                    }
                }
        }
        break;
    case 2:
            for (short i = 0; i < size_Of_arr_peopls; i++) {
                for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                    if (people[i]->Surname.compare(people[j]->Surname) > 0) {
                        swap(people[i]->Name, people[j]->Name);
                        swap(people[i]->Surname, people[j]->Surname);
                        swap(people[i]->sex, people[j]->sex);
                        swap(people[i]->piesel, people[j]->piesel);
                        swap(people[i]->Year, people[j]->Year);
                    }
                }
            }
     
        break;
    case 3:
            for (short i = 0; i < size_Of_arr_peopls; i++) {
                for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                    if (people[i]->sex.compare(people[j]->sex) > 0) {
                        swap(people[i]->Name, people[j]->Name);
                        swap(people[i]->Surname, people[j]->Surname);
                        swap(people[i]->sex, people[j]->sex);
                        swap(people[i]->piesel, people[j]->piesel);
                        swap(people[i]->Year, people[j]->Year);
                    }
                }
            }
        break;
    case 4:
        for (short i = 0; i < size_Of_arr_peopls; i++)
        {
            for (short j = i + 1; j < size_Of_arr_peopls; j++)
            {
                if (people[i]->piesel.compare(people[j]->piesel) > 0)
                {
                    swap(people[i]->Name, people[j]->Name);
                    swap(people[i]->Surname, people[j]->Surname);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 5:

        for (short i = 0; i < size_Of_arr_peopls; i++) {
            for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                if (people[i]->Year.compare(people[j]->Year) > 0) {
                    swap(people[i]->Name, people[j]->Name);
                    swap(people[i]->Surname, people[j]->Surname);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
        
    }
}
void Uzond::find(char* keyword) {

    for (short i = 0; i < size_Of_arr_peopls; i++)
    {
        if (strstr_lower(stringToArrChar(people[i]->Name).data(), keyword)
            || strstr_lower(stringToArrChar(people[i]->Surname).data(), keyword)
            || strstr_lower(stringToArrChar(people[i]->piesel).data(), keyword)
            || strstr_lower(stringToArrChar(people[i]->Year).data(), keyword)
            || strstr_lower(stringToArrChar(people[i]->sex).data(), keyword))

        {
            cout << left << setw(3) << i + 1 << "  ";
            print_find(stringToArrChar(people[i]->Name).data(), MAXLINE, keyword, MAXLINE, Red);
            print_find(stringToArrChar(people[i]->Surname).data(), MAXLINE, keyword, MAXLINE, Red);
            print_find(stringToArrChar(people[i]->Year).data(), MAXLINE, keyword, MAXLINE, Red);
            print_find(stringToArrChar(people[i]->piesel).data(), MAXLINE, keyword, MAXLINE, Red);
            print_find(stringToArrChar(people[i]->sex).data(), MAXLINE, keyword, MAXLINE, Red);

            cout << endl;
        }
    }
    cout << endl;
}


bool Uzond::initForFile(std::istream& in, short size_of_peopl) {
   
        string name_u, numer;
        in >> name_u >> numer;
        Name = name_u;
        Numer = numer;

        if (size_of_peopl > 0) {
            Users** p = new Users * [size_of_peopl];
            for (int j = 0; j < size_of_peopl; j++) {
                string name, surname, year, pesel, sex;
                in >> name >> surname >> year >> pesel >> sex;
                p[j] = new Users(name, surname, year, pesel, sex);
            }
           people = p;
        }
    
    return true;
}

std::istream& operator>>(std::istream& in, Uzond*& program){
    short size, size_of_peopl;
    in >> size >> size_of_peopl;
    program = new Uzond[size];
    for (short i = 0; i < size; i++) {
        program[i].initForFile(in, size_of_peopl);
        program[i].set_size(size);
        program[i].set_size_Of_arr_peopls(size_of_peopl);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Uzond& program) {
    program.save(out);
    return out;
}
bool Uzond::save(std::ostream& out) const {
    out << size << " " << size_Of_arr_peopls << " ";

    for (short i = 0; i < size; i++) {
        out << Name << " " << Numer << " ";
        for (short j = 0; j < size_Of_arr_peopls; j++) {
            out << people[j]->Name << " " << people[j]->Surname << " "
                << people[j]->Year << " " << people[j]->piesel << " "
                << people[j]->sex << " ";
        }
        out << std::endl;
    }

    return true;
}
