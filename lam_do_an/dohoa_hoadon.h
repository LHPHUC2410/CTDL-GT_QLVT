#pragma once
#include<iostream>
#include"hoadon.h"
#include"cac_dohoa.h"
#include"nhanvien.h"
#include"graphics.h"
#pragma comment(lib, "graphics.lib")

using namespace std;

Nhanvien* tim_nhan_vien(list_nv dsnv, string sohd);
nodehd* tim_hoa_don(list_nv dsnv, string sohd);

void xoatoanmanhinh() {
	setfillstyle(SOLID_FILL, 0);
	bar(0, 101, 1430, 800);
}

void hienthi_nhaplai_hd()
{
	setfillstyle(SOLID_FILL, RED);
	setbkcolor(RED);
	setcolor(15);
	bar(800, 140, 1110, 170);
	outtextxy(870, 148, (char*)"NHAP SAI. MOI NHAP LAI");
	setfillstyle(SOLID_FILL, 6);
	setbkcolor(6);
	setcolor(15);
}

void xoa_hienthi_nhaplai_hd()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(800, 140, 1110, 170);
	setfillstyle(SOLID_FILL, 6);
	setbkcolor(6);
	setcolor(15);
}

void khung_vt_nv_hd()
{
	tao_button(100, 50, 350, 100, "VAT TU", 0, 11);
	tao_button(351, 50, 600, 100, "NHAN VIEN", 0, 11);
	tao_button(601, 50, 850, 100, "HOA DON", 0, 6);
	tao_button(851, 50, 1100, 100, "THONG KE", 0, 11);
	setfillstyle(SOLID_FILL, RED);
	bar(1101, 50, 1150, 100);
	setcolor(WHITE);
	setbkcolor(RED);
	outtextxy(1120, 67, (char*)"X");
}

void khunglcnhapxuathd()
{
	setfillstyle(SOLID_FILL, 3);
	setbkcolor(3);
	setcolor(15);
	bar(50, 110, 230, 140);							// // HOA DON NHAP
	outtextxy(90, 118, (char*)"HOA DON NHAP");
	bar(250, 110, 430, 140);						//  // HOA DON XUAT
	outtextxy(290, 118, (char*)"HOA DON XUAT");
	bar(450, 110, 630, 140);
	outtextxy(500, 118, (char*)"IN HOA DON");      //IN 
	bar(650, 110, 830, 140);
	outtextxy(700, 118, (char*)"TRA HANG");        //TRA HANG
	////- nut OK ----
	setfillstyle(SOLID_FILL, 2);
	setbkcolor(2);
	bar(850, 110, 900, 140);
	outtextxy(865, 118, (char*)"OK");
}

void Khung_nhap_cthd()
{
	setcolor(WHITE);
	rectangle(50, 180, 1300, 280);
	line(50, 230, 1300, 230);
	setfillstyle(SOLID_FILL, YELLOW);
	setbkcolor(0);
	setcolor(15);
	outtextxy(60, 248, (char*)"MA VT:");			//MA VT
	bar(120, 240, 240, 270);
	outtextxy(280, 248, (char*)"TEN VT:");			//TEN VAT TU
	bar(340, 240, 520, 270);
	outtextxy(560, 248, (char*)"SO LUONG:");		//SO LUONG 
	bar(640, 240, 730, 270);
	outtextxy(770, 248, (char*)"DON GIA:");			//DON GIA
	bar(840, 240, 930, 270);
	outtextxy(970, 248, (char*)"VAT(%):");			//VAT
	bar(1030, 240, 1120, 270);

	//---khung XONG---
	setfillstyle(SOLID_FILL, 2);
	setbkcolor(2);
	setcolor(15);
	bar(1200, 240, 1290, 270);
	outtextxy(1225, 248, (char*)"XONG");
}

void khungnhaphd()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setbkcolor(0);

	rectangle(50, 180, 1300, 280);
	line(50, 230, 1300, 230);
	outtextxy(60, 198, (char*)"MA NV: ");			//MA NV
	bar(120, 190, 240, 220);
	outtextxy(280, 198, (char*)"HO & TEN NV: ");    // HO TEN NV
	bar(380, 190, 600, 220);
	outtextxy(640, 198, (char*)"SO HD: ");			//SO HD
	bar(700, 190, 800, 220);
	outtextxy(840, 198, (char*)"NGAY LAP: ");		// NGAY LAP HD
	bar(920, 190, 970, 220);						// NGAY
	bar(980, 190, 1030, 220);						//THANG
	bar(1040, 190, 1120, 220);						//NAM

	//---khung luu---
	setfillstyle(SOLID_FILL, 2);
	setbkcolor(2);
	setcolor(15);
	bar(1200, 190, 1290, 220);
	outtextxy(1230, 198, (char*)"LUU");

	//Khung xoa
	setfillstyle(SOLID_FILL, RED);
	bar(1200, 140, 1290, 170);
	setbkcolor(RED);
	outtextxy(1230, 148, (char*)"XOA");
	//setfillstyle(SOLID_FILL, 6);
	//setcolor(WHITE);
	//setbkcolor(6);

	//---khung nhap cthd------
	Khung_nhap_cthd();
}


void khungincthd()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(50, 300, 1300, 661);
	setfillstyle(SOLID_FILL, RED);
	setbkcolor(RED);
	rectangle(50, 300, 1300, 660);
	for (int i = 340; i < 650; i += 40)
	{
		line(50, i, 1300, i);
	}
	floodfill(60, 310, 15);
	line(180, 300, 180, 660); //MA VT
	line(480, 300, 480, 660); //TEN VT
	line(610, 300, 610, 660); //DVT
	line(740, 300, 740, 660); //SO LUONG
	line(870, 300, 870, 660); //DON GIA
	line(1000, 300, 1000, 660); // VAT
	line(1250, 300, 1250, 660); //TT
	outtextxy(80, 313, (char*)"MA VAT TU");
	outtextxy(280, 313, (char*)"TEN VAT TU");
	outtextxy(500, 313, (char*)"DON VI TINH");
	outtextxy(640, 313, (char*)"SO LUONG");
	outtextxy(780, 313, (char*)"DON GIA");
	outtextxy(910, 313, (char*)"VAT(%)");
	outtextxy(1090, 313, (char*)"THANH TIEN");
	outtextxy(1253, 313, (char*)"T.Thai");
	setbkcolor(BLACK);
	outtextxy(1000, 668, (char*)"Tong tien: ");
	tao_button(500, 680, 580, 710, "", 0, YELLOW);
	outtextxy(530, 688, (char*)"<<");
	tao_button(700, 680, 780, 710, "", 0, YELLOW);
	outtextxy(730, 688, (char*)">>");
}

