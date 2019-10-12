# 433Mhz-Receiver-Raspberry

# About
433Mhz-Receiver-Raspberry is for receiving 433 Mhz wireless commands.

Example Hardware
https://www.amazon.de/receiver-Superregeneration-Wireless-Transmitter-Burglar/dp/B00ATZV5EQ

See also:
https://github.com/ninjablocks/433Utils

See https://projects.drogon.net/raspberry-pi/wiringpi/pins/ for pin mapping of the raspberry pi GPIO connector

See https://github.com/schattenmann80/433Mhz-Receiver-Raspberry/wiki (German)

## Install:

  - Download and install wiringPI
    - ```sudo apt-get install wiringpi```
  
  - Download this repository
    - ```cd ~```
    - ```git clone --recursive https://github.com/schattenmann80/433Mhz-Receiver-Raspberry.git```
    - ```cd 433Mhz-Receiver-Raspberry```
    - ```sudo make```
  - Hardware setup
    - Pin 2 ( WiringPi layout) is the input pin.  (GIPO 27 normal Layout)
    - The Output pin is selectable with command line arguments.
    
## Run
  - ```cd /home/pi/433Mhz-Receiver-Raspberry``` 
  - ```sudo ./receiver -l```
    - receives all incoming messages and display them
  - ```sudo ./receiver [output pin]  [message code]```
     - if a massage is received with the same code then [message code] set the output pin for 500 ms to High. For Pin mapping see        https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     
## Build receiver binary and make it accessible from everywhere
  - ```cd /home/pi/433Mhz-Receiver-Raspberry```
  - ```sudo make```
  - ```sudo mv receiver /usr/bin/receiver```
  - ```sudo chown root:root /usr/bin/receiver```
  - ```sudo chmod u+s /usr/bin/receiver```
  - now you can use "sudo receiver" in all directorys

## Stop
  - Stop the programm with ctrl-c 


