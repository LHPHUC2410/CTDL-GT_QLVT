#pragma once
#include "khaibao.h"
using namespace std;

string ma = "VT00000000";

// ===============Them vat tu=====================================================
// tao ma vat tu random -> check trùng -> nhap vat tu -> them vat tu vao danh sach
Vattu *create_node();
void Them_Vat_Tu(tree &vt, Vattu *p);
void Nhap_Vat_Tu(DS_VATTU &dsvt);
string tao_ma_vt(tree vt);
Vattu *check_trung(tree vt, string a);

//===================Chuyen cay nhi phan sang cay AVL==============================
int height(tree vt);
bool checkAVL(tree vt);
// ===========Xoay trai===================
tree XoayTrai(tree a);
// ===========Xoay phai===================
tree XoayPhai(tree a);
tree cap_nhap_AVL(tree vt);


//================In danh sach vat tu=======================================================
void print_mavt(tree vt);
void Xuat_list_VT(tree vt);
void Duyet_LNR(tree vt, Vattu **arr, int &sl);
void xep_noi_bot(Vattu **arr, int sl);
void VT_info(tree t);

//=================Hieu chinh vat tu========================================================
// search -> found -> edit
Vattu *check_ton_tai(tree vt);
void Hieu_chinh_VT(tree vt);

//=================Xoa vat tu===============================================================
// search -> found -> delete
Vattu *Find_min(tree vt);
tree Xoa_VT(tree root, string key);

//=================Tuong tac voi file=======================================================
// ghi du lieu -> day vao file
void Push_info(tree vt, ofstream &outfile);
void Write_info(tree vt, int sl);
// lay tu file ra
void Read_info(DS_VATTU &dsvt);

//=================Giai phong vung nho danh sach vat tu =====================================
void free_mem(tree vt);

//==================Cap nhap so luong ton====================================================
bool cap_nhat_slt_nv(tree vt, string loai, CT_HOADON &cthd);
void cap_nhat_slt_nv_xoa(tree vt, string loai, CT_HOADON &cthd);

