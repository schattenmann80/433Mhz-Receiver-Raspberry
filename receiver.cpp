

#include "rcswitch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <iostream>
#include <string>
#include "receiver.h"
#include <fstream>
     
RCSwitch mySwitch;
 
void checkInput(){
	while(1)
	{
		std::string input;
		std::cin >> input;
		if(input == "exit"){
			printf("Stoppe Programm");
			exit(0);
		}
	}
}


void receiveMessageAndOutput(int pin, int massage){
	
	pinMode (pin, OUTPUT); 
	
	while(1) {

		delay(10);
	  
		if (mySwitch.available()) {
	
			int value = mySwitch.getReceivedValue();
	
			if (value == 0) {
				
			} else if(value == massage) {    
				digitalWrite (pin, HIGH) ;	// On
				delay (500) ;		// mS
				digitalWrite (pin, LOW) ;	// Off
			}
			mySwitch.resetAvailable();
		}  
	}
}

void decode(int value){
	static int sReturn[12];
	int nReturnPos = 0;

	for (int i = 0; i < 12; i++) {
		sReturn[11 - i] = (value & (3 << (2 * i))) >> (2 * i);
	}
	/*
	for (int i = 0; i < 12; i++) {
		printf("%i", sReturn[i]);
	}
	
	printf("\n"); */
	
	static char group[5];
	for (int i = 0; i < 5; i++) {
		group[i] = (sReturn[nReturnPos++] == 0) ? '1' : '0';
	}
	printf("group %s ", group);
	
	int number = 0;
	for (int i = 1; i < 6; i++) {
		if(sReturn[nReturnPos++] == 0)
		{
			number = i;
		}
	}
	printf("number %i ", number);
	
	printf("state %s \n \n", sReturn[nReturnPos++] == 0 ? "1" : "0");
	
}

int main(int argc, char *argv[]) {
  
    // This pin is not the first pin on the RPi GPIO header!
    // Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
    // for more information.
    int PIN = 2;
     
    if(wiringPiSetup() == -1) {
        printf("wiringPiSetup failed, exiting...");
		return 0;
    }


	
	mySwitch = RCSwitch();
    mySwitch.enableReceive(PIN);  // Receiver on interrupt 0 => that is pin #2
	 
	if(argv[1] != NULL){
		if(strcmp(argv[1], "-l") == 0){
			printf("Listen mode\n");
			
			while(1) {
	  
				delay(10);
	  
				if (mySwitch.available()) {
			
					int value = mySwitch.getReceivedValue();
			
					if (value == 0) {
						printf("Unknown encoding\n");
					} else {    
						printf("Received %i\n", mySwitch.getReceivedValue() );
						decode(mySwitch.getReceivedValue());
					}
					mySwitch.resetAvailable();
				}  
			}
			
		}else if(strcmp(argv[1], "-s") == 0){
			
			printf("service go \n");
			std::ifstream infile("init");
			
			int outputPin = 1;
			int code = 0;
			
			std::string line;
			
			std::getline(infile, line);
			outputPin = atoi( line.c_str() );
			
			std::getline(infile, line);
			code = atoi( line.c_str() );
			
			printf("Pin %i\n", outputPin);
			
			printf("Code %i\n", code);
			
			receiveMessageAndOutput(outputPin, code);
			
		}else if(argv[2] != NULL){
			int outputPin = 1;
			outputPin = atoi(argv[1]);
			
			int code = atoi(argv[2]);
			
			receiveMessageAndOutput(outputPin, code);
		}
	}
	 

  exit(0);


}

