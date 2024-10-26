#ifndef PHIM_H
#define PHIM_H

#include <string>

class Phim {
private:
    std::string tenPhim;
    int thoiLuong; // thoi luong phim tinh bang phut
    int namXuatBan;
    std::string theLoai;
    double danhGia; // danh gia tu 1-10

public:
    Phim(std::string ten, int thoiLuong, int nam, std::string theLoai, double danhGia);
    
    std::string getTenPhim() const;
    int getThoiLuong() const;
    int getNamXuatBan() const;
    std::string getTheLoai() const;
    double getDanhGia() const;
    
    void hienThiThongTin() const;
    void xemPhim() const; // Chuc nang xem phim
};

#endif

