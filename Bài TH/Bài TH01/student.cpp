// Mã số sinh viên: 25730093
// Họ và tên sinh viên: Kiều Quang Việt
// Ngày sinh: 11/06/2000
// Lớp: IT003.F11.CN1.CNTT
// Giảng viên: ThS. Mai Xuân Hùng

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Câu 1: Cấu trúc Student
struct Student {
    string mssv;
    string name;
    float dtb;
};

/// ===================================== NGUYÊN MẪU HÀM ===================================== ///
void readFile(const string &fileName, Student a[], int &n); // Hàm đọc file
void inDSSV(Student students[], int n); // Hàm in danh sách sinh viên
bool timSVTheoMSSV(const Student students[], int n, string mssv); // Hàm tìm sinh viên theo MSSV
void xuatThongTinSV_MSSV(const Student students[], int n, string mssv); // Hàm xuất thông tin sinh viên theo MSSV
void capNhatThongTinSV(Student students[], int n, string mssv, string newName, float newDtb); // Hàm cập nhật thông tin sinh viên
float timDiemTBMax(const Student students[], int n); // Hàm tìm điểm trung bình cao nhất
void xuatSVCoDiemTBMax(const Student students[], int n); // Hàm xuất sinh viên có điểm trung bình cao nhất
void sapXepTheoDiemTB(Student students[], int n); // Hàm sắp xếp sinh viên theo điểm trung bình tăng dần
void chenSV_MangTangDan(Student students[], int &n, Student newStudent); // Hàm chèn sinh viên vào mảng đã sắp xếp theo điểm trung bình tăng dần
void xoaSVTheoMSSV(Student students[], int &n, string mssv); // Hàm xóa sinh viên theo MSSV
void ShowMenu(); // Hàm hiển thị menu

/// ===================================== CÀI ĐẶT CÁC HÀM ===================================== ///


// Câu 2: Hàm đọc file
void readFile(const string &fileName, Student a[], int &n) {
    ifstream file(fileName);
    n = 0;
    if (!file) {
        cerr << "Khong mo duoc file " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string dtb_str;

        getline(ss, a[n].mssv, ',');
        getline(ss, a[n].name, ',');
        getline(ss, dtb_str, ',');
        a[n].dtb = stof(dtb_str);

        n++;
    }

    file.close();
}

// Câu 3: Hàm in danh sách sinh viên
void inDSSV(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << students[i].mssv << "\t"
             << students[i].name << "\t"
             << students[i].dtb << endl;
    }
}

// Câu 4: Hàm tìm sinh viên theo MSSV
bool timSVTheoMSSV(const Student students[], int n, string mssv) {
    for (int i = 0; i < n; i++) {
        if (students[i].mssv == mssv) {
            return true;
        }
    }
    return false;
}

void xuatThongTinSV_MSSV(const Student students[], int n, string mssv) {
    for (int i = 0; i < n; i++) {
        if (students[i].mssv == mssv) {
            cout << "Thong tin sinh vien:" << endl;
            cout << students[i].mssv << "\t"
                 << students[i].name << "\t"
                 << students[i].dtb << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi MSSV: " << mssv << endl;
}

// Câu 5: Hàm cập nhật thông tin sinh viên
void capNhatThongTinSV(Student students[], int n, string mssv, string newName, float newDtb) {
    for (int i = 0; i < n; i++) {
        if (students[i].mssv == mssv) {
            students[i].name = newName;
            students[i].dtb = newDtb;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi MSSV: " << mssv << endl;
}

// Câu 6: Hàm tìm điểm trung bình cao nhất
float timDiemTBMax(const Student students[], int n) {
    if (n == 0)
        return -1;
    
    float maxDtb = students[0].dtb;
    for (int i = 1; i < n; i++) {
        if (students[i].dtb > maxDtb) {
            maxDtb = students[i].dtb;
        }
    }
    return maxDtb;
}

// Câu 7: Hàm xuất sinh viên có điểm trung bình cao nhất
void xuatSVCoDiemTBMax(const Student students[], int n) {
    float maxDtb = timDiemTBMax(students, n);
    cout << "Sinh vien co diem trung binh cao nhat (" << maxDtb << "):" << endl;
    for (int i = 0; i < n; i++) {
        if (students[i].dtb == maxDtb) {
            cout << students[i].mssv << "\t"
                 << students[i].name << "\t"
                 << students[i].dtb << endl;
        }
    }
}

// Câu 8: Hàm sắp xếp sinh viên theo điểm trung bình tăng dần
void sapXepTheoDiemTB(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].dtb > students[j].dtb) {
                swap(students[i], students[j]);
            }
        }
    }
}