//==================================Them vat tu==========================================================================================================
Vattu *create_node()
{
    Vattu *newNode = new Vattu;
    newNode->TENVT = "";
    newNode->DVT = "";
    newNode->SoLuongTon = -1;
    newNode->check_NHD = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Vattu *check_trung(tree vt, string a)
{
    if(vt == NULL || vt->MAVT.compare(a) == 0)
        return vt;
    else if(vt->MAVT.compare(a) > 0)
        return check_trung(vt->left, a);
    else
        return check_trung(vt->right, a);
}
string tao_ma_vt(tree vt)
{
    do
    {
        for(int i = 2; i < ma.length(); i++)
        {
            ma[i] = rand() % (57 - 48 + 1) + 48; // random ma[i] thuoc doan [0, 9]
        }
    }while(check_trung(vt, ma) != NULL);
    return ma;
}
void Them_Vat_Tu(tree &vt, Vattu *p)
{
    if( vt == NULL)
        vt = p;
    else
    {
        if( p->MAVT.compare(vt->MAVT) > 0)
            Them_Vat_Tu(vt->right, p);
        else
            Them_Vat_Tu(vt->left, p);
    }
}

//==========================================Xuat vat tu==========================================================================================================
void Duyet_LNR(tree vt, Vattu **arr, int &sl)
{
    if (vt != NULL)
    {
        Duyet_LNR(vt->left, arr, sl);
        arr[sl++] = vt;
        Duyet_LNR(vt->right, arr, sl);
    }
}
void xep_noi_bot_SL(Vattu** arr, int sl)
{
    for (int i = 0; i < sl - 1; i++)
    {
        for (int j = 0; j < sl - i - 1; j++)
        {
            if (arr[j]->SoLuongTon > arr[j + 1]->SoLuongTon)
            {
                Vattu* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void xep_noi_bot(Vattu **arr, int sl)
{
    for(int i = 0; i < sl-1; i++)
    {
        for(int j = 0; j < sl-i-1; j++)
        {
            if(arr[j]->TENVT.compare(arr[j+1]->TENVT) > 0)
            {
                Vattu *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//==========================================Xoa vat tu============================================================================================================
Vattu *Find_min(tree vt)
{
    if(vt != NULL)
    {
        while(vt->left != NULL)
            vt = vt->left;
    }
    return vt;
}
tree Xoa_VT(tree root, string key)
{
    if(root == NULL) return root;
    else if(key.compare(root->MAVT) > 0)
        root->right = Xoa_VT(root->right, key);
    else if(key.compare(root->MAVT) < 0)
        root->left = Xoa_VT(root->left, key);
    else
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // only child
        else if(root->left == NULL)
        {
            Vattu *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Vattu *temp = root;
            root = root->left;
            delete temp;
        }
        // 2 children
        else
        {
            Vattu *temp = Find_min(root->right);
            // coppy data
            root->MAVT = temp->MAVT;
            root->DVT = temp->DVT;
            root->TENVT = temp->TENVT;
            root->SoLuongTon = temp->SoLuongTon;

            root->right = Xoa_VT(root->right, temp->MAVT);
        }
    }
    return root;
}
//================================Giai phong vung nho===========================================================================================
void free_mem(tree vt)
{
    if(vt == NULL )
        return;
    free_mem(vt->left);
    free_mem(vt->right);
    delete vt;
}
//==================================Tuong tac file==============================================================================================
//============Ghi vao file===========
void Push_info(tree vt, ofstream &outfile)
{
    if(vt != NULL)
    {
        outfile << vt->MAVT << "," << vt->TENVT << "," << vt->DVT << "," << vt->SoLuongTon << "," << vt->check_NHD << endl;
        Push_info(vt->left, outfile);
        Push_info(vt->right, outfile);
    }
}
void Write_info(tree vt, int sl)
{
    ofstream outfile;
    outfile.open("dsvt.txt", ios_base :: trunc); // xoa sach va ghi vao file -> do co chuc nang xoa kho ghi noi tiep -> co the gay lap du lieu
    outfile << sl << endl;
    Push_info(vt, outfile);
    outfile.close();
}
//==========Lay du lieu tu file=========
void Read_info(DS_VATTU &dsvt)
{
    ifstream file_to_pro;
    file_to_pro.open("dsvt.txt", ios_base :: in);
    file_to_pro >> dsvt.sl;
    for(int i = 0; i < dsvt.sl; i++)
    {
        file_to_pro.ignore();
        Vattu *temp = create_node();
        getline(file_to_pro, temp->MAVT, ',');
        getline(file_to_pro, temp->TENVT, ',');
        getline(file_to_pro, temp->DVT, ',');
        file_to_pro >> temp->SoLuongTon;
        char x;
        file_to_pro >> x;
        file_to_pro >> temp->check_NHD;

        Them_Vat_Tu(dsvt.root, temp);
    }
    file_to_pro.close();
}
//==================Cap nhap so luong ton=====================================================================================================================
bool cap_nhat_slt_nv(tree vt, string loai, CT_HOADON &cthd) // da tim thay hoa don -> so sanh -> cap nhap slt
{
    //tim vat tu -> cap nhap slt
    Vattu* temp = check_trung(vt, cthd.MAVT);
    // da tim thay ->  thay doi so luong ton
    if (loai == "N") // chi co 2 loai 'N' va 'X'
        temp->SoLuongTon = temp->SoLuongTon + cthd.Soluong;
    else if (loai == "X" && temp->SoLuongTon >= cthd.Soluong)
        temp->SoLuongTon = temp->SoLuongTon - cthd.Soluong;
    else //error
    {
        //cout << "So luong ton khong du!\n So luong con lai la: " << temp->SoLuongTon << endl;
        //system("pause");
        return false;
    }
    temp->check_NHD++; 
    return true;
}
void cap_nhat_slt_nv_xoa(tree vt, string loai, CT_HOADON &cthd)
{
    Vattu* tmp = check_trung(vt, cthd.MAVT);
    if (loai == "N") tmp->SoLuongTon = tmp->SoLuongTon - cthd.Soluong;
    else if (loai == "X" && tmp->SoLuongTon >= cthd.Soluong) tmp->SoLuongTon = tmp->SoLuongTon + cthd.Soluong;
}

void cap_nhat_slt_nv_trahang(tree vt, CT_HOADON& cthd)
{
    Vattu* tmp = check_trung(vt, cthd.MAVT);
    tmp->SoLuongTon = tmp->SoLuongTon + cthd.Soluong;
    tmp->check_NHD--;
    cthd.Trangthai = 0;
}
//===================Chuyen cay nhi phan sang cay AVL==============================
int height(tree vt)
{
    if(vt == NULL) return -1;
    return max(height(vt->left), height(vt->right)) +1;
}
bool checkAVL(tree vt)
{
    if(vt == NULL) return true;
    if( abs(height(vt->left) - height(vt->right)) > 1)
        return false;
    return checkAVL(vt->left) && checkAVL(vt->right);
}
// ===========Xoay trai===================
tree XoayPhai(tree a)
{
    Vattu *b = a->left;
    Vattu *d = b->right;
    a->left = d;
    b->right = a;
    return b;
}
// ===========Xoay phai===================
tree XoayTrai(tree a)
{
    Vattu *b = a->right;
    Vattu *d = b->left;
    a->right = d;
    b->left = a;
    return b;
}
tree cap_nhap_AVL(tree vt)
{
    if( abs(height(vt->left) - height(vt->right)) > 1)
    {
        if(height(vt->left) > height(vt->right))
        {
            Vattu *x = vt->left;
            if(height(x->left) >= height(x->right))    // Trai - trai
                vt = XoayPhai(vt);
            else                                        // Trai _ phai
            {
                vt->left = XoayTrai(vt->left);
                vt = XoayPhai(vt);
            }
        }
        else
        {
            Vattu *x = vt->right;
            if(height(x->right) >= height(x->left))    // Phai- Phai
                vt = XoayTrai(vt);
            else
            {
                vt->right = XoayPhai(vt->right);        // Phai -trai
                vt = XoayTrai(vt);
            }
        }
    }
    if(vt->left != NULL)
        vt->left = cap_nhap_AVL(vt->left);
    if(vt->right != NULL)
        vt->right = cap_nhap_AVL(vt->right);
    return vt;
}