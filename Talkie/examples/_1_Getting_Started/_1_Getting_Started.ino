// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.
//
// Welcome to the Talkie library examples.
//
// Talkie is a speech synthesiser that works from a fixed vocabulary.
//
// There are hundreds of words in the 'Vocabulary' examples.
//
// Sound is output on digital pin 3. It can drive headphones directly, or add a simple audio amplifier to drive a loudspeaker.
// 

#include "talkie.h"

Talkie voice;

void setup() {
  voice.say("/VOCAB/EXAMPLE/DANGER.BIN");
  voice.say("/VOCAB/EXAMPLE/DANGER.BIN");
  voice.say("/VOCAB/EXAMPLE/RED.BIN");
  voice.say("/VOCAB/EXAMPLE/ALERT.BIN");
  voice.say("/VOCAB/EXAMPLE/MOTOR.BIN");
  voice.say("/VOCAB/EXAMPLE/IS.BIN");
  voice.say("/VOCAB/EXAMPLE/ON.BIN");
  voice.say("/VOCAB/EXAMPLE/FIRE.BIN");
}

void loop() {
}