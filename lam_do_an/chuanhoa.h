
#include"khaibao.h"
#include<ctime>
using namespace std;
//////


bool checknam(Ngay ngay) {
	if (ngay.nam >= 2000) {
		return true;
	}
	return false;
}

bool checknamnhuan(int n) {
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
		return true;
	}
	return false;
}

bool checkthang(Ngay ngay) {
	if (ngay.thang > 0 && ngay.thang <= 12) {
		return true;
	}
	return false;
}

bool checkngay(Ngay ngay) {
	int MAXNGAY[] = { 100,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (checknamnhuan(ngay.nam)) {
		MAXNGAY[2] = 29;
	}
	//for (int i = 1; i < 13; i++) {
	//	if (i >= 8) {
	//		if (i % 2 == 0) {
	//			MAXNGAY[i] = 31;
	//		}
	//		else {
	//			MAXNGAY[i] = 30;
	//		}
	//	} 
	//	if (i <= 7) {
	//		if (i % 2 == 0) {
	//			MAXNGAY[i] = 30;
	//		}
	//		else {
	//			MAXNGAY[i] = 31;
	//		}
	//	}
	//	if (i == 2) {
	//		if (checknamnhuan(ngay.nam)) {
	//			MAXNGAY[2] = 29;
	//		}
	//		else {
	//			MAXNGAY[2] = 28;
	//		}
	//	}
	//}

	if (ngay.ngay <= MAXNGAY[ngay.thang] && ngay.ngay > 0) {
		return true;
	}
	return false;
}

int Daytoint(Ngay n1) {
	int cnt = 0;
	for (int i = 2000; i < n1.nam; i++) {
		if (checknamnhuan(i)) {
			cnt += 366;
		}
		else {
			cnt += 365;
		}
	}
	int MAXNGAY[] = { 100,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (checknamnhuan(n1.nam)) {
		MAXNGAY[2] = 29;
	}
	for (int i = 1; i < n1.thang; i++) {
		cnt += MAXNGAY[i];
	}
	cnt += n1.ngay;
	return cnt;
}

int khoangcach2ngay(Ngay n1, Ngay n2) {
	return Daytoint(n2) - Daytoint(n1);
}

Ngay ngayhientai()
{
	Ngay ngayhientai;
	time_t now;
	time(&now);

	struct tm timeinfo;
	localtime_s(&timeinfo, &now);

	int year = timeinfo.tm_year + 1900;
	int month = timeinfo.tm_mon + 1;
	int day = timeinfo.tm_mday;

	ngayhientai.ngay = day;
	ngayhientai.thang = month;
	ngayhientai.nam = year;
	return ngayhientai;
}

bool CheckNgayThangNam(Ngay ngay) {
	if ((checknam(ngay) && checkthang(ngay) && checkngay(ngay)) && khoangcach2ngay(ngayhientai(),ngay) <=0 ) {
		return true;
	}
	return false;
}
