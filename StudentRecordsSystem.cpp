#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <windows.h>
#include <set>

using namespace std;

const int line_spaces = 159;

string printNmid(string s, char feg);
string printNmid(string s);
string wordtolower(string &s);
bool isGender(string &s);

class Person
{
private:
    string name;
    int age;
    string gender;
    string address;
    string phone;
public:
    Person(){}
    ~Person(){}
    void view()
    {
        cout << "\n";
        cout << printNmid("NAME: " + name);
        cout << printNmid("AGE: " + to_string(age));
        cout << printNmid("GENDER: " + gender);
        cout << printNmid("ADDRESS: " + address);
        cout << printNmid("PHONE: " + phone);
        cout << "\n";
    }
    void setData()
    {
        cout << "Enter student's name: ";           cin >> name;
        cout << "Enter student's age: ";            cin >> age;
        do
        {
            cout << "Enter student's gender (male/female) : ";  
            cin >> gender;
        } while (isGender(gender));
        cout << "Enter student's address: ";            cin >> address;
        cout << "Enter student's phone: ";            cin >> phone;
    }
};

class Student : public Person
{
private:
    float gpa;
    string depart;
    int level;
    int id;
public:
    Student() 
    {}
    ~Student()
    {}
    int getId()
    {
        return id;
    }
    void setId(int dd)
    {
        id = dd;
    }
    void modify()
    {
        Person::setData();
        cout << "Enter student's gpa: ";          cin >> gpa;
        cout << "Enter student's depart: ";     cin >> depart;
        cout << "Enter student's level: ";      cin >> level;      
    }
    void setData()
    {
        cout << "Enter student's id: ";     cin >> id;
        Student::modify();
    }
    void view()
    {
        cout << printNmid(to_string(id), '-');
        Person::view();
        cout << printNmid("GPA: " + to_string(gpa));
        cout << printNmid("DEPART: " + depart);
        cout << printNmid("LEVEL: " + to_string(level));
        cout << printNmid("-",'-');
    }
};

void goodbye();
void pressanykey();
string printNmid(int width, string s);
void menu(int menum);
void welcome();

int main(void)
{
    Student *st[100];
    bool found = false;
    int num = 0;
    system("cls");
    system("color 08");
    welcome();
    int searchNum;
    int choice;
    do
    {
        system("color 08");
        menu(1);
        cout << "Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            system("color 0a");
            menu(2);
            /* add */
            found = false;
            cout << "Enter the id of student: ";
            cin >> searchNum;
            for (int i = 0; i < num; i++)
            {
                if (searchNum == st[i]->getId() && st[i] != NULL)
                {
                    found = true;
                }
            }
            if (!found)
            {
                st[num] = new Student();
                st[num]->setId(searchNum);
                st[num]->modify();
                num++;
            }
            else   cout << "id exists, please choose new one!!!\n";
            pressanykey();
            system("cls");
            break;
        case 2:
            system("cls");
            system("color 09");
            menu(3);
            /* view */
            if (num == 0)
                cout << "it's empty, please fill it...\n";
            else 
            {
                for (int i = 0; i < num; i++)
                {
                    if (st[i] != NULL)
                    st[i]->view();
                }
            }
            pressanykey();
            system("cls");  
            break;
        case 3:
            system("cls");
            system("color 0c");
            menu(4);
            /* search */
            if (num == 0) cout << "it's empty, please fill it...\n";
            else 
            {
                found = false;
                cout << "Enter the id of student: ";
                cin >> searchNum;
                for (int i = 0; i < num; i++)
                {
                    if (st[i] == NULL) continue;
                    if (searchNum == st[i]->getId())
                    {
                        found = true;
                        st[i]->view();
                    }
                }
                if (!found) cout << "Wrong id\n";
            }
            pressanykey();
            system("cls");
            break;
        case 4:
            system("cls");
            system("color 06");
            menu(5);
            /* modify */
            if (num == 0) cout << "it's empty, please fill it...\n";
            else 
            {
                found = false;
                cout << "Enter the id of student: ";
                cin >> searchNum;
                for (int i = 0; i < num; i++)
                {
                    if (searchNum == st[i]->getId() && st[i] != NULL)
                    {
                        found = true;
                        st[i]->modify();
                    }
                }
                if (!found) cout << "Wrong id\n";
            }
            pressanykey();
            system("cls");
            break;
        case 5:
            system("cls");
            system("color 09");
            menu(6);
            /* delete */
            found = false;
            cout << "Enter the id of student: ";
            cin >> searchNum;
            for (int i = 0; i < num; i++)
            {
                found = true;
                if (searchNum == st[i]->getId())
                {
                    delete st[i];
                    st[i] = NULL; 
                }
                if (st[i] == NULL) continue;
            }
            if (!found) cout << "Wrong id\n";
            else cout << "student's records has been deleted successfully!!!\n";
            pressanykey();
            system("cls");
            break;
        case 0:
            system("cls");
            goodbye();
            break;
        default:
            system("cls");
            cout << "Wrong Choice\n";
            pressanykey();
            system("cls");
            break;
        }
    } while (choice != 0);
}

