#pragma once
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include "vattu.h"
using namespace std;
void tao_button(int x1, int y1, int x2, int y2, string s, int text_color, int box_color);
bool check_dung_nhap = false;
void arrow_right(int x, int y, int color)
{
	int points[8] = { x, y, x + 30, y + 15, x, y + 30, x, y };
	drawpoly(4, points);
	setfillstyle(SOLID_FILL, color);
	fillpoly(4, points);
}
void arrow_left(int x, int y, int color)
{
	int points[8] = { x, y, x - 30, y + 15, x, y + 30, x, y };
	drawpoly(4, points);
	setfillstyle(SOLID_FILL, color);
	fillpoly(4, points);
}
void HienThiConTro(string s, int x1, int y1, int x2, int y2) {
	s[s.size() - 1] = '|';
	delay(50);
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
	s[s.size() - 1] = ' ';
	delay(50);
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
}
void lay_them_kitu(int x1, int y1, int x2, int y2, string& s, char c)
{
	char tmp = s[s.size() - 1];
	s[s.size() - 1] = c;
	s.push_back(tmp);
	setfillstyle(SOLID_FILL, 6);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
}
void xoa_1_kitu(int x1, int y1, int x2, int y2, string& s)
{
	if (s.size() == 1) return;
	setfillstyle(SOLID_FILL, 6);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	char tmp = s[s.size() - 1];
	s.pop_back();
	s[s.size() - 1] = tmp;
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
}
void Nhap_string(int x1, int y1, int x2, int y2, string& tenvt)
{
	setfillstyle(SOLID_FILL, 6);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	setcolor(WHITE);
	tenvt += '|';
	outtextxy(x1 + 10, y1 + 10, (char*)tenvt.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		setcolor(WHITE);
		outtextxy(x1 + 10, y1 + 10, (char*)tenvt.c_str());
		if (GetAsyncKeyState(VK_DELETE))
		{
			check_dung_nhap = true;
			break;
		}
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || (int)c == 32)
			{
				lay_them_kitu(x1, y1, x2, y2, tenvt, c);
			}
			else if (c == 8) // backspace
			{
				xoa_1_kitu(x1, y1, x2, y2, tenvt);
			}
			//else if ((int)c == 127) //delete: huy bo lenh nhap
			//{
			//	break;
			//}
			else if (c == 13) // enter
			{
				tenvt.pop_back();
				tao_button(x1, y1, x2, y2, "", 0, 6);
				outtextxy(x1 + 10, y1 + 10, (char*)tenvt.c_str());
				break;
			}
		}
		else HienThiConTro(tenvt, x1, y1, x2, y2);
	}
}
void Nhap_number(int x1, int y1, int x2, int y2, float& number, string& s_tmp)
{
	setfillstyle(SOLID_FILL, 6);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	setcolor(WHITE);
	string s = "";
	s = s_tmp + '|';
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		setcolor(WHITE);
		outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
		if (GetAsyncKeyState(VK_DELETE))
		{
			check_dung_nhap = true;
			break;
		}
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c >= '0' && c <= '9' || (int)c == 32)
			{
				lay_them_kitu(x1, y1, x2, y2, s, c);
			}
			else if (c == 8) // backspace
			{
				xoa_1_kitu(x1, y1, x2, y2, s);
			}
			//else if ((int)c == 127) //delete: huy bo lenh nhap
			//{
			//	break;
			//}
			else if (c == 13) // enter
			{
				s.pop_back();
				tao_button(x1, y1, x2, y2, "", 0, 6);
				outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
				if (s.size() == 0) return;
				s_tmp = s;
				if (chi_nhap_so(s) == false) return;
				float tmp1 = 0, tmp2 = 0;
				string s1 = "", s2 = "";
				bool check_float = false;
				for (int i = 0; i < s.size(); i++)
				{
					if (s[i] == '.')
					{
						check_float = true;
						int tmp = 1;
						s2 = s.substr(i + 1, s.size() - (i + 1));
						s1 = s.substr(0, i);
						for (int k = 1; k <= (s.size() - (i + 1)); k++) tmp *= 10;
						tmp1 = stof(s1); tmp2 = stof(s2) / tmp;
						break;
					}
				}
				if (check_float == false) number = stof(s);
				else number = tmp1 + tmp2;
				break;
			}
		}
		else HienThiConTro(s, x1, y1, x2, y2);
	}
}
// tao o chu "YEU CAU NHAP LAI"
void yeu_cau_nhap_lai(int x1, int y1, int x2, int y2, int text_color, int box_color, int mau_nen_nhap)
//mau_nen_nhap la de resert lai mau cho o nhap, vi tao_button su dung setbk no tao mau khac.
{
	tao_button(x1, y1 - 45, x2, y1 - 20, "YEU CAU NHAP LAI", WHITE, box_color);
	setbkcolor(mau_nen_nhap);
}
// xoa o chu "YEU CAU NHAP LAI"
void xoa_yeu_cau_nhap_lai(int x1, int y1, int x2, int y2, int text_color, int box_color, int mau_nen_nhap)
{
	tao_button(x1, y1 - 45, x2, y1 - 20, "", BLACK, box_color);
	setbkcolor(mau_nen_nhap);
}
void tao_button(int x1, int y1, int x2, int y2, string s, int text_color, int box_color)
{
	int tmp = (x2 - x1 - s.size()) / 2;
	setfillstyle(SOLID_FILL, box_color);
	bar(x1, y1, x2, y2);
	setcolor(text_color);
	setbkcolor(box_color);
	outtextxy(x1 + tmp-25, y1 + (y2 - y1) / 2 - 8, (char*)s.c_str());
}
void in_number(int x, int y, float n)
{
	int t = n;
	char tmp[100];
	if (n - t == 0)
	{
		snprintf(tmp, 100, "%.*f", 0, n);
	}
	else
	{
		snprintf(tmp, 100, "%.*f", 3, n);
	}
	outtextxy(x, y, tmp);
}
void Nhap_number_float(int x1, int y1, int x2, int y2, float& number)
{
	//setfillstyle(SOLID_FILL, 6);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	//setcolor(WHITE);
	string s = "|";
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		//Kiem tra trung mavt
		//setcolor(WHITE);
		outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c >= '0' && c <= '9' || (int)c == 32)
			{
				lay_them_kitu(x1, y1, x2, y2, s, c);
			}
			else if (c == 8) // backspace
			{
				xoa_1_kitu(x1, y1, x2, y2, s);
			}
			else if (c == 13) // enter
			{
				s.pop_back();
				tao_button(x1, y1, x2, y2, "", 0, 6);
				outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
				if (s.size() == 0) return;
				if (chi_nhap_so(s) == false) return;
				float tmp1 = 0, tmp2 = 0;
				string s1 = "", s2 = "";
				bool check_float = false;
				for (int i = 0; i < s.size(); i++)
				{
					if (s[i] == '.')
					{
						//64.6547
						check_float = true;
						int tmp = 1;
						s2 = s.substr(i + 1, s.size() - (i + 1));
						s1 = s.substr(0, i);
						for (int k = 1; k <= (s.size() - (i + 1)); k++) tmp *= 10;
						tmp1 = stof(s1); tmp2 = stof(s2) / tmp;
						break;
					}
				}
				if (check_float == false) number = stof(s);
				else number = tmp1 + tmp2;
				break;
			}
		}
		else HienThiConTro(s, x1, y1, x2, y2);
	}
}

