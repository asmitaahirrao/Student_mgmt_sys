#include<iostream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<conio.h>
class student
{
	int rollno;
	char name[20];
	char gender;
	int age;
	int std;
	float marks;
public:
	int getrollno()
	{
		return rollno;
	}
	void getdata()
	{
		cout << "Enter student details" << endl;
		cout << "Roll no.: ";
		cin >> rollno;
		cout << "Name: ";
		cin >> name;
		cout << "Gender: ";
		cin >> gender;
		cout << "Age: ";
		cin >> age;
		cout << "Standard: ";
		cin >> std;
	}
	void showdata()
	{
		cout << "Student Details" << endl;
		cout << "Roll no: " << rollno << endl;
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Age: " << age << endl;
		cout << "Standard: " << std << endl;
	}
	void listdata()
	{
		cout.setf(ios::left);
		cout << setw(10) << rollno;
		cout << setw(10) << name;
		cout << setw(10) << gender;
		cout << setw(10) << age;
		cout << setw(20) << std;
		cout << endl;
	}
	void modifydata()
	{
		cout << "Roll no: " << rollno << endl;
		cout << "Enter student details\n";
		cout << "Name: ";
		cin >> name;
		cout << "Gender: ";
		cin >> gender;
		cout << "Age: ";
		cin >> age;
		cout << "Standard: ";
		cin >> std;
	}
};
void menu()
{
	cout << "STUDENT RECORDS\n";
	cout << "=======================\n";
	cout << "0. Exit\n";
	cout << "1. Register New Student\n";
	cout << "2. Show All Students\n";
	cout << "3. Search Student\n";
	cout << "4. Modify record\n";
	cout << "5. Delete record\n";
	cout << "Enter your choice: ";
}
void heading()
{
	cout.setf(ios::left);
	cout << setw(10) << "Roll no";
	cout << setw(10) << "Name";
	cout << setw(10) << "Gender";
	cout << setw(10) << "Age";
	cout << setw(20) << "Standard";
	cout << endl;
}
int main()
{
	clrscr();
	int n = 0, ch, rn, i, flag = 0, pos;
	student s[10];
	do
	{
		system("cls");
		menu();
		cin >> ch;
		switch (ch)
		{
		case 1: s[n].getdata(); n++;
			cout << "\nRecord saved successfully....\n";
			break;
		case 2:
			if (n > 0)
			{
				heading();
				for (i = 0; i < n; i++)
				{
					s[i].listdata();
				}
			}
			else
			{
				cout << "\nNothing to display....\n";
			}
			break;
		case 3:
			if (n > 0)
			{
				cout << "Enter roll no to display: ";
				cin >> rn;
				for (i = 0; i < n; i++)
				{
					if (rn == s[i].getrollno())
					{
						s[i].showdata();
						flag++;
					}
				}
			}
			else
			{
				cout << "\nNothing to display....\n";
			}
			if (flag == 0)
			{
				cout << "\nNo such roll no found....\n";
			}
			break;
		case 4:
			if (n > 0)
			{
				int pos;
				cout << "Enter roll no to modify: ";
				cin >> rn;
				for (i = 0; i < n; i++)
				{
					if (rn == s[i].getrollno())
					{
						cout << "Following record will be modified....\n";
						s[i].showdata();
						cout << "\nEnter new data\n";
						s[i].modifydata();
						flag++;
					}
				}
			}
			else
			{
				cout << "\nNothing to display....\n";
			}
			if (flag == 0)
			{
				cout << "\nNo such roll no found....\n";
			}
			break;
		case 5:
			if (n > 0)
			{
				cout << "Enter roll no to delete: ";
				cin >> rn;
				for (i = 0; i < n; i++)
				{
					if (rn == s[i].getrollno())
					{
						cout << "Following record is deleted....\n";
						s[i].showdata();
						flag++;
						pos = i;
						break;
					}
				}
				for (i = pos; i < n - 1; i++)
				{
					s[i] = s[i + 1];
				}
				n--;
			}
			else
			{
				cout << "\nNothing to display....\n";
			}
			if (flag == 0)
			{
				cout << "\nNo such roll no found....\n";
			}
			break;
		}
		system("pause");
	} while (ch);
	menu();
	s[0].listdata();
	getch();
	return 0;
}