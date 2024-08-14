#pragma once
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include "vattu.h"
#include "dohoa_hoadon.h"
#include "dohoa_doanhthu.h"
#include "dohoa_vattu.h"
#include "dohoa_nhanvien.h"

using namespace std;
int check_type;
/*
	1: Ten
	2: So luong
*/
int pos_trang = 1;
int main()
{
	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);
	initwindow(width, height, "do an vat tu");
	int arrow_color = 14;
	int box_color = 11;
	int text_color = 14;
	sc_main_vt(text_color, box_color);
	DS_VATTU dsvt;
	list_nv Listnv;
	Read_info(dsvt);
	doc_file_nv(Listnv);
	POINT mouse;
	while (1)
	{
		GetCursorPos(&mouse);
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 100 && mouse.x <= 350 && mouse.y >= 70 && mouse.y <= 130)
		{
			khoi_dong_vattu(dsvt, mouse, text_color, box_color, pos_trang, check_type);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 351 && mouse.x <= 600 && mouse.y >= 70 && mouse.y <= 130)
		{
			khoi_dong_nhanvien(Listnv, mouse, text_color, box_color, pos_trang);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 601 && mouse.x <= 850 && mouse.y >= 70 && mouse.y <= 130)
		{
			tao_button(601, 50, 850, 100, "HOA DON", 0, 6);
			main_hoadon(dsvt, Listnv);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 851 && mouse.x <= 1100 && mouse.y >= 70 && mouse.y <= 130)
		{
			khoi_dong_tk(Listnv, text_color, box_color, mouse);
			//thong_ke_hoadon(Listnv);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1101 && mouse.x <= 1150 && mouse.y >= 70 && mouse.y <= 125)
		{
			Write_info(dsvt.root, dsvt.sl);
			ghi_file_nv(Listnv);
			giai_phong_nv(Listnv);
			free_mem(dsvt.root);
			cout << mahdcu;
			break;
		}
		delay(50);
	}
	closegraph();
	//getch();
	return 0;
}
