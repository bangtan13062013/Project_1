#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int dem =0;

struct SinhVien {
    unsigned long int msv;
    int khoahoc,namsinh;
	char hodem[30];
    char ten[20];
    char gioitinh[10];
    char nganhhoc[50];
    char quequan[30];
    float diemM1,diemM2,diemM3;

    void Nhap(){
    	cout<<"Ma sinh vien: ";
		cin>>msv;
    	cout<<"Ho dem: ";
		fflush(stdin);gets(hodem); //fflush(stdin) de xoa bo dem, gets() de doc ki tu trong stdin 
		cout<<"Ten: ";
		fflush(stdin);gets(ten);
    	cout<<"Gioi tinh: ";
		fflush(stdin);gets(gioitinh);
    	cout<<"Nam sinh: ";
		cin>>namsinh;
		cout<<"Que quan: ";
		fflush(stdin);gets(quequan);
		cout<<"Nganh hoc: ";
		fflush(stdin);gets(nganhhoc);
		cout<<"Khoa hoc: ";
		cin>>khoahoc;
    	do{
    		cout<<"Diem mon 1: ";
    		cin>>diemM1;
    		cout<<"Diem mon 2: ";
    		cin>>diemM2;
    		cout<<"Diem mon 3: ";
    		cin>>diemM3;
    		if(diemM1<0||diemM2<0||diemM3<0||diemM1>10||diemM2>10||diemM3>10){ //diem nhap vao ph?i lon hon 0 va be hon 10
    	    	cout<<"Diem khong hop le. Moi nhap lai!\n";    		
    	    }
		}
		while(diemM1<0||diemM2<0||diemM3<0||diemM1>10||diemM2>10||diemM3>10);
	}
	
	float diemTB(){
		return (diemM1+diemM2+diemM3)/3;
	}
	
	string Hocluc(){
		string hl;
		if(diemTB()>=9){
	    	hl="Xuat sac";
	    }else if(diemTB()>=8){
	    	hl="Gioi";
		}else if(diemTB()>=6.5){
			hl="Kha";
		}else if(diemTB()>=5.5){
			hl="Trung binh";
		}else hl="Yeu";
		return hl;
	}	
                          	// ham setw() thay doi do rong be rong khi xuat du lieu, duoc cung cap bang thu vien iomanip
	void Xuat(){ 
		cout<<setw(2)<<++dem<<setw(13)<<msv<<setw(15)<<hodem<<setw(15)<<ten<<setw(8)<<gioitinh<<setw(15)<<namsinh<<setw(15)<<quequan<<setw(10)<<nganhhoc<<setw(10)<<khoahoc;
		cout<<setw(11)<<diemM1<<setw(12)<<diemM2<<setw(12)<<diemM3<<setw(10)<<setprecision(2)<<fixed<<diemTB()<<setw(13)<<Hocluc()<<endl;
	}                                                                         // ham setprecision(2) va fixed dung de xuat diemTB lam tron lay hai chu so phan thap phan
	//in ra thong tin sinh vien vua nhap vao file 
	void write(std::fstream&myFile){
		myFile<<setw(2)<<"STT"<<setw(9)<<"MSV"<<setw(14)<<"Ho dem"<<setw(14)<<"Ten"<<setw(16)<<"Gioi tinh"<<setw(13)<<"Nam sinh"<<setw(12)<<"Que quan"<<setw(13)<<"Nganh hoc";
		myFile<<setw(11)<<"Khoa hoc"<<setw(12)<<"Diem mon1"<<setw(12)<<"Diem mon2"<<setw(12)<<"Diem mon3"<<setw(9)<<"Diem TB"<<setw(9)<<"Hoc luc"<<endl;
		myFile<<setw(2)<<++dem<<setw(13)<<msv<<setw(15)<<hodem<<setw(15)<<ten<<setw(8)<<gioitinh<<setw(15)<<namsinh<<setw(15)<<quequan<<setw(10)<<nganhhoc<<setw(10)<<khoahoc;
		myFile<<setw(11)<<diemM1<<setw(12)<<diemM2<<setw(12)<<diemM3<<setw(10)<<setprecision(2)<<fixed<<diemTB()<<setw(13)<<Hocluc()<<endl;
	}
};

typedef struct SinhVien SV; //dat ten cho struct SinhVien thanh SV

