# couscous

![couscous](imgur.com image replace me!)

A short description of the keyboard/project

Keyboard Maintainer: [Coen Schalkwijk](https://github.com/yourusername)  
Hardware Supported: The PCBs, controllers supported  
Hardware Availability: links to where you can find this hardware

Make example for this keyboard (after setting up your build environment):

    make couscous:default

See [build environment setup]https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.

Do you have trouble flashing your pro micro ? You need to put it in « flash mode » :
short the ground and reset pins. You can then flash your firmware (with avrdude for instance).

QMK provides a convenient Makefile rule for this :

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

make handwired/couscous
make handwired/cosucous:right_hand

avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:handwired_couscous_default.hex -P/dev/ttyACM0
avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:handwired_couscous_right_hand.hex -P/dev/ttyACM0


# Work in progress:
numpad
oled

## Physical design
* Wider (1.25u) left most (L-hand) and rightmost (R-hand) button row.
* More space between last button col and layer shift keys.
* Additional row of keys on top?
* Wrist pad, fix between L & R hand, tilted bottom plate.