void welcome()
{
    // sources : photo of welcome word && the website manytools.org -> asciiart
    cout << "\n\n                @@@@,      @@@@@(      &@@@*                 .@@@&                                                                               \n";
    Sleep(300);
    cout << "                *@@@&     #@@@@@@.    ,@@@@                  .@@@&                                                                               \n";
    Sleep(300);
    cout << "                 @@@@,   ,@@@/@@@&    @@@@     .&@@@@@/      .@@@&      .%@@@@@&,        .%@@@@@%.      (@@@  #@@@@#   /@@@@&.       ,&@@@@@*    \n";
    Sleep(300);
    cout << "                  @@@@   @@@& *@@@*  /@@@(   #@@@@/*#@@@@.   .@@@&    %@@@@(*/@@@@#    @@@@@(*(@@@@@    (@@@@@#*/@@@@@@&//@@@@@    &@@@@/*%@@@@  \n";
    Sleep(300);
    cout << "                  #@@@/ #@@@   &@@@  @@@@   %@@@.     %@@@   .@@@&   %@@@*      .     @@@@       @@@@   (@@@%    .@@@@     &@@@.  &@@@.     &@@@ \n";
    Sleep(300);
    cout << "                   @@@@,@@@/    @@@#(@@@,   @@@@@@@@@@@@@@,  .@@@&   @@@@            *@@@#       %@@@*  (@@@/    .@@@&     &@@@.  @@@@@@@@@@@@@@.\n";
    Sleep(300);
    cout << "                   *@@@@@@&     *@@@@@@%    %@@@.            .@@@&   #@@@/     ,%(*.  @@@@       @@@@   (@@@/    .@@@&     &@@@.  &@@@.          \n";
    Sleep(300);
    cout << "                    &@@@@@       &@@@@@.     %@@@@#(#@@@@/   .@@@&    #@@@@#((@@@@%    @@@@@#(#@@@@&    (@@@/    .@@@&     &@@@.   @@@@@#(%@@@@. \n";
    Sleep(300);
    cout << "                    .@@@@/        @@@@(        .%@@@@@#      .@@@&      .%@@@@@%.        .#@@@@@#.      (@@@/    .@@@&     &@@@.     ,&@@@@@(    \n\n\n";
}

