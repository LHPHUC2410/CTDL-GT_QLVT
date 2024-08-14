//#ifndef THUCTHI_H_INCLUDED
//#define THUCTHI_H_INCLUDED
//#pragma once
//#include "vattu.h"
//#include "hoadon.h"
//#include "nhanvien.h"
//
//void MENU()
//{
//    DS_VATTU dsvt;
//    list_nv dsnv;
//    bool check_all = true;
//    int lua_chon;
//
//    // Dua du lieu tu file vao tai day
//    doc_file_nv(dsnv);
//    Read_info(dsvt);
//
//
//    while(check_all)
//    {
//    system("cls");
//        cout << "\t\t\t1. Cap nhap vat tu( Them / Xoa / Hieu chinh ).\n";
//        cout << "\t\t\t2. In danh sach vat tu.\n";
//        cout << "\t\t\t3. Hieu chinh nhan vien.(Them, sua, xoa)\n";
//        cout << "\t\t\t4. In danh sach nhan vien.\n";
//        cout << "\t\t\t5. Lap hoa don.\n";
//        cout << "\t\t\t6. Tra hang.\n";
//        cout << "\t\t\t7. In hoa don.\n";
//        cout << "\t\t\t8. Thong ke cac hoa don.\n";
//        cout << "\t\t\t9. Thong ke doanh thu.\n";
//        cout << "\t\t\t0. EXIT.\n\n";
//
//        cout << "Hay nhap lua chon cua ban:";
//        cin >> lua_chon;
//        switch(lua_chon)
//        {
//            case 1:
//            {
//                menu_vt(dsvt);
//                break;
//            }
//            case 2:
//            {
//                if(dsvt.sl > 0)
//                    Xuat_list_VT(dsvt);
//                else
//                    cout << "Danh sach rong.\n";
//                system("pause");
//                break;
//            }
//            case 3:
//            {
//                hieu_chinh_nv(dsnv);
//                break;
//            }
//            case 4:
//            {
//                sort_nv(dsnv);
//                print_dsnv(dsnv);
//                break;
//            }
//            case 5:
//            {
//                update_hd(dsnv, dsvt);
//                break;
//            }
//            case 7:
//            {
//                for (int i = 0; i < dsnv.sl; i++)
//                {
//                    innodehd(dsnv.dsnv[i]->dshd);
//                }
//                break;
//            }
//            case 8:
//            {
//                thong_ke_hd_intime(dsnv);
//                break;
//            }
//            case 0:
//            {
//                // truoc khi thoat can luu file va giai phong bo nho
//                Write_info(dsvt.root, dsvt.sl);
//                ghi_file_nv(dsnv);
//
//                giai_phong_nv(dsnv);
//                free_mem(dsvt.root);
//
//                check_all = false;
//                break;
//            }
//            default:
//                break;
//        }
//    }
//}
//
//#endif // THUCTHI_H_INCLUDED
