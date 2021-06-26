
#include "M5Atom.h"
#include "BleKeyboard.h"

uint8_t DisBuff[2 + 5 * 5 * 3];
BleKeyboard bleKeyboard("Mute Button", "M5Stack Atom Matrix", 100);;

void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
    DisBuff[0] = 0x05;
    DisBuff[1] = 0x05;
    for (int i = 0; i < 25; i++)
    {
        DisBuff[2 + i * 3 + 0] = Rdata;
        DisBuff[2 + i * 3 + 1] = Gdata;
        DisBuff[2 + i * 3 + 2] = Bdata;
    }
}

void setup()
{
    M5.begin(false, false, true);
    delay(10);
    setBuff(0x00, 0x00, 0x00);
    M5.dis.displaybuff(DisBuff);

    bleKeyboard.begin();
}

bool muted = false;
int blue_level = 0;
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
    if (muted) {
      setBuff(0xff, 0x00, 0x00);
    } else {
      setBuff(0x00, 0x00, 0x00);
    }
  } else {
    muted = false;
    if (blue_level < 10) {
      increment = 10;
    } else if (blue_level > 240) {
      increment = -10;
    }
    blue_level += increment;
    setBuff(0x00, 0x00, blue_level);
  }
  // Don't ask me why these have to be in the loop, they just do.
  M5.dis.displaybuff(DisBuff);
  M5.update();
  delay(50);
}
