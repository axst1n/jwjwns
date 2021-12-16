#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;

int entered,choice;
const int AmountOfBooks=5;
struct Location
{
	int row,floor,shelf;
};
struct Book
{
	string name,author,genre,language,article;
	int yearofrelease,numberofpages;
	char availability;
	Location location;
};
Book books[AmountOfBooks]={};
void Input()
{
	int want;
	cout<<"������� ����� ������� ���� (������)?\n";
	cin>>want;
	cin.ignore(32767,'\n');
	if(want>5||want<=0)
	{
		system("cls");
		cout<<"�������� ���-��!\n";
	}
	else if(entered==5)
	{
		system("cls");
		cout<<"�� ��� �������� 5 ����!\n";
	}
	else if(entered>0&&want+entered>5)
	{
		system("cls");
		cout<<"�� ��� �������� "<<entered<<" �����, ��� ����� �������� "<<5-entered<<" �����.\n";
	}
	else
	{
		system("cls");
		for(int i=0;i<want;i++)
		{
			if(entered>0) cout<<"���� ��������� "<<entered<<" ����.\n\n";
			int bufnum;
			string bufstr;
			nazvanie:
			cout<<"��������:\n";
			cin>>bufstr;
			if(bufstr.length()<3)
			{
				cout<<"�������� ����� ��������!\n\n";
				goto nazvanie;
			}
			else books[i].name=bufstr;
			system("cls");
			imya:
			cout<<"�����: \n";
			cin>>bufstr;
			if(bufstr.length()<3)
			{
				cout<<"�������� ����� ����� ������!\n\n";
				goto imya;
			}
			else books[i].author=bufstr;
			system("cls");
			god:
			cout<<"��� �������:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum>2021||bufnum<-3350)
			{
				cout<<"�������� ��� �������!\n\n";
				goto god;
			}
			else books[i].yearofrelease=bufnum;
			system("cls");
			zhanr:
			cout<<"�������� ���� �� ������������ ���� ������\n1. �����\n2. �����\n3. �����\n4. ������\n5. ����\n6. ��������\n7. �������\n8. ������\n9. �������\n10. ����������\n\n����:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum>10||bufnum<1)
			{
				cout<<"�������� ����!\n\n";
				goto zhanr;
			}
			else
			{
				switch(bufnum)
				{
					case 1:
					{
						books[i].genre="�����";
						break;
					}
					case 2:
					{
						books[i].genre="�����";
						break;
					}
					case 3:
					{
						books[i].genre="�����";
						break;
					}
					case 4:
					{
						books[i].genre="������";
						break;
					}
					case 5:
					{
						books[i].genre="����";
						break;
					}
					case 6:
					{
						books[i].genre="��������";
						break;
					}
					case 7:
					{
						books[i].genre="�������";
						break;
					}
					case 8:
					{
						books[i].genre="������";
						break;
					}
					case 9:
					{
						books[i].genre="�������";
						break;
					}
					case 10:
					{
						books[i].genre="����������";
						break;
					}
				}
			}
			system("cls");
			yazik:
			cout<<"�������� ���� �� ������������ ���� ������\n1. ����������\n2. �������\n3. ����������\n4. ��������\n\n����:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum>4||bufnum<1)
			{
				cout<<"�������� ����!\n\n";
				goto yazik;
			}
			else
			{
				switch(bufnum)
				{
					case 1:
					{
						books[i].language="����������";
						break;
					}
					case 2:
					{
						books[i].language="�������";
						break;
					}
					case 3:
					{
						books[i].language="����������";
						break;
					}
					case 4:
					{
						books[i].language="��������";
						break;
					}
				}
			}
			system("cls");
			artikul:
			cout<<"�������:\n";
			cin>>bufstr;
			if(bufstr.length()<3)
			{
				cout<<"�������� �������� ��������!\n\n";
				goto artikul;
			}
			else books[i].article=bufstr;
			system("cls");
			stranic:
			cout<<"���������� �������:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<6||bufnum>9999)
			{
				cout<<"�������� ���-�� �������!\n\n";
				goto stranic;
			}
			else books[i].numberofpages=bufnum;
			system("cls");
			ryad:
			cout<<"���������������:\n\n���:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<1||bufnum>9)
			{
				cout<<"�������� ���!\n\n";
				goto ryad;
			}
			else books[i].location.row=bufnum;
			system("cls");
			etazh:
			cout<<"����:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<1||bufnum>9)
			{
				cout<<"�������� ����!\n\n";
				goto etazh;
			}
			else books[i].location.floor=bufnum;
			system("cls");
			polka:
			cout<<"�����:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<1||bufnum>9)
			{
				cout<<"�������� �����!\n\n";
				goto polka;
			}
			else books[i].location.shelf=bufnum;
			system("cls");
			nalichie:
			char bufchar;
			cout<<"�������:\n";
			cin>>bufchar;
			cin.ignore(32767,'\n');
			if(bufchar!='+'&&bufchar!='-')
			{
				cout<<"�������� ��������!\n\n";
				goto nalichie;
			}
			else books[i].availability=bufchar;
			entered++;
			system("cls");
		}
	}
}
void rqout()
{
	system("cls");
	printf("|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|");
	printf("\n| � |      ��������      |     �����     |��������|   ����   |   ����   |�������|�������|�����|�������|\n");
	printf("|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|");
	if(entered==0) printf("\n|                                       �� ���� ��������� ����!                                       |");
}
void Output()
{
	rqout();
	if(entered>0) for(int i=0;i<entered;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
	printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
}
void RequestOutput()
{
	start:
	int vibor;
	system("cls");
	cout<<"�� ���� ����� ������?\n1. ��������\n2. �����\n3. ��� �������\n4. ����\n5. ����\n6. �������\n7. ���-�� �������\n8. �����\n9. �������\n��� �����: ";
	cin>>choice;
	cin.ignore(32767,'\n');
	if(choice>9||choice<1)
	{
		cout<<"�������� �����!\n\n";
		goto start;
	}
	else
	{
		system("cls");
		switch(choice)
		{
			case 1:
			{
				cout<<"�������� ��������:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].name<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].name==books[vibor].name;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 2:
			{
				cout<<"�������� ������:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].author<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].author==books[vibor].author;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 3:
			{
				cout<<"�������� ��� �������:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].yearofrelease<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].yearofrelease==books[vibor].yearofrelease;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 4:
			{
				cout<<"�������� ����:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].genre<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].genre==books[vibor].genre;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 5:
			{
				cout<<"�������� ����:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].language<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].language==books[vibor].language;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 6:
			{
				cout<<"�������� �������:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].article<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].article==books[vibor].article;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 7:
			{
				cout<<"�������� ���-�� �������:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].numberofpages<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].numberofpages==books[vibor].numberofpages;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 8:
			{
				stst:
				cout<<"���, ���� ��� �����?\n1. ���\n2. ����\n3. �����\n";
				cin>>choice;
				if(choice>3||choice<1)
				{
					cout<<"�������� �����!\n\n";
					goto stst;
				}
				else
				{
					system("cls");
					switch(choice)
					{
						case 1:
						{
							cout<<"�������� ���:\n";
							for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].location.row<<"\n";
							cin>>vibor;
							rqout();
							for(int i;books[i].location.row==books[vibor].location.row;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
							printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
							break;
						}
						case 2:
						{
							cout<<"�������� ����:\n";
							for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].location.floor<<"\n";
							cin>>vibor;
							rqout();
							for(int i;books[i].location.floor==books[vibor].location.floor;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
							printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
							break;
						}
						case 3:
						{
							cout<<"�������� �����:\n";
							for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].location.shelf<<"\n";
							cin>>vibor;
							rqout();
							for(int i;books[i].location.shelf==books[vibor].location.shelf;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
							printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
							break;
						}
					}
				}
				break;
			}
			case 9:
			{
				cout<<"�������� ���������:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].availability<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].availability==books[vibor].availability;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
		}
	}
}
int main()
{
	system("chcp 1251");
	system("cls");
	NewRequest:
	//cout<<"1. �������� �����\n2. ������� ����� �������\n3. ������� ������� �� �������\n4. ��������� ��������� � ����\n5. ��������� ��������� �� �����\n\n�������� ������ �����:\n";
	cout<<"1. �������� �����\n2. ������� ����� �������\n3. ������� ������� �� �������\n\n�������� ������ �����:\n";
	cin>>choice;
	cin.ignore(32767,'\n');
	system("cls");
	switch(choice)
	{
		case 1:
		{
			Input();
			goto NewRequest;
		}
		case 2:
		{
			Output:
			Output();
			cout<<"\n���� ��������:\n1. � ������� ����\n2. �����\n3. ������� ������� �� �������\n\n";
			cin>>choice;
			cin.ignore(32767,'\n');
			system("cls");
			switch(choice)
			{
				case 1: goto NewRequest;
				case 2: return 0;
				case 3: goto RequestOutput;
				default:
				{
					cout<<"������������ ����!\n\n";
					goto NewRequest;
				}
			}
		}
		case 3:
		{
			RequestOutput:
			RequestOutput();
			cout<<"\n���� ��������:\n1. � ������� ����\n2. �����\n3. ������� ����� �������\n\n";
			cin>>choice;
			cin.ignore(32767,'\n');
			system("cls");
			switch(choice)
			{
				case 1: goto NewRequest;
				case 2: return 0;
				case 3: goto Output;
				default:
				{
					cout<<"������������ ����!\n\n";
					goto NewRequest;
				}
			}
		}
		/*case 4:
		{
			ofstream f1("testtt.txt", ios::binary | ios::out);
	        f1.write((char*)&books, sizeof(books));
	    	f1.close();
	    	fwrite(&books, sizeof(books),1,"testtt.txt");
			goto NewRequest;
		}
		case 5:
		{
			ifstream f2("testtt.txt", ios::binary | ios::in);
	        f2.read((char*)&books, sizeof(books));
	    	f2.close();
			goto NewRequest;
		}*/
		default:
		{
			cout<<"������������ ����!\n";
			goto NewRequest;
		}
	}
}
