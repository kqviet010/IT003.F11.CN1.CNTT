// Mã số sinh viên: 25730093
// Họ và tên sinh viên: Kiều Quang Việt
// Ngày sinh: 11/06/2000
// Lớp: IT003.F11.CN1.CNTT
// Giảng viên: ThS. Mai Xuân Hùng

#include <iostream>
#include <fstream>
using namespace std;

/// ===================================== NGUYÊN MẪU HÀM ===================================== ///
bool readFile(const string& filename, int a[], int &n); // Hàm đọc file vào mảng đã cấp phát sẵn
void xuat1c(int a[],int n); // Hàm xuất
int timPhanTuLonNhat(int a[], int n); // Câu 3
int timPhanTuNhoNhat(int a[], int n); // Câu 4
int tinhTrungBinhCong(int a[], int n); // Câu 5
int demSoChan(int a[], int n); // Câu 6
int demSoLe(int a[], int n); // Câu 6
bool checkSoNguyenTo(int num); // Câu 6
int demSoNguyenTo(int a[], int n); // Câu 6
void swap(int &x, int &y); // Câu 5
void interchangeSort(int a[], int n); // Câu 5
int soLanXuatHienX(int a[], int n, int x); // Câu 6
bool linearSearch(int a[], int n, int x); // Câu 7
bool binarySearch(int a[], int n, int x); // Câu 7
void xoaPhanTuX(int a[], int &n, int x); // Câu 8
void chenPhanTuX_MangTangDan(int a[], int &n, int x); // Câu 9
void bubleSort_TangDan(int a[], int n); // Câu 9
void daoNguocMang(int a[], int n); // Câu 10
bool kiemTraMangDoiXung(int a[], int n); // Câu 11
void ShowMenu(); // Hàm hiển thị menu


/// ===================================== CÀI ĐẶT CÁC HÀM ===================================== ///
// Hàm đọc file vào mảng đã cấp phát sẵn
bool readFile(const string& filename, int a[], int &n) 
{
    int i;
    ifstream file(filename);
    if (!file) {
        cout << "Không thể mở file!" << endl;
        return false;
    }

    file >> n;  // đọc số phần tử
    for (i = 0; i < n; i++) {
        file >> a[i];  // đọc từng phần tử vào mảng
    }

    file.close();
    return true;
}

// Hàm xuất
void xuat1c(int a[],int n)
{
    int i;
    for (i = 0; i < n; i++) 
        cout << a[i] <<" ";
    cout << endl;
}

// Câu 3: Tìm phần tử lớn nhất trong mảng
int timPhanTuLonNhat(int a[], int n) {
    int _max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > _max) {
            _max = a[i];
        }
    }
    return _max;
}

// Câu 4: Tìm phần tử nhỏ nhất trong mảng
int timPhanTuNhoNhat(int a[], int n) {
    int _min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < _min) {
            _min = a[i];
        }
    }
    return _min;
}

// Câu 5: Tính trung bình cộng các phần tử trong mảng
int tinhTrungBinhCong(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

// Câu 6: Đếm số lượng phần tử chẵn, lẻ và nguyên tố trong mảng
int demSoChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int demSoLe(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

bool checkSoNguyenTo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int demSoNguyenTo(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (checkSoNguyenTo(a[i])) {
            count++;
        }
    }
    return count;
}

// Câu 5: Sắp xếp mảng theo thứ tự giam dần bằng thuật toán Interchange sort
void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void interchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Câu 6: Đếm số lần xuất hiện của một phần tử x trong mảng
int soLanXuatHienX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

// Câu 7: Tìm kiếm phần tử x trong mảng (tìm kiếm tuần tự, tim kiếm nhị phân)
bool linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return true; 
        }
    }
    return false;
}

bool binarySearch(int a[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return true;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

// Câu 8: Xóa tất cả các phần tử có giá trị bằng x khỏi mảng
void xoaPhanTuX(int a[], int &n, int x) {
    int i = 0;
    while (i < n) {
        if (a[i] == x) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--; 
        }
        else
            i++;
    }
}

// Câu 9: Chèn một phần tử x vào mảng tại vị trí pos
void chenPhanTuX_MangTangDan(int a[], int &n, int x) {
    int i;
    while(n > 0 && a[n-1] > x)
    {
        a[n]=a[n-1];
        n--;
    }
    a[n] = x;
    n++;
}
void bubleSort_TangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
// Câu 10: Đảo ngược mảng
void daoNguocMang(int a[], int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
}

// Câu 11: Kiểm tra mảng có đối xứng hay không?
bool kiemTraMangDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            return false;
        }
    }
    return true;
}

