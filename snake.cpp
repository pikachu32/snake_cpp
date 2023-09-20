#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <cstdlib>
using namespace std;
int bost = 4;
struct poz {
	int x, y;
}v[100];

void afisare(char h[][100])
{
	for (int i = 1; i <= 20; i++)

		cout << h[i] << endl;

}


int veri(char h[][100])
{
	int s = 0;
	for (int i = 2; i <= 19; i++)
		if (h[i][0] != 'x')
			s++;
	for (int i = 2; i <= 19; i++)
		if (h[i][29] != 'x')
			s++;
	if (s != 0)
		return s;
	else
	{
		if (strcmp(h[1], h[20]) != 0)
			s++;
	}
	return s;
}

void stanga(char  h[][100], poz v[], int& l)
{
	int i;
	if (h[v[1].x][v[1].y - 1] == '@')
		l++;
	if (h[v[1].x][v[1].y - 1] == 'B')
		bost++;
	for (i = l; i >= 2; i--)
	{
		v[i].x = v[i - 1].x;
		v[i].y = v[i - 1].y;
		h[v[i].x][v[i].y] = 'o';
	}
	h[v[l].x][v[l].y] = ' ';
	v[1].y = v[1].y - 1;
	h[v[1].x][v[1].y] = 'D';
}

void dreapta(char  h[][100], poz v[], int& l)
{
	int i;
	if (h[v[1].x][v[1].y + 1] == '@')
		l++;
	if (h[v[1].x][v[1].y + 1] == 'B')
		bost++;
	for (i = l; i >= 2; i--)
	{
		v[i].x = v[i - 1].x;
		v[i].y = v[i - 1].y;
		h[v[i].x][v[i].y] = 'o';
	}
	h[v[l].x][v[l].y] = ' ';
	v[1].y = v[1].y + 1;
	h[v[1].x][v[1].y] = 'D';
}

void sus(char h[][100], poz v[], int& l)
{
	int i;
	if (h[v[1].x - 1][v[1].y] == '@')
		l++;
	if (h[v[1].x - 1][v[1].y] == 'B')
		bost++;
	for (i = l; i >= 2; i--)
	{
		v[i].x = v[i - 1].x;
		v[i].y = v[i - 1].y;
		h[v[i].x][v[i].y] = 'o';
	}
	h[v[l].x][v[l].y] = ' ';
	v[1].x = v[1].x - 1;
	h[v[1].x][v[1].y] = 'D';
}

void jos(char h[][100], poz v[], int& l)
{
	int i;
	if (h[v[1].x + 1][v[1].y] == '@')
		l++;
	if (h[v[1].x + 1][v[1].y] == 'B')
		bost++;
	for (i = l; i >= 2; i--)
	{
		v[i].x = v[i - 1].x;
		v[i].y = v[i - 1].y;
		h[v[i].x][v[i].y] = 'o';
	}
	h[v[l].x][v[l].y] = ' ';
	v[1].x = v[1].x + 1;
	h[v[1].x][v[1].y] = 'D';
}

int veri2(int l, poz v[])
{
	for (int i = 2; i <= l; i++)
	{
		if (v[1].x == v[i].x && v[1].y == v[i].y)
			return 1;
	}
	return 0;
}

int main()
{
again:
	char h[100][100];
	poz v[100];
	int l = 2;
	v[1].x = 18;
	v[1].y = 10;

	strcpy_s(h[1], "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	for (int o = 2; o <= 19; o++)
		strcpy_s(h[o], "x                            x");
	strcpy_s(h[20], h[1]);
	h[v[1].x][v[1].y] = 'D';


	afisare(h);
	char ch, ch1;

	int a = 500;
	bost = 4;
	ch1 = 'a';
	int n = 5, m = 5;
	h[n][m] = '@';

	system("color 22");
	while (veri(h) == 0 && veri2(l, v) == 0)
	{

		if (h[n][m] != '@')
		{
		fruct:
			n = rand() % 19 + 1;
			m = rand() % 30 + 1;
			if (h[n][m] == ' ')
				h[n][m] = '@';
			else
				goto fruct;
			int x;
			x = rand() % 10 + 1;
			if (x == 5)
			{
				n = rand() % 19 + 1;
				m = rand() % 30 + 1;
				if (h[n][m] == ' ')
					h[n][m] = 'B';
			}
		}

		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'r')
				if (bost != 0 && ch == 'r')
					bost--;
				else
				{
					if (ch1 == 'a')
						ch = 'a';
					if (ch1 == 'd')
						ch = 'd';
					if (ch1 == 's')
						ch = 's';
					if (ch1 == 'w')
						ch = 'w';
				}
			if (ch == 'a')
				stanga(h, v, l);
			if (ch == 'w')
				sus(h, v, l);
			if (ch == 's')
				jos(h, v, l);
			if (ch == 'd')
				dreapta(h, v, l);

			ch1 = ch;
		}
		else
		{
			if (ch1 == 'a')
				stanga(h, v, l);
			if (ch1 == 'w')
				sus(h, v, l);
			if (ch1 == 'd')
				dreapta(h, v, l);
			if (ch1 == 's')
				jos(h, v, l);
		}
		system("color 47");
		system("cls");
		cout << "SCORE:" << l << endl;
		cout << "BOST:" << bost << endl;
		afisare(h);

		if (l < 5)
			a = 300;
		if (l < 10 && l>5)
			a = 250;
		if (l < 15 && l>10)
			a = 150;
		if (l < 20 && l>15)
			a = 100;
		if (l > 25)
			a = 50;
		Sleep(a);
	}
	cout << "game over!" << endl;
	cout << "Try again? " << endl;
	cout << "Type 1";
	char q;
	q = _getch();
	if (q == '1')
		goto again;
	return 0;
}
