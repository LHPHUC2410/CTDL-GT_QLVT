#pragma once
#include <iostream>
#include "khaibao.h"
#include <cstdlib>
#include <ctime>
#include "hoadon.h"
#include <fstream>
using namespace std;
string ma_nv()
{
    srand(time(NULL));
    int tmp = rand() % 500 + 1;
    string Manv = string(3 - to_string(tmp).size(), '0') + to_string(tmp);
    return Manv;
}
Nhanvien* kt_ma_nv(list_nv dsnv, string ma)
{
    for (int i = 0; i < dsnv.sl; i++)
    {
        if (ma.compare(dsnv.dsnv[i]->MANV) == 0) return dsnv.dsnv[i];
    }
    return NULL;
}
bool check_manv_trung(list_nv Listnv, string ma)
{
    for (int i = 0; i < Listnv.sl; i++)
    {
        if (ma == Listnv.dsnv[i]->MANV) return true;
    }
    return false;
}
void sort_nv(list_nv& dsnv)
{
    string s1, s2;
    for (int i = 0; i < dsnv.sl - 1; i++)
    {
        s1 = dsnv.dsnv[i]->TEN + " ";
        s1 += dsnv.dsnv[i]->HO;
        for (int j = i + 1; j < dsnv.sl; j++)
        {
            s2 = dsnv.dsnv[j]->TEN + " ";
            s2 += dsnv.dsnv[j]->HO;
            if (s2.compare(s1)<0)
            {
                Nhanvien tmp = *dsnv.dsnv[i];
                *dsnv.dsnv[i] = *dsnv.dsnv[j];
                *dsnv.dsnv[j] = tmp;
                s1 = s2;
            }
        }
    }
}
bool check_nhap_hoten_nv(string s)
{
    if (s.empty() == true) return false;
    bool check = false;
    for (int i = 0; i < s.size(); i++) if (s[i] != ' ') check = true;
    if (check == false) return check;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        if ((s[i] < 'a' || s[i] > 'z') && s[i] != ' ') return false;
    }
    return true;
}

bool check_n1_den_n2(Ngay n1, Ngay n2, Ngay ngay_lap_hd)
{
    bool check_n1 = false, check_n2 = false;
    if (n1.nam < ngay_lap_hd.nam) check_n1 = true;
    else if (n1.nam == ngay_lap_hd.nam)
    {
        if (n1.thang < ngay_lap_hd.thang) check_n1 = true;
        else if (n1.thang == ngay_lap_hd.thang && n1.ngay <= ngay_lap_hd.ngay) check_n1 = true;
    }
    if (n2.nam > ngay_lap_hd.nam) check_n2 = true;
    else if (n2.nam == ngay_lap_hd.nam)
    {
        if (n2.thang > ngay_lap_hd.thang) check_n2 = true;
        else if (n2.thang == ngay_lap_hd.thang && n2.ngay >= ngay_lap_hd.ngay) check_n2 = true;
    }
    if (check_n1 == true && check_n2 == true) return true;
    return false;
}
void giai_phong_nv(list_nv& dsnv)
{
    for (int i = 0; i < dsnv.sl; i++)
    {
        delete dsnv.dsnv[i];
    }
}
void doc_file_nv (list_nv &dsnv)
{
    ifstream fileinnv;
    fileinnv.open("Listnv.txt", ios_base::in);
    fileinnv >> dsnv.sl;
    mahdcu = laymahdmax(fileinnv);
    for (int i = 0; i < dsnv.sl; i++)
    {
        fileinnv.ignore();
        dsnv.dsnv[i] = new Nhanvien;
        getline(fileinnv, dsnv.dsnv[i]->HO, ','); fileinnv.seekg(1, ios::cur);
        getline(fileinnv,dsnv.dsnv[i]->TEN, ','); fileinnv.seekg(1, ios::cur);
        getline(fileinnv, dsnv.dsnv[i]->PHAI, ','); fileinnv.seekg(1, ios::cur);
        fileinnv >> dsnv.dsnv[i]->MANV;
        Doc_file_hd(dsnv.dsnv[i]->dshd, fileinnv);
    }
    fileinnv.close();
}
void ghi_file_nv(list_nv dsnv)
{
    if (dsnv.sl == 0) return;
    ofstream fileoutnv;
    fileoutnv.open("Listnv.txt", ios_base::trunc);
    fileoutnv << dsnv.sl << " " << mahdcu << endl;
    for (int i = 0; i < dsnv.sl; i++)
    {  
        fileoutnv << dsnv.dsnv[i]->HO << ", ";
        fileoutnv << dsnv.dsnv[i]->TEN << ", ";
        fileoutnv << dsnv.dsnv[i]->PHAI << ", ";
        fileoutnv << dsnv.dsnv[i]->MANV << endl;
        Ghi_file_hd(dsnv.dsnv[i]->dshd, fileoutnv);
    }
    fileoutnv.close();
}
