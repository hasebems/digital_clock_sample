Digital Clock Sample
======================

ラズパイpicoと4桁の7segLEDで、Digital Clockを作成します。
ラズパイpicoには、RTC(realtime clock)機能があり、ハードウェアで時刻を持つことが出来ます。
このプログラムでは、RTCに時間を設定し、そこから時間を取得して、7segLEDにその時間を表示します。

This project creates a digital clock using a Raspberry Pi Pico and a 4-digit 7-segment LED display.
The Raspberry Pi Pico has an RTC (Real Time Clock) function that can maintain time in hardware.
In this program, we set the time on the RTC, retrieve the time from it, and display that time on the 7-segment LED.


ラズパイのRTCを動かす
---------------------

- RTCを動かすには以下の2つのライブラリが必要
    - RP2040_RTC
    - TimeLib
- RP2040_RTC
    - Library Manager でRP2040_RTCを選び、インストール（なぜか最初エラーが出たが、ボードやライブラリを最新にしたらインストール出来た）
- TimeLib
    - https://github.com/PaulStoffregen/Time
    - 上記サイトのマニュアルにAPIが記載されているので、必要に応じて参照のこと
    - .zipを落として、「スケッチ」->「ライブラリをインクルード」->「.zip形式のライブラリをインストール」でファイルを指定
- スケッチ例から RP2040_RTC_Time をロードし、#include <TimeLib> を追加して、コンパイル

Running the Raspberry Pi RTC
-----------------------------

- Two libraries are required to run the RTC
    - RP2040_RTC
    - TimeLib
- RP2040_RTC
    - Select RP2040_RTC in Library Manager and install (I encountered an error at first, but it installed successfully after updating the board and libraries to the latest versions)
- TimeLib
    - https://github.com/PaulStoffregen/Time
    - The API is documented in the manual on the above site, so refer to it as needed
    - Download the .zip file and install it via "Sketch" -> "Include Library" -> "Add .ZIP Library..."
- Load RP2040_RTC_Time from sketch examples, add #include <TimeLib>, and compile

ラズパイで7segLEDを光らせる
---------------------------

- TM1637 のライブラリを使用
    - https://github.com/avishorp/TM1637
    - Library Manager で TM1637 を選び、インストール

Lighting up the 7-segment LED with Raspberry Pi
------------------------------------------------

- Use the TM1637 library
    - https://github.com/avishorp/TM1637
    - Select TM1637 in Library Manager and install
