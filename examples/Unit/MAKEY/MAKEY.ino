/*
 * SPDX-FileCopyrightText: 2025 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
/*
 * @Hardwares: M5Core + Unit ?
 * @Platform Version: Arduino M5Stack Board Manager v2.1.3
 * @Dependent Library:
 * M5Stack@^0.4.6: https://github.com/m5stack/M5Stack
 */

#include <M5Stack.h>

#define NOTE_D1  (294)
#define NOTE_DL1 (261)
#define NOTE_DL2 (293)
#define NOTE_DL3 (329)
#define NOTE_DL4 (349)
#define NOTE_DL5 (392)
#define NOTE_DL6 (440)
#define NOTE_DL7 (494)

void setup()
{
    M5.begin();             // Init M5Stack.  初始化M5Stack
    M5.Power.begin();       // Init power  初始化电源模块
    M5.lcd.setTextSize(2);  // Set the text size to 2.  设置文字大小为2
    M5.Lcd.println("M5Stack Makey Piano.");
    Wire.begin();  // Wire init, adding the I2C bus.  Wire初始化, 加入i2c总线
}

int Key1 = 0, Key2 = 0, Index = 0;
void showKey()
{
    M5.Lcd.setCursor(20, 200);
    M5.Lcd.setTextColor(BLUE, BLACK);
    M5.Lcd.print(Index);
    M5.Lcd.print("   ");

    M5.Lcd.setCursor(5 + 0 * 16, 110);
    if ((Key1 & (0x01 << 0)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL1, 20);
    }
    M5.Lcd.print("1");
    M5.Lcd.setCursor(5 + 1 * 16, 110);
    if ((Key1 & (0x01 << 1)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL2, 20);
    }
    M5.Lcd.print("2");
    M5.Lcd.setCursor(5 + 2 * 16, 110);
    if ((Key1 & (0x01 << 2)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL3, 20);
    }
    M5.Lcd.print("3");
    M5.Lcd.setCursor(5 + 3 * 16, 110);
    if ((Key1 & (0x01 << 3)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL4, 20);
    }
    M5.Lcd.print("4");
    M5.Lcd.setCursor(5 + 4 * 16, 110);
    if ((Key1 & (0x01 << 4)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL5, 20);
    }
    M5.Lcd.print("5");
    M5.Lcd.setCursor(5 + 5 * 16, 110);
    if ((Key1 & (0x01 << 5)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL6, 20);
    }
    M5.Lcd.print("6");
    M5.Lcd.setCursor(5 + 6 * 16, 110);
    if ((Key1 & (0x01 << 6)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_DL7, 20);
    }
    M5.Lcd.print("7");

    M5.Lcd.setCursor(10 + 7 * 16, 110);
    if ((Key1 & (0x01 << 7)) == 0x00)
        M5.Lcd.setTextColor(WHITE, BLACK);
    else {
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Speaker.tone(NOTE_D1, 20);
    }
}

int CommandStatus = 0;
void loop()
{
    Wire.requestFrom(0x51, 2);
    while (Wire.available()) {
        Key1 = Wire.read();
        Key2 = Wire.read();
        Index++;
    }
    showKey();
    // delay(10);
    M5.update();
}