#pragma once
#pragma comment(lib, "graphics.lib")
#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include "vattu.h"
#include "cac_dohoa.h"
#include "nhanvien.h"
using namespace std;
void sc_main_nv(int text_color, int box_color);
void sc_resert_hienthi_nv()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(101, 241, 899, 679);
	setcolor(8);
	rectangle(100, 200, 900, 680);
	line(300, 200, 300, 680);
	line(450, 200, 450, 680);
	line(700, 200, 700, 680);
	for (int i = 240; i <= 680; i += 40)
	{
		line(100, i, 900, i);
	}
}
void sc_hieu_chinh_nv()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(951, 201, 1299, 699);
	tao_button(950, 200, 1300, 230, "HIEU CHINH", BLACK, WHITE);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(980, 250, (char*)"HO");
	outtextxy(980, 370, (char*)"TEN");
	outtextxy(980, 490, (char*)"PHAI");
	tao_button(980, 270, 1250, 300, "", 0, 14);
	tao_button(980, 390, 1250, 420, "", 0, 14);
	tao_button(980, 510, 1114, 540, "NAM", 0, 14);
	tao_button(1115, 510, 1250, 540, "NU", 0, 14);
	setfillstyle(SOLID_FILL, 14);
	bar(1255, 510, 1280, 540);
	setcolor(0);
	outtextxy(1260, 515, (char*)"V");
	tao_button(1000, 669, 1055, 699, "HUY", BLACK, WHITE);
	tao_button(1190, 669, 1245, 699, "LUU", BLACK, WHITE);
}
void in_nhanvien_ten(int pos_trang, list_nv Listnv , int so_trang, int j)
{
	sc_resert_hienthi_nv();
	for (int i = 280; i <= 680; i += 40)
	{
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(105, i - 20, (char*)Listnv.dsnv[j]->MANV.c_str());
		outtextxy(310, i - 20, (char*)Listnv.dsnv[j]->HO.c_str());
		outtextxy(460, i - 20, (char*)Listnv.dsnv[j]->TEN.c_str());
		outtextxy(710, i - 20, (char*)Listnv.dsnv[j]->PHAI.c_str());
		j++;
		if (j == Listnv.sl || j == so_trang * 11) break;
	}
	arrow_left(470, 710, YELLOW);
	arrow_right(560, 710, YELLOW);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(490, 715, (char*)to_string(pos_trang).c_str());
	outtextxy(510, 715, (char*)"/");
	outtextxy(530, 715, (char*)to_string(so_trang).c_str());
}

void in_ds_ten_nv(list_nv Listnv, int& pos_trang, int text_color, int box_color)
{
	if (Listnv.sl == 0) return;
	pos_trang = 1;
	sc_main_nv(text_color, box_color);
	tao_button(351, 50, 600, 100, "NHAN VIEN", 0, 6);
	tao_button(250, 160, 340, 190, "TEN", 0, 6);
	//Sap xep
	sort_nv(Listnv);
	// In
	int j = 0;
	int so_trang = 0;
	if (Listnv.sl % 11 == 0 && Listnv.sl != 0) so_trang = Listnv.sl / 11;
	else so_trang = (Listnv.sl / 11) + 1;
	in_nhanvien_ten(pos_trang, Listnv, so_trang, j);
}

