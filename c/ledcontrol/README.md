This program controls the Milk V Duo internal LED via a touch sensor (https://arduinogetstarted.com/tutorials/arduino-touch-sensor).


First, you need to disable the blinking script on the Milk V Duo:
- mv /mnt/system/blink.sh /mnt/system/blink.sh_backup && sync
- restart the system


Connect touch sensor to Milk V Duo:
- SIG to GP16
- GND to GND
- VCC to 3V3(OUT)


Connect Milk V Duo via USB C to your computer and do:
- source ../envsetup.sh
- make
- make upload
- make run
- ctrl c


The LED will turn on when you touch the sensor.  When you are done:
- make kill