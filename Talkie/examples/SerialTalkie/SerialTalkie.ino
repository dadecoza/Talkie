#include "talkie.h"
Talkie voice;
char vocab[] = "/VOCAB/TI99/";

char buf[100];
int inx=0;

void setup() {
// Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  voice.say("/VOCAB/TI99/READY.BIN");
}

void talk(char* word) {
  char filename[50];
  memset(filename, '\0', sizeof(filename));
  strcpy(filename, vocab);
  strcat(filename, word);
  strcat(filename, ".BIN");
  if (voice.exists(filename)) {
    voice.say(filename);
  } else {
    for (int i=0; word[i] != '\0'; i++) {
      memset(filename, '\0', sizeof(filename));
      strcpy(filename, vocab);
      char tmp[] = {'A', '\0'};
      tmp[0]= word[i];
      strcat(filename, tmp);
      strcat(filename, ".BIN");
      voice.say(filename);
    }
  }
}

void loop() {
  while (Serial.available() > 0) {
    char b = Serial.read();
    if (b == 13) Serial.write(10);
    Serial.write(b);
    if (( b == '\n')||(b == '\r')){
      char wordbuf[50];
      int wordinx = 0;
      memset(wordbuf, '\0', sizeof(wordbuf));
      for (int i=0; i < inx; i++) {
        if (buf[i] == ' ') {
          talk(wordbuf);
          memset(wordbuf, '\0', sizeof(wordbuf));
          wordinx=0;
        } else {
          wordbuf[wordinx++] = buf[i];
        }
      }
      talk(wordbuf);
      memset(buf, '\0', sizeof(buf));
      inx=0;
    } else {
      b = toupper(b);
      if (((b>64)&&(b<91))||((b>47)&&(b<58))||(b==32)) {
        buf[inx++] = b;
      }
    }
  }
}