void sc_main_nv(int text_color, int box_color)
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
	//tao_button(1210, 50, 1280, 100, "XONG", WHITE, RED);
	tao_button(600, 120, 930, 149, "", WHITE, BLACK);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(100, 165, (char*)"SAP XEP THEO");
	outtextxy(950, 165, (char*)"HIEU CHINH (THEO MNV)");
	outtextxy(950, 125, (char*)"XOA (THEO MNV)");
	tao_button(1130, 160, 1300, 190, "", 0, box_color);
	tao_button(1130, 120, 1300, 149, "", 0, box_color);
	tao_button(250, 160, 340, 190, "TEN", 0, box_color);
	tao_button(100, 200, 300, 240, "MA NV", 0, box_color);
	tao_button(301, 200, 450, 240, "HO", 0, box_color);
	tao_button(451, 200, 700, 240, "TEN", 0, box_color);
	tao_button(701, 200, 900, 240, "PHAI", 0, box_color);
	sc_resert_hienthi_nv();
	setcolor(WHITE);
	rectangle(950, 200, 1300, 700);
	tao_button(950, 200, 1300, 230, "THEM NHAN VIEN", 0, WHITE);
	setfillstyle(SOLID_FILL, BLACK);
	bar(980, 240, 1150, 270);
	bar(980, 360, 1150, 390);
	bar(980, 480, 1150, 510);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(980, 250, (char*)"MA NHAN VIEN");
	outtextxy(980, 370, (char*)"HO");
	outtextxy(980, 490, (char*)"TEN");
	outtextxy(980, 610, (char*)"PHAI");
	tao_button(980, 270, 1250, 300, "", 0, 14);
	tao_button(980, 390, 1250, 420, "", 0, 14);
	tao_button(980, 510, 1250, 540, "", 0, 14);
	tao_button(980, 630, 1114, 660, "NAM", 0, 14);
	tao_button(1115, 630, 1250, 660, "NU", 0, 14);
	setfillstyle(SOLID_FILL, 14);
	bar(1255, 630, 1280, 660);
	setcolor(0);
	outtextxy(1260, 635, (char*)"V");
	tao_button(1000, 669, 1055, 699, "HUY", BLACK, WHITE);
	tao_button(1190, 669, 1245, 699, "LUU", BLACK, WHITE);
}

