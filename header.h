#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

struct Node {
	string MaMH;
	Node* pnext;
};

struct MonHoc {
	Node* Head;
	Node* Tail;
};

struct SinhVien {
	//string maLop;
	int No;
	string MSSV;
	string Ten;
	string Ho;
	string Gioitinh;
	string Ngaysinh;
	string ID;
	SinhVien* pnext;
};

struct SVList {
	SinhVien* Head;
	SinhVien* Tail;
};


void khoitao(SVList& sv);
bool checkSVList(SVList sv);
void taoLopHocMoi(string a);
int demList(SVList sv);
void themHocSinhVaoLopbangFile(string a, SVList& sv);
void themHocSinhVaoLopThuCong(SVList& sv);
void saveSVVaoFile(string a, SVList sv);
void xuatHocSinhTrongLop(SVList sv);