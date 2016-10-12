

#include "rcswitch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
     
     
RCSwitch mySwitch;
 


int main(int argc, char *argv[]) {
  
     // This pin is not the first pin on the RPi GPIO header!
     // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     // for more information.
     int PIN = 2;
     
     if(wiringPiSetup() == -1) {
       printf("wiringPiSetup failed, exiting...");
       return 0;
     }

     int outputPin = 1;
     if (argv[1] != NULL) outputPin = atoi(argv[1]);

     mySwitch = RCSwitch();
     mySwitch.enableReceive(PIN);  // Receiver on interrupt 0 => that is pin #2
     
	 pinMode (outputPin, OUTPUT); 
    
    while(1) {
	  
		delay(10);
	  
		if (mySwitch.available()) {
	
			int value = mySwitch.getReceivedValue();
	
			if (value == 0) {
				printf("Unknown encoding\n");
			} else {    
				printf("Received %i\n", mySwitch.getReceivedValue() );
				digitalWrite (outputPin, HIGH) ;	// On
				delay (500) ;		// mS
				digitalWrite (outputPin, LOW) ;	// Off
			}
			mySwitch.resetAvailable();
		}  
	}

  exit(0);


}

