# Hotkeyboard

## What is this?

This repo contains the code for a Teensy which has buttons via an analog input connected. When pressing a button it sends a key combination in the form of `CTRL+SHIFT+ALT+WIN` + `<letter>` and it starts with the letter `a` (= button 1, defined in the code). 

The buttons are differenciated by voltage division using resistors, see the [Fritzing schematic](Hotkeypad.fzz). You can use the [Excel sheet](Button-Resistance.xlsx) to get the resistor values you need. The voltage values shouldn't be too close together so that you can differenciate each button.