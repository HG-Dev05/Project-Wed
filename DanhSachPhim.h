#ifndef DANHSACHPHIM_H
#define DANHSACHPHIM_H

#include "Phim.h"

class DanhSachPhim {
private:
    Phim* danhSach;
    int soLuongPhim;

public:
    DanhSachPhim();
    ~DanhSachPhim();

    void themPhim(const Phim& phim);
    void xoaPhim(const std::string& tenPhim);
    void timKiemPhim(const std::string& tenPhim) const;
    void hienThiDanhSach() const;
    void sapXepPhimTheoNam();
    void luuDanhSach(const std::string& tenFile) const;
    void taiDanhSach(const std::string& tenFile);
};

#endif

