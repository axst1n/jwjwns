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
	cout<<"Сколько будем вносить книг (подряд)?\n";
	cin>>want;
	cin.ignore(32767,'\n');
	if(want>5||want<=0)
	{
		system("cls");
		cout<<"Неверное кол-во!\n";
	}
	else if(entered==5)
	{
		system("cls");
		cout<<"Вы уже добавили 5 книг!\n";
	}
	else if(entered>0&&want+entered>5)
	{
		system("cls");
		cout<<"Вы уже добавили "<<entered<<" книги, еще можно добавить "<<5-entered<<" книги.\n";
	}
	else
	{
		system("cls");
		for(int i=0;i<want;i++)
		{
			if(entered>0) cout<<"Было добавлено "<<entered<<" книг.\n\n";
			int bufnum;
			string bufstr;
			nazvanie:
			cout<<"Название:\n";
			cin>>bufstr;
			if(bufstr.length()<3)
			{
				cout<<"Неверная длина названия!\n\n";
				goto nazvanie;
			}
			else books[i].name=bufstr;
			system("cls");
			imya:
			cout<<"Автор: \n";
			cin>>bufstr;
			if(bufstr.length()<3)
			{
				cout<<"Неверная длина имени автора!\n\n";
				goto imya;
			}
			else books[i].author=bufstr;
			system("cls");
			god:
			cout<<"Год выпуска:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum>2021||bufnum<-3350)
			{
				cout<<"Неверный год выпуска!\n\n";
				goto god;
			}
			else books[i].yearofrelease=bufnum;
			system("cls");
			zhanr:
			cout<<"Выберите жанр из приведенного ниже списка\n1. Роман\n2. Драма\n3. Поэма\n4. Сказка\n5. Эпос\n6. Детектив\n7. Комедия\n8. Лирика\n9. Рассказ\n10. Справочник\n\nЖанр:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum>10||bufnum<1)
			{
				cout<<"Неверный жанр!\n\n";
				goto zhanr;
			}
			else
			{
				switch(bufnum)
				{
					case 1:
					{
						books[i].genre="Роман";
						break;
					}
					case 2:
					{
						books[i].genre="Драма";
						break;
					}
					case 3:
					{
						books[i].genre="Поэма";
						break;
					}
					case 4:
					{
						books[i].genre="Сказка";
						break;
					}
					case 5:
					{
						books[i].genre="Эпос";
						break;
					}
					case 6:
					{
						books[i].genre="Детектив";
						break;
					}
					case 7:
					{
						books[i].genre="Комедия";
						break;
					}
					case 8:
					{
						books[i].genre="Лирика";
						break;
					}
					case 9:
					{
						books[i].genre="Рассказ";
						break;
					}
					case 10:
					{
						books[i].genre="Справочник";
						break;
					}
				}
			}
			system("cls");
			yazik:
			cout<<"Выберите язык из привиденного ниже списка\n1. Украинский\n2. Русский\n3. Английский\n4. Немецкий\n\nЯзык:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum>4||bufnum<1)
			{
				cout<<"Неверный язык!\n\n";
				goto yazik;
			}
			else
			{
				switch(bufnum)
				{
					case 1:
					{
						books[i].language="Украинский";
						break;
					}
					case 2:
					{
						books[i].language="Русский";
						break;
					}
					case 3:
					{
						books[i].language="Английский";
						break;
					}
					case 4:
					{
						books[i].language="Немецкий";
						break;
					}
				}
			}
			system("cls");
			artikul:
			cout<<"Артикул:\n";
			cin>>bufstr;
			if(bufstr.length()<3)
			{
				cout<<"Неверная величина артикула!\n\n";
				goto artikul;
			}
			else books[i].article=bufstr;
			system("cls");
			stranic:
			cout<<"Количество страниц:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<6||bufnum>9999)
			{
				cout<<"Неверное кол-во страниц!\n\n";
				goto stranic;
			}
			else books[i].numberofpages=bufnum;
			system("cls");
			ryad:
			cout<<"Местонахождение:\n\nРяд:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<1||bufnum>9)
			{
				cout<<"Неверный ряд!\n\n";
				goto ryad;
			}
			else books[i].location.row=bufnum;
			system("cls");
			etazh:
			cout<<"Этаж:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<1||bufnum>9)
			{
				cout<<"Неверный этаж!\n\n";
				goto etazh;
			}
			else books[i].location.floor=bufnum;
			system("cls");
			polka:
			cout<<"Полка:\n";
			cin>>bufnum;
			cin.ignore(32767,'\n');
			if(bufnum<1||bufnum>9)
			{
				cout<<"Неверная полка!\n\n";
				goto polka;
			}
			else books[i].location.shelf=bufnum;
			system("cls");
			nalichie:
			char bufchar;
			cout<<"Наличие:\n";
			cin>>bufchar;
			cin.ignore(32767,'\n');
			if(bufchar!='+'&&bufchar!='-')
			{
				cout<<"Неверное значение!\n\n";
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
	printf("\n| № |      Название      |     Автор     |Выпущена|   Жанр   |   Язык   |Артикул|Страниц|Место|Наличие|\n");
	printf("|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|");
	if(entered==0) printf("\n|                                       Не было добавлено книг!                                       |");
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
	cout<<"По чему будем искать?\n1. Название\n2. Автор\n3. Год выпуска\n4. Жанр\n5. Язык\n6. Артикул\n7. Кол-во страниц\n8. Место\n9. Наличие\nВаш выбор: ";
	cin>>choice;
	cin.ignore(32767,'\n');
	if(choice>9||choice<1)
	{
		cout<<"Неверный выбор!\n\n";
		goto start;
	}
	else
	{
		system("cls");
		switch(choice)
		{
			case 1:
			{
				cout<<"Выберите название:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].name<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].name==books[vibor].name;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 2:
			{
				cout<<"Выберите автора:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].author<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].author==books[vibor].author;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 3:
			{
				cout<<"Выберите год выпуска:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].yearofrelease<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].yearofrelease==books[vibor].yearofrelease;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 4:
			{
				cout<<"Выберите жанр:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].genre<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].genre==books[vibor].genre;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 5:
			{
				cout<<"Выберите язык:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].language<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].language==books[vibor].language;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 6:
			{
				cout<<"Выберите артикул:\n";
				for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].article<<"\n";
				cin>>vibor;
				rqout();
				for(int i;books[i].article==books[vibor].article;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
				printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
				break;
			}
			case 7:
			{
				cout<<"Выберите кол-во страниц:\n";
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
				cout<<"Ряд, этаж или полка?\n1. Ряд\n2. Этаж\n3. Полка\n";
				cin>>choice;
				if(choice>3||choice<1)
				{
					cout<<"Неверный выбор!\n\n";
					goto stst;
				}
				else
				{
					system("cls");
					switch(choice)
					{
						case 1:
						{
							cout<<"Выберите ряд:\n";
							for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].location.row<<"\n";
							cin>>vibor;
							rqout();
							for(int i;books[i].location.row==books[vibor].location.row;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
							printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
							break;
						}
						case 2:
						{
							cout<<"Выберите этаж:\n";
							for(int i=0;i<entered;i++) cout<<i+1<<". "<<books[i].location.floor<<"\n";
							cin>>vibor;
							rqout();
							for(int i;books[i].location.floor==books[vibor].location.floor;i++) printf("\n| %-2d|%-20s|%-15s|  %-6d|%-10s|%-10s| %-6s|  %-5d|%d/%d/%d|   %-4c|",i+1,books[i].name.c_str(),books[i].author.c_str(),books[i].yearofrelease,books[i].genre.c_str(),books[i].language.c_str(),books[i].article.c_str(),books[i].numberofpages,books[i].location.row,books[i].location.floor,books[i].location.shelf,books[i].availability);
							printf("\n|---+--------------------+---------------+--------+----------+----------+-------+-------+-----+-------|\n");
							break;
						}
						case 3:
						{
							cout<<"Выберите полку:\n";
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
				cout<<"Выберите состояние:\n";
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
	//cout<<"1. Добавить книги\n2. Вывести общую таблицу\n3. Вывести таблицу по запросу\n4. Сохранить структуру в файл\n5. Загрузить структуру из файла\n\nВыберите нужный пункт:\n";
	cout<<"1. Добавить книги\n2. Вывести общую таблицу\n3. Вывести таблицу по запросу\n\nВыберите нужный пункт:\n";
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
			cout<<"\nВаше действие:\n1. В главное меню\n2. Выход\n3. Вывести таблицу по запросу\n\n";
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
					cout<<"Неправильный ввод!\n\n";
					goto NewRequest;
				}
			}
		}
		case 3:
		{
			RequestOutput:
			RequestOutput();
			cout<<"\nВаше действие:\n1. В главное меню\n2. Выход\n3. Вывести общую таблицу\n\n";
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
					cout<<"Неправильный ввод!\n\n";
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
			cout<<"Неправильный ввод!\n";
			goto NewRequest;
		}
	}
}
