#include <stdio.h>
#include <math.h>

// Hàm chuyển đổi số thập phân sang nhị phân
int dec2bin(int n) {
  int bin = 0;
  int i = 1;
  while (n > 0) {
    bin += (n % 2) * i;
    n /= 2;
    i *= 10;
  }
  return bin;
}

// Hàm chuyển đổi số thập phân sang dạng chuẩn IEEE 754 độ chính xác đơn
void dec2ieee(float x) {
  // Kiểm tra số âm hay dương
  int sign = (x < 0) ? 1 : 0;
  // Lấy giá trị tuyệt đối
  x = fabs(x);
  // Tìm số mũ và phần nguyên
  int exp = 0;
  int int_part = 0;
  if (x >= 1) {
    // Nếu số lớn hơn hoặc bằng 1, dịch phẩy sang trái cho đến khi có dạng 1.xxxx
    while (x >= 2) {
      x /= 2;
      exp++;
    }
    int_part = 1;
  } else if (x > 0) {
    // Nếu số nhỏ hơn 1 và lớn hơn 0, dịch phẩy sang phải cho đến khi có dạng 1.xxxx
    while (x < 1) {
      x *= 2;
      exp--;
    }
    int_part = 1;
  }
  // Tính phần mũ theo công thức e = exp + 127
  int e = exp + 127;
  // Chuyển phần mũ sang nhị phân
  int e_bin = dec2bin(e);
  // Tính phần thập phân
  float dec_part = x - int_part;
  // Chuyển phần thập phân sang nhị phân
  int dec_bin = 0;
  int i = 1;
  for (int j = 0; j < 23; j++) {
    dec_part *= 2;
    int bit = (int) dec_part;
    dec_bin += bit * i;
    dec_part -= bit;
    i *= 10;
  }
  // In kết quả
  printf("Sign: %d\n", sign);
  printf("Exponent: %d (%d in binary)\n", e, e_bin);
  printf("Mantissa: %d (%d in binary)\n", int_part, dec_bin);
  printf("IEEE 754: %d%d%d\n", sign, e_bin, dec_bin);
}

// Hàm chính để kiểm tra
int main() {
  float x;
  printf("Enter a decimal number: ");
  scanf("%f", &x);
  dec2ieee(x);
  return 0;
}
