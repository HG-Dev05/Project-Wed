#include <iostream>
#include <string>
#include "Phim.h"
#include "DanhSachPhim.h"
#include "QuanLiNguoiDung"
void hienThiMenu() {
    std::cout << "================ Quan Ly Trang Xem Phim Online ================\n";
    std::cout << "1. Dang ky tai khoan\n";
    std::cout << "2. Dang nhap\n";
    std::cout << "3. Them phim moi\n";
    std::cout << "4. Xoa phim\n";
    std::cout << "5. Tim kiem phim\n";
    std::cout << "6. Hien thi danh sach phim\n";
    std::cout << "7. Sap xep phim theo nam phat hanh\n";
    std::cout << "8. Luu danh sach phim vao file\n";
    std::cout << "9. Tai danh sach phim tu file\n";
    std::cout << "0. Thoat\n";
    std::cout << "===============================================================\n";
    std::cout << "Chon chuc nang: ";
}

int main() {
    DanhSachPhim danhSachPhim;
    DanhSachNguoiDung danhSachNguoiDung;
    int luaChon;
    std::string tenPhim, theLoai, daoDien, tenNguoiDung, matKhau;
    int nam;

    do {
        hienThiMenu();
        std::cin >> luaChon;

        switch (luaChon) {
            case 1:
                std::cout << "Nhap ten nguoi dung: ";
                std::cin.ignore();
                std::getline(std::cin, tenNguoiDung);
                std::cout << "Nhap mat khau: ";
                std::getline(std::cin, matKhau);
                danhSachNguoiDung.dangKy(tenNguoiDung, matKhau);
                break;
            case 2:
                std::cout << "Nhap ten nguoi dung: ";
                std::cin.ignore();
                std::getline(std::cin, tenNguoiDung);
                std::cout << "Nhap mat khau: ";
                std::getline(std::cin, matKhau);
                if (danhSachNguoiDung.dangNhap(tenNguoiDung, matKhau)) {
                    std::cout << "Dang nhap thanh cong!\n";
                } else {
                    std::cout << "Ten nguoi dung hoac mat khau sai!\n";
                }
                break;
            case 3:
                std::cout << "Nhap ten phim: ";
                std::cin.ignore();
                std::getline(std::cin, tenPhim);
                std::cout << "Nhap the loai: ";
                std::getline(std::cin, theLoai);
                std::cout << "Nhap nam phat hanh: ";
                std::cin >> nam;
                std::cin.ignore();
                std::cout << "Nhap dao dien: ";
                std::getline(std::cin, daoDien);
                danhSachPhim.themPhim(Phim(tenPhim, theLoai, nam, daoDien));
                std::cout << "Da them phim moi!\n";
                break;
            case 4:
                std::cout << "Nhap ten phim can xoa: ";
                std::cin.ignore();
                std::getline(std::cin, tenPhim);
                danhSachPhim.xoaPhim(tenPhim);
                break;
            case 5:
                std::cout << "Nhap ten phim can tim: ";
                std::cin.ignore();
                std::getline(std::cin, tenPhim);
                danhSachPhim.timKiemPhim(tenPhim);
                break;
            case 6:
                danhSachPhim.hienThiDanhSach();
                break;
            case 7:
                danhSachPhim.sapXepPhimTheoNam();
                std::cout << "Danh sach phim da duoc sap xep theo nam phat hanh!\n";
                break;
            case 8:
                danhSachPhim.luuDanhSach("phim.txt");
                std::cout << "Da luu danh sach phim vao file!\n";
                break;
            case 9:
                danhSachPhim.taiDanhSach("phim.txt");
                std::cout << "Da tai danh sach phim tu file!\n";
                break;
            case 0:
                std::cout << "Thoat chuong trinh...\n";
                break;
            default:
                std::cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }

    } while (luaChon != 0);

    return 0;
}

