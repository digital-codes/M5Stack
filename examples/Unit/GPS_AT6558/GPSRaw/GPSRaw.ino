/*
 * SPDX-FileCopyrightText: 2025 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
/*
 * @Hardwares: M5Core + Unit GPS
 * @Platform Version: Arduino M5Stack Board Manager v2.1.3
 * @Dependent Library:
 * M5GFX@^0.2.3: https://github.com/m5stack/M5GFX
 * M5Unified@^0.2.2: https://github.com/m5stack/M5Unified
 */

#include <M5Unified.h>
#include "M5GFX.h"

HardwareSerial GPSRaw(2);

M5GFX display;
M5Canvas canvas(&display);

void setup()
{
    M5.begin();
    M5.Power.begin();
    GPSRaw.begin(9600);

    display.begin();

    canvas.setColorDepth(1);  // mono color
    canvas.setFont(&fonts::efontCN_14);
    canvas.createSprite(display.width(), display.height());
    canvas.setTextSize(2);
    canvas.setPaletteColor(1, GREEN);
    canvas.setTextScroll(true);

    canvas.println("GPS Raw Example");
    canvas.pushSprite(0, 0);
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (Serial.available()) {
        int ch = Serial.read();
        GPSRaw.write(ch);
    }

    if (GPSRaw.available()) {
        int ch = GPSRaw.read();
        Serial.write(ch);
        canvas.print(ch);
        canvas.pushSprite(0, 0);
    }
}