void khung_in_hoadontheongay()
{
	rectangle(40, 150, 1310, 660);
	setfillstyle(SOLID_FILL, BLACK);
	bar(50, 300, 1300, 661);
	setfillstyle(SOLID_FILL, RED);
	setbkcolor(RED);
	rectangle(50, 300, 1300, 660);
	for (int i = 340; i < 650; i += 40)
	{
		line(50, i, 1300, i);
	}
	floodfill(60, 310, 15);
	line(200, 300, 200, 660); //SO HD
	line(480, 300, 480, 660); //NGAY LAP
	line(700, 300, 700, 660); //LOAI HOA DON
	line(1050, 300, 1050, 660); //HO TEN
	// 1050-1300 => TRI GIA
	outtextxy(80, 313, (char*)"SO HOA DON");
	outtextxy(280, 313, (char*)"NGAY LAP");
	outtextxy(550, 313, (char*)"LOAI HOA DON");
	outtextxy(800, 313, (char*)"HO TEN NHAN VIEN");
	outtextxy(1150, 313, (char*)"TRI GIA");
	setbkcolor(BLACK);
	tao_button(500, 680, 580, 710, "", 0, YELLOW);
	outtextxy(530, 688, (char*)"<<");
	tao_button(700, 680, 780, 710, "", 0, YELLOW);
	outtextxy(730, 688, (char*)">>");
	//-------------------------------
}

void khunginhoadon()
{
	rectangle(40, 150, 1310, 660);
	setbkcolor(BLACK);
	outtextxy(590, 160, (char*)"SO HOA DON");
	//setcolor(YELLOW);
	setbkcolor(0);
	outtextxy(60, 220, (char*)"Ngay lap:");
	outtextxy(60, 240, (char*)"So hoa don:");
	outtextxy(60, 260, (char*)"Loai:");
	outtextxy(400, 240, (char*)"Ma Nhan Vien:");
	outtextxy(400, 260, (char*)"Ho Ten Nhan Vien:");
	rectangle(520, 160, 760, 210);
	setfillstyle(SOLID_FILL, YELLOW);
	bar(530, 180, 750, 209);
	khungincthd();
}

void khung_in_vattu()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(50, 300, 1300, 661);
	//rectangle(40, 150, 1310, 660);
	setfillstyle(SOLID_FILL, BLACK);
	bar(50, 300, 1300, 661);
	setfillstyle(SOLID_FILL, RED);
	setbkcolor(RED);
	rectangle(50, 300, 1300, 660);
	for (int i = 340; i < 650; i += 40)
	{
		line(50, i, 1300, i);
	}
	floodfill(60, 310, 15);
	line(400, 300, 400, 660); //SO HD
	line(900, 300, 900, 660); //NGAY LAP

	outtextxy(180, 313, (char*)"MA VAT TU");
	outtextxy(600, 313, (char*)"TEN VAT TU");
	outtextxy(1050, 313, (char*)"SO LUONG TON");
	setbkcolor(BLACK);
	tao_button(500, 680, 580, 710, "", 0, YELLOW);
	outtextxy(530, 688, (char*)"<<");
	tao_button(700, 680, 780, 710, "", 0, YELLOW);
	outtextxy(730, 688, (char*)">>");
}

void khung_in_nhanvien()
{
	setfillstyle(SOLID_FILL, BLACK);
	bar(50, 300, 1300, 661);
	//rectangle(40, 150, 1310, 660);
	setfillstyle(SOLID_FILL, BLACK);
	bar(50, 300, 1300, 661);
	setfillstyle(SOLID_FILL, RED);
	setbkcolor(RED);
	rectangle(50, 300, 1300, 660);
	for (int i = 340; i < 650; i += 40)
	{
		line(50, i, 1300, i);
	}
	floodfill(60, 310, 15);
	line(400, 300, 400, 660); //SO HD
	line(900, 300, 900, 660); //NGAY LAP

	outtextxy(180, 313, (char*)"MA NHAN VIEN");
	outtextxy(600, 313, (char*)"TEN NHAN VIEN");
	outtextxy(1050, 313, (char*)"PHAI");
	setbkcolor(BLACK);
	tao_button(500, 680, 580, 710, "", 0, YELLOW);
	outtextxy(530, 688, (char*)"<<");
	tao_button(700, 680, 780, 710, "", 0, YELLOW);
	outtextxy(730, 688, (char*)">>");
}


void luachon(HOADON& hoadon, bool &thoat_ham)   //Lua chon nhap/xuat/in hoadon + Nhap hoadon.loai //
{

	//xoatoanmanhinh();
	khunglcnhapxuathd();
	while (1)
	{
		POINT point;
		GetCursorPos(&point);
		if (GetAsyncKeyState(VK_LBUTTON) && ((point.x >= 851 && point.x <= 1140) || (point.x >= 100 && point.x <= 600)) && point.y >= 70 && point.y <= 130)
		{
			// THOAT
			khung_vt_nv_hd();
			thoat_ham = true;
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 50 && point.x <= 230 && point.y >= 130 && point.y <= 160)
		{
			//----DOI MAU NEN___
			xoatoanmanhinh();
			khunglcnhapxuathd();
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			bar(50, 110, 230, 140);
			outtextxy(90, 118, (char*)"HOA DON NHAP");

			khungnhaphd();
			khungincthd();
			hoadon.loai = "N";
			////----TEST-----
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 250 && point.x <= 430 && point.y >= 130 && point.y <= 160)
		{
			xoatoanmanhinh();
			khunglcnhapxuathd();
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			bar(250, 110, 430, 140);
			outtextxy(290, 118, (char*)"HOA DON XUAT");
			khungnhaphd();
			khungincthd();
			hoadon.loai = "X";
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 450 && point.x <= 630 && point.y >= 130 && point.y <= 160)
		{
			xoatoanmanhinh();
			khunglcnhapxuathd();
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			bar(450, 110, 630, 140);
			outtextxy(500, 118, (char*)"IN HOA DON");
			khunginhoadon();
			hoadon.loai = "IN";
		}

		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 650 && point.x <= 830 && point.y >= 130 && point.y <= 160)
		{
			xoatoanmanhinh();
			khunglcnhapxuathd();
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			bar(650, 110, 830, 140);
			outtextxy(700, 118, (char*)"TRA HANG");
			khunginhoadon();
			hoadon.loai = "TRA";
		}

		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 850 && point.x <= 900 && point.y >= 130 && point.y <= 170)
		{
			setfillstyle(SOLID_FILL, 0);
			bar(850, 110, 900, 140);
			break;
		}

	}
	delay(50);
	//return s;
}



