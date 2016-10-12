# 433Mhz-Receiver-Raspberry

- Install:

  - Download and build wiringPI
    - git clone git://git.drogon.net/wiringPi
    - cd wiringPi
    - sudo ./build
  
  - Download this repository
    - cd /home/pi
    - git clone --recursive https://github.com/schattenmann80/433Mhz-Receiver-Raspberry.git
    - cd 433Mhz-Receiver-Raspberry
    - sudo make
    
- Run:
  - sudo ./receiver -l
    - receive all incoming messages and display them
   - sudo ./receiver [output pin]  [message code]
     - if a massage is received with the same code then [message code] set the output pin for 500 ms to High
     
- Make receiver bash command
  - cd /home/pi/433Mhz-Receiver-Raspberry
  - sudo mv receiver /usr/bin/receiver
  - sudo chown root:root /usr/bin/receiver
  - sudo chmod u+s /usr/bin/receiver
