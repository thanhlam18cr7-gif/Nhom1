#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class HienVat {
private:
    string ten;
    string baoTang;
    vector<pair<string, string>> thongTin;  // cặp (nhãn, giá trị) giống <dt>/<dd>
    vector<string> moTa;                    // các đoạn mô tả giống <p>

public:
    HienVat(string ten, string baoTang) : ten(ten), baoTang(baoTang) {}

    void themThongTin(const string& nhan, const string& giaTri) {
        thongTin.push_back({nhan, giaTri});
    }

    void themMoTa(const string& doan) { moTa.push_back(doan); }

    // Hiển thị trên màn hình console (thay cho trình duyệt)
    void hienThi() const {
        cout << "==============================\n";
        cout << ten << "\n" << baoTang << "\n";
        cout << "==============================\n";
        for (const auto& tt : thongTin)
            cout << tt.first << ": " << tt.second << "\n";
        cout << "------------------------------\n";
        for (const auto& doan : moTa)
            cout << doan << "\n\n";
    }

    // Xuất ra file HTML, tương ứng với trang web ban đầu
    void xuatHTML(const string& tenFile) const {
        ofstream f(tenFile);
        f << "<!DOCTYPE html>\n<html lang=\"vi\">\n<head>\n"
          << "<meta charset=\"utf-8\">\n"
          << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
          << "<title>" << ten << "</title>\n</head>\n<body>\n<main>\n"
          << "<h1>" << ten << "</h1>\n<p>" << baoTang << "</p>\n<dl>\n";
        for (const auto& tt : thongTin)
            f << "<dt>" << tt.first << "</dt><dd>" << tt.second << "</dd>\n";
        f << "</dl>\n";
        for (const auto& doan : moTa)
            f << "<p>" << doan << "</p>\n";
        f << "</main>\n</body>\n</html>\n";
    }
};

int main() {
    HienVat hv("Áo dài của nguyên Phó Chủ tịch nước Nguyễn Thị Bình",
               "Bảo tàng Đà Nẵng");

    hv.themThongTin("Loại hiện vật", "Áo dài");
    hv.themThongTin("Gắn với", "Bà Nguyễn Thị Bình, nguyên Phó Chủ tịch nước");
    hv.themThongTin("Hiến tặng", "Câu lạc bộ Di sản Áo dài Đà Nẵng");
    hv.themThongTin("Lưu giữ tại", "Bảo tàng Đà Nẵng, 42 Bạch Đằng (31 Trần Phú), Hải Châu");

    hv.themMoTa("Đây là chiếc áo dài của bà Nguyễn Thị Bình, người phụ nữ đã đặt bút ký "
                "tên vào Hiệp định Paris năm 1973 về chấm dứt chiến tranh, lập lại hòa bình "
                "ở Việt Nam.");
    hv.themMoTa("Hiện vật do Câu lạc bộ Di sản Áo dài Đà Nẵng hiến tặng cho Bảo tàng Đà Nẵng.");

    hv.hienThi();
    hv.xuatHTML("hien_vat.html");
    cout << "Da xuat file hien_vat.html\n";
    return 0;
}
