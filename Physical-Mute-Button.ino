#include "M5Atom.h"
#include "BleKeyboard.h"

BleKeyboard bleKeyboard("Zoom Mute Button", "Fufu Fang", 100);;

void KbdLedCb(KbdLeds *kbls)
{
    if (kbls->bmScrollLock) {
        M5.dis.setBrightness(100);
        M5.dis.fillpix(CRGB::Green);
    } else {
        M5.dis.setBrightness(100);
        M5.dis.fillpix(CRGB::Black);
        for (int i = 0; i < 5; i += 4) {
            for (int j = 0; j < 5; j += 4) {
                M5.dis.drawpix(i, j, CRGB::Green);
            }
        }
    }
}

void setup()
{
    M5.begin(false, false, true);
    delay(10);
    M5.dis.setBrightness(20);
    M5.dis.fillpix(CRGB::Black);

    bleKeyboard.begin();
    /* must have delay for the BLE  finish initalisation */
    delay(1000);
    bleKeyboard.setLedChangeCallBack(KbdLedCb);
}

int brightness = 0;
int increment = 0;
void loop()
{
  if(bleKeyboard.isConnected()) {
    if (M5.Btn.wasPressed()) {
      bleKeyboard.press(KEY_SCROLL_LOCK);
      delay(50);
      bleKeyboard.releaseAll();
    }
  } else {
    M5.dis.fillpix(CRGB::Blue);
    if (brightness <= 0) {
      increment = 2;
    } else if (brightness >= 100) {
      increment = -2;
    }
    brightness += increment;
    M5.dis.setBrightness(brightness);
  }
  // Don't ask me why these have to be in the loop, they just do.
  M5.update();
  delay(50);
}
