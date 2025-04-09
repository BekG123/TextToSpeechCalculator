/* Mini Calculator Text to Speech Project
 *
 * Reads two number inputs and operation from the user such that x is the first number to be computed, y is the second number, and the operation on the two numbers. 
 The user input is lit up on the PCB and then converted to the speaker as a human voice uttering the result. 
 *
 * ENGR 40M
 * Student: Bekhruz Malikov
 * Name: Text to Speech Mini-Calculator
 */
// Arrays of pin numbers
const byte ANODE_PINS[8] = {13, 12, 11, 10, 9, 8, 7, 6};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};

// Global variables to store user input
int user_input1 = 0;
int user_input2 = 0;
char operation = '\0';
int result = 0;

// Timing vars
unsigned long lastMillis = 0;  // Variable to track time
unsigned long displayDuration = 1000;  // Duration for LEDs to stay on (1 second)
bool ledOn = false;


void setup() {

  // Configure all 8 anode (+) and all 8 cathode (-) pins to outputs
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], OUTPUT);
    pinMode(CATHODE_PINS[i], OUTPUT);
  }
  // Turn all 16 pins "off"(PMOS)
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], HIGH);
    pinMode(CATHODE_PINS[i], HIGH);
  }
  
  // Initialize serial communication
  // (to be read by Serial Monitor on your computer)
  Serial.begin(115200);
  Serial.setTimeout(100);

// FUNCTION START HERE 
}
//Function: Turns off all anode and cathode pins before start
void clearDisplay() {

  for (byte i = 0; i < 8; i++) {
    digitalWrite(ANODE_PINS[i], HIGH);  // Set anode pins HIGH (off)
  }
    for (byte j = 0; j < 8; j++ ) {
    digitalWrite(CATHODE_PINS[j], HIGH); // Set cathode pins HIGH (off)
    }
}
// brightness adjustment(to be done at the very end, potentially)

// turns on specific LEDs - to be used in hard-coded functions
void turnOnLed(byte row, byte col) {
  digitalWrite(ANODE_PINS[row], LOW);
  digitalWrite(CATHODE_PINS[col], LOW);
}
// turns off specific LEDs - to be used in hard-coded functions
void turnOffLed(byte row, byte col) {
  digitalWrite(ANODE_PINS[row], HIGH);
  digitalWrite(CATHODE_PINS[col], HIGH);
}