//ham nay de in ra mot dong ki hieu "____" nham muc dich tang tham mi 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
//ham tao tieu de thong bao thuoc tinh cho thong tin in ra
void Tieude(){
	cout<<setw(2)<<"STT"<<setw(9)<<"MSV"<<setw(14)<<"Ho dem"<<setw(14)<<"Ten"<<setw(16)<<"Gioi tinh"<<setw(13)<<"Nam sinh"<<setw(12)<<"Que quan"<<setw(13)<<"Nganh hoc";
	cout<<setw(11)<<"Khoa hoc"<<setw(12)<<"Diem mon1"<<setw(12)<<"Diem mon2"<<setw(12)<<"Diem mon3"<<setw(9)<<"Diem TB"<<setw(9)<<"Hoc luc"<<endl;
}
//nhap so luong sinh vien
void NhapSL(int &n){
	do{
		cout<<"\nNhap so luong sinh vien: ";
		cin>>n;
		if(n<0) 
		    cout<<"\n\tNhap lai!\n";
	}while(n<0);
}
//nhap danh sach sinh vien
void NhapSV(SV a[],int n){
	printLine(100);
	int res=0;
	for(int i=0;i<n;i++){
		do{
			res=0; 
		    cout<<"\n\tNhap thong tin sinh vien thu "<<i+1<<": "<<endl;
		    a[i].Nhap();
		    for(int j=0;j<i;j++){
		    	if(a[j].msv==a[i].msv){
			        cout<<"\nNhap lai.\n";
			        res++;
		        }
			}
		}while(res!=0);
    }
}
//xuat danh sach sinh vien
void XuatSV(SV a[],int n){
	printLine(160); //in ra mot dong "____" de tang tham mi 
	Tieude();
	dem=0;
	for(int i=0;i<n;i++){
		a[i].Xuat();
	}
	printLine(160);
}
//them thong tin sinh vien
void ThemSV(SV a[],int &n){
    n++;
    int res=0;
    do{
    	res=0;
        cout<<"\n\tNhap thong tin vinh vien can them: "<<endl;
        a[n-1].Nhap();
        for(int i=0;i<n-1;i++){
       	    if(a[i].msv==a[n-1].msv)
       	    cout<<"\n\tMa sinh vien bi trung. Nhap lai!"<<endl;
       	    res++;
	   }break;
    }while(res!=0);
}
//xoa thong tin sinh vien
void XoaSV(SV a[],int &n){
	int soct;
	int res=0;
	cout<<"\n\tNhap ma sinh vien can xoa: ";
	cin>>soct;
	for(int i=0;i<n;i++){
		if(a[i].msv==soct){
			res++;
			for(int j=i;j<n;j++){
				a[j]=a[j+1];
			}
		}
	}
	if(res==0)
	cout<<"\n\tMa so sinh vien vua nhap khong ton tai\n";
	else n--;
}
//chinh sua thong tin sinh vien
void SuaSV(SV a[],int n){
	int soct;
	cout<<"\n\tNhap ma sinh vien can chinh sua: ";
	cin>>soct;
	for(int i=0;i<n;i++){
		if(a[i].msv==soct){
			a[i].Nhap();
		}
	}
}
//tim kiem thong tin sinh vien theo ma sinh vien
void SearchSV(SV a[],int n){
	int soct;
	cout<<"\n\tNhap ma sinh vien can tim: ";
	cin>>soct;
	printLine(160);
	Tieude();
	for(int i=0;i<n;i++){
		if(a[i].msv==soct){
			a[i].Xuat();
		}
	}
	printLine(160);
}
//sap xep danh sach sinh vien theo ma sinh vien
void ArrangeMSV(SV a[],int n){
	dem=0;
	cout<<"\n\tDANH SACH SINH VIEN SAP XEP THEO MSV TANG DAN: "<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].msv>a[j].msv){
		         swap(a[i],a[j]);	//ham swap hoan doi gia tri hai bien cho nhau
			}
		}
	}
	XuatSV(a,n);
}
//sap xep danh sach sinh vien theo ten alphabet
void ArrangeTenSV(SV a[],int n){
	dem=0;
	cout<<"\n\tDANH SACH SINH VIEN SAP XEP THEO TEN ALPHABET: "<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(a[i].ten,a[j].ten)>0){
				swap(a[i],a[j]);
			}
		}
	}
	XuatSV(a,n);
}
//ham khiem tra diem lon nhat
float Max(SV a[],int n){
	float max=a[0].diemTB();
	for(int i=1;i<n;i++){
		if(a[i].diemTB()>max){
			max=a[i].diemTB();
		}
	}
	return max;
}
//ham in ra diem lon nhat
void MaxSV(SV a[],int n){
	dem=0;
	cout<<"\n\tDANH SACH SINH VIEN CO DIEM TB CAO NHAT: "<<endl;
	printLine(160);
	Tieude();
	for(int i=0;i<n;i++){
		if(a[i].diemTB()==Max(a,n)){
			a[i].Xuat();
		}
	}
	printLine(160);
}
//ham kiem tra diem nho nhat
float Min(SV a[],int n){
	float min=a[0].diemTB();
	for(int i=1;i<n;i++){
		if(a[i].diemTB()<min){
			min=a[i].diemTB();
		}
	}
	return min;
}
//ham in ra diem nho nhat
void MinSV(SV a[],int n){
	dem=0;
	cout<<"\n\tDANH SACH SINH VIEN CO DIEM TB THAP NHAT: "<<endl;
	printLine(160);
	Tieude();
	for(int i=0;i<n;i++){
		if(a[i].diemTB()==Min(a,n)){
			a[i].Xuat();
		}
	}
	printLine(160);
}
//luu thong tin vua nhap vao file
void SaveF(SV a[],int n,fstream&myFile){
	for(int i=0;i<n;i++){
		a[i].write(myFile);
	}
}