// Hàm hiển thị menu
void ShowMenu()
{
    cout << "\n============================= MENU CHUC NANG =============================\n";
    cout << "\n0. Thoat chuong trinh\n";
    cout << "1. Xuat mang doc tu file\n";
    cout << "2. Tim min\n";
    cout << "3. Tim max\n";
    cout << "4. Tinh trung binh cong\n";
    cout << "5. Dem so chan, so le, so nguyen to\n";
    cout << "6. Sap xep mang giam dan\n";
    cout << "7. Tim kiem x (tuan tu, nhi phan)\n";
    cout << "8. Dem so lan xuat hien x \n";
    cout << "9. Xoa phan tu x\n";
    cout << "10. Chen phan tu x vao mang tang dan\n";
    cout << "11. Dao nguoc mang\n";
    cout << "12. Kiem tra mang doi xung\n";
    cout << "=========================================================================\n";
}


int main() {
    int a[100];  // mảng đủ lớn để chứa dữ liệu (ví dụ tối đa 100 phần tử)
    int n = 0, chucnang;

    cout << "================================ XUAT MANG DOC TU FILE ================================" << endl;
    if (readFile("data.txt", a, n)==true) 
        xuat1c(a,n);

    do{
        ShowMenu();
        cout << "\nNhap lua chon: ";
        cin >> chucnang;
        switch (chucnang)
        {
            case 1: {
                cout << "Xuat mang tu file: ";
                if (readFile("data.txt", a, n)==true) 
                    xuat1c(a,n);
                break;
            }
            case 2: {
                cout << "Gia tri nho nhat trong mang la: " << timPhanTuNhoNhat(a, n) << endl;
                break;
            }
            case 3: {
                cout << "Gia tri lon nhat trong mang la: " << timPhanTuLonNhat(a, n) << endl;
                break;
            }
            case 4: {
                cout << "Trung binh cong cac phan tu trong mang la: " << tinhTrungBinhCong(a, n) << endl;
                break;
            }
            case 5: {
                cout << "So luong so chan trong mang: " << demSoChan(a, n) << endl;
                cout << "So luong so le trong mang: " << demSoLe(a, n) << endl;
                cout << "So luong so nguyen to trong mang: " << demSoNguyenTo(a, n) << endl;
                break;
            }
            case 6: {
                interchangeSort(a, n);
                cout << "Mang sau khi sap xep giam dan: ";
                xuat1c(a, n);
                break;
            }
            case 7: {
                int x;
                cout << "Tim kiem phan tu x trong mang. " << endl;
                cout << "Nhap x: ";
                cin >> x;
                if (linearSearch(a, n, x)) {
                    cout << "Phan tu " << x << " co trong mang." << endl;
                } else {
                    cout << "Phan tu " << x << " khong co trong mang." << endl;
                }
                break; 
            }
            case 8: {
                int x;
                cout << "Dem so lan xuat hien cua phan tu x trong mang." << endl;
                cout << "Nhap x: ";
                cin >> x;
                cout << "Phan tu " << x << " xuat hien " << soLanXuatHienX(a, n, x) << " lan trong mang." << endl;
                break; 
            }
            case 9: {
                int x;
                cout << "Xoa phan tu x khoi mang." << endl;
                cout << "Nhap x: ";
                cin >> x;
                xoaPhanTuX(a, n, x);
                cout << "Mang sau khi xoa phan tu " << x << ": ";
                xuat1c(a, n);
                break; 
            }
            case 10: {
                int x;
                cout << "Chen phan tu x vao mang tang dan." << endl;
                cout << "Nhap x: ";
                cin >> x;
                cout << "Mang truoc khi chen phan tu " << x << ": ";
                bubleSort_TangDan(a, n);
                xuat1c(a, n);

                chenPhanTuX_MangTangDan(a, n, x);
                cout << "Mang sau khi chen phan tu " << x << ": ";
                xuat1c(a, n);
                break; 
            }
            case 11: {
                daoNguocMang(a, n);
                cout << "Mang sau khi dao nguoc: ";
                xuat1c(a, n);
                break; 
            }
            case 12: {
                if (kiemTraMangDoiXung(a, n)) {
                    cout << "Mang doi xung." << endl;
                } else {
                    cout << "Mang khong doi xung." << endl;
                }
                break; 
            }
            default: {
                if (chucnang != 0) {
                    cout << "Lua chon khong hop le. Vui long nhap lai !!!" << endl;
                    break;
                }
                else
                    cout << "Thoat chuong trinh. Hen gap lai!" << endl;
            }
        }
    } while (chucnang != 0);

    return 0;
}