// *****************
// FIRST NUMBER ONLY
// *****************
void showInput1() {

      // #0
      if (user_input1 == 0) {
        //first column of '0'
        turnOnLed(0,0); 
        clearDisplay();
        turnOnLed(1,0);
        clearDisplay();
        turnOnLed(2,0);
        clearDisplay();
        turnOnLed(3,0);
        clearDisplay();
        turnOnLed(4,0);
        clearDisplay();
        turnOnLed(5,0);
        clearDisplay();
        turnOnLed(6,0);
        clearDisplay();
        turnOnLed(7,0);
        clearDisplay();
        //second column of '0'
        turnOnLed(0,1); 
        clearDisplay();
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }

      // #1
      else if (user_input1 == 1) {
      // iterate over rows and columns
      for (byte y = 0; y < 8; y++) {
        for (byte x = 0; x < 8; x++) {
          turnOnLed(x, 0); // turn on all anode pins and only first cathode pin on 
        }
      }
    }

      // #2
      else if (user_input1 == 2) {
        // the body of number 2 hard-coded
        //the top two LEDs
        turnOnLed(0,0);
        clearDisplay();
        turnOnLed(0,1);
        clearDisplay();
        //the right top two LEDs(right-side of PCB)
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        //the middle two LEDs
        turnOnLed(3,0);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        //the left bottom three LEDs
        turnOnLed(4,0);
        clearDisplay();
        turnOnLed(5,0);
        clearDisplay();
        turnOnLed(6,0);
        clearDisplay();
        //the bottom two LEDs
        turnOnLed(7,0);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }

      // #3
      else if (user_input1 == 3) {
        //the body of 3 hard-coded
        //the top two LEDs
        turnOnLed(0,0);
        clearDisplay();
        turnOnLed(0,1);
        clearDisplay();
        //the right top two LEDs(right-side of PCB)
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        //the middle two LEDs
        turnOnLed(3,0);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        //the right bottom three LEDs
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        //the bottom two LEDs
        turnOnLed(7,0);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }
      
      // #4
      else if (user_input1 == 4) {
        //the body of 4 hard-coded
        //the first four LEDs of first column of '4'
        turnOnLed(0,0);
        clearDisplay(); 
        turnOnLed(1,0);
        clearDisplay();
        turnOnLed(2,0);
        clearDisplay();
        turnOnLed(3,0);
        clearDisplay();
        //the second column of '4' minus top LED
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }

      // #5
      else if (user_input1 == 5) {
        //the body of 5 hard-coded
        //the top two LEDs
        turnOnLed(0,0);
        clearDisplay();
        turnOnLed(0,1);
        clearDisplay();
        //the left top two LEDs
        turnOnLed(1,0);
        clearDisplay();
        turnOnLed(2,0);
        clearDisplay();
        //the middle two LEDs
        turnOnLed(3,0);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        //the right bottom three LEDs
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        //the bottom two LEDs
        turnOnLed(7,0);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }

      // #6
      else if (user_input1 == 6) {
        //the body of 6 hard-coded
        //the first column of '6'
        turnOnLed(0,0); 
        clearDisplay();
        turnOnLed(1,0);
        clearDisplay();
        turnOnLed(2,0);
        clearDisplay();
        turnOnLed(3,0);
        clearDisplay();
        turnOnLed(4,0);
        clearDisplay();
        turnOnLed(5,0);
        clearDisplay();
        turnOnLed(6,0);
        clearDisplay();
        turnOnLed(7,0);
        clearDisplay();
        //the second column of '6' minus the two LEDs on top and one on the bottom
        turnOnLed(0,1); 
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
      }
      
      // #7 
      else if (user_input1 == 7) {
        //the body of 7 hard-coded
        //the first LED 
        turnOnLed(0,0);
        clearDisplay();
        //the second column of '7'
        turnOnLed(0,1); 
        clearDisplay();
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }

      // #8
      else if (user_input1 == 8) {
        //the body of 8 hard-coded
        //the top parts of '8'
        turnOnLed(0,0);
        clearDisplay();
        turnOnLed(0,1);
        clearDisplay();
        turnOnLed(1,0);
        clearDisplay();
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,0);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        //the bottom parts of '8'
        turnOnLed(4,0);
        clearDisplay();
        turnOnLed(5,0);
        clearDisplay();
        turnOnLed(6,0);
        clearDisplay();
        turnOnLed(7,0);
        clearDisplay();
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }

      // #9
      else if (user_input1 == 9) {
        //the body of 9 hard-coded
        //the second column of '9'
        turnOnLed(0,0);
        clearDisplay();
        turnOnLed(1,0);
        clearDisplay();
        turnOnLed(2,0);
        clearDisplay();
        //the left top three LEDs
        turnOnLed(0,1); 
        clearDisplay();
        turnOnLed(1,1);
        clearDisplay();
        turnOnLed(2,1);
        clearDisplay();
        turnOnLed(3,1);
        clearDisplay();
        turnOnLed(4,1);
        clearDisplay();
        turnOnLed(5,1);
        clearDisplay();
        turnOnLed(6,1);
        clearDisplay();
        turnOnLed(7,1);
        clearDisplay();
      }
      //end of hard-coding user input 1
}
    
// **************
// OPERATIONS ONLY
// **************
void showOperation() {

      if (operation == '+') {
      //hard-coded
      turnOnLed(3,3);
      clearDisplay();
      turnOnLed(4,3);
      clearDisplay();
      turnOnLed(2,3);
      clearDisplay();
      turnOnLed(3,2);
      clearDisplay();
      turnOnLed(3,4);
      clearDisplay();
    }
    else if (operation == '-') {
      turnOnLed(3,2);
      clearDisplay();
      turnOnLed(3,3);
      clearDisplay();
      turnOnLed(3,4);
      clearDisplay();
    }
    else if (operation == '*') {
      turnOnLed(3,3);
      clearDisplay();
    }
    else if (operation == '/') {
      turnOnLed(2,2);
      clearDisplay();
      turnOnLed(3,3);
      clearDisplay();
      turnOnLed(4,4);
      clearDisplay();
    }
    // end of hard-coding the operations 
}

