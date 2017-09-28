// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'S', '1', '2', '3'},
  {' ', '4', '5', '6'},
  {'C', '7', '8', '9'},
  {'M', 'V', '0', 'R'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, 2, 3, 4, 5);

char mode[4] = "JOG";
double target = 0000.0;
int rate = 128;
double volume = 0000.0;

int modeSelector = 1;
boolean isCancel = false;
boolean isEditing = false;
boolean isStopped = false;
int curPos;

String rateString = "128";
String targetString = "0000";
void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  displayScreen(target, rate, volume, mode);
  keypad.addEventListener(keypadEvent);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):


  // print the number of seconds since reset:

  char key = keypad.getKey();
  Serial.println(rateString); //debug
  Serial.println(targetString); //debug


}


// Taking care of some special events.
void keypadEvent(KeypadEvent key) {
  switch (key) {
    case 'S':
      if (keypad.getState() != RELEASED || isEditing == true) {
        break;
      }
      if (isStopped == false) {
        lcd.setCursor(7, 1);
        lcd.print("HOLD");
        isStopped = true;
      } else if (isStopped == true) {
        lcd.setCursor(7, 1);
        lcd.print("    ");
        isStopped = false;
      }
    case 'C' :
      break;

    case 'M':
      if (keypad.getState() != RELEASED || isEditing != false) {
        break;
      }
      if (modeSelector == 1) {
        lcd.setCursor(12, 1);
        lcd.print("JOG ");
        modeSelector++;
        break;
      }
      else if (modeSelector == 2) {
        lcd.setCursor(12, 1);
        lcd.print("NANO");
        modeSelector++;
        break;
      }
      else if (modeSelector == 3) {
        lcd.setCursor(12, 1);
        lcd.print("CEE ");
        modeSelector = 1;
        break;
      }
    case 'R':
      if (keypad.getState() != RELEASED ) {
        break;
      }
      if (isEditing == false) {
        Serial.println("editing");
        curPos = 13;
        lcd.setCursor(curPos, 0);
        lcd.cursor();
        lcd.blink();
        isEditing = true;
        while (isEditing == true) {
          key = keypad.getKey();
          if (curPos > 15)
          {
            curPos = 15;
            isEditing = false;
            lcd.noBlink();
            lcd.noCursor();
          }
          if (key == 'C') {
            lcd.noCursor();
            lcd.noBlink();
            isEditing = false;
          }

        }
      }
    case 'V':
      if (keypad.getState() != RELEASED ) {
        break;
      }
      if (isEditing == false) {
        Serial.println("editing");
        curPos = 0;
        lcd.setCursor(curPos, 0);
        lcd.cursor();
        lcd.blink();
        isEditing = true;
        while (isEditing == true) {
          key = keypad.getKey();
          if (curPos == 4){
            curPos = 3;
            isEditing = false;
            lcd.noBlink();
            lcd.noCursor();
          }
          if (key == 'C') {
            lcd.noCursor();
            lcd.noBlink();
            isEditing = false;
          }
        }
      }
    case '1':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('1');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos-1) {
          case 0:
            targetString.setCharAt(0, '1');
            break;
          case 1:
            targetString.setCharAt(1, '1');
            break;
          case 2:
            targetString.setCharAt(2, '1');
            break;
          case 3:
            targetString.setCharAt(3, '1');
            break;
          case 13:
            rateString.setCharAt(0, '1');
            break;
          case 14:
            rateString.setCharAt(1, '1');
            break;
          case 15:
            rateString.setCharAt(2, '1');
            break;
        }
        break;

      }
    case '2':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('2');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '2');
            break;
          case 1:
            targetString.setCharAt(1, '2');
            break;
          case 2:
            targetString.setCharAt(2, '2');
            break;
          case 3:
            targetString.setCharAt(3, '2');
            break;
          case 13:
            rateString.setCharAt(0, '2');
            break;
          case 14:
            rateString.setCharAt(1, '2');
            break;
          case 15:
            rateString.setCharAt(2, '2');
            break;
        }
        break;
      }
    case '3':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('3');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '3');
            break;
          case 1:
            targetString.setCharAt(1, '3');
            break;
          case 2:
            targetString.setCharAt(2, '3');
            break;
          case 3:
            targetString.setCharAt(3, '3');
            break;
          case 13:
            rateString.setCharAt(0, '3');
            break;
          case 14:
            rateString.setCharAt(1, '3');
            break;
          case 15:
            rateString.setCharAt(2, '3');
            break;
        }
        break;
      }
        case '4':
          if (keypad.getState() == RELEASED && isEditing == true) {
            lcd.print('4');
            curPos++;
            lcd.setCursor(curPos, 0);
        switch (curPos) {
              case 0:
               targetString.setCharAt(0, '4');
                break;
              case 1:
               targetString.setCharAt(1, '4');
                break;
              case 2:
                targetString.setCharAt(2, '4');
                break;
              case 3:
               targetString.setCharAt(3, '4');
                break;
              case 13:
                rateString.setCharAt(0, '4');
                break;
              case 14:
                rateString.setCharAt(1, '4');
                break;
              case 15:
                rateString.setCharAt(2, '4');
                break;
            }
            break;
          }
    case '5':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('5');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '5');
            break;
          case 1:
            targetString.setCharAt(1, '5');
            break;
          case 2:
            targetString.setCharAt(2, '5');
            break;
          case 3:
            targetString.setCharAt(3, '5');
            break;
          case 13:
            rateString.setCharAt(0, '5');
            break;
          case 14:
            rateString.setCharAt(1, '5');
            break;
          case 15:
            rateString.setCharAt(2, '5');
            break;
        }
        break;
      }
        case '6':
          if (keypad.getState() == RELEASED && isEditing == true) {
            lcd.print('6');
            curPos++;
            lcd.setCursor(curPos, 0);
        switch (curPos) {
              case 0:
                targetString.setCharAt(0, '6');
                break;
              case 1:
                targetString.setCharAt(1, '6');
                break;
              case 2:
               targetString.setCharAt(2, '6');
                break;
              case 3:
                targetString.setCharAt(3, '6');
                break;
              case 13:
                rateString.setCharAt(0, '6');
                break;
              case 14:
                rateString.setCharAt(1, '6');
                break;
              case 15:
                rateString.setCharAt(2, '6');
                break;
            }
            break;
          }
    case '7':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('7');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '7');
            break;
          case 1:
            targetString.setCharAt(1, '7');
            break;
          case 2:
            targetString.setCharAt(2, '7');
            break;
          case 3:
            targetString.setCharAt(3, '7');
            break;
          case 13:
            rateString.setCharAt(0, '7');
            break;
          case 14:
            rateString.setCharAt(1, '7');
            break;
          case 15:
            rateString.setCharAt(2, '7');
            break;
        }
        break;
      }
    case '8':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('8');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '8');
            break;
          case 1:
            targetString.setCharAt(1, '8');
            break;
          case 2:
            targetString.setCharAt(2, '8');
            break;
          case 3:
            targetString.setCharAt(3, '8');
            break;
          case 13:
            rateString.setCharAt(0, '8');
            break;
          case 14:
            rateString.setCharAt(1, '8');
            break;
          case 15:
            rateString.setCharAt(2, '8');
            break;
        }
        break;
      }
    case '9':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('9');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '9');
            break;
          case 1:
            targetString.setCharAt(1, '9');
            break;
          case 2:
            targetString.setCharAt(2, '9');
            break;
          case 3:
            targetString.setCharAt(3, '9');
            break;
          case 13:
            rateString.setCharAt(0, '9');
            break;
          case 14:
            rateString.setCharAt(1, '9');
            break;
          case 15:
            rateString.setCharAt(2, '9');
            break;
        }
        break;
      }
    case '0':
      if (keypad.getState() == RELEASED && isEditing == true) {
        lcd.print('0');
        curPos++;
        lcd.setCursor(curPos, 0);
        switch (curPos) {
          case 0:
            targetString.setCharAt(0, '0');
            break;
          case 1:
            targetString.setCharAt(1, '0');
            break;
          case 2:
            targetString.setCharAt(2, '0');
            break;
          case 3:
            targetString.setCharAt(3, '0');
            break;
          case 13:
            rateString.setCharAt(0, '0');
            break;
          case 14:
            rateString.setCharAt(1, '0');
            break;
          case 15:
            rateString.setCharAt(2, '0');
            break;
        }
        break;
      }
  }
}


void displayScreen(double T, int R, double V, char M[4]) {
  lcd.setCursor(0, 0);
  char targetFormat[6] = "";
  sprintf(targetFormat, "%04d.0", T);
  lcd.print(targetFormat);
  lcd.setCursor(13, 0);
  lcd.print(R);
  lcd.setCursor(0, 1);
  char targetVolume[6] = "";
  sprintf(targetVolume, "%04d.0", V);
  lcd.print(targetVolume);
  lcd.setCursor(12, 1);
  lcd.print(M);
}


