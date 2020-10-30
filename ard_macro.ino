#include <Keyboard.h>
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>

#define PIN 16
#define NUMPIXELS 4

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
char keys[ROWS][COLS] = { // Define the Keymap
  {'1', '2', '3', '^'},   //R0
  {'4', '5', '6', 'v'},   //R1
  {'7', '8', '9', 'C'},   //R2
  {'*', '0', '#', 'D'}    //R3
  };                      //   C0 C1 C2 C3
byte rowPins[ROWS] = {2,3,4,5};  // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = {6,7,8,9};  // Connect keypad COL0, COL1 COL2, and COL3 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );  // Create the Keypad
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Initialize NeoPixel library

int mode = 3;

void setup()  {
  pixels.clear();
  pixels.setPixelColor(mode, 20, 0, 0);
  //kpd.setDebounceTime(250);
  pixels.begin();
}

void loop()  {
  char key = kpd.getKey();

  if (key)  {
    switch (key)  {
      case 'A': mode = 3; break;
      case 'B': mode = 2; break;
      case 'C': mode = 1; break;
      case 'D': mode = 0; break; 
      case 'v':
        mode--;
        if (mode < 0) {
          mode = 3;
        }
      break;
      case '^':
        mode++;
        if (mode > 3) {
          mode = 0;
        }
     }
    switch (mode)  {
      case 0:
        pixels.clear();
        pixels.setPixelColor(mode, 10, 10, 0);
        Keyboard.press(KEY_RIGHT_ALT);
    break;
      case 1:
        pixels.clear();
        pixels.setPixelColor(mode, 0, 0, 20);
      break;
      case 2:
        pixels.clear();
        pixels.setPixelColor(mode, 0, 20, 0);
        Keyboard.press(KEY_RIGHT_SHIFT);
      break;
      case 3:
        pixels.clear();
        pixels.setPixelColor(mode, 20, 0, 0);
        Keyboard.press(KEY_RIGHT_CTRL);
      break;
     }
    if (mode != 1)  {
      switch (key)  {
        case '1': Keyboard.press(KEY_F13); break;
        case '2': Keyboard.press(KEY_F14); break;
        case '3': Keyboard.press(KEY_F15); break;
        case '4': Keyboard.press(KEY_F16); break;
        case '5': Keyboard.press(KEY_F17); break;
        case '6': Keyboard.press(KEY_F18); break;
        case '7': Keyboard.press(KEY_F19); break;
        case '8': Keyboard.press(KEY_F20); break;
        case '9': Keyboard.press(KEY_F21); break;
        case '0': Keyboard.press(KEY_F23); break;
        case '*': Keyboard.press(KEY_F22); break;
        case '#': Keyboard.press(KEY_F24); break;
       }
     }
    if (mode == 1)  {
      switch (key)  {
        case '1': Keyboard.press('['); break;
        case '2': Keyboard.press(';'); break;
        case '3': Keyboard.press('.'); break;
        case '4': Keyboard.press('p'); break;
        case '5': Keyboard.press('l'); break;
        case '6': Keyboard.press(','); break;
        case '7': Keyboard.press('o'); break;
        case '8': Keyboard.press('k'); break;
        case '9': Keyboard.press('m'); break;
        case '0': Keyboard.press('i'); break;
        case '*': Keyboard.press('j'); break;
        case '#': Keyboard.press('n'); break;
       }
     }
    delay(50);
    Keyboard.releaseAll();
  }
 pixels.show();
}