void Menu(){
	cout<<"\n\t\t\t CHUONG TRINH QUAN LY SINH VIEN C++\n";
	cout<<endl;
	cout<<"\t\t****************************MENU**************************\n";
	cout<<"\t\t** 1.Nhap danh sach sinh vien                           **\n";
	cout<<"\t\t** 2.Hien thi danh sach sinh vien                       **\n";
	cout<<"\t\t** 3.Them thong tin sinh vien theo MSV                  **\n";
    cout<<"\t\t** 4.Xoa thong tin sinh vien theo MSV                   **\n";
    cout<<"\t\t** 5.Sua thong tin sinh vien                            **\n";
	cout<<"\t\t** 6.Tim kiem thong tin sinh vien theo MSV              **\n";
	cout<<"\t\t** 7.Sap xep danh sach sinh vien theo MSV               **\n";
	cout<<"\t\t** 8.Sap xep danh sach sinh vien theo ten ALphabet      **\n";
	cout<<"\t\t** 9.Hien thi thong tin sinh vien co diem TB cao nhat   **\n";
	cout<<"\t\t** 10.Hien thi thong tin sinh vien co diem TB thap nhat **\n";
	cout<<"\t\t** 11.Luu thong tin sinh vien vua nhap vao file         **\n";
	cout<<"\t\t** 0.Thoat chuong trinh                                 **\n";
	cout<<"\t\t**********************************************************\n";	
}
int main(){
	int n,luachon;
	SV a[1000];

	//menu
	do{
		Menu();
		cout<<"\n\t**** @^ . ^@ **** Nhap lua chon chuc nang: ";
		cin>>luachon;
	 //chuc nang chuong trinh
	    switch(luachon){
	    	case 1: cout<<"\n\t--------Ban dang thuc hien chua nang 1:Nhap danh sach sinh vien--------\n";
			        NhapSL(n);
	    		    NhapSV(a,n);
	    		    break;
	    	case 2: cout<<"\n\t--------Ban dang thuc hien chuc nang 2:Hien thi danh sach sinh vien--------\n";
					XuatSV(a,n);
			        break;
			case 3: cout<<"\n\t--------Ban dang thuc hien chuc nang 3:Them thong tin sinh vien--------\n";
					
					ThemSV(a,n);
					cout<<" \n           Da them thong tin sinh vien!           \n";
				    break;
			case 4: cout<<"\n\t--------Ban dang thuc hien chuc nang 4:Xoa sinh vien theo ma sinh vien--------\n";
					XoaSV(a,n);
					cout<<"   \n         Da xoa sinh vien!           \n";
				    break;
			case 5: cout<<"\n\t--------Ban dang thuc hien chuc nang 5:Sua thong tin sinh vien--------\n";
					SuaSV(a,n);
					cout<<" \n           Da sua thong tin sinh vien!           \n";
				    break;
			case 6: cout<<"\n\t--------Ban dang thuc hien chuc nang 6:Tim kiem thong tin sinh vien--------\n";
					SearchSV(a,n);
				    break;
			case 7: cout<<"\n\t--------Ban dang thuc hien chuc nang 7:Sap xep thong tin sinh vien theo ma sinh vien--------\n";
					ArrangeMSV(a,n);
			        break;
			case 8: cout<<"\n\t--------Ban dang thuc hien chuc nang 8:Sap xep thong tin sinh vien theo ten--------\n";
					ArrangeTenSV(a,n);
			        break;
			case 9: cout<<"\n\t--------Ban dang thuc hien chuc nang 9:Hien thi thong tin sinh vien co diem TB cao nhat--------\n";
					MaxSV(a,n);
			        break;
			case 10:cout<<"\n\t--------Ban dang thuc hien chuc nang 10:Hien thi thong tin sinh vien co diem TB thap nhat--------\n";
					MinSV(a,n);
			         break;    
			case 11:{
					fstream myFile;                  
					myFile.open("qlsv.txt",ios::out);  /*mo file*/  
					SaveF(a,n,myFile);	
					myFile.close();  /*dong file*/
					cout<<"\n\t        Thong tin vua nhap da duoc truyen vao file!          \n";		     
					break;
					}
			case 0: cout<<"\n\t\t @^ . ^@ Thoat chuong trinh!"<<endl;
					cout<<endl;
					cout<<"\n\t\t\t DE TAI DO AN: QUAN LY SINH VIEN";
					cout<<"\n\t\t\t DINH THI MY DUYEN_2722235440_TH27.62\n";
			        return 0;   
			default: 
			        cout<<"\n\t---Khong co chuc nang nay. Hay chon chuc nang khac trong MENU!---\n";
			    break;		        	
		}
    }while(true);
	return 0;
}