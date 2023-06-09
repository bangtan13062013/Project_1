#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#define MAX 100
using namespace std;

struct SinhVien {
    int msv;
    string ten,gioitinh;
    int tuoi;
    float diemM1;
    float diemM2;
    float diemM3;
    float diemTB = 0;
    char hocluc[10] = "-";
};
typedef SinhVien SV;

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}

void tinhDTB(SV &sv) {
    sv.diemTB = (sv.diemM1 + sv.diemM2 + sv.diemM3) / 3;    
}

void xeploai(SV &sv) {
    if(sv.diemTB >= 8) strcpy(sv.hocluc, "Gioi");
    else if(sv.diemTB >= 6.5) strcpy(sv.hocluc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocluc, "Trung binh");
    else strcpy(sv.hocluc, "Yeu");
}

void nhapThongTinSV(SV &sv, int msv) {
    cout << "\n Nhap ten: ";cin>>sv.ten ;
    cout << " Nhap gioi tinh: ";cin>>sv.gioitinh ;
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem mon 1: "; cin >> sv.diemM1;
    cout << " Nhap diem mon 2: "; cin >> sv.diemM2;
    cout << " Nhap diem mon 3: "; cin >> sv.diemM3;
    sv.msv = msv;
    tinhDTB(sv);
    xeploai(sv);
}

void nhapSV(SV a[], int msv, int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n], msv);
    printLine(40);
}

void HienthiSV(SV a[], int n) {
    printLine(100);
    cout <<"\n STT\tMSV\tHo va ten\tGioi tinh\tTuoi\tMon 1\tMon 2\tMon 3\tDiem TB\tHoc luc";
    for(int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].msv);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].gioitinh);
        printf("\t\t%d", a[i].tuoi);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemM1, a[i].diemM2, a[i].diemM3);
        printf("\t%.2f", a[i].diemTB);
        printf("\t%s", a[i].hocluc);
    }
    printLine(100);
}

void capNhatThongTinSV(SV &sv) {
    cout << "\n Nhap ten: ";cin>>sv.ten;
    cout << " Nhap gioi tinh: ";cin>>sv.gioitinh;
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem Mon 1: "; cin >> sv.diemM1;
    cout << " Nhap diem Mon 2: "; cin >> sv.diemM2;
    cout << " Nhap diem Mon 3: "; cin >> sv.diemM3;
    tinhDTB(sv);
    xeploai(sv);
}

void capNhatSV(SV a[], int msv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].msv == msv) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin sinh vien co MSV = " << msv;
            capNhatThongTinSV(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co MSV = %d khong ton tai.", msv);
    }
}

int xoaTheoMSV(SV a[], int msv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].msv == msv) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SV co MSV = " << msv;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co MSV = %d khong ton tai.", msv);
        return 0;
    } else {
        return 1;
    }
}

int msvLonNhat (SV a[], int n) {
    int msvMax = 0;
    if (n > 0) {
        msvMax = a[0].msv;
        for(int i = 0;i < n; i++) {
            if (a[i].msv > msvMax) {
                msvMax = a[i].msv;
            }
        }
    }
    return msvMax;
}

void sapxepTheoMSV(SV a[], int n) {
    //Sap xep theo MSV tang dan
    SV tmp;
    for(int i = 0;i < n;i++){
        for(int j = i+1; j < n;j++){
            if(a[i].msv > a[j].msv){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapXepTheoTen(SV a[], int n) {
    //Sap xep sinh vien theo ten theo thu tu tang dan
    SV tmp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0;i < n; i++) {
        strcpy(tenSV1, a[i].ten);
        for(int j = i+1; j < n; j++) {
            strcpy(tenSV2, a[j].ten);
            if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

float DiemTbmax(SV a[],int n){
	float max=a[0].diemTB;
	for(int i=1;i<n;i++){
		if(a[i].diemTB>max){
			max=a[i].diemTB;
		}
	}
	return max;
}

void inDiemtbmax(SV a[],int n){
	SV HienthiSV;
	printLine(100);
	cout<<"Danh sach sinh vien co diem TB cao nhat"<<endl;
	for(int i=0;i<n;i++){
		if(a[i].diemTB==DiemTbmax(a,n)){
		HienthiSV;
		}
	}
}

float DiemTbmin(SV a[],int n){
	float min=a[0].diemTB;
	for(int i=1;i<n;i++){
		if(a[i].diemTB<min){
			min=a[i].diemTB;
		}
	}
	return min;
}

void inDiemtbmin(SV a[],int n){
	SV HienthiSV;
	printLine(100);
	cout<<"Danh sach sinh vien co diem TB cao nhat"<<endl;
	for(int i=0;i<n;i++){
		if(a[i].diemTB==DiemTbmin(a,n)){
		HienthiSV;
		}
	}
}

int docFile(SV a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].msv, &a[i].ten, 
            &a[i].gioiTinh, &a[i].tuoi, &a[i].diemM1, &a[i].diemM2, &a[i].diemM3, 
            &a[i].diemTB, &a[i].hocluc) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    // tra ve so luong sinh vien duoc doc tu file
    return i;
    fclose (fp);
}

void ghiFile(SV a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].msv, a[i].ten,a[i].gioiTinh, 
            a[i].tuoi, a[i].diemM1, a[i].diemM2, a[i].diemM3, a[i].diemTB, a[i].hocluc);
    }
    fclose (fp);
}



int main(){
	int key;
    int soluongSV = 0;
    int idCount = 0;
    SV arraySV[MAX]; 
    //nhapsv
    idCount++;
    nhapSV(arraySV, idCount, soluongSV);
	soluongSV++;
    //hienthidanhsachsv
    HienthiSV(arraySV, soluongSV);
    //hienthisvmax
    inDiemtbmax(arraySV, soluongSV);
}