void NhapNgay_DH(Ngay& NGAY)
{
	bool checkngay = false;
	do {
		//hienthi_nhaplai_hd();

		setfillstyle(SOLID_FILL, 6);
		setbkcolor(6);
		setcolor(15);

		int ngay, thang, nam;
		Nhap_number_int(920, 190, 970, 220, ngay);  // Nhap ngay
		NGAY.ngay = ngay;
		Nhap_number_int(980, 190, 1030, 220, thang);   // Nhap thang
		NGAY.thang = thang;
		Nhap_number_int(1040, 190, 1120, 220, nam);   // Nhap nam
		NGAY.nam = nam;

		checkngay = CheckNgayThangNam(NGAY);
		if (!checkngay) {
			hienthi_nhaplai_hd();
			// Hien thi thong bao loi
			delay(1000);
		}

	} while (!checkngay);

	xoa_hienthi_nhaplai_hd();
}


void in_cthd_DH(CT_HOADON cthd, int y, DS_VATTU dsvt)
{
	setfillstyle(SOLID_FILL, YELLOW);
	setbkcolor(0);
	setcolor(15);
	outtextxy(80, y + 13, (char*)cthd.MAVT.c_str());   // in MA VT

	//outtextxy(640, y + 13, (char*)to_string(cthd.Soluong).c_str());   // in SO LUONG
	in_number(640, y + 13, cthd.Soluong);
	//outtextxy(770, y + 13, (char*)to_string(cthd.Dongia).c_str());    //in DON GIA
	in_number(770, y + 13, cthd.Dongia);
	//outtextxy(900, y + 13, (char*)to_string(cthd.VAT).c_str());      //in VAT
	in_number(900, y + 13, cthd.VAT);
	//outtextxy(1100, y + 13, (char*)to_string(giatrihoadon(cthd)).c_str());  // Thanh tien
	in_number(1110, y + 13, giatricthoadon(cthd));
	//in ten vt + DVT
	Vattu* temp = check_trung(dsvt.root, cthd.MAVT);
	outtextxy(250, y + 13, (char*)temp->TENVT.c_str());
	outtextxy(500, y + 13, (char*)temp->DVT.c_str());
	//===in TRANG THAI====
	string trangthai;
	if (cthd.Trangthai) trangthai = "T T";
	else trangthai = "Tra";
	outtextxy(1260, y + 13, (char*)trangthai.c_str());
}

void in_tongtien(nodecthd* Nodecthd)
{
	//---reset de cap nhat
	setfillstyle(SOLID_FILL, 0);
	setbkcolor(BLACK);
	bar(1000, 661, 1300, 700);
	outtextxy(1000, 668, (char*)"Tong tien: ");
	/*outtextxy(1100, 668, (char*)to_string(tonggiatrihoadon(Nodecthd)).c_str());*/
	in_number(1110, 668, tonggiatrihoadon(Nodecthd));
}

void in_1_trang(int pos_trang, CT_HOADON cthd[], int sl, int sotrang, int j, DS_VATTU dsvt)
{
	khungincthd();
	for (int i = 340; i <= 660; i += 40)
	{
		in_cthd_DH(cthd[j], i, dsvt);
		j++;
		if (j % 8 == sl || j == pos_trang * 8) break;
	}
	outtextxy(620, 688, (char*)to_string(pos_trang).c_str());
	outtextxy(640, 688, (char*)"/");
	outtextxy(660, 688, (char*)to_string(sotrang).c_str());
}

void in_node_cthd(nodecthd* Nodecthd, DS_VATTU dsvt)
{
	//xoatoanmanhinh();
	if (Nodecthd == NULL) return;
	int trangmax = 1;
	int tranghientai = 1;
	if (Soluongnodecthd(Nodecthd) == 0) trangmax = 1;
	if (Soluongnodecthd(Nodecthd) > 0 && Soluongnodecthd(Nodecthd) % 8 == 0) trangmax = Soluongnodecthd(Nodecthd) / 8;
	else trangmax = Soluongnodecthd(Nodecthd) / 8 + 1;
	if (Soluongnodecthd(Nodecthd) == 0) tranghientai = 1;
	if (Soluongnodecthd(Nodecthd) > 0 && Soluongnodecthd(Nodecthd) % 8 == 0) tranghientai = Soluongnodecthd(Nodecthd) / 8;
	else tranghientai = Soluongnodecthd(Nodecthd) / 8 + 1;
	CT_HOADON* mangcthd = new CT_HOADON[Soluongnodecthd(Nodecthd)];
	nodecthd* p = Nodecthd;
	int index = 0;
	while (p != NULL)
	{
		mangcthd[index] = p->cthd;
		p = p->next;
		index++;
	}
	int sl;
	if (tranghientai == trangmax)
	{
		sl = Soluongnodecthd(Nodecthd) % 8;
	}
	else sl = 8;
	int j = (tranghientai - 1) * 8;
	in_1_trang(tranghientai, mangcthd, sl, trangmax, j, dsvt);
	in_tongtien(Nodecthd);
	POINT point;
	while (1)
	{
		GetCursorPos(&point);
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 700 && point.x <= 780 && point.y >= 700 && point.y <= 730 && tranghientai < trangmax)
		{
			tranghientai++;
			if (tranghientai == trangmax)
			{
				sl = Soluongnodecthd(Nodecthd) % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang(tranghientai, mangcthd, sl, trangmax, j, dsvt);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 500 && point.x <= 580 && point.y >= 700 && point.y <= 730 && tranghientai > 1)
		{
			tranghientai--;
			if (tranghientai == trangmax)
			{
				sl = Soluongnodecthd(Nodecthd) % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang(tranghientai, mangcthd, sl, trangmax, j, dsvt);
		}
		if (GetAsyncKeyState(VK_RBUTTON)) break;
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 120 && point.x <= 240 && point.y >= 260 && point.y <= 290)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 210 && point.y <= 240)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 50 && point.x <= 230 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 250 && point.x <= 430 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 450 && point.x <= 630 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 100 && point.x <= 1100 && point.y >= 70 && point.y <= 120)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 160 && point.y <= 190) break;

	}
	delete[] mangcthd;
}


