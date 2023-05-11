#include"header.h"

void khoitao(SVList& sv) {
	sv.Head = NULL;
	sv.Tail = NULL;
}

bool checkSVList(SVList sv) {
	if (sv.Head == NULL && sv.Tail == NULL)
		return true;
	return false;
}

void taoNamHocMoi() {
	string a;
	cout << "Nhap nam hoc moi: ";
	getline(cin, a);
}


//a la ten lop hoc
//TAO LOP HOC MOI CHO NAM NHAT 2
void taoLopHocMoi(string a) {
	fstream f1;
	f1.open("ClassList.csv", ios::app);
	if (f1.fail()) {
		cout << "Khong the mo duoc file" << endl;
		return;
	}
	f1 << a << endl;
	f1.close();
}


int demList(SVList sv) {
	int dem = 1;
	for (SinhVien* p = sv.Head; p != NULL; p = p->pnext) {
		dem++;
	}
	return dem;
}

//a la ten lop cua file
//THEM HOC SINH VAO BANG FILE CSV 4
void themHocSinhVaoLopbangFile(string a,SVList &sv) {
	fstream f;
	string b = "Classes\\" + a + ".csv";
	f.open(b, ios::in);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	while (!f.eof()) {
		SinhVien* p = new SinhVien;
		string t;
		p->No = demList(sv);
		getline(f, t, ',');
		getline(f, p->MSSV, ',');
		getline(f, p->Ten, ',');
		getline(f, p->Ho, ',');
		getline(f, p->Gioitinh, ',');
		getline(f, p->Ngaysinh, ',');
		getline(f, p->ID, '\n');
		p->pnext = NULL;
		if (checkSVList(sv))
			sv.Head = sv.Tail = p;
		else {
			sv.Tail->pnext = p;
			sv.Tail = p;
		}
	}
	f.close();
}


//THEM HOC SINH NAM 1 VAO LOP 3
void themHocSinhVaoLopThuCong(SVList& sv) {
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		SinhVien* p = new SinhVien;
		p->No = demList(sv);
		cout << "Nhap MSSV: ";
		getline(cin, p->MSSV);
		cout << "Nhap Ten: ";
		getline(cin, p->Ten);
		cout << "Nhap Ho: ";
		getline(cin, p->Ho);
		cout << "Nhap Gioi tinh: ";
		getline(cin, p->Gioitinh);
		cout << "Nhap Ngay sinh: ";
		getline(cin, p->Ngaysinh);
		cout << "Nhap ID: ";
		getline(cin, p->ID);
		p->pnext = NULL;
		if (checkSVList(sv))
			sv.Head = sv.Tail = p;
		else {
			sv.Tail->pnext = p;
			sv.Tail = p;
		}
	}
}


//xuat hoc sinh cua lop moi tao
void xuatHocSinhTrongLop(SVList sv) {
	if (checkSVList(sv)) {
		cout << "Class is empty!" << endl;
		return;
	}
	SinhVien* p = sv.Head;
	while (p != NULL) {
		string b = p->Ho + " " + p->Ten;
		cout << p->No << "\t" << p->MSSV << "\t" << b << "\t" << p->Gioitinh << "\t" << p->Ngaysinh << "\t" << p->ID << endl;
		p = p->pnext;
	}
}

//a la ten lop
//luu lai cac hoc sinh vao file lop moi tao
void saveSVVaoFile(string a, SVList sv) {
	string b = "Classes\\" + a + ".csv";
	fstream f;
	f.open(b, ios::out);
	if (f.fail()) {
		cout << "Khong mo duoc file" << endl;
		return;
	}
	for (SinhVien* p = sv.Head; p != NULL; p = p->pnext) {
		f << p->No << "," << p->MSSV << "," << p->Ten << "," << p->Ho << "," << p->Gioitinh << "," << p->Ngaysinh << "," << p->ID << endl;
	}
	f.close();
}