void Nhap_number_int(int x1, int y1, int x2, int y2, int& number)
{
	setfillstyle(SOLID_FILL, 6);
	setbkcolor(6);
	setcolor(15);
	//setfillstyle(SOLID_FILL, 6);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	//setcolor(WHITE);
	string s = "|";
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		//Kiem tra trung mavt
		//setcolor(WHITE);
		outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c >= '0' && c <= '9' || (int)c == 32)
			{
				lay_them_kitu(x1, y1, x2, y2, s, c);
			}
			else if (c == 8) // backspace
			{
				xoa_1_kitu(x1, y1, x2, y2, s);
			}
			else if (c == 13) // enter
			{
				s.pop_back();
				tao_button(x1, y1, x2, y2, "", 0, 6);
				outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
				if (s.size() == 0) return;
				if (chi_nhap_so(s) == false) return;
				float tmp1 = 0, tmp2 = 0;
				string s1 = "", s2 = "";
				bool check_float = false;
				for (int i = 0; i < s.size(); i++)
				{
					if (s[i] == '.')
					{
						//64.6547
						check_float = true;
						int tmp = 1;
						s2 = s.substr(i + 1, s.size() - (i + 1));
						s1 = s.substr(0, i);
						for (int k = 1; k <= (s.size() - (i + 1)); k++) tmp *= 10;
						tmp1 = stoi(s1); tmp2 = stoi(s2) / (float)tmp;
						break;
					}
				}
				if (check_float == false) number = stoi(s);
				else number = tmp1 + tmp2;
				break;
			}
		}
		else HienThiConTro(s, x1, y1, x2, y2);
	}
}