void in_thongtin_hoadon(Nhanvien* nv, HOADON hoadon)
{
	//=====NGAY => DD/MM/YYYY===
	string ngay, thang, nam;
	ngay = to_string(hoadon.NgaylapHD.ngay);
	thang = to_string(hoadon.NgaylapHD.thang);
	nam = to_string(hoadon.NgaylapHD.nam);
	if (ngay.length() == 1) ngay = "0" + ngay;
	if (thang.length() == 1) thang = "0" + thang;
	string Ngaylaphd = ngay + " / " + thang + " / " + nam;
	//===================
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(130, 220, (char*)Ngaylaphd.c_str());
	outtextxy(140, 240, (char*)hoadon.SoHD.c_str());
	outtextxy(100, 260, (char*)hoadon.loai.c_str());
	outtextxy(500, 240, (char*)nv->MANV.c_str());
	string hoten = nv->HO + " " + nv->TEN;
	outtextxy(530, 260, (char*)hoten.c_str());

}

void in_hoadon_DH(string sohd, list_nv dsnv, DS_VATTU dsvt)
{
	//========NHAP SO HD======
	setcolor(WHITE);
	setbkcolor(6);
	Nhap_string(530, 180, 750, 209, sohd);
	nodehd* t = tim_hoa_don(dsnv, sohd);
	Nhanvien* nv = tim_nhan_vien(dsnv, sohd);
	if (t != NULL)
	{
		in_thongtin_hoadon(nv, t->hoadon);
		in_node_cthd(t->hoadon.dscthd, dsvt);
	}
	else
	{
		xoatoanmanhinh();
		setfillstyle(SOLID_FILL, RED);
		bar(550, 400, 800, 450);
		setbkcolor(RED);
		setcolor(WHITE);
		outtextxy(570, 418, (char*)"MA HOA DON KHONG TON TAI");
	}

}

void in_tk_1_hoadon(HOADON hoadon, int y, list_nv dsnv)
{
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(80, y + 13, (char*)hoadon.SoHD.c_str()); // in SOHD
	//=====NGAY => DD/MM/YYYY===
	string ngay, thang, nam;
	ngay = to_string(hoadon.NgaylapHD.ngay);
	thang = to_string(hoadon.NgaylapHD.thang);
	nam = to_string(hoadon.NgaylapHD.nam);
	if (ngay.length() == 1) ngay = "0" + ngay;
	if (thang.length() == 1) thang = "0" + thang;
	string Ngaylaphd = ngay + " / " + thang + " / " + nam;
	outtextxy(290, y + 13, (char*)Ngaylaphd.c_str());
	string loai;
	if (hoadon.loai == "N") loai = "Nhap";
	else if (hoadon.loai == "X") loai = "Xuat";
	outtextxy(520, y + 13, (char*)loai.c_str());
	Nhanvien* nv = tim_nhan_vien(dsnv, hoadon.SoHD);
	string hoten = nv->HO + " " + nv->TEN;
	outtextxy(800, y + 13, (char*)hoten.c_str());
	in_number(1150, y + 13, tonggiatrihoadon(hoadon.dscthd));
	//delete nv;
}

int dem_sohoadon_n1n2(list_nv dsnv, Ngay n1, Ngay n2)
{
	int cnt = 0;
	nodehd* temp = NULL;
	for (int i = 0; i < dsnv.sl; i++)
	{
		temp = dsnv.dsnv[i]->dshd;
		while (temp != NULL)
		{
			if (check_n1_den_n2(n1, n2, temp->hoadon.NgaylapHD))
			{
				cnt++;
			}
			temp = temp->next;
		}
	}
	//xoa_bonho_nodehd(temp);
	return cnt;
}

void in_1_trang_lk_hoadon(int pos_trang, int sl, int sotrang, int j, list_nv dsnv, Ngay n1, Ngay n2)
{
	khung_in_hoadontheongay();
	nodehd* temp = NULL;
	//khungincthd();
	HOADON* manghd = new HOADON[dem_sohoadon_n1n2(dsnv, n1, n2)];
	int index = 0;
	for (int i = 0; i < dsnv.sl; i++)
	{
		temp = dsnv.dsnv[i]->dshd;
		while (temp != NULL)
		{
			if (check_n1_den_n2(n1, n2, temp->hoadon.NgaylapHD))
			{
				manghd[index] = temp->hoadon;
				index++;
			}
			temp = temp->next;
		}
	}
	for (int i = 340; i <= 660; i += 40)
	{
		in_tk_1_hoadon(manghd[j], i, dsnv);
		j++;
		if (j % 8 == sl || j == pos_trang * 8) break;
	}
	outtextxy(620, 688, (char*)to_string(pos_trang).c_str());
	outtextxy(640, 688, (char*)"/");
	outtextxy(660, 688, (char*)to_string(sotrang).c_str());
	delete[] manghd;
}



void in_thongkehoadon(list_nv dsnv, Ngay n1, Ngay n2)
{
	if (dem_sohoadon_n1n2(dsnv, n1, n2) == 0) return;
	int trangmax = 1;
	int tranghientai = 1;
	if (dem_sohoadon_n1n2(dsnv, n1, n2) == 0) trangmax = 1;
	if (dem_sohoadon_n1n2(dsnv, n1, n2) > 0 && dem_sohoadon_n1n2(dsnv, n1, n2) % 8 == 0) trangmax = dem_sohoadon_n1n2(dsnv, n1, n2) / 8;
	else trangmax = dem_sohoadon_n1n2(dsnv, n1, n2) / 8 + 1;
	if (dem_sohoadon_n1n2(dsnv, n1, n2) == 0) tranghientai = 1;
	if (dem_sohoadon_n1n2(dsnv, n1, n2) > 0 && dem_sohoadon_n1n2(dsnv, n1, n2) % 8 == 0) tranghientai = dem_sohoadon_n1n2(dsnv, n1, n2) / 8;
	else tranghientai = dem_sohoadon_n1n2(dsnv, n1, n2) / 8 + 1;
	int sl;
	if (tranghientai == trangmax)
	{
		sl = dem_sohoadon_n1n2(dsnv, n1, n2) % 8;
	}
	else sl = 8;
	int j = (tranghientai - 1) * 8;
	in_1_trang_lk_hoadon(tranghientai, sl, trangmax, j, dsnv, n1, n2);

	POINT point;
	while (1)
	{
		GetCursorPos(&point);
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 700 && point.x <= 780 && point.y >= 710 && point.y <= 740 && tranghientai < trangmax)
		{
			tranghientai++;
			if (tranghientai == trangmax)
			{
				sl = dem_sohoadon_n1n2(dsnv, n1, n2) % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang_lk_hoadon(tranghientai, sl, trangmax, j, dsnv, n1, n2);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 500 && point.x <= 580 && point.y >= 710 && point.y <= 740 && tranghientai > 1)
		{
			tranghientai--;
			if (tranghientai == trangmax)
			{
				sl = dem_sohoadon_n1n2(dsnv, n1, n2) % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang_lk_hoadon(tranghientai, sl, trangmax, j, dsnv, n1, n2);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 120 && point.x <= 240 && point.y >= 260 && point.y <= 290)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 210 && point.y <= 240)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 50 && point.x <= 230 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 250 && point.x <= 430 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 450 && point.x <= 630 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 100 && point.x <= 1100 && point.y >= 70 && point.y <= 120)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 160 && point.y <= 190) break;

	}
}

