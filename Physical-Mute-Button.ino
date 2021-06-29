
#include "M5Atom.h"
#include "BleKeyboard.h"

BleKeyboard bleKeyboard("Mute Button", "M5Stack Atom Matrix", 100);;

void setup()
{
    M5.begin(false, false, true);
    delay(10);
    M5.dis.fillpix(CRGB::Black);
    bleKeyboard.begin();
}

bool muted = false;
int brightness = 0;
int increment = 0;
void loop()
{
  if(bleKeyboard.isConnected()) {
    if (M5.Btn.wasPressed()) {
      muted = !muted;
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('M');
      delay(100);
      bleKeyboard.releaseAll();
    }
    M5.dis.setBrightness(100);
    if (muted) {
      M5.dis.fillpix(CRGB::Green);
    } else {
      M5.dis.fillpix(CRGB::Black);
    }
  } else {
    muted = false;
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
