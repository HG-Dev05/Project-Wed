#include "Phim.h"
#include <iostream>

Phim::Phim(std::string ten, int thoiLuong, int nam, std::string theLoai, double danhGia)
    : tenPhim(ten), thoiLuong(thoiLuong), namXuatBan(nam), theLoai(theLoai), danhGia(danhGia) {}

std::string Phim::getTenPhim() const { return tenPhim; }

int Phim::getThoiLuong() const { return thoiLuong; }

int Phim::getNamXuatBan() const { return namXuatBan; }

std::string Phim::getTheLoai() const { return theLoai; }

double Phim::getDanhGia() const { return danhGia; }

void Phim::hienThiThongTin() const {
    std::cout << "Ten phim: " << tenPhim << "\n";
    std::cout << "Thoi luong: " << thoiLuong << " phut\n";
    std::cout << "Nam xuat ban: " << namXuatBan << "\n";
    std::cout << "The loai: " << theLoai << "\n";
    std::cout << "Danh gia: " << danhGia << "/10\n";
}

void Phim::xemPhim() const {
    std::cout << "Ban dang xem phim: " << tenPhim << "\n";
}