void thong_ke_hoadon(list_nv dsnv)
{
	setbkcolor(0);
	setcolor(15);
	khung_in_hoadontheongay();
	Ngay n1;
	Ngay n2;
	bool checkngay = false;
	//====TAO KHUNG NHAP===
	setcolor(WHITE);
	setbkcolor(BLACK);
	outtextxy(490, 188, (char*)"TU NGAY: ");
	outtextxy(480, 238, (char*)"DEN NGAY: ");
	setfillstyle(SOLID_FILL, YELLOW);
	setbkcolor(0);
	bar(570, 180, 620, 210);						// NGAY
	bar(630, 180, 680, 210);						//THANG
	bar(690, 180, 760, 210);						//NAM
	bar(570, 230, 620, 260);						// NGAY
	bar(630, 230, 680, 260);						//THANG
	bar(690, 230, 760, 260);						//NAM
	//===========NHAP NGAY 1 =========
	do {
		//hienthi_nhaplai_hd();

		setfillstyle(SOLID_FILL, 6);
		setbkcolor(6);
		setcolor(15);

		int ngay, thang, nam;
		Nhap_number_int(570, 180, 620, 210, ngay);  // Nhap ngay
		n1.ngay = ngay;
		Nhap_number_int(630, 180, 680, 210, thang);   // Nhap thang
		n1.thang = thang;
		Nhap_number_int(690, 180, 760, 210, nam);   // Nhap nam
		n1.nam = nam;

		checkngay = CheckNgayThangNam(n1);
		if (!checkngay) {
			hienthi_nhaplai_hd();
			// Hien thi thong bao loi
			//setfillstyle(SOLID_FILL, 6);
			//setbkcolor(RED);
			//outtextxy(820, 148, (char*)"NGAY THANG NAM KHONG HOP LE");
			delay(1000); // Delay de thay thong bao loi
		}

	} while (!checkngay);
	xoa_hienthi_nhaplai_hd();
	setcolor(WHITE);
	line(800, 150, 1300, 150);
	//======NHAP NGAY 2==========
	checkngay = false;
	do {
		//hienthi_nhaplai_hd();

		setfillstyle(SOLID_FILL, 6);
		setbkcolor(6);
		setcolor(15);

		int ngay, thang, nam;
		Nhap_number_int(570, 230, 620, 260, ngay);  // Nhap ngay
		n2.ngay = ngay;
		Nhap_number_int(630, 230, 680, 260, thang);   //  Nhap thang
		n2.thang = thang;
		Nhap_number_int(690, 230, 760, 260, nam);   // Nhap nam
		n2.nam = nam;

		checkngay = CheckNgayThangNam(n2);
		if (!checkngay) {
			hienthi_nhaplai_hd();
			// Hien thi thong bao loi
			//setfillstyle(SOLID_FILL, 6);
			//setbkcolor(RED);
			//outtextxy(820, 148, (char*)"NGAY THANG NAM KHONG HOP LE");
			delay(1000); // Delay de thay thong bao loi
		}

	} while (!checkngay);
	xoa_hienthi_nhaplai_hd();
	line(800, 150, 1300, 150);

	//=============================
	in_thongkehoadon(dsnv, n1, n2);
	if (dem_sohoadon_n1n2(dsnv, n1, n2) == 0)
	{
		setfillstyle(SOLID_FILL, RED);
		setbkcolor(RED);
		setcolor(15);
		bar(800, 140, 1110, 170);
		outtextxy(870, 148, (char*)"KHONG CO HOA DON NAO");
		setfillstyle(SOLID_FILL, 6);
		setbkcolor(6);
		setcolor(15);
	}
}

//=================================================
void in_ct_vattu(Vattu* vt, int y)
{
	setfillstyle(SOLID_FILL, YELLOW);
	setbkcolor(0);
	setcolor(15);
	outtextxy(180, y + 13, (char*)vt->MAVT.c_str());
	outtextxy(600, y + 13, (char*)vt->TENVT.c_str());
	in_number(1050, y + 13, vt->SoLuongTon);
}


void in_1_trang_vattu(int pos_trang, int sl, int sotrang, int j, DS_VATTU dsvt)
{
	Vattu** arrvt = new Vattu * [dsvt.sl];
	int temp = 0;
	Duyet_LNR(dsvt.root, arrvt, temp);
	khung_in_vattu();
	for (int i = 340; i <= 660; i += 40)
	{
		in_ct_vattu(arrvt[j], i);
		j++;
		if (j % 8 == sl || j == pos_trang * 8) break;
	}
	/*outtextxy(620, 688, (char*)to_string(pos_trang).c_str());*/
	setfillstyle(SOLID_FILL, BLACK);
	bar(620, 680, 690, 710);
	in_number(620, 688, (float)pos_trang);
	outtextxy(640, 688, (char*)"/");
	in_number(660, 688, (float)sotrang);
	/*outtextxy(660, 688, (char*)to_string(sotrang).c_str());*/
}

