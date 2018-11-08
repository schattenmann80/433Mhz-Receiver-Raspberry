# 433Mhz-Receiver-Raspberry

# About
433Mhz-Receiver-Raspberry is for receiving 433 Mhz wireless commands.
It is possible to display the received command on a gpio pin.

Example Hardware
https://www.amazon.de/receiver-Superregeneration-Wireless-Transmitter-Burglar/dp/B00ATZV5EQ

See also:
https://github.com/ninjablocks/433Utils

See https://projects.drogon.net/raspberry-pi/wiringpi/pins/ for pin mapping of the raspberry pi GPIO connector

See https://github.com/schattenmann80/433Mhz-Receiver-Raspberry/wiki (German)

## Install:

  - Download and build wiringPI
    - ```git clone git://git.drogon.net/wiringPi```
    - ```cd wiringPi```
    - ```sudo ./build```
  
  - Download this repository
    - ```cd /home/pi```
    - ```git clone --recursive https://github.com/schattenmann80/433Mhz-Receiver-Raspberry.git```
    - ```cd 433Mhz-Receiver-Raspberry```
    - ```sudo make```
  - Hardware setup
    - Receiver data input pin is pin 2 under WiringPi layout (GIPO 27 normal Layout)
    - The Output pin is selectable with the command line argument
    
## Run
  - ```cd /home/pi/433Mhz-Receiver-Raspberry``` 
  - ```sudo ./receiver -l```
    - receives all incoming messages and display them
  - ```sudo ./receiver [output pin]  [message code]```
     - if a massage is received with the same code then [message code] set the output pin for 500 ms to High. For Pin mapping see        https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     
## Make receiver bash command
  - ```cd /home/pi/433Mhz-Receiver-Raspberry```
  - ```sudo make```
  - ```sudo mv receiver /usr/bin/receiver```
  - ```sudo chown root:root /usr/bin/receiver```
  - ```sudo chmod u+s /usr/bin/receiver```
  - now you can use "sudo receiver" in all directorys

## Stop
  - Stop the programm with ctrl-c 
  
## Autostart
  - To Autostart receiver add output pin and message code to init.<br>
    Open init with some text editor and write in the first line the pin number
    and in the second line the message code and save it
  - Put the following line in /etc/rc.local above the line with "exit(o)". <br>
    `/home/pi/433Mhz-Receiver-Raspberry/receiver -s &`