void khoi_dong_nhanvien(list_nv& Listnv, POINT mouse, int text_color, int box_color, int& pos_trang)
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 1536, 864);
	sc_main_nv(text_color, box_color);
	tao_button(351, 50, 600, 100, "NHAN VIEN", 0, 6);
	in_ds_ten_nv(Listnv, pos_trang, text_color, box_color);
	while (1)
	{
		GetCursorPos(&mouse);
		int so_trang = 0;
		if (Listnv.sl % 11 == 0 && Listnv.sl != 0) so_trang = Listnv.sl / 11;
		else so_trang = (Listnv.sl / 11) + 1;
		if (GetAsyncKeyState(VK_LBUTTON) && ((mouse.x >= 601 && mouse.x <= 1140) || (mouse.x >= 100 && mouse.x <= 350)) && mouse.y >= 70 && mouse.y <= 130)
		{
			sc_main_nv(text_color, box_color);
			break;
		}
		// THEM NHAN VIEN
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 950 && mouse.x <= 1300 && mouse.y >= 220 && mouse.y <= 260)
		{
			tao_button(950, 200, 1300, 230, "THEM NHAN VIEN", 0, 6);
			Nhanvien* nv = new Nhanvien;
			Listnv.dsnv[Listnv.sl] = new Nhanvien;
			nv->MANV = ma_nv();
			while (check_manv_trung(Listnv, nv->MANV) == true)
			{
				nv->MANV = ma_nv();
			}
			tao_button(980, 270, 1250, 300, nv->MANV, 0, 14);
			tao_button(980, 390, 1250, 420, "", 0, 14);
			tao_button(980, 510, 1250, 540, "", 0, 14);
			tao_button(980, 630, 1114, 660, "NAM", 0, 14);
			tao_button(1115, 630, 1250, 660, "NU", 0, 14);
			setbkcolor(6);
			Nhap_string(980, 390, 1250, 420, nv->HO);
			while (check_nhap_hoten_nv(nv->HO) == false)
			{
				yeu_cau_nhap_lai(980, 390, 1250, 420, WHITE, BLACK, 6);
				Nhap_string(980, 390, 1250, 420, nv->HO);
			}
			xoa_yeu_cau_nhap_lai(980, 390, 1250, 420, BLACK, BLACK, 6);
			Nhap_string(980, 510, 1250, 540, nv->TEN);
			while (check_nhap_hoten_nv(nv->TEN) == false)
			{
				yeu_cau_nhap_lai(1000, 510, 1250, 540, WHITE, BLACK, 6);
				Nhap_string(980, 510, 1250, 540, nv->TEN);
			}
			xoa_yeu_cau_nhap_lai(1000, 510, 1250, 540, BLACK, BLACK, 6);
			bool nam = true;
			while (1)
			{
				GetCursorPos(&mouse);
				if(GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 980 && mouse.x <= 1118 && mouse.y >= 650 && mouse.y <= 690)
				{
					tao_button(980, 630, 1114, 660, "NAM", 0, 6);
					tao_button(1115, 630, 1250, 660, "NU", 0, 14);
					nam = true;
				}
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1119 && mouse.x <= 1250 && mouse.y >= 650 && mouse.y <= 690)
				{
					tao_button(1115, 630, 1250, 660, "NU", 0, 6);
					tao_button(980, 630, 1114, 660, "NAM", 0, 14);
					nam = false;
				}
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1255 && mouse.x <= 1280 && mouse.y >= 650 && mouse.y <= 690)
				{
					if (nam == true) nv->PHAI = "Nam";
					else nv->PHAI = "Nu";
					break;
				}
			}
			nv->HO = chuanhoa_name(nv->HO);
			nv->TEN = chuanhoa_name(nv->TEN);

			bool check_them_nv = false;

			while (1)
			{
				GetCursorPos(&mouse);
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1190 && mouse.x <= 1260 && mouse.y >= 690 && mouse.y <= 730)
				{
					check_them_nv = true;
					break;
				}
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1000 && mouse.x <= 1070 && mouse.y >= 690 && mouse.y <= 730)
				{
					break;
				}
			}
			if (check_them_nv == true)
			{
				Listnv.dsnv[Listnv.sl] = nv;
				Listnv.sl++;
			}
			else
			{
				delete Listnv.dsnv[Listnv.sl];
				delete nv;
			}
			in_ds_ten_nv(Listnv, pos_trang, text_color, box_color);
		}
		//XOA NHAN VIEN
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1130 && mouse.x <= 1300 && mouse.y >= 140 && mouse.y <= 179)
		{
			tao_button(1130, 120, 1300, 149, "", 0, 6);
			Nhanvien* nv_xoa = new Nhanvien;
			string s_tmp_xoanv = "";
			Nhap_string(1130, 120, 1300, 149, nv_xoa->MANV);
			s_tmp_xoanv = nv_xoa->MANV;
			nv_xoa = kt_ma_nv(Listnv, nv_xoa->MANV);
			while (check_dung_nhap == false && (nv_xoa == NULL || kt_chuoi_rong(nv_xoa->MANV)))
			{
				yeu_cau_nhap_lai(700, 170, 900, 199, WHITE, BLACK, 6);
				nv_xoa = new Nhanvien;
				nv_xoa->MANV = s_tmp_xoanv;
				Nhap_string(1130, 120, 1300, 149, nv_xoa->MANV);
				s_tmp_xoanv = nv_xoa->MANV;
				nv_xoa = kt_ma_nv(Listnv, nv_xoa->MANV);
			}
			check_dung_nhap = false;
			xoa_yeu_cau_nhap_lai(700, 170, 900, 199, WHITE, BLACK, 6);
			if (nv_xoa != NULL && nv_xoa->dshd == NULL)
			{
				int pos;
				for (int i = 0; i < Listnv.sl; i++)
					if (Listnv.dsnv[i] == nv_xoa)
					{
						pos = i;
						break;
					}
				for (int i = pos; i < Listnv.sl - 1; i++)
				{
					*Listnv.dsnv[i] = *Listnv.dsnv[i + 1];
				}
				delete Listnv.dsnv[Listnv.sl - 1];
				Listnv.sl--;
				in_ds_ten_nv(Listnv, pos_trang, text_color, box_color);
			}
			else if (nv_xoa != NULL)
			{
				setcolor(WHITE);
				setbkcolor(RED);
				outtextxy(700, 125, (char*)"NHAN VIEN NAY DA LAP HOA DON");
			}
		}
		// SUA NHAN VIEN
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1130 && mouse.x <= 1300 && mouse.y >= 180 && mouse.y <= 220)
		{
			sc_hieu_chinh_nv();
			tao_button(1130, 160, 1300, 190, "", 0, 6);
			Nhanvien* nv_sua = new Nhanvien;
			Nhanvien ss;
			string s_tmp_suanv = "";
			Nhap_string(1130, 160, 1300, 190, nv_sua->MANV);
			s_tmp_suanv = nv_sua->MANV;
			nv_sua = kt_ma_nv(Listnv, nv_sua->MANV);
			while (check_dung_nhap == false && (nv_sua == NULL || kt_chuoi_rong(nv_sua->MANV)))
			{
				yeu_cau_nhap_lai(700, 210, 900, 240, WHITE, BLACK, 6);
				nv_sua = new Nhanvien;
				nv_sua->MANV = s_tmp_suanv;
				Nhap_string(1130, 160, 1300, 190, nv_sua->MANV);
				s_tmp_suanv = nv_sua->MANV;
				nv_sua = kt_ma_nv(Listnv, nv_sua->MANV);
			}
			check_dung_nhap = false;
			xoa_yeu_cau_nhap_lai(700, 210, 900, 240, WHITE, BLACK, 6);
			if (nv_sua != NULL)
			{
				ss = *nv_sua;
				sc_hieu_chinh_nv();
				tao_button(950, 200, 1300, 230, "HIEU CHINH", BLACK, box_color);
				setbkcolor(6);
				Nhap_string(980, 270, 1250, 300, nv_sua->HO);
				while (check_nhap_hoten_nv(nv_sua->HO) == false)
				{
					yeu_cau_nhap_lai(980, 350, 1250, 380, WHITE, BLACK, 6);
					Nhap_string(980, 270, 1250, 300, nv_sua->HO);
				}
				xoa_yeu_cau_nhap_lai(980, 350, 1250, 380, BLACK, BLACK, 6);
				Nhap_string(980, 390, 1250, 420, nv_sua->TEN);
				while (check_nhap_hoten_nv(nv_sua->TEN) == false)
				{
					yeu_cau_nhap_lai(980, 470, 1250, 500, WHITE, BLACK, 6);
					Nhap_string(980, 390, 1250, 420, nv_sua->TEN);
				}
				xoa_yeu_cau_nhap_lai(980, 470, 1250, 500, BLACK, BLACK, 6);
				bool nam = true;
				while (1)
				{
					GetCursorPos(&mouse);
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 980 && mouse.x <= 1118 && mouse.y >= 530 && mouse.y <= 570)
					{
						tao_button(980, 510, 1114, 540, "NAM", 0, 6);
						tao_button(1115, 510, 1250, 540, "NU", 0, 14);

						nam = true;
					}
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1119 && mouse.x <= 1250 && mouse.y >= 530 && mouse.y <= 570)
					{
						tao_button(1115, 510, 1250, 540, "NU", 0, 6);
						tao_button(980, 510, 1114, 540, "NAM", 0, 14);
						nam = false;
					}
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1255 && mouse.x <= 1280 && mouse.y >= 530 && mouse.y <= 570)
					{
						if (nam == true) nv_sua->PHAI = "Nam";
						else nv_sua->PHAI = "Nu";
						break;
					}
				}
				nv_sua->HO = chuanhoa_name(nv_sua->HO);
				nv_sua->TEN = chuanhoa_name(nv_sua->TEN);
				bool check_sua_nv = false;

				while (1)
				{
					GetCursorPos(&mouse);
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1190 && mouse.x <= 1260 && mouse.y >= 690 && mouse.y <= 730)
					{
						check_sua_nv = true;
						break;
					}
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1000 && mouse.x <= 1070 && mouse.y >= 690 && mouse.y <= 730)
					{
						break;
					}
				}
				if (check_sua_nv == false)
				{
					*nv_sua = ss;
				}
				in_ds_ten_nv(Listnv, pos_trang, text_color, box_color);
			}
		}
		// IN NHAN VIEN
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 250 && mouse.x <= 340 && mouse.y >= 180 && mouse.y <= 220 && Listnv.sl > 0)
		{
			in_ds_ten_nv(Listnv, pos_trang, text_color, box_color);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 440 && mouse.x <= 475 && mouse.y >= 730 && mouse.y <= 770 && pos_trang > 1)
		{
			pos_trang--;
			sc_main_nv(text_color, box_color);
			tao_button(351, 50, 600, 100, "NHAN VIEN", 0, 6);
			tao_button(250, 160, 340, 190, "TEN", 0, 6);
			//Sap xep
			sort_nv(Listnv);
			// In
			int j = (pos_trang - 1) * 11;
			in_nhanvien_ten(pos_trang, Listnv, so_trang, j);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 560 && mouse.x <= 595 && mouse.y >= 730 && mouse.y <= 770 && pos_trang < so_trang)
		{
			pos_trang++;
			sc_main_nv(text_color, box_color);
			tao_button(351, 50, 600, 100, "NHAN VIEN", 0, 6);
			tao_button(250, 160, 340, 190, "TEN", 0, 6);
			//Sap xep
			sort_nv(Listnv);
			// In
			int j = (pos_trang - 1) * 11;
			in_nhanvien_ten(pos_trang, Listnv, so_trang, j);
		}
		delay(50);
	}
}