// *****************
//SECOND NUMBER ONLY
// *****************
void showInput2() {
      
      // #0 
      if (user_input2 == 0) {
        //the body of number 0 hard-coded
        //the first column of '0'
        turnOnLed(0,6);
        clearDisplay();
        turnOnLed(1,6);
        clearDisplay();
        turnOnLed(2,6);
        clearDisplay();
        turnOnLed(3,6);
        clearDisplay();
        turnOnLed(4,6);
        clearDisplay();
        turnOnLed(5,6);
        clearDisplay();
        turnOnLed(6,6);
        clearDisplay();
        turnOnLed(7,6);
        clearDisplay();
        //the second column of '0'
        turnOnLed(0,7);
        clearDisplay();
        turnOnLed(1,7);
        clearDisplay();
        turnOnLed(2,7);
        clearDisplay();
        turnOnLed(3,7);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }

      // #1
      else if (user_input2 == 1) {
        //the body of number 1 hard-coded
        //the second column of '1'
        turnOnLed(0,7);
        clearDisplay();
        turnOnLed(1,7);
        clearDisplay();
        turnOnLed(2,7);
        clearDisplay();
        turnOnLed(3,7);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }

      // #2
      else if (user_input2 == 2) {
        // the body of number 2 hard-coded
        //the top two LEDs
        turnOnLed(0, 6);
        clearDisplay();
        turnOnLed(0, 7);
        clearDisplay();
        //the right top two LEDs
        turnOnLed(1, 7);
        clearDisplay();
        turnOnLed(2, 7);
        clearDisplay();
        //the middle two LEDs
        turnOnLed(3, 7);
        clearDisplay();
        turnOnLed(3,6);
        clearDisplay();
        //the left bottom three LEDs
        turnOnLed(4, 6);
        clearDisplay();
        turnOnLed(5,6);
        clearDisplay();
        turnOnLed(6, 6);
        clearDisplay();
        //the bottom two LEDs
        turnOnLed(7, 6);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
        }

      // #3
      else if (user_input2 == 3) {
        //the body of number 3 hard-coded
        //the top two LEDs
        turnOnLed(0, 6);
        clearDisplay();
        turnOnLed(0, 7);
        clearDisplay();
        //the right top two LEDs
        turnOnLed(1, 7);
        clearDisplay();
        turnOnLed(2, 7);
        clearDisplay();
        //the middle two LEDs
        turnOnLed(3, 7);
        clearDisplay();
        turnOnLed(3,6);
        clearDisplay();
        //the right bottom three LEDs
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        //the bottom two LEDs
        turnOnLed(7, 6);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }

      // #4
      else if (user_input2 == 4) {
        //the body of number 4 hard-coded
        //the first four LEDs of first column of '4'
        turnOnLed(0,6);
        clearDisplay();
        turnOnLed(1,6);
        clearDisplay();
        turnOnLed(2,6);
        clearDisplay();
        turnOnLed(3,6);
        //the second column of '4' minus top LED
        turnOnLed(1,7);
        clearDisplay();
        turnOnLed(2,7);
        clearDisplay();
        turnOnLed(3,7);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }
      
      // #5
      else if (user_input2 == 5) {
        //the body of number 5 hard-coded
        //the top two LEDs
        turnOnLed(0, 6);
        clearDisplay();
        turnOnLed(0, 7);
        clearDisplay();
        //the left top two LEDs
        turnOnLed(1,6);
        clearDisplay();
        turnOnLed(2,6);
        clearDisplay();
        //the middle two LEDs
        turnOnLed(3, 7);
        clearDisplay();
        turnOnLed(3,6);
        clearDisplay();
        //the right bottom three LEDs
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        //the bottom LEDs
        turnOnLed(7, 6);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }
      // #6
      else if (user_input2 == 6) {
        //the body of number 6 hard-coded
        //the first column of '6'
        turnOnLed(0,6);
        clearDisplay();
        turnOnLed(1,6);
        clearDisplay();
        turnOnLed(2,6);
        clearDisplay();
        turnOnLed(3,6);
        clearDisplay();
        turnOnLed(4,6);
        clearDisplay();
        turnOnLed(5,6);
        clearDisplay();
        turnOnLed(6,6);
        clearDisplay();
        turnOnLed(7,6);
        clearDisplay();
        //the second column of '6' minus the two LEDs on top and one on the bottom
        turnOnLed(0,7);
        clearDisplay();
        turnOnLed(3,7);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
      }

      // #7
      else if (user_input2 == 7) {
        //the body of number 7 hard-coded
        //the first LED 
        turnOnLed(0,6);
        clearDisplay();
        //the second column of '7'
        turnOnLed(0,7);
        clearDisplay();
        turnOnLed(1,7);
        clearDisplay();
        turnOnLed(2,7);
        clearDisplay();
        turnOnLed(3,7);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }

      // #8
      else if (user_input2 == 8) {
        //the body of number 8 hard-coded
        //the top parts of '8'
        turnOnLed(0,6);
        clearDisplay();
        turnOnLed(0,7);
        clearDisplay();
        turnOnLed(1,6);
        clearDisplay();
        turnOnLed(1,7);
        clearDisplay();
        turnOnLed(2,6);
        clearDisplay();
        turnOnLed(2,7);
        clearDisplay();
        //the bottom parts of '8'
        turnOnLed(4,6);
        clearDisplay();
        turnOnLed(5,6);
        clearDisplay();
        turnOnLed(6,6);
        clearDisplay();
        turnOnLed(7,6);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
      }

      // #9 
      else if (user_input2 == 9) {
        //the body of number 9 hard-coded
        //the second column of '9'
        turnOnLed(0,7);
        clearDisplay();
        turnOnLed(1,7);
        clearDisplay();
        turnOnLed(2,7);
        clearDisplay();
        turnOnLed(3,7);
        clearDisplay();
        turnOnLed(4,7);
        clearDisplay();
        turnOnLed(5,7);
        clearDisplay();
        turnOnLed(6,7);
        clearDisplay();
        turnOnLed(7,7);
        clearDisplay();
        //the left top three LEDs
        turnOnLed(0,6);
        clearDisplay();
        turnOnLed(1,6);
        clearDisplay();
        turnOnLed(2,6);
        clearDisplay();
      }

}

