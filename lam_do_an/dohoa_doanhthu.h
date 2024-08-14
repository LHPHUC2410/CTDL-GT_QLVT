#pragma once
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <iostream>
#include <string>
#include "cac_dohoa.h"
#include "hoadon.h"
#include "dohoa_hoadon.h"
using namespace std;
void sc_resert_hienthi_dt()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(101, 241, 1139, 719);
	setcolor(8);
	rectangle(100, 200, 1140, 720);
	line(300, 200, 300, 720);
	for (int i = 240; i <= 720; i += 40)
	{
		line(100, i, 1140, i);
	}
	int j = 1;
	for (int i = 240; i <= 680; i += 40)
	{
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(105, i + 15, (char*)"THANG");
		string s_thang = to_string(j);
		outtextxy(160, i + 15, (char*)s_thang.c_str());
		j++;
	}
}

void sc_main_dt(int text_color, int box_color)
{
	tao_button(100, 50, 350, 100, "VAT TU", 0, box_color);
	tao_button(351, 50, 600, 100, "NHAN VIEN", 0, box_color);
	tao_button(601, 50, 850, 100, "HOA DON", 0, box_color);
	tao_button(851, 50, 1100, 100, "THONG KE", 0, box_color);
	setfillstyle(SOLID_FILL, RED);
	bar(1101, 50, 1150, 100);
	setcolor(WHITE);
	setbkcolor(RED);
	outtextxy(1120, 67, (char*)"X");
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(100, 165, (char*)"HAY CHON NAM: ");
	tao_button(250, 160, 340, 190, "", box_color, box_color);
	setfillstyle(SOLID_FILL, box_color);
	bar(400, 160, 900, 190);
	setcolor(0);
	outtextxy(560, 165, (char*)"BANG THONG KE DOANH THU NAM: ");
	tao_button(100, 200, 300, 240, "THANG", 0, box_color);
	tao_button(301, 200, 1140, 240, "THONG KE", 0, box_color);
	sc_resert_hienthi_dt();
}
void sc_main_tkhd(int text_color, int box_color)
{
	tao_button(100, 50, 350, 100, "VAT TU", 0, box_color);
	tao_button(351, 50, 600, 100, "NHAN VIEN", 0, box_color);
	tao_button(601, 50, 850, 100, "HOA DON", 0, box_color);
	tao_button(851, 50, 1100, 100, "THONG KE", 0, box_color);
	setfillstyle(SOLID_FILL, RED);
	bar(1101, 50, 1150, 100);
	setcolor(WHITE);
	setbkcolor(RED);
	outtextxy(1120, 67, (char*)"X");
}
void sc_luachon(int text_color, int box_color)
{
	tao_button(100, 50, 350, 100, "VAT TU", 0, box_color);
	tao_button(351, 50, 600, 100, "NHAN VIEN", 0, box_color);
	tao_button(601, 50, 850, 100, "HOA DON", 0, box_color);
	tao_button(851, 50, 1100, 100, "THONG KE", 0, box_color);
	setfillstyle(SOLID_FILL, RED);
	bar(670, 105, 700, 135);
	bar(1101, 50, 1150, 100);
	setcolor(WHITE);
	setbkcolor(RED);
	outtextxy(1120, 67, (char*)"X");
	outtextxy(675, 110, (char*)"OK");
	setfillstyle(SOLID_FILL, box_color);
	bar(150, 105, 341, 135);
	bar(375, 105, 660, 135);
	setcolor(BLACK);
	setbkcolor(box_color);
	outtextxy(165, 115, (char*)"THONG KE DOANH THU");
	outtextxy(400, 115, (char*)"THONG KE HOA DON THEO THOI GIAN");
}
void in_dt(list_nv Listnv, float** thong_ke, int nam)
{
	for (int i = 0; i < Listnv.sl; i++)
	{
		nodehd* list_hd = Listnv.dsnv[i]->dshd;
		while (list_hd != NULL)
		{
			if (list_hd->hoadon.loai == "X")
			{
				thong_ke[list_hd->hoadon.NgaylapHD.nam][list_hd->hoadon.NgaylapHD.thang] += tonggiatrihoadon(list_hd->hoadon.dscthd);
			}
			list_hd = list_hd->next;
		}
	}
	int j = 1;
	for (int i = 240; i <= 680; i += 40)
	{
		setcolor(WHITE);
		setbkcolor(BLACK);
		in_number(340, i+15, thong_ke[nam][j]);
		j++;
	}
	
}

