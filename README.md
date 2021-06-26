# Physical-Mute-Button
This is an Arduino sketch for a physical mute button suitable for Zoom and Microsoft Teams. 

## Hardware requirement
You need a M5Stack Atom Matrix. You can buy them from various places. I have listed a few
below. 
 - https://shop.pimoroni.com/products/atom-matrix-esp32-development-kit
 - https://thepihut.com/products/atom-matrix-esp32-development-kit
 - https://www.adafruit.com/product/4497
 - https://shop.m5stack.com/products/atom-matrix-esp32-development-kit?variant=39524837195948

M5Stack Atom Matrix contains a 5x5 RGB LED array with a physical button beneath. This means
that you can press on the LED array, and trigger actions. 

## How does it work
This sketch configures M5Stack Atom Matrix into a Bluetooth Keyboard. After you pair it
with your computer, pressing the Atom Matrix's button sends ``Ctrl + Shift + M`` to your
computer, which is the keyboard shortcut for mute on Microsoft Teams. You can configure
your Zoom to share the same mute keyboard shortcut as Microsoft Teams. (This is what I did)

**Please note that the LED status of the button is NOT automatically synchronised with
the Zoom or Microsoft Teams.** This means that if you change the mute settings without
using the button, the LED of the button will not change automatically. 

## How to set it up
### Flashing the M5Stack Atom Matrix
 1. Clone this repository
 2. Follow the guide [here](https://docs.m5stack.com/en/arduino/arduino_development) to 
set up Arduino IDE. Note that you need both the ``M5Stack-Atom`` board manager and the 
``M5Atom`` library.
 2. Install the [ESP32 BLE Keyboard library](https://github.com/T-vK/ESP32-BLE-Keyboard)
 3. Open this sketch, and flash it onto your M5Stack Atom Matrix. 

### Software configuration
 1. On your operating system, search for Bluetooth Device, and pair with ``Mute Button``.
 2. To use this button with Zoom, change Zoom's shortcut for "Mute/unmute my audio" from
``Alt + A`` to ``Ctrl + Shift + M``. I decided to set the key presses to Microsoft Teams's
mute shortcut, because you cannot change Microsoft Teams's keyboard shortcuts, whereas you
can change Zoom's. 

Before successful pairing, the mute button flashes blue. After successful pairing, the
mute button goes dark. Afte pressing it, it turns red. 

## Why
I was issued a Plantronics C3200 headset, which contains a mute button that synchronises
with Microsoft Teams and Zoom. However the LED is not big or bright enough. I saw various
tutorials on the Internet on setting up Zoom mute buttons. I find those setups a bit
clunky - some of them do not have LED indication, some of them require breadboard which
is not very neat. 

## Possible improvements
Both Zoom and Microsoft Teams have APIs to query the state of the call. You can use those
APIs to mute the call directly. This would be better than issuing a keyboard shortcut.
However these require more efforts than I am willing to give. 

## License
This repository is licensed under GPLv3.

    Physical Mute Button
    Copyright (C) 2021  Fufu Fang

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

