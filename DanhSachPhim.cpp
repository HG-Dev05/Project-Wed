#include "DanhSachPhim.h"
#include <iostream>
#include <fstream>

DanhSachPhim::DanhSachPhim() : danhSach(Null), soLuongPhim(0) {}

DanhSachPhim::~DanhSachPhim() {
    delete[] danhSach;
}

// Them phim vao danh sach
void DanhSachPhim::themPhim(const Phim& phim) {
    Phim* temp = new Phim[soLuongPhim + 1];
    for (int i = 0; i < soLuongPhim; ++i) {
        temp[i] = danhSach[i];
    }
    temp[soLuongPhim] = phim;
    delete[] danhSach;
    danhSach = temp;
    soLuongPhim++;
}

// Xoa phim theo ten
void DanhSachPhim::xoaPhim(const std::string& tenPhim) {
    int viTri = -1;
    for (int i = 0; i < soLuongPhim; ++i) {
        if (danhSach[i].getTenPhim() == tenPhim) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        std::cout << "Khong tim thay phim" << std::endl;
        return;
    }

    Phim* temp = new Phim[soLuongPhim - 1];
    for (int i = 0, j = 0; i < soLuongPhim; ++i) {
        if (i != viTri) {
            temp[j++] = danhSach[i];
        }
    }

    delete[] danhSach;
    danhSach = temp;
    soLuongPhim--;
}

// Tim kiem phim theo ten
void DanhSachPhim::timKiemPhim(const std::string& tenPhim) const {
    for (int i = 0; i < soLuongPhim; ++i) {
        if (danhSach[i].getTenPhim() == tenPhim) {
            danhSach[i].hienThi();
            return;
        }
    }
    std::cout << "Khong tim thay phim" << std::endl;
}

// Hien thi danh sach phim
void DanhSachPhim::hienThiDanhSach() const {
    for (int i = 0; i < soLuongPhim; ++i) {
        danhSach[i].hienThi();
        std::cout << std::endl;
    }
}

// Sap xep phim theo nam phat hanh
void DanhSachPhim::sapXepPhimTheoNam() {
    for (int i = 0; i < soLuongPhim - 1; ++i) {
        for (int j = i + 1; j < soLuongPhim; ++j) {
            if (danhSach[i].getNamPhatHanh() > danhSach[j].getNamPhatHanh()) {
                Phim temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

// Luu danh sach phim vao file
void DanhSachPhim::luuDanhSach(const std::string& tenFile) const {
    std::ofstream outFile(tenFile);
    for (int i = 0; i < soLuongPhim; ++i) {
        outFile << danhSach[i].getTenPhim() << '\n'
                << danhSach[i].getTheLoai() << '\n'
                << danhSach[i].getNamPhatHanh() << '\n'
                << danhSach[i].getDaoDien() << '\n';
    }
    outFile.close();
}

// Tai danh sach phim tu file
void DanhSachPhim::taiDanhSach(const std::string& tenFile) {
    std::ifstream inFile(tenFile);
    if (!inFile) {
        std::cout << "Khong the mo file!" << std::endl;
        return;
    }

    std::string ten, theLoai, daoDien;
    int nam;
    while (getline(inFile, ten) && getline(inFile, theLoai) && inFile >> nam && inFile.ignore() && getline(inFile, daoDien)) {
        themPhim(Phim(ten, theLoai, nam, daoDien));
    }

    inFile.close();
}