void in_ds_vattu(DS_VATTU& dsvt)
{
	if (dsvt.root == NULL) return;
	int trangmax = 1;
	int tranghientai = 1;
	if (dsvt.sl == 0) trangmax = 1;
	if (dsvt.sl > 0 && dsvt.sl % 8 == 0) trangmax = dsvt.sl / 8;
	else trangmax = dsvt.sl / 8 + 1;
	if (dsvt.sl == 0) tranghientai = 1;
	if (dsvt.sl > 0 && dsvt.sl % 8 == 0) tranghientai = dsvt.sl / 8;
	else tranghientai = dsvt.sl / 8 + 1;
	int sl;
	if (tranghientai == trangmax)
	{
		sl = dsvt.sl % 8;
	}
	else sl = 8;
	int j = (tranghientai - 1) * 8;
	in_1_trang_vattu(tranghientai, sl, trangmax, j, dsvt);
	POINT point;
	while (1)
	{
		GetCursorPos(&point);
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 700 && point.x <= 780 && point.y >= 710 && point.y <= 740 && tranghientai < trangmax)
		{
			tranghientai++;
			if (tranghientai == trangmax)
			{
				sl = dsvt.sl % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang_vattu(tranghientai, sl, trangmax, j, dsvt);
			delay(50);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 500 && point.x <= 580 && point.y >= 710 && point.y <= 740 && tranghientai > 1)
		{
			tranghientai--;
			if (tranghientai == trangmax)
			{
				sl = dsvt.sl % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang_vattu(tranghientai, sl, trangmax, j, dsvt);
			delay(50);
		}

		if (GetAsyncKeyState(VK_RBUTTON)) break;
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 210 && point.y <= 240)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 50 && point.x <= 230 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 250 && point.x <= 430 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 450 && point.x <= 630 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 100 && point.x <= 1100 && point.y >= 70 && point.y <= 120)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 160 && point.y <= 190) break;

	}
}
//===============================================-=
void in_ct_nhanvien(Nhanvien* nv, int y)
{
	setfillstyle(SOLID_FILL, YELLOW);
	setbkcolor(0);
	setcolor(15);
	outtextxy(180, y + 13, (char*)nv->MANV.c_str());
	string hoten = nv->HO + " " + nv->TEN;
	outtextxy(600, y + 13, (char*)hoten.c_str());
	outtextxy(1050, y + 13, (char*)nv->PHAI.c_str());
}


void in_1_trang_nhanvien(int pos_trang, int sl, int sotrang, int j, list_nv dsnv)
{
	khung_in_nhanvien();
	for (int i = 340; i <= 660; i += 40)
	{
		in_ct_nhanvien(dsnv.dsnv[j], i);
		j++;
		if (j % 8 == sl || j == pos_trang * 8) break;
	}
	outtextxy(620, 688, (char*)to_string(pos_trang).c_str());
	outtextxy(640, 688, (char*)"/");
	outtextxy(660, 688, (char*)to_string(sotrang).c_str());
}

void in_ds_nhanvien(list_nv dsnv)
{
	if (dsnv.sl == 0) return;
	int trangmax = 1;
	int tranghientai = 1;
	if (dsnv.sl == 0) trangmax = 1;
	if (dsnv.sl > 0 && dsnv.sl % 8 == 0) trangmax = dsnv.sl / 8;
	else trangmax = dsnv.sl / 8 + 1;
	if (dsnv.sl == 0) tranghientai = 1;
	if (dsnv.sl > 0 && dsnv.sl % 8 == 0) tranghientai = dsnv.sl / 8;
	else tranghientai = dsnv.sl / 8 + 1;
	int sl;
	if (tranghientai == trangmax)
	{
		sl = dsnv.sl % 8;
	}
	else sl = 8;
	int j = (tranghientai - 1) * 8;
	in_1_trang_nhanvien(tranghientai, sl, trangmax, j, dsnv);
	POINT point;
	while (1)
	{
		GetCursorPos(&point);
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 700 && point.x <= 780 && point.y >= 710 && point.y <= 740 && tranghientai < trangmax)
		{
			tranghientai++;
			if (tranghientai == trangmax)
			{
				sl = dsnv.sl % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang_nhanvien(tranghientai, sl, trangmax, j, dsnv);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 500 && point.x <= 580 && point.y >= 710 && point.y <= 740 && tranghientai > 1)
		{
			tranghientai--;
			if (tranghientai == trangmax)
			{
				sl = dsnv.sl % 8;
			}
			else sl = 8;
			int j = (tranghientai - 1) * 8;
			in_1_trang_nhanvien(tranghientai, sl, trangmax, j, dsnv);
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 120 && point.x <= 240 && point.y >= 260 && point.y <= 290)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 210 && point.y <= 240)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 50 && point.x <= 230 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 250 && point.x <= 430 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 450 && point.x <= 630 && point.y >= 130 && point.y <= 160)
		{

			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 100 && point.x <= 1100 && point.y >= 70 && point.y <= 120)
		{
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 160 && point.y <= 190) break;
		if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 120 && point.x <= 240 && point.y >= 210 && point.y <= 240) break;
	}
}
//===================================================