// Câu 9: Hàm chèn sinh viên vào mảng đã sắp xếp theo điểm trung bình tăng dần
void chenSV_MangTangDan(Student students[], int &n, Student newStudent) {
    int i = n - 1;
    while (i >= 0 && students[i].dtb > newStudent.dtb) {
        students[i + 1] = students[i];
        i--;
    }
    students[i + 1] = newStudent;
    n++;
}

// Câu 10: Hàm xóa sinh viên theo MSSV
void xoaSVTheoMSSV(Student students[], int &n, string mssv) {
    for (int i = 0; i < n; i++) {
        if (students[i].mssv == mssv) {       
            for (int j = i; j < n - 1; j++) {
                students[j] = students[j + 1];
            }
            n--;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi MSSV: " << mssv << endl;
}

// Câu 11: Hàm hiển thị menu
void ShowMenu()
{
{
    cout << "\n============================= MENU CHUC NANG =============================\n";
    cout << "\n0. Thoat chuong trinh\n";
    cout << "1. Xuat danh sach sinh vien hien tai\n";
    cout << "2. Tim sinh vien theo MSSV\n";
    cout << "3. Cap nhat thong tin sinh vien\n";
    cout << "4. Tim diem trung binh cao nhat\n";
    cout << "5. Xuat sinh vien co diem trung binh cao nhat\n";
    cout << "6. Sap xep sinh vien theo diem trung binh tang dan\n";
    cout << "7. Chen sinh vien vao mang da sap xep theo diem trung binh tang dan\n";
    cout << "8. Xoa sinh vien theo MSSV\n";
    cout << "=========================================================================\n";
}


int main() {
    const int MAX = 100;
    Student students[MAX];
    int n, chucnang;

    readFile("students.txt", students, n);
    do {
        ShowMenu();
        cout << "\nNhap lua chon: ";
        cin >> chucnang;
        switch (chucnang)
        {
            case 1: {
                cout << "Danh sach sinh vien:" << endl;
                inDSSV(students, n);
                break;
            }
            case 2: {
                string mssv;
                cout << "Nhap MSSV can tim: ";
                cin >> mssv;
                if (timSVTheoMSSV(students, n, mssv)) {
                    cout << "Sinh vien co MSSV " << mssv << " ton tai." << endl;
                    xuatThongTinSV_MSSV(students, n, mssv);
                } else {
                    cout << "Khong tim thay sinh vien voi MSSV: " << mssv << endl;
                }
                break;
            }
            case 3: {
                string mssv, newName;
                float newDtb;
                cout << "Nhap MSSV sinh vien can cap nhat: ";
                cin >> mssv;
                cout << "Nhap ten moi: ";
                cin.ignore();
                getline(cin, newName);
                cout << "Nhap diem trung binh moi: ";
                cin >> newDtb;
                capNhatThongTinSV(students, n, mssv, newName, newDtb);
                break;
            }
            case 4: {
                float maxDtb = timDiemTBMax(students, n);
                if (maxDtb != -1) {
                    cout << "Diem trung binh cao nhat la: " << maxDtb << endl;
                } else {
                    cout << "Danh sach sinh vien rong." << endl;
                }
                break;
            }
            case 5: {
                xuatSVCoDiemTBMax(students, n);
                break;
            }
            case 6: {
                sapXepTheoDiemTB(students, n);
                cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh tang dan:" << endl;
                inDSSV(students, n);
                break;
            }
            case 7: {
                Student newStudent;
                cout << "Nhap MSSV sinh vien can chen: ";
                cin >> newStudent.mssv;
                cout << "Nhap ten sinh vien: ";
                cin.ignore();
                getline(cin, newStudent.name);
                cout << "Nhap diem trung binh sinh vien: ";
                cin >> newStudent.dtb;
                chenSV_MangTangDan(students, n, newStudent);
                cout << "Danh sach sinh vien sau khi chen:" << endl;
                inDSSV(students, n);
                break;
            }
            case 8: {
                string mssv;
                cout << "Nhap MSSV sinh vien can xoa: ";
                cin >> mssv;
                xoaSVTheoMSSV(students, n, mssv);
                cout << "Danh sach sinh vien sau khi xoa:" << endl;
                inDSSV(students, n);
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