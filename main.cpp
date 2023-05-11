#include"header.h"


int main() {
	SVList sv;
	khoitao(sv);
	string a;
	cout << "Nhap ten lop hoc: ";
	getline(cin, a);
	taoLopHocMoi(a);
	themHocSinhVaoLopThuCong(sv);
	themHocSinhVaoLopbangFile(a, sv);
	xuatHocSinhTrongLop(sv);
	saveSVVaoFile(a, sv);
}