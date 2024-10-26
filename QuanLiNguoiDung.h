#ifndef QUANLYNGUOIDUNG_H
#define QUANLYNGUOIDUNG_H

#include <string>
#include "Phim.h"

class NguoiDung {
protected:
    std::string tenDangNhap;
    std::string matKhau;

public:
    NguoiDung(std::string ten, std::string mk);
    virtual void hienThiMenu() = 0; // Ham ao thuan tuy
    std::string getTenDangNhap() const;
};

class Admin : public NguoiDung {
public:
    Admin(std::string ten, std::string mk);
    void hienThiMenu() override;
    void themPhim(Phim** dsPhim, int& soLuongPhim);
    void xoaPhim(Phim** dsPhim, int& soLuongPhim);
};

class ThanhVien : public NguoiDung {
private:
    Phim** dsPhimYeuThich;
    int soLuongPhimYeuThich;

public:
    ThanhVien(std::string ten, std::string mk);
    ~ThanhVien();
    void hienThiMenu() override;
    void themPhimYeuThich(Phim* phim);
    void hienThiDanhSachYeuThich();
    void timKiemPhim(Phim** dsPhim, int soLuongPhim);
};

#endif