// *****************
//EQUAL SIGN ONLY
// *****************
void showEqual() {
    //equal sign hard-coded
    turnOnLed(2,2);
    clearDisplay();
    turnOnLed(2,3);
    clearDisplay();
    turnOnLed(2,4);
    clearDisplay();
    turnOnLed(4,2);
    clearDisplay();
    turnOnLed(4,3);
    clearDisplay();
    turnOnLed(4,4);
    clearDisplay();
}
// *****************
//RESULT ONLY
// *****************
void showResult() {

  if (result == 0) {
    //the first column of '0'
    turnOnLed(0,6);
    clearDisplay();
    turnOnLed(1,6);
    clearDisplay();
    turnOnLed(2,6);
    clearDisplay();
    turnOnLed(3,6);
    clearDisplay();
    turnOnLed(4,6);
    clearDisplay();
    turnOnLed(5,6);
    clearDisplay();
    turnOnLed(6,6);
    clearDisplay();
    turnOnLed(7,6);
    clearDisplay();
    //the second column of '0'
    turnOnLed(0,7);
    clearDisplay();
    turnOnLed(1,7);
    clearDisplay();
    turnOnLed(2,7);
    clearDisplay();
    turnOnLed(3,7);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }
  
  else if (result == 1) {
    //the second column of '1'
    turnOnLed(0,7);
    clearDisplay();
    turnOnLed(1,7);
    clearDisplay();
    turnOnLed(2,7);
    clearDisplay();
    turnOnLed(3,7);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  } 
  
  else if (result == 2) {
    //the top two LEDs
    turnOnLed(0, 6);
    clearDisplay();
    turnOnLed(0, 7);
    clearDisplay();
    //the right top two LEDs
    turnOnLed(1, 7);
    clearDisplay();
    turnOnLed(2, 7);
    clearDisplay();
    //the middle two LEDs
    turnOnLed(3, 7);
    clearDisplay();
    turnOnLed(3,6);
    clearDisplay();
    //the left bottom three LEDs
    turnOnLed(4, 6);
    clearDisplay();
    turnOnLed(5,6);
    clearDisplay();
    turnOnLed(6, 6);
    clearDisplay();
    //the bottom two LEDs
    turnOnLed(7, 6);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }

  else if (result == 3) {
    //the top two LEDs
    turnOnLed(0, 6);
    clearDisplay();
    turnOnLed(0, 7);
    clearDisplay();
    //the right top two LEDs
    turnOnLed(1, 7);
    clearDisplay();
    turnOnLed(2, 7);
    clearDisplay();
    //the middle two LEDs
    turnOnLed(3, 7);
    clearDisplay();
    turnOnLed(3,6);
    clearDisplay();
    //the right bottom three LEDs
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    //the bottom two LEDs
    turnOnLed(7, 6);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }

  else if (result == 4) {
    //the first four LEDs of first column of '4'
    turnOnLed(0,6);
    clearDisplay();
    turnOnLed(1,6);
    clearDisplay();
    turnOnLed(2,6);
    clearDisplay();
    turnOnLed(3,6);
    //the second column of '4' minus top LED
    turnOnLed(1,7);
    clearDisplay();
    turnOnLed(2,7);
    clearDisplay();
    turnOnLed(3,7);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }

  else if (result == 5) {
    //the top two LEDs
    turnOnLed(0, 6);
    clearDisplay();
    turnOnLed(0, 7);
    clearDisplay();
    //the left top two LEDs
    turnOnLed(1,6);
    clearDisplay();
    turnOnLed(2,6);
    clearDisplay();
    //the middle two LEDs
    turnOnLed(3, 7);
    clearDisplay();
    turnOnLed(3,6);
    clearDisplay();
    //the right bottom three LEDs
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    //the bottom LEDs
    turnOnLed(7, 6);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }

  else if (result == 6) {
    //the first column of '6'
    turnOnLed(0,6);
    clearDisplay();
    turnOnLed(1,6);
    clearDisplay();
    turnOnLed(2,6);
    clearDisplay();
    turnOnLed(3,6);
    clearDisplay();
    turnOnLed(4,6);
    clearDisplay();
    turnOnLed(5,6);
    clearDisplay();
    turnOnLed(6,6);
    clearDisplay();
    turnOnLed(7,6);
    clearDisplay();
    //the second column of '6' minus the two LEDs on top and one on the bottom
    turnOnLed(0,7);
    clearDisplay();
    turnOnLed(3,7);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
  }

  else if (result == 7) {
    //the first LED 
    turnOnLed(0,6);
    clearDisplay();
    //the second column of '7'
    turnOnLed(0,7);
    clearDisplay();
    turnOnLed(1,7);
    clearDisplay();
    turnOnLed(2,7);
    clearDisplay();
    turnOnLed(3,7);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }

  else if (result == 8) {
    //the top parts of '8'
    turnOnLed(0,6);
    clearDisplay();
    turnOnLed(0,7);
    clearDisplay();
    turnOnLed(1,6);
    clearDisplay();
    turnOnLed(1,7);
    clearDisplay();
    turnOnLed(2,6);
    clearDisplay();
    turnOnLed(2,7);
    clearDisplay();
    //the bottom parts of '8'
    turnOnLed(4,6);
    clearDisplay();
    turnOnLed(5,6);
    clearDisplay();
    turnOnLed(6,6);
    clearDisplay();
    turnOnLed(7,6);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
  }

  else if (result == 9) {
    //the second column of '9'
    turnOnLed(0,7);
    clearDisplay();
    turnOnLed(1,7);
    clearDisplay();
    turnOnLed(2,7);
    clearDisplay();
    turnOnLed(3,7);
    clearDisplay();
    turnOnLed(4,7);
    clearDisplay();
    turnOnLed(5,7);
    clearDisplay();
    turnOnLed(6,7);
    clearDisplay();
    turnOnLed(7,7);
    clearDisplay();
    //the left top three LEDs
    turnOnLed(0,6);
    clearDisplay();
    turnOnLed(1,6);
    clearDisplay();
    turnOnLed(2,6);
    clearDisplay();
  }
}


    //test 
  // After the display duration has passed, clear the display and move to the next state

