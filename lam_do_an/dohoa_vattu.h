#pragma once
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include "vattu.h"
#include "cac_dohoa.h"
#include "nhanvien.h"
using namespace std;
void sc_resert_hienthi_vt()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(101, 241, 899, 679);
	setcolor(8);
	rectangle(100, 200, 900, 680);
	line(300, 200, 300, 680);
	line(550, 200, 550, 680);
	line(700, 200, 700, 680);
	for (int i = 240; i <= 680; i += 40)
	{
		line(100, i, 900, i);
	}
}
void in_vattu_ten(int pos_trang, Vattu** nodes, int sl, int so_trang, int j)
{
	sc_resert_hienthi_vt();
	for (int i = 280; i <= 680; i += 40)
	{
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(105, i - 20, (char*)nodes[j]->MAVT.c_str());
		outtextxy(310, i - 20, (char*)nodes[j]->TENVT.c_str());
		outtextxy(560, i - 20, (char*)nodes[j]->DVT.c_str());
		in_number(710, i - 20, nodes[j]->SoLuongTon);
		j++;
		if (j == sl || j == so_trang*11) break;
	}
	arrow_left(470, 710, YELLOW);
	arrow_right(560, 710, YELLOW);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(490, 715, (char*)to_string(pos_trang).c_str());
	outtextxy(510, 715, (char*)"/");
	outtextxy(530, 715, (char*)to_string(so_trang).c_str());
}
void sc_hieu_chinh_vt()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(951, 201, 1299, 699);
	tao_button(950, 200, 1300, 230, "HIEU CHINH", BLACK, WHITE);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(980, 250, (char*)"TEN VAT TU");
	outtextxy(980, 370, (char*)"DON VI TINH");
	tao_button(980, 270, 1250, 300, "", 0, 14);
	tao_button(980, 390, 1250, 420, "", 0, 14);
	tao_button(1000, 669, 1055, 699, "HUY", BLACK, WHITE);
	tao_button(1190, 669, 1245, 699, "LUU", BLACK, WHITE);
}
void sc_main_vt(int text_color, int box_color)
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
	tao_button(600, 120, 920, 149, "", WHITE, BLACK);
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(100, 165, (char*)"SAP XEP THEO");
	outtextxy(950, 165, (char*)"HIEU CHINH (THEO MVT)");
	outtextxy(950, 125, (char*)"XOA (THEO MVT)");
	tao_button(1130, 160, 1300, 190, "", 0, box_color);
	tao_button(1130, 120, 1300, 149, "", 0, box_color);
	tao_button(250, 160, 340, 190, "TEN", 0, box_color);
	tao_button(360, 160, 450, 190, "SL", 0, box_color);
	tao_button(100, 200, 300, 240, "MA VT", 0, box_color);
	tao_button(301, 200, 550, 240, "TEN", 0, box_color);
	tao_button(551, 200, 700, 240, "DON VI TINH", 0, box_color);
	tao_button(701, 200, 900, 240, "SO LUONG TON", 0, box_color);
	sc_resert_hienthi_vt();
	setcolor(WHITE);
	rectangle(950, 200, 1300, 700);
	tao_button(950, 200, 1300, 230, "THEM VAT TU", 0, WHITE);
	setfillstyle(SOLID_FILL, BLACK);
	bar(980, 240, 1150, 270);
	bar(980, 360, 1150, 390);

	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(980, 250, (char*)"MA VAT TU"); 
	outtextxy(980, 370, (char*)"TEN VAT TU");
	outtextxy(980, 490, (char*)"SO LUONG TON");
	outtextxy(980, 610, (char*)"DON VI TINH");
	tao_button(980, 270, 1250, 300, "", 0, 14);
	tao_button(980, 390, 1250, 420, "", 0, 14);
	tao_button(980, 510, 1250, 540, "", 0, 14);
	tao_button(980, 630, 1250, 660, "", 0, 14);
	tao_button(1000, 669, 1055, 699, "HUY", BLACK, WHITE);
	tao_button(1190, 669, 1245, 699, "LUU", BLACK, WHITE);
}
void in_ds_ten_vt(DS_VATTU dsvt, int& pos_trang, int& check_type, int text_color, int box_color)
{
	if (dsvt.sl == 0) return;
	check_type = 1;
	pos_trang = 1;
	sc_main_vt(text_color, box_color);
	tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
	tao_button(250, 160, 340, 190, "TEN", 0, 6);
	Vattu** nodes = new Vattu * [dsvt.sl];
	int sl = 0;
	//Day node Vattu vao mang con tro
	Duyet_LNR(dsvt.root, nodes, sl);
	//Sap xep
	xep_noi_bot(nodes, sl);
	// In
	int j = 0;
	int so_trang = 0;
	if (dsvt.sl % 11 == 0 && dsvt.sl != 0) so_trang = dsvt.sl / 11;
	else so_trang = (dsvt.sl / 11) + 1;
	in_vattu_ten(pos_trang, nodes, sl, so_trang, j);
	delete[] nodes;
	nodes = nullptr;
}
void khoi_dong_vattu(DS_VATTU &dsvt, POINT mouse, int text_color, int box_color, int &pos_trang, int &check_type)
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 1536, 864);
	sc_main_vt(text_color, box_color);
	tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
	in_ds_ten_vt(dsvt, pos_trang, check_type, text_color, box_color);
	while (1)
	{
		check_dung_nhap = false;
		GetCursorPos(&mouse);
		int so_trang = 0;
		if (dsvt.sl % 11 == 0 && dsvt.sl != 0) so_trang = dsvt.sl / 11;
		else so_trang = (dsvt.sl / 11) + 1;
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 351 && mouse.x <= 1140 && mouse.y >= 70 && mouse.y <= 130)
		{
			sc_main_vt(text_color, box_color);
			break;
		}
		// XOA VATTU (THEO MA)
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1130 && mouse.x <= 1300 && mouse.y >= 140 && mouse.y <= 179)
		{
			tao_button(1130, 120, 1300, 149, "", 0, 6);
			Vattu* vt_xoa = create_node();
			string s_tmp_xoa = "";
			Nhap_string(1130, 120, 1300, 149, vt_xoa->MAVT);
			s_tmp_xoa = vt_xoa->MAVT;
			vt_xoa = check_trung(dsvt.root, vt_xoa->MAVT);
			while (check_dung_nhap == false && (vt_xoa == NULL || kt_chuoi_rong(vt_xoa->MAVT)))
			{
				yeu_cau_nhap_lai(700, 170, 900, 199, WHITE, BLACK, 6);
				vt_xoa = create_node();
				vt_xoa->MAVT = s_tmp_xoa;
				Nhap_string(1130, 120, 1300, 149, vt_xoa->MAVT);
				s_tmp_xoa = vt_xoa->MAVT;
				vt_xoa = check_trung(dsvt.root, vt_xoa->MAVT);
			}
			check_dung_nhap = false;
			xoa_yeu_cau_nhap_lai(700, 170, 900, 199, WHITE, BLACK, 6);
			if (vt_xoa != NULL && vt_xoa->check_NHD == 0)
			{
				dsvt.root = Xoa_VT(dsvt.root, vt_xoa->MAVT);
				while (!checkAVL(dsvt.root)) {
					dsvt.root = cap_nhap_AVL(dsvt.root);
				}
				dsvt.sl--;
				in_ds_ten_vt(dsvt, pos_trang, check_type, text_color, box_color);
			}
			else if(vt_xoa != NULL)
			{
				setcolor(WHITE);
				setbkcolor(RED);
				outtextxy(700, 125, (char*)"HOA DON DA CO VAT TU NAY");
			}
		}
		//SUA VATTU (THEO MA)
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1130 && mouse.x <= 1300 && mouse.y >= 180 && mouse.y <= 220)
		{
			tao_button(1130, 160, 1300, 190, "", 0, 6);
			Vattu* vt_sua = create_node();
			Vattu vt_tmp;
			string s_tmp_sua = "";
			Nhap_string(1130, 160, 1300, 190, vt_sua->MAVT);
			s_tmp_sua = vt_sua->MAVT;
			vt_sua = check_trung(dsvt.root, vt_sua->MAVT);
			while (check_dung_nhap == false && (vt_sua == NULL || kt_chuoi_rong(vt_sua->MAVT)))
			{
				yeu_cau_nhap_lai(700, 210, 900, 240, WHITE, BLACK, 6);
				vt_sua = create_node();
				vt_sua->MAVT = s_tmp_sua;
				Nhap_string(1130, 160, 1300, 190, vt_sua->MAVT);
				s_tmp_sua = vt_sua->MAVT;
				vt_sua = check_trung(dsvt.root, vt_sua->MAVT);
			}
			check_dung_nhap = false;
			xoa_yeu_cau_nhap_lai(700, 210, 900, 240, WHITE, BLACK, 6);
			if (vt_sua != NULL)
			{
				vt_tmp = *vt_sua;
				sc_hieu_chinh_vt();
				tao_button(950, 200, 1300, 230, "HIEU CHINH", BLACK, box_color);
				setbkcolor(6);
				Nhap_string(980, 270, 1250, 300, vt_sua->TENVT);
				while (check_nhap_hoten_nv(vt_sua->TENVT) == false)
				{
					yeu_cau_nhap_lai(980, 350, 1250, 380, WHITE, BLACK, 6);
					Nhap_string(980, 270, 1250, 300, vt_sua->TENVT);
				}
				xoa_yeu_cau_nhap_lai(980, 350, 1250, 380, BLACK, BLACK, 6);
				Nhap_string(980, 390, 1250, 420, vt_sua->DVT);
				while (kt_chuoi_rong(vt_sua->DVT) == true || chi_nhap_so(vt_sua->DVT) == true)
				{
					yeu_cau_nhap_lai(980, 470, 1250, 500, WHITE, BLACK, 6);
					Nhap_string(980, 390, 1250, 420, vt_sua->DVT);
				}
				xoa_yeu_cau_nhap_lai(980, 470, 1250, 500, BLACK, BLACK, 6);
				vt_sua->TENVT = chuanhoa_name(vt_sua->TENVT);
				vt_sua->DVT = chuanhoa_name(vt_sua->DVT);
				bool check_sua_vt = false;

				while (1)
				{
					GetCursorPos(&mouse);
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1190 && mouse.x <= 1250 && mouse.y >= 690 && mouse.y <= 730)
					{
						check_sua_vt = true;
						break;
					}
					if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1000 && mouse.x <= 1060 && mouse.y >= 690 && mouse.y <= 730)
					{
						break;
					}
				}

				if (check_sua_vt == false)
				{
					*vt_sua = vt_tmp;
				}
				in_ds_ten_vt(dsvt, pos_trang, check_type, text_color, box_color);
			}
		}
		//THEM VAT TU 
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 950 && mouse.x <= 1300 && mouse.y >= 220 && mouse.y <= 260)
		{
			tao_button(950, 200, 1300, 230, "THEM VAT TU", 0, 6);
			Vattu* vt_add = create_node();
			if (dsvt.sl == 0)
			{
				int middle = pow(10, ma.length() - 2) / 2;
				vt_add->MAVT = "VT" + to_string(middle);
			}
			else  vt_add->MAVT = tao_ma_vt(dsvt.root);
			tao_button(980, 270, 1250, 300, vt_add->MAVT, 0, 14);
			tao_button(980, 390, 1250, 420, "", 0, 14);
			tao_button(980, 510, 1250, 540, "", 0, 14);
			tao_button(980, 630, 1250, 660, "", 0, 14);
			setbkcolor(6);
			Nhap_string(980, 390, 1250, 420, vt_add->TENVT);
			while (check_nhap_hoten_nv(vt_add->TENVT) == false)
			{
				yeu_cau_nhap_lai(980, 390, 1250, 420, WHITE, BLACK, 6);
				Nhap_string(980, 390, 1250, 420, vt_add->TENVT);
			}
			xoa_yeu_cau_nhap_lai(980, 390, 1250, 420, BLACK, BLACK, 6);
			string s_tmp = "";
			Nhap_number(980, 510, 1250, 540, vt_add->SoLuongTon, s_tmp);
			while (vt_add->SoLuongTon < 0)
			{
				yeu_cau_nhap_lai(1000, 510, 1250, 540, WHITE, BLACK, 6);
				Nhap_number(980, 510, 1250, 540, vt_add->SoLuongTon, s_tmp);
			}
			xoa_yeu_cau_nhap_lai(1000, 510, 1250, 540, BLACK, BLACK, 6);
			Nhap_string(980, 630, 1250, 660, vt_add->DVT);
			while (kt_chuoi_rong(vt_add->DVT) == true || chi_nhap_so(vt_add->DVT) == true)
			{
				yeu_cau_nhap_lai(980, 630, 1250, 660, WHITE, BLACK, 6);
				Nhap_string(980, 630, 1250, 660, vt_add->DVT);
			}
			xoa_yeu_cau_nhap_lai(980, 630, 1250, 660, BLACK, BLACK, 6);
			vt_add->TENVT = chuanhoa_name(vt_add->TENVT);
			vt_add->DVT = chuanhoa_name(vt_add->DVT);
			bool check_them_vt = false;

			while (1)
			{
				GetCursorPos(&mouse);
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1190 && mouse.x <= 1250 && mouse.y >= 690 && mouse.y <= 730)
				{
					check_them_vt = true;
					break;
				}
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 1000 && mouse.x <= 1060 && mouse.y >= 690 && mouse.y <= 730)
				{
					break;
				}
			}

			if (check_them_vt == true) 
			{
				dsvt.sl++;
				Them_Vat_Tu(dsvt.root, vt_add);
			}
			while (check_them_vt == true && checkAVL(dsvt.root) == false) {
				dsvt.root = cap_nhap_AVL(dsvt.root);
			}
			in_ds_ten_vt(dsvt, pos_trang, check_type, text_color, box_color);
		}
		//// Xuat vat tu (theo ten)
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 250 && mouse.x <= 340 && mouse.y >= 180 && mouse.y <= 220 && dsvt.sl != 0)
		{
			in_ds_ten_vt(dsvt, pos_trang, check_type, text_color, box_color);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 440 && mouse.x <= 475 && mouse.y >= 730 && mouse.y <= 770 && pos_trang > 1 && check_type == 1)
		{
			pos_trang--;
			sc_main_vt(text_color, box_color);
			tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
			tao_button(250, 160, 340, 190, "TEN", 0, 6);
			Vattu** nodes = new Vattu * [dsvt.sl];
			int sl = 0;
			//Day node Vattu vao mang con tro
			Duyet_LNR(dsvt.root, nodes, sl);
			//Sap xep
			xep_noi_bot(nodes, sl);
			// In
			int j = (pos_trang - 1) * 11;
			in_vattu_ten(pos_trang, nodes, sl, so_trang, j);
			delete[] nodes;
			nodes = nullptr;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 560 && mouse.x <= 595 && mouse.y >= 730 && mouse.y <= 770 && pos_trang < so_trang && check_type == 1)
		{
			pos_trang++;
			sc_main_vt(text_color, box_color);
			tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
			tao_button(250, 160, 340, 190, "TEN", 0, 6);
			Vattu** nodes = new Vattu * [dsvt.sl];
			int sl = 0;
			//Day node Vattu vao mang con tro
			Duyet_LNR(dsvt.root, nodes, sl);
			//Sap xep
			xep_noi_bot(nodes, sl);
			// In
			int j = (pos_trang - 1) * 11;
			in_vattu_ten(pos_trang, nodes, sl, so_trang, j);
			delete[] nodes;
			nodes = nullptr;
		}
		// Xuat vat tu (theo sl) 
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 360 && mouse.x <= 450 && mouse.y >= 180 && mouse.y <= 220 && dsvt.sl != 0)
		{
			check_type = 2;
			pos_trang = 1;
			sc_main_vt(text_color, box_color);
			tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
			tao_button(360, 160, 450, 190, "SL", 0, 6);
			Vattu** nodes = new Vattu * [dsvt.sl];
			int sl = 0;
			//Day node Vattu vao mang con tro
			Duyet_LNR(dsvt.root, nodes, sl);
			//Sap xep
			xep_noi_bot_SL(nodes, sl);
			// In
			int j = 0;
			int so_trang = 0;
			if (dsvt.sl % 11 == 0 && dsvt.sl != 0) so_trang = dsvt.sl / 11;
			else so_trang = (dsvt.sl / 11) + 1;
			in_vattu_ten(pos_trang, nodes, sl, so_trang, j);
			delete[] nodes;
			nodes = nullptr;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 440 && mouse.x <= 475 && mouse.y >= 730 && mouse.y <= 770 && pos_trang > 1 && check_type == 2)
		{
			pos_trang--;
			sc_main_vt(text_color, box_color);
			tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
			tao_button(360, 160, 450, 190, "SL", 0, 6);
			Vattu** nodes = new Vattu * [dsvt.sl];
			int sl = 0;
			//Day node Vattu vao mang con tro
			Duyet_LNR(dsvt.root, nodes, sl);
			//Sap xep
			xep_noi_bot_SL(nodes, sl);
			// In
			int j = (pos_trang - 1) * 11;
			in_vattu_ten(pos_trang, nodes, sl, so_trang, j);
			delete[] nodes;
			nodes = nullptr;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 560 && mouse.x <= 595 && mouse.y >= 730 && mouse.y <= 770 && pos_trang < so_trang && check_type == 2)
		{
			pos_trang++;
			sc_main_vt(text_color, box_color);
			tao_button(100, 50, 350, 100, "VAT TU", 0, 6);
			tao_button(360, 160, 450, 190, "SL", 0, 6);
			Vattu** nodes = new Vattu * [dsvt.sl];
			int sl = 0;
			//Day node Vattu vao mang con tro
			Duyet_LNR(dsvt.root, nodes, sl);
			//Sap xep
			xep_noi_bot_SL(nodes, sl);
			// In
			int j = (pos_trang - 1) * 11;
			in_vattu_ten(pos_trang, nodes, sl, so_trang, j);
			delete[] nodes;
			nodes = nullptr;
		}
		delay(50);
	}

}
