#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Konfigurasi OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Variabel teks yang akan di-scroll
String text = "KALIAN BUNGUL";
int textWidth;
int x = SCREEN_WIDTH;

void setup() {
  // Inisialisasi serial monitor
  Serial.begin(115200);
  
  // Inisialisasi OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Bersihkan layar OLED
  display.clearDisplay();
  display.display();

  // Atur ukuran font
  display.setTextSize(2); // Ukuran besar
  display.setTextColor(SSD1306_WHITE);

  // Hitung panjang teks
  textWidth = text.length() * 12; // Kira-kira 12 pixel per karakter (font ukuran 2)
}

void loop() {
  // Bersihkan layar sebelum menggambar
  display.clearDisplay();

  // Gambar teks pada posisi x
  display.setCursor(x, (SCREEN_HEIGHT / 2) - 8); // Teks di tengah vertikal
  display.print(text);

  // Perbarui layar
  display.display();

  // Geser teks ke kiri
  x--;

  // Jika teks keluar dari layar, mulai lagi dari kanan
  if (x < -textWidth) {
    x = SCREEN_WIDTH;
  }

  // Tambahkan delay untuk memperlambat scrolling
  delay(30);
}