void Nhapcthd_DH(string loai, DS_VATTU dsvt, CT_HOADON& cthd)
{
	setfillstyle(SOLID_FILL, 6);
	setbkcolor(6);
	setcolor(15);
	string str;
	float n = 0;
	if (loai == "X") cthd.Trangthai = true;
	in_ds_vattu(dsvt);
	setbkcolor(6);
	setcolor(15);
	Nhap_string(120, 240, 240, 270, str);  //Nhap MA VT
	cthd.MAVT = str;
	Vattu* temp = check_trung(dsvt.root, cthd.MAVT);

	while (temp == NULL || temp->SoLuongTon == 0) {
		if (temp == NULL) {
			tao_button(800, 140, 1110, 170, "", WHITE, RED);
			setbkcolor(RED);
			outtextxy(820, 148, (char*)"MA VAT TU KHONG TON TAI, NHAP LAI");
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			Nhap_string(120, 240, 240, 270, str);  //Nhap MA VT
			cthd.MAVT = str;
			temp = check_trung(dsvt.root, cthd.MAVT);
		}
		else if (loai == "N")
		{
			break;
		}
		else
		{
			tao_button(800, 140, 1110, 170, "", WHITE, RED);
			setbkcolor(RED);
			outtextxy(820, 148, (char*)"VAT TU HIEN HET HANG, NHAP LAI");
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			Nhap_string(120, 240, 240, 270, str);  //Nhap MA VT
			cthd.MAVT = str;
			temp = check_trung(dsvt.root, cthd.MAVT);
		}
	}
	bar(340, 240, 520, 270);
	//Vattu* temp = check_trung(dsvt.root, cthd.MAVT);
	outtextxy(360, 248, (char*)temp->TENVT.c_str());
	xoa_hienthi_nhaplai_hd();



	Nhap_number_float(640, 240, 730, 270, n);  //Nhap SO LUONG
	cthd.Soluong = n;
	while (true) {
		if (!cap_nhat_slt_nv(dsvt.root, loai, cthd)) {
			tao_button(800, 140, 1110, 170, "", WHITE, RED);
			setbkcolor(RED);
			outtextxy(805, 148, (char*)"SO LUONG TON KHONG DU, CON LAI ");
			in_number(1050, 148, temp->SoLuongTon);
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			Nhap_number_float(640, 240, 730, 270, n);  //Nhap SO LUONG
			cthd.Soluong = n;
		}
		else if (cthd.Soluong <= 0) {
			tao_button(800, 140, 1110, 170, "", WHITE, RED);
			setbkcolor(RED);
			outtextxy(805, 148, (char*)"NHAP SO LUONG LON HON 0 ");
			//in_number(1050, 148, temp->SoLuongTon);
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			Nhap_number_float(640, 240, 730, 270, n);  //Nhap SO LUONG
			cthd.Soluong = n;
		}
		else {
			break;
		}
	}

	xoa_hienthi_nhaplai_hd();

	n = 0;
	Nhap_number_float(840, 240, 930, 270, n);   // Nhap don gia
	cthd.Dongia = n;
	if (cthd.Dongia <= 0)
	{
		do
		{
			hienthi_nhaplai_hd();
			Nhap_number_float(840, 240, 930, 270, n);
			cthd.Dongia = n;
		} while (n <= 0);
	}
	xoa_hienthi_nhaplai_hd();
	n = 0;
	Nhap_number_float(1030, 240, 1120, 270, n);  //Nhap VAT
	cthd.VAT = n;
	if (cthd.VAT < 0 || cthd.VAT > 100)
	{
		do
		{
			hienthi_nhaplai_hd();
			Nhap_number_float(1030, 240, 1120, 270, n);  //Nhap VAT
			cthd.VAT = n;
		} while (n < 0 || n > 100);
	}
	xoa_hienthi_nhaplai_hd();
	cthd.Trangthai = 1;
	//delete temp;
}

void Nhap_node_cthd_DH(nodecthd*& Nodecthd, DS_VATTU& dsvt, string loai)
{
	//int y = 340;
	Nodecthd = NULL;
	CT_HOADON cthd;
	while (1)
	{
		Nhapcthd_DH(loai, dsvt, cthd);
		while (1)
		{
			POINT point;
			GetCursorPos(&point);
			if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 260 && point.y <= 290) break;
		}
		themvaocuoinode(Nodecthd, cthd);
		Khung_nhap_cthd();

		//---in cthd vua nhap ra man hinh---
		in_node_cthd(Nodecthd, dsvt);

		//in_tongtien(Nodecthd);
		while (1)
		{
			POINT point;
			GetCursorPos(&point);
			if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 120 && point.x <= 240 && point.y >= 260 && point.y <= 290) break;

			if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 210 && point.y <= 240)
			{
				//khungnhaphd();
				xoatoanmanhinh();
				return;
			}
			if (GetAsyncKeyState(VK_LBUTTON) && point.x >= 1200 && point.x <= 1290 && point.y >= 160 && point.y <= 190)
			{
				//==XOA KHUNG NHAP HD
				setfillstyle(SOLID_FILL, BLACK);
				bar(40, 231, 1310, 281);
				//===TAO KHUNG NHAP MA VT CAN XOA====
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(590, 230, (char*)"MA VAT TU");
				rectangle(520, 231, 760, 280);
				setfillstyle(SOLID_FILL, YELLOW);
				bar(530, 250, 750, 279);
				string mavt;
				Nhap_string(530, 250, 750, 279, mavt);
				XoaCT_Hoadon_nv(Nodecthd, mavt, dsvt, loai);
				//==XOA KHUNG NHAP HD
				setfillstyle(SOLID_FILL, BLACK);
				bar(40, 231, 1310, 281);
				bar(30, 300, 1310, 760);
				setfillstyle(SOLID_FILL, YELLOW);
				Khung_nhap_cthd();
				khungincthd();
				setbkcolor(BLACK);
				setcolor(WHITE);
				in_node_cthd(Nodecthd, dsvt);
			}

		}
	}
}

void Nhap_hoadon_DH(HOADON& hoadon, DS_VATTU& dsvt)
{

	//=====TU DONG CAP NHAT SO HD=====
	hoadon.SoHD = tao_ma_hd();
	bar(700, 190, 800, 220);
	setcolor(BLACK);
	outtextxy(730, 198, (char*)hoadon.SoHD.c_str());
	setcolor(WHITE);
	NhapNgay_DH(hoadon.NgaylapHD);
	Nhap_node_cthd_DH(hoadon.dscthd, dsvt, hoadon.loai);
}

nodehd* tim_hoa_don(list_nv dsnv, string sohd)
{
	nodehd* t = NULL;
	for (int i = 0; i < dsnv.sl; i++)
	{
		t = dsnv.dsnv[i]->dshd;
		while (t != NULL)
		{
			if (t->hoadon.SoHD == sohd)
			{
				return t;
			}
			t = t->next;
		}
	}
	return NULL;
}

Nhanvien* tim_nhan_vien(list_nv dsnv, string sohd)
{
	nodehd* t = NULL;
	for (int i = 0; i < dsnv.sl; i++)
	{
		t = dsnv.dsnv[i]->dshd;
		while (t != NULL)
		{
			if (t->hoadon.SoHD == sohd)
			{
				return dsnv.dsnv[i];
			}
			t = t->next;
		}
	}
	return NULL;
}

