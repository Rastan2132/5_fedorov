#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>
#include <vector>
#include <sstream>


using namespace std;

#define MAXLINE 20
#define num_ 3
#define sex_ 2
#define year_ 4
#define piesel_ 12

#define MENU "| q-Zamkac |  a-ADD uzytkownika  |  d-Usuwanie uzytkownika |  e-Redaktor |  s-Sortowac |  y-Szukaj |" 
#define stru "#       Name                 Surname	          Year		       Piesel 	       Sex"

#define MANIP setw(MAXLINE) <<  left 

int rand_data(string sex);
string rand_data(int max);

struct COLOR
{
    short text;
    short back;
};
enum ConsoleColor
{
    Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

enum Keys { Enter = 13, Backspace = 8 };
enum SpecialKeys { Left = 75, Right = 77, End = 79, Home = 71, Esc = 27, Del = 83 };

class Uzond {
private:
    class Users {

        string Name;
        string Surname;
        string Year;
        string piesel;
        string sex;
    public:
        Users() : Name(""), Surname(""), Year(""), piesel(""), sex("") {}
        Users(string name, string surname, string year, string pesel, string sex)
            : Name(name), Surname(surname), Year(year), piesel(pesel), sex(sex) {}

        Users(const Users& other);

        
        void show();
        friend class Uzond;
    };

private:
    Users** people;
    string Name;
    string Numer;
    short  size_Of_arr_peopls;
    short size;

public:
    Uzond();
    Uzond(const Uzond& other);
    ~Uzond();
    void setPeople(Users** people_);
    Users** getPeople() const { return people; }

    int get_size_Of_arr_peopls() { return size_Of_arr_peopls; }
    void set_size_Of_arr_peopls(int size_Of_arr_peopls_) { size_Of_arr_peopls = size_Of_arr_peopls_; }

    int get_size() { return size; }
    void set_size(short size_) { size = size_; }

    void setName(string Name_) { Name = Name_; }
    string getName() const { return Name; }

    void setNumer(string Numer_) { Numer = Numer_; }
    string getNumer() const { return Numer; }

    void createPeopleArray(int size_of_people, vector<string> arrOfNames, vector<string> arrOfSurnames);
    Users* getPerson(int index) const;
    void removePerson(int index);

    void addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames);
    void show_ones( int j);

    void edit(int index_1, string name, string surname, string year, string piesel, string sex);
    void find(char* keyword);
    bool initForFile(istream& in, short size_of_peopl);
    void sort(short flag);
    bool save(std::ostream& out) const;
    Users& operator[](int index) {
        return *people[index];
    }
    Uzond& operator=(const Uzond& other) {
        if (this != &other) {
            delete[] people;

            Name = other.Name;
            Numer = other.Numer;
            size_Of_arr_peopls = other.size_Of_arr_peopls;
            people = new Users * [size_Of_arr_peopls];
            for (int i = 0; i < size_Of_arr_peopls; i++) {
                people[i] = new Users(*other.people[i]);
            }
        }
        return *this;
    }


};

void error();

void removeUzond(Uzond*& program, short index);
Uzond* create(short size, short size_of_peopl, vector<string> arrOfNameUrzant, vector<string> arrOfNames, vector<string> arrOfSurnames);
void show(Uzond* program);
void add(Uzond*& program, vector<string> arr_name, vector<string> arr_suname, vector<string>arr_of_name_urzant);
char* strstr_lower(char* str_a, char* str_b);
bool isalpha_r(unsigned char a);
bool isdigit_r(unsigned char a);
vector<char> stringToArrChar(const string& str);
void edit(Uzond*& program, short index_1, short index_2);
void dell(Uzond*& program);
bool chek_file(string file);
void find(Uzond*& program);

COORD getCursorPosition(void);
void Clear(int x, int y, long cnt = 100);
bool stredit(char* str, int buffer_size, int x, int y, int cursor = 0, bool clear_after = true);
void showcursor(bool flag);
void setCursorPosition(int x, int y);
COORD getConsoleSize();
COLOR GetColor();
WORD GetColorWord();
void SetColor(COLOR Color);
void print_find(char* str, short str_size, char* keyword, short key_size, int text = -1, int back = -1);

void DeleteCh(char* str, int& cursor, int& term);
void InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb);


std::istream& operator>>(std::istream& in, Uzond*& program);
std::ostream& operator<<(std::ostream& out, const Uzond& program);