void calculate() {
  //CALCULATIONS 
      // the math 
      if (operation == '+') {
        result = user_input1 + user_input2;
      }
      else if (operation == '-') {
        result = user_input1 - user_input2;
      } 
      else if (operation == '*') {
        result = user_input1 * user_input2;
      } 
      else if (operation == '/') {
        if (user_input2 != 0) {
          result = user_input1 / user_input2;
        }
        else {
          Serial.println("Error: Division by Zero");
          return;
        }
      }
      return result;
}

    // others should be off
  
  // if user input is say number 1, light up these rows and columns 




void loop() {
  // You shouldn't need to edit this function during lab 3a.
  // static byte ledOn[8][8];
  // remember the data between calls 
  static char message[3];
  //turn every LED off before starting
  clearDisplay();
 

  //User Inputs
  if (Serial.available()) {
    // Parse the values from the serial string
    user_input1 = Serial.parseInt(); //number one
    operation = Serial.read(); //operation of choice
    user_input2 = Serial.parseInt(); //number two
    
    calculate();
    Serial.println(result);
    //PUT THE TIMING OF THE LEDS INTO A HEPLER FUNCTION
    // USER INPUT 1 LOOP
    lastMillis = millis();  // Start timing the display duration
    ledOn = true;  // Turn LEDs on
    
    while (millis() - lastMillis < displayDuration) {
      if (ledOn) {
        showInput1();
      }
    }

    //OPERATION LOOP 
    clearDisplay();
    ledOn = false;
    //reset timer
    lastMillis = millis();
    ledOn = true;
  
    while (millis() - lastMillis < displayDuration) {
      if (ledOn) {
        showOperation();
      }
    }

    //USER INPUT 2 LOOP
    clearDisplay();
    ledOn = false;
    //reset timer
    lastMillis = millis();
    ledOn = true;
    
    while (millis() - lastMillis < displayDuration) {
      if (ledOn) {
        showInput2();
      }
    }
    //EQUAL SIGN LOOP
    clearDisplay();
    ledOn = false;
    //reset timer
    lastMillis = millis();
    ledOn = true;

    while(millis() - lastMillis < displayDuration) {
      if (ledOn) {
        showEqual();
      }
    }

    //RESULT LOOP
    clearDisplay();
    ledOn = false;
    //reset timer
    lastMillis = millis();
    ledOn = true;

    while (millis() - lastMillis < displayDuration) {
      if (ledOn) {
        //the result
        showResult();
      }
    }

    //CALCULATIONS 

      // a very important debug line that basically prevented weird output. 
      // I guess it helps dealing with new lines, if I enter a new line
      // instead of jumping to the print operation
      // it exits

      // IMPORTANT CONDITIONS/DEBUGGERS
      if (Serial.read() != '\n') {
        Serial.println("Input must be an operation and two valid numbers(0-9)");
        return;
      }  
      // need results to be between (0-9 inclusive) to be displayed on PCB
      if (result < 0 || result > 9 ) {
        Serial.println("The operation is out of range");
        return; 
      } else if (result >= 0 || result <= 9) { //the valid result 
        sprintf(message, "%d %c %d is %d ", user_input1, operation, user_input2, result);
        Serial.println(message);
        // light up appropriate LEDs
      } else { //to catch divison by zero errors
        Serial.println("The operation is out of range - invalid input");
        return; 
      }
  
  } // end of the input loop
  

}

// GET USER INPUT FIRST AND CHECK WHETHER IT IS VALID, IN RANGE
// CALL THE RESULT FUNCTION HERE AS IT IS CALLED EVERY LOOP
// RESULT FUNCTION SHOULD LIGHT UP APPROPRIATE LEDS


//TODO:
// 0) Fix the ghosting bug
// 1) Get Results to show up on screen
// 2) Finish up the array of all numbers to show on up screen
// MILESTONE WOOOOOO -> 10 hours to kill this sucker
// 3) Solder + attach speaker 
// 4) Code up the talkie module TTS