void menu(int menum)
{
    switch (menum)
    {
    case 1:
        cout << printNmid("1-Add New Students' Records");
        Sleep(300);
        cout << printNmid("2-View All Students' Records");
        Sleep(300);
        cout << printNmid("3-Search For A Student's Records");
        Sleep(300);
        cout << printNmid("4-Modify A Student's Records");
        Sleep(300);
        cout << printNmid("5-Delete A Student's Records");
        Sleep(300);
        cout << printNmid("0-Exit");
        // welcome & main menu
        break;
    case 2:
        cout << printNmid("-",'-');
        cout << printNmid(" ") << printNmid("add new student") << printNmid(" ");
        cout << printNmid("-", '-');
        break;
    case 3:
        cout << printNmid("-", '-');
        cout << printNmid(" ") << printNmid("view students' records") << printNmid(" ");
        cout << printNmid("-", '-');
        break;
    case 4:
        cout << printNmid("-", '-');
        cout << printNmid(" ") << printNmid("search for student") << printNmid(" ");
        cout << printNmid("-", '-');
        break;
    case 5:
        cout << printNmid("-", '-');
        cout << printNmid(" ") << printNmid("modify student record") << printNmid(" ");
        cout << printNmid("-", '-');
        break;
    case 6:
        cout << printNmid("-", '-');
        cout << printNmid(" ") << printNmid("delete student record") << printNmid(" ");
        cout << printNmid("-", '-');
        break;
    default:
        cout << "there is no menu for " << menum << "\n";
        break;
    }
}
string printNmid(string s, char feg)
{
    int width = line_spaces - 2;
    int len = s.length();
    if (width < len)
        return s;
    int deff = width - len;
    int pad1 = deff / 2;
    int pad2 = deff - pad1;
    return "+" + string(pad1, feg) + s + string(pad2, feg) + "+";
}
string printNmid(string s)
{
    int width = line_spaces - 4;
    int len = s.length();
    if (width < len)
        return s;
    int deff = width - len;
    int pad1 = deff / 2;
    int pad2 = deff - pad1;
    return "||" + string(pad1, ' ') + s + string(pad2, ' ') + "||";
}

string printNmid(int width, string s)
{
    int len = s.length();
    if (width < len)
        return s;
    int deff = width - len;
    int pad1 = deff / 2;
    int pad2 = deff - pad1;
    return string(pad1, ' ') + s + string(pad2, ' ');
}
void pressanykey()
{
    cout << "Press any key and ENTER to continue... ";
    string anykey;
    cin >> anykey;
}
void goodbye()
{
    cout << "\n\n           (@@@@@@@@@@@@@@@@@@@@@&.  #@@@@(                                                                 %@@@@/                                             ";
    Sleep(300);
    cout << "           (@@@@@@@@@@@@@@@@@@@@@&.  #@@@@(                                                                 %@@@@/                                             ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@(                                                                 %@@@@/                                             ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@( .#@@@@@@#.          (@@@@@@@@@%.       .%@@@#  ,%@@@@@&/        %@@@@/     ,&@@@@&,     *&@@@@@@@@&*               ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@@@@@@@@@@@@@&.     ,@@@@@@@@@@@@@@@*     .&@@@%%@@@@@@@@@@@#      %@@@@/   *@@@@@&,    .&@@@@@@@@@@@@@@%.            ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@@(     .%@@@@#    ,&@@@&.     /@@@@%     .&@@@@@*     /@@@@@*     %@@@@/ /@@@@@#.      #@@@@,      *&#(*,            ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@#       /@@@@%.             .*%@@@@&     .&@@@@/       %@@@@(     %@@@@@@@@@@(         /@@@@@@@&(,.                  ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@(       /@@@@%.     *%@@@@@@@@@@@@@&     .&@@@@,       #@@@@(     %@@@@@@@@@@@%.        .%@@@@@@@@@@@@@(             ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@(       /@@@@%.   *@@@@@@(.   ,@@@@%     .&@@@@,       #@@@@(     %@@@@@% *@@@@@,             ,(@@@@@@@@@*           ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@(       /@@@@%.   %@@@@*      (@@@@%     .&@@@@,       #@@@@(     %@@@@/   .%@@@@#    ./(#%&.       #@@@@(           ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@(       /@@@@%.   (@@@@@@&&&@@@@@@@&.    .&@@@@,       #@@@@(     %@@@@/     (@@@@&.   /@@@@@@&&&&&@@@@@#            ";
    Sleep(300);
    cout << "                   .@@@@@(           #@@@@(       /@@@@%.    .&@@@@@@@&/ /@@@@%    .&@@@@,       #@@@@(     %@@@@/      ,@@@@@/    ,%@@@@@@@@@@@(              \n\n";
    Sleep(1000);
}
string wordtolower(string &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        s[i] == tolower(s[i]);
    }
    return s;
}
bool isGender(string &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        s[i] = tolower(s[i]);
    }
    return s != "male" && s != "female";
}