void Trahang_DH(list_nv dsnv, string sohd, DS_VATTU& dsvt)
{
	//========NHAP SO HD======
	//in_hoadon_DH(sohd, dsnv);
	setcolor(WHITE);
	setbkcolor(6);
	Nhap_string(530, 180, 750, 209, sohd);
	nodehd* t = tim_hoa_don(dsnv, sohd);
	Nhanvien* nv = tim_nhan_vien(dsnv, sohd);
	if (t == NULL)
	{
		xoatoanmanhinh();
		setfillstyle(SOLID_FILL, RED);
		bar(550, 400, 800, 450);
		setbkcolor(RED);
		setcolor(WHITE);
		outtextxy(570, 418, (char*)"MA HOA DON KHONG TON TAI");
	}
	else if (t->hoadon.loai == "X")
	{
		HOADON Hoadon = t->hoadon;
		if (khoangcach2ngay(Hoadon.NgaylapHD, ngayhientai()) >= 0 && khoangcach2ngay(Hoadon.NgaylapHD, ngayhientai()) <= 3)
		{
			setbkcolor(BLACK);
			setcolor(WHITE);
			in_thongtin_hoadon(nv, Hoadon);
			in_node_cthd(Hoadon.dscthd, dsvt);

			//in_hoadon_DH(sohd, dsnv);
			//setfillstyle(SOLID_FILL, 6);
			string mavt;
			//setcolor(WHITE);
			//setbkcolor(6);	setbkcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);

			bar(519, 161, 759, 179);
			outtextxy(590, 160, (char*)"MA VAT TU");
			rectangle(520, 160, 760, 210);
			setfillstyle(SOLID_FILL, YELLOW);
			bar(530, 180, 750, 209);
			setcolor(WHITE);
			setbkcolor(6);
			Nhap_string(530, 180, 750, 209, mavt);
			nodecthd* temp = Hoadon.dscthd;
			while (temp != NULL)
			{
				if (temp->cthd.MAVT == mavt)
				{
					temp->cthd.Trangthai = 0;
					cap_nhat_slt_nv_trahang(dsvt.root, temp->cthd);
				}
				temp = temp->next;
			}
			setbkcolor(BLACK);
			setcolor(WHITE);
			in_node_cthd(Hoadon.dscthd, dsvt);
		}
		else
		{
			xoatoanmanhinh();
			setfillstyle(SOLID_FILL, RED);
			bar(550, 400, 850, 450);
			setbkcolor(RED);
			setcolor(WHITE);
			outtextxy(570, 418, (char*)"HOA DON DA QUA HAN TRA HANG");
		}
	}
	else
	{
		xoatoanmanhinh();
		setfillstyle(SOLID_FILL, RED);
		bar(550, 400, 850, 450);
		setbkcolor(RED);
		setcolor(WHITE);
		outtextxy(570, 418, (char*)"KHONG THE TRA HANG HOA DON NHAP");
	}
}

void Nhap_node_hoadon_DH(DS_VATTU& dsvt, list_nv dsnv)
{
	HOADON hoadon;
	bool thoat_ham = false;
	luachon(hoadon, thoat_ham);
	if (thoat_ham == true) return;
	POINT mouse;
	string str;
	Nhanvien* nv = new Nhanvien;
	if (hoadon.loai == "N" || hoadon.loai == "X")
	{
		while (1)
		{
			setbkcolor(BLACK);
			setcolor(WHITE);
			in_ds_nhanvien(dsnv);
			setfillstyle(SOLID_FILL, 6);
			setbkcolor(6);
			Nhap_string(120, 190, 240, 220, str);
			nv->MANV = str;
			if (kt_ma_nv(dsnv, nv->MANV) == NULL)
			{
				do
				{
					tao_button(800, 140, 1110, 170, "", WHITE, RED);
					setbkcolor(RED);
					outtextxy(820, 148, (char*)"MA NHAN VIEN KHONG TON TAI, NHAP LAI");
					setfillstyle(SOLID_FILL, 6);
					setbkcolor(6);
					Nhap_string(120, 190, 240, 220, str);
					nv->MANV = str;
				} while (kt_ma_nv(dsnv, nv->MANV) == NULL);
			}
			xoa_hienthi_nhaplai_hd();
			//===TU DONG CAP NHAT TEN NV====
			string tennv = kt_ma_nv(dsnv, nv->MANV)->HO + " " + kt_ma_nv(dsnv, nv->MANV)->TEN;
			setfillstyle(SOLID_FILL, 6);
			bar(380, 190, 600, 220);
			setcolor(BLACK);
			outtextxy(400, 198, (char*)tennv.c_str());
			setcolor(WHITE);
			kt_ma_nv(dsnv, nv->MANV);
			Nhap_hoadon_DH(hoadon, dsvt);
			themvaocuoinodehd(kt_ma_nv(dsnv, nv->MANV)->dshd, hoadon);
			while (1)
			{
				GetCursorPos(&mouse);
				if (GetAsyncKeyState(VK_LBUTTON) && mouse.x >= 100 && mouse.x <= 1100 && mouse.y >= 70 && mouse.y <= 120)
				{
					xoatoanmanhinh();
					return;
				}


			}
			luachon(hoadon, thoat_ham);
		}
	}
	if (hoadon.loai == "IN")
	{
		string sohd;
		in_hoadon_DH(sohd, dsnv, dsvt);
	}
	if (hoadon.loai == "TRA")
	{
		setbkcolor(BLACK);
		setcolor(WHITE);
		outtextxy(870, 175, (char*)"SO HOA DON HIEN TAI: ");
		in_number(1030, 175, mahdcu);
		string sohd;
		Trahang_DH(dsnv, sohd, dsvt);
	}

	//else
	//{
	//	//string sohd;
	//	//in_hoadon_DH(sohd,dsnv);
	//}
	delete nv;


}





void main_hoadon(DS_VATTU& dsvt, list_nv& Dsnv)
{
	xoatoanmanhinh();
	khung_vt_nv_hd();
	khunglcnhapxuathd();
	POINT point;
	while (1)
	{
		//break;
		GetCursorPos(&point);
		if (GetAsyncKeyState(VK_LBUTTON) && ((point.x >= 851 && point.x <= 1140) || (point.x >= 100 && point.x <= 600)) && point.y >= 70 && point.y <= 130)
		{
			khung_vt_nv_hd();
			tao_button(601, 50, 850, 100, "HOA DON", 0, 11);
			break;
		}
		if (GetAsyncKeyState(VK_LBUTTON) && ((point.x >= 50 && point.x <= 230) || (point.x >= 250 && point.x <= 430) ||
			(point.x >= 450 && point.x <= 630) || (point.x >= 650 && point.x <= 830)) && point.y >= 130 && point.y <= 160)
		{
			Nhap_node_hoadon_DH(dsvt, Dsnv);
		}
		delay(50);
	}
}


