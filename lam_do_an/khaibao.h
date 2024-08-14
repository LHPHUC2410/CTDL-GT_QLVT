#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int max_MAVT = 10;
const int max_SoHD = 20;

struct CT_HOADON {
	string MAVT;
	int Soluong;
	long Dongia;
	int VAT;
	bool Trangthai;
    CT_HOADON()
    {
        Trangthai = 1;
    }
};
struct nodecthd{
    CT_HOADON cthd;
    nodecthd *next;
};

struct Ngay {
	int ngay, thang, nam;
	Ngay()
	{
        ngay = thang = nam = 0;
	}
};

struct HOADON {
	string SoHD;
	Ngay NgaylapHD;
	string loai;
	nodecthd* dscthd;
};

struct nodehd {
	HOADON hoadon;
	nodehd* next;
};

struct Vattu{
    //data
    string MAVT;
    string TENVT;
    string DVT;
    float SoLuongTon;
    int check_NHD;
    //pointer
    Vattu *left;
    Vattu *right;
};
typedef struct Vattu* tree;
struct DS_VATTU
{
    tree root = NULL;
    int sl = 0;
};

struct Nhanvien {
	string MANV;
	string HO;
	string TEN;
	string PHAI;
	nodehd* dshd;
    Nhanvien()
    {
        dshd=NULL;
    }
};

struct list_nv
{
    Nhanvien* dsnv[500];
    int sl;
    list_nv() {
        sl=0;
    }
};
bool chi_nhap_so(string s)
{
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            if (i == (s.size() - 1) || i == 0) return false;
            tmp++;
        }
        if ((s[i] < '0' || s[i] > '9' || tmp > 1) && s[i]!='.') return false;
    }
    return true;
}
bool kt_chuoi_rong(string s)
{
    if (s.empty() == true) return true;
    bool check = true;
    for (int i = 0; i < s.size(); i++) if (s[i] != ' ') check = false;
    if (check == true) return true;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') && s[i] != ' ') return true;
    }
    return false;
}
string chuanhoa_name(string ten)
{
    string name = "";
    for (int i = 0; i < ten.size(); i++)
    {
        if (ten[i] >= 'A' && ten[i] <= 'Z')
            ten[i] += 32;
    }
    for (int i = 0; i < ten.size(); i++)
    {
        if (i != 0 && ten[i] == ' ' && ten[i - 1] != ' ')
            name += ten[i];
        else if (ten[i] >= 'a' && ten[i] <= 'z')
            name += ten[i];
    }
    if (name[name.size() - 1] == ' ') name.pop_back();
    name[0] -= 32;
    for (int i = 1; i < name.size(); i++)
    {
        if (i != name.size() - 1 && name[i] == ' ')
            name[i + 1] -= 32;
    }
    return name;
}
