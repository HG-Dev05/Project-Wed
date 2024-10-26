#include "QuanLyNguoiDung.h"
#include <iostream>

// Dinh nghia class NguoiDung
NguoiDung::NguoiDung(std::string ten, std::string mk)
    : tenDangNhap(ten), matKhau(mk) {}

std::string NguoiDung::getTenDangNhap() const { return tenDangNhap; }

// Dinh nghia class Admin
Admin::Admin(std::string ten, std::string mk)
    : NguoiDung(ten, mk) {}

void Admin::hienThiMenu() {
    std::cout << "1. Them phim\n";
    std::cout << "2. Xoa phim\n";
}

void Admin::themPhim(Phim** dsPhim, int& soLuongPhim) {
    std::string ten, theLoai;
    int thoiLuong, nam;
    double danhGia;

    std::cout << "Nhap ten phim: ";
    std::cin >> ten;
    std::cout << "Nhap thoi luong: ";
    std::cin >> thoiLuong;
    std::cout << "Nhap nam xuat ban: ";
    std::cin >> nam;
    std::cout << "Nhap the loai: ";
    std::cin >> theLoai;
    std::cout << "Nhap danh gia: ";
    std::cin >> danhGia;

    dsPhim[soLuongPhim++] = new Phim(ten, thoiLuong, nam, theLoai, danhGia);
}

void Admin::xoaPhim(Phim** dsPhim, int& soLuongPhim) {
    std::string ten;
    std::cout << "Nhap ten phim can xoa: ";
    std::cin >> ten;

    for (int i = 0; i < soLuongPhim; i++) {
        if (dsPhim[i]->getTenPhim() == ten) {
            delete dsPhim[i];
            dsPhim[i] = dsPhim[soLuongPhim - 1];
            soLuongPhim--;
            break;
        }
    }
}

// Dinh nghia class ThanhVien
ThanhVien::ThanhVien(std::string ten, std::string mk)
    : NguoiDung(ten, mk), soLuongPhimYeuThich(0) {
    dsPhimYeuThich = new Phim*[100]; // Mang dong
}

ThanhVien::~ThanhVien() {
    delete[] dsPhimYeuThich;
}

void ThanhVien::hienThiMenu() {
    std::cout << "1. Tim phim\n";
    std::cout << "2. Them phim yeu thich\n";
    std::cout << "3. Hien thi danh sach phim yeu thich\n";
    std::cout << "4. Xem phim\n";
}

void ThanhVien::themPhimYeuThich(Phim* phim) {
    dsPhimYeuThich[soLuongPhimYeuThich++] = phim;
}

void ThanhVien::hienThiDanhSachYeuThich() {
    std::cout << "Danh sach phim yeu thich:\n";
    for (int i = 0; i < soLuongPhimYeuThich; i++) {
        dsPhimYeuThich[i]->hienThiThongTin();
    }
}

void ThanhVien::timKiemPhim(Phim** dsPhim, int soLuongPhim) {
    std::string tuKhoa;
    std::cout << "Nhap ten phim hoac the loai de tim: ";
    std::cin >> tuKhoa;

    bool timThay = false;
    for (int i = 0; i < soLuongPhim; i++) {
        if (dsPhim[i]->getTenPhim().find(tuKhoa) != std::string::npos ||
            dsPhim[i]->getTheLoai().find(tuKhoa) != std::string::npos) {
            dsPhim[i]->hienThiThongTin();
            timThay = true;
        }
    }
    if (!timThay) {
        std::cout << "Khong tim thay phim nao!\n";
    }
}

