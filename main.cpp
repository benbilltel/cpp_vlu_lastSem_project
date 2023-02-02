/*Le Thanh Hoang
2274801030052*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
#define KTM 100
void nhapMang(int arr[KTM], int &spt);
void xuatMang(int arr[KTM], int spt);
void taoMangNgauNhien(int arr[KTM], int &spt);
int tongNguyenAm(int arr[KTM], int spt);
float trungBinhCongNguyenAm(int arr[KTM], int spt);
bool ktraSoHT(int a);
int tongSoHT(int arr[KTM], int spt);
bool ktraSoCP(int a);
int demSoCP(int arr[KTM], int spt);
bool kTraChuSoLe(int a);
bool kTraMangSoToanChuSoLe(int arr[KTM], int spt);
bool kTraMangToanSoNguyenAm(int arr[KTM], int spt);
bool kTraMangToanSoCP(int arr[KTM], int spt);
bool kTraMangTangDan(int arr[KTM], int spt);
void themPhanTuVaoMang(int arr[KTM], int &spt);
void menu();
int main()
{
    menu();
    return 0;
}
void menu()
{
    int chon, arr[KTM], spt;
    do
    {
        cout << "Le Thanh Hoang - 2274801030052" << endl
             << "1.Nhap mang" << endl
             << "2.Xuat mang" << endl
             << "3.Tao mang ngau nhien" << endl
             << "4.Tinh tong cac so nguyen am co trong mang" << endl
             << "5.Tinh trung binh cong cac so nguyen am co trong mang" << endl
             << "6.Tinh tong cac so hoan thien co trong mang" << endl
             << "7.Dem so chinh phuong co trong mang" << endl
             << "8.Kiem tra mang co ton tai phan tu la so nguyen toan chu so la so le" << endl
             << "9.Kiem tra mang co phai la mang toan so nguyen am hay khong" << endl
             << "10.Kiem tra mang co phai mang toan so chinh phuong hay khong" << endl
             << "11.Kiem tra mang co phai la mang tang dan hay khong" << endl
             << "12.Them phan tu vao mang" << endl
             << "0.Thoat" << endl;
        cin >> chon;
        switch (chon)
        {
        case 1:
            nhapMang(arr, spt);
            break;
        case 2:
            xuatMang(arr, spt);
            break;
        case 3:
            taoMangNgauNhien(arr, spt);
            break;
        case 4:
        {
            int tong = tongNguyenAm(arr, spt);
            if (tong < 0)
            {
                cout << "Tong cac so nguyen am trong mang : " << tong << endl;
            }
            else
            {
                cout << "Mang khong co so nguyen am." << endl;
            }
        }
        break;
        case 5:
        {
            float tbc = trungBinhCongNguyenAm(arr, spt);
            if (tbc < 0)
            {
                cout << "Trung binh cong cac so nguyen am co trong mang : " << tbc << endl;
            }
            else
            {
                cout << "Mang khong co so nguyen am." << endl;
            }
        }
        break;
        case 6:
        {
            if (tongSoHT(arr, spt) > 0)
            {
                cout << "Tong cac so hoan thien co trong mang : " << tongSoHT(arr, spt) << endl;
            }
            else
            {
                cout << "Mang khong co so hoan thien" << endl;
            }
        }
        break;
        case 7:
        {
            cout << "So chinh phuong co trong mang la : " << demSoCP(arr, spt) << endl;
        }
        break;
        case 8:
            if (kTraMangSoToanChuSoLe(arr, spt))
            {
                cout << "Mang ton tai phan tu co toan chu so la chu so le." << endl;
            }
            else
            {
                cout << "Mang khong ton tai phan tu co toan chu so la chu so le." << endl;
            }
            break;
        case 9:
            if (kTraMangToanSoNguyenAm(arr, spt))
            {
                cout << "Mang la mang toan so nguyen am" << endl;
            }
            else
            {
                cout << "Mang khong phai la mang toan so nguyen am" << endl;
            }
            break;
        case 10:
            if (kTraMangToanSoCP(arr, spt))
            {
                cout << "Mang la mang toan so chinh phuong" << endl;
            }
            else
            {
                cout << "Mang khong phai la mang toan so chinh phuong" << endl;
            }
            break;
        case 11:
            if (kTraMangTangDan(arr, spt))
            {
                cout << "Mang la mang tang dan" << endl;
            }
            else
            {
                cout << "Mang khong phai la mang tang dan" << endl;
            }
            break;
        case 12:
            themPhanTuVaoMang(arr, spt);
            break;
        default:
            break;
        }
    } while (chon > 0 && chon < 13);
}
void themPhanTuVaoMang(int arr[KTM], int &spt)
{
    spt++;
    cout << "Nhap phan tu can them vao : " << endl;
    cin >> arr[spt - 1];
    xuatMang(arr, spt);
}
bool kTraMangTangDan(int arr[KTM], int spt)
{
    for (int i = 1; i < spt; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true;
}
bool kTraMangToanSoCP(int arr[KTM], int spt)
{
    for (int i = 0; i < spt; i++)
    {
        if (!ktraSoCP(arr[i]))
        {
            return false;
        }
    }
    return true;
}
bool kTraMangToanSoNguyenAm(int arr[KTM], int spt)
{
    for (int i = 0; i < spt; i++)
    {
        if (arr[i] > 0)
        {
            return false;
        }
    }
    return true;
}
bool kTraMangSoToanChuSoLe(int arr[KTM], int spt)
{
    for (int i = 0; i < spt; i++)
    {
        if (kTraChuSoLe(arr[i]))
        {
            return true;
        }
    }
    return false;
}
bool kTraChuSoLe(int a)
{
    int chuyen = 1;
    do
    {
        if ((a % 10) % 2 == 0)
        {
            chuyen = 0;
            break;
        }
    } while (a /= 10);

    return chuyen == 1;
}
bool ktraSoCP(int a)
{
    return double(sqrt(a)) - int(sqrt(a)) == 0;
}
int demSoCP(int arr[KTM], int spt)
{
    int dem = 0;
    for (int i = 0; i < spt; i++)
    {
        if (ktraSoCP(arr[i]))
        {
            dem++;
        }
    }
    return dem;
}
bool ktraSoHT(int a)
{
    if (a <= 0)
    {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= a / 2; i++)
    {
        if (a % i == 0)
            sum += i;
    }
    return sum == a;
}
int tongSoHT(int arr[KTM], int spt)
{
    int sum = 0;
    for (int i = 0; i < spt; i++)
    {
        if (ktraSoHT(arr[i]))
        {
            sum += arr[i];
        }
    }
    return sum;
}
float trungBinhCongNguyenAm(int arr[KTM], int spt)
{
    float tong, dem = 0.0;
    for (int i = 0; i < spt; i++)
    {
        if (arr[i] < 0)
        {
            tong += arr[i];
            dem++;
        }
    }
    return tong / dem;
}
int tongNguyenAm(int arr[KTM], int spt)
{
    int tong;
    for (int i = 0; i < spt; i++)
    {
        if (arr[i] < 0)
        {
            tong += arr[i];
        }
    }
    return tong;
}
void taoMangNgauNhien(int arr[KTM], int &spt)
{
    srand(time(NULL));
    do
    {
        cout << "Nhap so luong phan tu mang: " << endl;
        cin >> spt;
    } while (spt <= 0 || spt > KTM);
    for (int i = 0; i < spt; i++)
    {
        arr[i] = rand() % 151 - 100;
    }
}
void nhapMang(int arr[KTM], int &spt)
{
    do
    {
        cout << "Nhap so luong phan tu mang: " << endl;
        cin >> spt;
    } while (spt <= 0 || spt > KTM);
    cout << "Nhap gia tri cho cac phan tu mang!" << endl;
    for (int i = 0; i < spt; i++)
    {
        cout << "Nhap gia tri cho phan tu thu " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
}
void xuatMang(int arr[], int spt)
{
    cout << "Cac phan tu cua mang : " << endl;
    for (int i = 0; i < spt; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}