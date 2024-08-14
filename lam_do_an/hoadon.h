#ifndef HOADON_H_INCLUDED
#define HOADON_H_INCLUDED

#pragma once

#include<iostream>
#include"khaibao.h"
#include"chuanhoa.h"
#include"vattu.h"
using namespace std;
int mahdcu = 0;

void NhapNgay(Ngay& NGAY);
void inngay(Ngay NGAY);
void Nhapcthoadon(CT_HOADON& cthd);
void themvaodaunode(nodecthd*& Nodecthd, CT_HOADON& cthd);
void themvaocuoinode(nodecthd*& Nodecthd, CT_HOADON& cthd);
void XoaCT_Hoadon(nodecthd*& Nodecthd, string s);
void Nhapnodecthoadon(nodecthd*& Nodecthd);
void incthd(CT_HOADON cthd);
void innodecthoadon(nodecthd* Nodecthd);
void Nhaphoadon(HOADON& hoadon);
void inhoadon(HOADON hoadon);
int Soluongnodecthd(nodecthd* Nodecthd);
void innodehd(nodehd* Nodehd);
void Nhapnodehd(nodehd*& Nodehd);
void Xoanodehd(nodehd*& Nodehd, string s);
int Soluongnodehd(nodehd* Nodehd);
void print_dshd(nodehd* dshd);

void xoa_bonho_nodecthd(nodecthd* Nodecthd)
{
	nodecthd* temp = Nodecthd;
	nodecthd* nodenext = NULL;
	while (temp != NULL)
	{
		nodenext = temp->next;
		delete temp;
		temp = nodenext;
	}
}

void xoa_bonho_nodehd(nodehd* Nodehd)
{
	nodehd* temp = Nodehd;
	nodehd* nodenext = NULL;
	while (temp != NULL)
	{
		nodenext = temp->next;
		delete temp;
		temp = nodenext;
	}
}

string dinh_dang_date(Ngay NGAY)
{
	string date = "";
	if (NGAY.ngay < 10) date = "0" + to_string(NGAY.ngay) + '/';
	else date = to_string(NGAY.ngay) + '/';
	if (NGAY.thang < 10) date += ("0" + to_string(NGAY.thang) + '/');
	else date += (to_string(NGAY.thang) + '/');
	date += to_string(NGAY.nam);
	return date;
}

nodecthd* newnodecthd(CT_HOADON x)
{
	nodecthd* temp = new nodecthd;
	temp->cthd = x;
	temp->next = NULL;
	return temp;
}

nodecthd* addnodecthd(nodecthd* Nodecthd, CT_HOADON cthd)
{
	nodecthd* temp = newnodecthd(cthd);
	Nodecthd->next = temp;
	return temp;
}

void themvaodaunode(nodecthd*& Nodecthd, CT_HOADON& cthd)
{
	nodecthd* temp = newnodecthd(cthd);
	if (Nodecthd == NULL)
	{
		Nodecthd = temp;
	}
	else
	{
		temp->next = Nodecthd;
		Nodecthd = temp;
	}
}