void khoi_dong_tk(list_nv &Listnv, int text_color, int box_color, POINT mouse)
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 1536, 864);
	sc_luachon(text_color, box_color);
	tao_button(851, 50, 1100, 100, "THONG KE", 0, 6);
	int rows = 2024, cols = 13;
	float** thong_ke = new float*[rows];
	for (int i = 0; i < rows; i++)
	{
		thong_ke[i] = new float[cols];
		for (int j = 0; j < cols; j++) thong_ke[i][j] = 0;
	}
	bool check_tk = true;
	// true: Thong ke doanh thu
	// false: Thong ke hoa don theo khoang tg
		// NHAP LUA CHON
		while (1)
		{
			GetCursorPos(&mouse);

			if (GetAsyncKeyState(VK_LBUTTON) && ((mouse.x >= 100 && mouse.x <= 850) || (mouse.x >= 1101 && mouse.x <= 1140)) && mouse.y >= 70 && mouse.y <= 130)
			{
				sc_luachon(text_color, box_color);
				break;
			}
			if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 150 && mouse.x <= 341 && mouse.y >= 125 && mouse.y <= 165)
			{
				setfillstyle(SOLID_FILL, 6);
				bar(150, 105, 341, 135);
				setcolor(BLACK);
				setbkcolor(6);
				outtextxy(165, 115, (char*)"THONG KE DOANH THU");

				setfillstyle(SOLID_FILL, box_color);
				bar(375, 105, 660, 135);
				setcolor(BLACK);
				setbkcolor(box_color);
				outtextxy(400, 115, (char*)"THONG KE HOA DON THEO THOI GIAN");

				check_tk = true;
			}
			if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 375 && mouse.x <= 660 && mouse.y >= 125 && mouse.y <= 165)
			{
				setfillstyle(SOLID_FILL, 6);
				bar(375, 105, 660, 135);
				setcolor(BLACK);
				setbkcolor(6);
				outtextxy(400, 115, (char*)"THONG KE HOA DON THEO THOI GIAN");

				setfillstyle(SOLID_FILL, box_color);
				bar(150, 105, 341, 135);
				setcolor(BLACK);
				setbkcolor(box_color);
				outtextxy(165, 115, (char*)"THONG KE DOANH THU");

				check_tk = false;
			}
			if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 670 && mouse.x <= 700 && mouse.y >= 125 && mouse.y <= 165)
			{
				if (check_tk == true) {
					sc_main_dt(text_color, box_color);
					tao_button(851, 50, 1100, 100, "THONG KE", 0, 6);
				}
				else {
					sc_main_tkhd(text_color, box_color);
					tao_button(851, 50, 1100, 100, "THONG KE", 0, 6);
				}
				break;
			}
			delay(50);
		}
		// THONG KE DOANH THU
		while (check_tk == true)
		{
			GetCursorPos(&mouse);
			if (GetAsyncKeyState(VK_LBUTTON) && ((mouse.x >= 100 && mouse.x <= 850) || (mouse.x >= 1101 && mouse.x <= 1140)) && mouse.y >= 70 && mouse.y <= 130)
			{
				sc_luachon(text_color, box_color);
				break;
			}
			if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 250 && mouse.x <= 340 && mouse.y >= 180 && mouse.y <= 220)
			{
				int nam = 0;
				Nhap_number_int(250, 160, 340, 190, nam);
				while (nam > 2023)
				{
					yeu_cau_nhap_lai(910, 180, 1100, 230, WHITE, BLACK, 6);
					Nhap_number_int(250, 160, 340, 190, nam);
				}
				xoa_yeu_cau_nhap_lai(910, 180, 1100, 230, BLACK, BLACK, 6);
				setcolor(0);
				setbkcolor(box_color);
				in_number(800, 165, nam);
				sc_resert_hienthi_dt();
				in_dt(Listnv, thong_ke, nam);
			}
			delay(50);
		}
		// THONG KE HOA DON TRONG KHOANG THOI GIAN
		if (check_tk == false)
		{
			thong_ke_hoadon(Listnv);
		}
	for (int i = 0; i < rows; i++) {
		delete[] thong_ke[i];
	}
	delete[] thong_ke;
}