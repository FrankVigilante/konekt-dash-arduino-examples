
/* Konekt Dash "Blink"
*
* Author: Frank J. Vigilante <vigilanf@gmail.com> 
*
* Purpose: This program demonstrates the ability to remotely turn off and on an LED 
* using Konekt's over the air serial mode. 
*
* License: Copyright (c) 2015 Konekt, Inc. All Rights Reserved. 
*
* Released under the MIT License (MIT)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*
*/



/* Note to self - Program currently throwing error: 
 *  
 *  Arduino: 1.6.5 (Windows 8.1), Board: "Dash, 120MHz"

Cannot run program "{runtime.tools.arm-none-eabi-gcc.path}\bin\arm-none-eabi-g++" (in directory "."): CreateProcess error=2, The system cannot find the file specified



Probably need to get the Konekt Dashboard conncted to a SIM card before the program will compile. If error still present after connecting sim card, just check out the directory referenced in the error log. 


 */



// Create global variables to be used in the setup and loop functions below:
const int ledPin = 13; // Change this to reflect the pin mapping of the Dash
int incomingByte;      // Create a variable to store and process the incoming cloud data 


void setup() {
   // The code below is only executed only once after powering on the Dash or Dash Pro:
   SerialCloud.begin(115200); // Initiliaze serial communication with the Dash Cloud
   SerialUSB.begin(9600); // Initialize serial communication for the Serial Monitor
   SerialUSB.println("Cloud Blink Example");
   pinMode(ledPin, OUTPUT); 
   digitalWrite(ledPin, LOW); 
   
}

void loop() {
   // The code below is executed repeatedly.
   // Your Dash or Dash Pro will work through each line of code.
   // After reaching the end of the code, it will start over:

   if (SerialCloud.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = SerialCloud.read();
    // if a capital H (ASCII 72) is typed into the Konekt Dashboard, turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    }
    // if it's an L (ASCII 76), turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}

   


   
    
    