void themvaocuoinode(nodecthd*& Nodecthd, CT_HOADON& cthd)
{
	nodecthd* temp = newnodecthd(cthd);
	nodecthd* t = Nodecthd;
	if (Nodecthd == NULL)
	{
		Nodecthd = temp;
	}
	else
	{
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
}


void Xoanodedau(nodecthd*& Nodecthd)
{
	if (Nodecthd == NULL)
	{
		return;
	}
	else
	{
		Nodecthd = Nodecthd->next;
	}
}

void Xoanodecuoi(nodecthd*& Nodecthd) {
	if (Nodecthd == NULL)
	{
		return;
	}
	else
	{
		nodecthd* truoc = NULL;
		nodecthd* sau = Nodecthd;
		while (sau->next != NULL)
		{
			truoc = sau;
			sau = sau->next;
		}
		if (truoc == NULL)
		{
			Nodecthd = NULL;
		}
		else
		{
			truoc->next = NULL;
		}
	}
}

void Xoanodegiua(nodecthd*& Nodecthd, int vt)
{
	nodecthd* truoc = NULL;
	nodecthd* sau = Nodecthd;
	for (int i = 1; i < vt; i++)
	{
		truoc = sau;
		sau = sau->next;
	}
	truoc->next = sau->next;
}

void XoaCT_Hoadon_nv(nodecthd*& Nodecthd, string s, DS_VATTU& dsvt, string loai)
{
	int cnt = 0;
	if (Nodecthd == NULL)
	{
		cout << "HOA DON RONG!";
	}
	else
	{
		nodecthd* temp = Nodecthd;
		while (temp != NULL)
		{
			cnt++;
			if (s == temp->cthd.MAVT)
			{
				if (cnt == 1)
				{
					cap_nhat_slt_nv_xoa(dsvt.root, loai, temp->cthd);
					Xoanodedau(Nodecthd);
					break;
				}
				else if (cnt == Soluongnodecthd(Nodecthd))
				{
					cap_nhat_slt_nv_xoa(dsvt.root, loai, temp->cthd);
					Xoanodecuoi(Nodecthd);
					break;
				}
				else
				{
					cap_nhat_slt_nv_xoa(dsvt.root, loai, temp->cthd);
					Xoanodegiua(Nodecthd, cnt);
					break;
				}
			}
			temp = temp->next;
		}
	}
}


// ------- TAO MA HOA DON TU DONG TANG DAN------
int laymahdmax(ifstream& filehd)
{
	int mahdmax = 0;
	filehd >> mahdmax;
	return mahdmax;
}

string tao_ma_hd() {
	mahdcu++;
	return "HD" + to_string(mahdcu);
}


float giatricthoadon(CT_HOADON cthd)
{
	//if (!cthd.Trangthai) return 0;
	return cthd.Soluong * cthd.Dongia * (1 + (float)cthd.VAT / 100);
}

float tonggiatrihoadon(nodecthd* Nodecthd)
{
	nodecthd* temp = Nodecthd;
	float tong = 0;
	while (temp != NULL)
	{
		if (temp->cthd.Trangthai == true)
		{
			tong = tong + giatricthoadon(temp->cthd);
		}
		temp = temp->next;
	}
	return tong;
}

int Soluongnodecthd(nodecthd* Nodecthd)
{
	int dem = 0;
	while (Nodecthd != NULL)
	{
		dem++;
		Nodecthd = Nodecthd->next;
	}
	return dem;
}

nodehd* newnodehd(HOADON hoadon)
{
	nodehd* temp = new nodehd;
	temp->hoadon = hoadon;
	temp->next = NULL;
	return temp;
}

void themvaodaunodehd(nodehd*& Nodehd, HOADON hoadon)
{
	nodehd* temp = newnodehd(hoadon);
	if (Nodehd == NULL)
	{
		Nodehd = temp;
	}
	else
	{
		temp->next = Nodehd;
		Nodehd = temp;
	}
}

void themvaocuoinodehd(nodehd*& Nodehd, HOADON hoadon)
{
	nodehd* temp = newnodehd(hoadon);
	if (Nodehd == NULL)
	{
		Nodehd = temp;
	}
	else
	{
		nodehd* t = Nodehd;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
}


int Soluongnodehd(nodehd* Nodehd)
{
	nodehd* temp = Nodehd;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

void Xoanodehddau(nodehd*& Nodehd)
{
	if (Nodehd == NULL) {
		return;
	}
	else
	{
		Nodehd = Nodehd->next;
	}
}

void Xoanodehdcuoi(nodehd*& Nodehd)
{
	if (Nodehd == NULL)
	{
		return;
	}
	else
	{
		nodehd* truoc = NULL;
		nodehd* sau = Nodehd;
		while (sau->next != NULL)
		{
			truoc = sau;
			sau = sau->next;
		}
		if (truoc->next == NULL)
		{
			Nodehd = NULL;
		}
		else
		{
			truoc->next = NULL;
		}
	}
}

void Xoanodehdgiua(nodehd*& Nodehd, int vt)
{
	if (Nodehd == NULL) {
		return;
	}
	nodehd* truoc = NULL;
	nodehd* sau = Nodehd;
	for (int i = 1; i < vt; i++)
	{
		truoc = sau;
		sau = sau->next;
	}
	if (truoc->next == NULL)
	{
		Nodehd = NULL;
	}
	else
	{
		truoc->next = sau->next;
	}
}

void Xoanodehd(nodehd*& Nodehd, string s)
{
	int cnt = 0;
	nodehd* temp = Nodehd;
	while (temp != NULL)
	{
		cnt++;
		if (temp->hoadon.SoHD == s)
		{
			if (cnt == 1)
			{
				Xoanodehddau(Nodehd);
			}
			else if (cnt == Soluongnodehd(Nodehd))
			{
				Xoanodehdcuoi(Nodehd);
			}
			else
			{
				Xoanodehdgiua(Nodehd, cnt);
			}
		}
		temp = temp->next;
	}
}



void Doc_file_hd(nodehd*& Nodehd, ifstream& filehd) {
	int slhd;
	filehd >> slhd;
	int slcthd;
	HOADON hdtemp;
	CT_HOADON cthdtemp;
	char x;
	for (int i = 0; i < slhd; i++)
	{
		filehd.ignore();
		getline(filehd, hdtemp.SoHD, ',');
		filehd >> hdtemp.NgaylapHD.ngay;
		filehd >> hdtemp.NgaylapHD.thang;
		filehd >> hdtemp.NgaylapHD.nam;
		filehd >> x;
		getline(filehd, hdtemp.loai);
		filehd >> slcthd;
		hdtemp.dscthd = NULL;
		for (int i = 0; i < slcthd; i++)
		{
			filehd.ignore();
			getline(filehd, cthdtemp.MAVT, ',');
			//filehd >> cthdtemp.MAVT;
			filehd >> cthdtemp.Soluong;
			filehd >> cthdtemp.Dongia;
			filehd >> cthdtemp.VAT;
			filehd >> x;
			filehd >> cthdtemp.Trangthai;
			themvaocuoinode(hdtemp.dscthd, cthdtemp);
		}
		themvaocuoinodehd(Nodehd, hdtemp);
	}
}

void Ghi_file_hd(nodehd* Nodehd, ofstream& filehd)
{
	filehd << Soluongnodehd(Nodehd) << endl;
	nodehd* temphd = Nodehd;
	while (temphd != NULL)
	{
		filehd << temphd->hoadon.SoHD << ",";
		filehd << temphd->hoadon.NgaylapHD.ngay << " ";
		filehd << temphd->hoadon.NgaylapHD.thang << " ";
		filehd << temphd->hoadon.NgaylapHD.nam << ",";
		filehd << temphd->hoadon.loai << endl;
		nodecthd* tempcthd = temphd->hoadon.dscthd;
		filehd << Soluongnodecthd(temphd->hoadon.dscthd) << endl;
		while (tempcthd != NULL)
		{
			filehd << tempcthd->cthd.MAVT << ",";
			filehd << tempcthd->cthd.Soluong << " ";
			filehd << tempcthd->cthd.Dongia << " ";
			filehd << tempcthd->cthd.VAT << ",";
			filehd << tempcthd->cthd.Trangthai << endl;
			tempcthd = tempcthd->next;
		}
		temphd = temphd->next;
	}
}


#endif // HOADON_H_INCLUDED