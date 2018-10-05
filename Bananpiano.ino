// Star wars notes - http://easy-letter-notes.com/star-wars/
// Midi notes - http://newt.phys.unsw.edu.au/jw/notes.html

#include <CapacitiveSensor.h>

#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

struct MySettings : public midi::DefaultSettings
{
  static const bool UseRunningStatus = false;
  static const long BaudRate = 115200;
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

const int velocity = 127;
const int channel = 1;

CapacitiveSensor c4 = CapacitiveSensor(2, 4);
CapacitiveSensor d4 = CapacitiveSensor(2, 5);
CapacitiveSensor e4 = CapacitiveSensor(2, 6);
CapacitiveSensor f4 = CapacitiveSensor(2, 7);
CapacitiveSensor g4 = CapacitiveSensor(2, 8);
CapacitiveSensor a4 = CapacitiveSensor(2, 9);
CapacitiveSensor b4 = CapacitiveSensor(2, 10);
CapacitiveSensor c5 = CapacitiveSensor(2, 11);

const int NOTE_C4 = 60;
const int NOTE_D4 = 62;
const int NOTE_E4 = 64;
const int NOTE_F4 = 65;
const int NOTE_G4 = 67;
const int NOTE_A4 = 69;
const int NOTE_B4 = 71;
const int NOTE_C5 = 72;

int threshold = 200;
int delayTime = 300;

void setup() {
//  Serial.begin(9600);
  MIDI.begin();
}

void loop() {

  byte samples = 30;
  bool playC4 = c4.capacitiveSensor(samples) > threshold;
  bool playD4 = d4.capacitiveSensor(samples) > threshold;
  bool playE4 = e4.capacitiveSensor(samples) > threshold;
  bool playF4 = f4.capacitiveSensor(samples) > threshold;
  bool playG4 = g4.capacitiveSensor(samples) > threshold;
  bool playA4 = a4.capacitiveSensor(samples) > threshold;
  bool playB4 = b4.capacitiveSensor(samples) > threshold;
  bool playC5 = c5.capacitiveSensor(samples) > threshold;
  
  if (playC4) {
    MIDI.sendNoteOn(NOTE_C4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_C4, velocity, channel);    
  }

  if (playD4) {
    MIDI.sendNoteOn(NOTE_D4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_D4, velocity, channel);    
  }

  if (playE4) {
    MIDI.sendNoteOn(NOTE_E4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_E4, velocity, channel);    
  }

  if (playF4) {
    MIDI.sendNoteOn(NOTE_F4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_F4, velocity, channel);    
  }

  if (playG4) {
    MIDI.sendNoteOn(NOTE_G4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_G4, velocity, channel);    
  }

  if (playA4) {
    MIDI.sendNoteOn(NOTE_A4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_A4, velocity, channel);    
  }

  if (playB4) {
    MIDI.sendNoteOn(NOTE_B4, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_B4, velocity, channel);    
  }

  if (playC5) {
    MIDI.sendNoteOn(NOTE_C5, velocity, channel);  
    delay(delayTime);
  }
  else {
    MIDI.sendNoteOff(NOTE_C5, velocity, channel);    
  }

}


