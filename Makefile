
# Defines the RPI variable which is needed by rc-switch/RCSwitch.h
CXXFLAGS=-DRPI

all: receiver

receiver:  rcswitch/RCSwitch.o receiver.o
	$(CXX) $(CXXFLAGS) $+ -o $@ -lwiringPi	

clean:
	$(RM) rc-switch/*.o *.o receiver

