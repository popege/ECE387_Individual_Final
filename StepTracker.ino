#include <SMARTWAV.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

SMARTWAV sWav;
int fsr = 0;

int fsrReading;

int count = 0;

unsigned long startTime;

unsigned long endTime;

double duration;

byte timerRunning;

double pace;

double avg[30];

int count1 = 0;

double avgPace;
int avgPace1;
int paceCompare;
int paceCounter;

uint32_t startTime1;



void setup() {
  // put your setup code here, to run once:

  sWav.init();
  sWav.reset();

 
  Serial.begin(9600);

  startTime1 = millis();

  
 sWav.volume(35);

 lcd.begin(16, 2);
  

}

void loop() {
  // put your main code here, to run repeatedly:




 char playList[50];       //array that stores all the microSD card audio files 
 char folders[50];        //array that stores all the microSD card folders/Dirs 
 char songName[10];       //array that stores the audio file name

 fsrReading = analogRead(fsr);

 uint32_t currentTime1 = millis();

paceCompare = avgPace1;



 
if(currentTime1 - startTime1 < 60000) {

 if(fsrReading > 600) {
  count1++;
  count= count + 2;
  pace = 120/duration;
  paceCounter = paceCounter + pace;

 
  Serial.println(count);
   //Serial.println(pace);
  //Serial.println(paceCounter);



  delay(500);
 }
}



else {
  startTime1 = currentTime1;

  avgPace1 = (paceCounter)/(count/2);
  
  Serial.println("Average Pace: "); Serial.print(avgPace1);
  Serial.println();

  int x = abs(avgPace1 - paceCompare);

  
  Serial.println("CHANGE: ");Serial.print(x);
 
}
 


if(abs(avgPace1 - paceCompare) >= 10) { //if change in pace is large enough to change bpm of music

  

if(avgPace1 > 10 && avgPace1 <= 125) {
  sWav.stopTrack();
  delay(100);
 sWav.setFolder("120bpm");
delay(100);
sWav.playTracks();
delay(100);
sWav.continuousPlay(ENABLE);
delay(100);
 
}

if(avgPace1 > 125 && avgPace1 <=135) {
 sWav.stopTrack();
  delay(100);
sWav.setFolder("130bpm");
delay(100);
sWav.playTracks();
delay(100);
sWav.continuousPlay(ENABLE);
delay(100);

}
if(avgPace1 > 135 && avgPace1 <=145) {
  sWav.stopTrack();
  delay(100);
 sWav.setFolder("140bpm");
delay(100);
sWav.playTracks();
delay(100);
sWav.continuousPlay(ENABLE);
delay(100);

}

if(avgPace1 > 145 && avgPace1 <=155) {
  sWav.stopTrack();
  delay(100);
  sWav.setFolder("150bpm");
delay(100);
sWav.playTracks();
delay(100);
sWav.continuousPlay(ENABLE);
delay(100);

}
if(avgPace1 > 155 && avgPace1 < 200) {
  sWav.stopTrack();
  delay(100);
  sWav.setFolder("160bpm");
delay(100);
sWav.playTracks();
delay(100);
sWav.continuousPlay(ENABLE);
delay(100);

}

}




lcd.setCursor(0, 0);
lcd.print("Steps: ");
lcd.setCursor(8, 0);
lcd.print(count);

lcd.setCursor(0, 1);
lcd.print("Steps/min: ");
lcd.setCursor(11, 1);
lcd.print(avgPace1);








stepsPerMinute(); //calculating average steps per minute for each step

  
 
  
  }

  


 void findAvg() {

 if(count1 <= 30) {
    count1++;
    avgPace = avgPace + pace;
  }
  else {
    count1 = 0;
    avgPace = 0;
  }

  if(avgPace > 4000) {
    avgPace1 = avgPace / 30;
  }

  Serial.println(avgPace1);
 
  }


  



  void stepsPerMinute() {

if (timerRunning == 0 && fsrReading < 500){  
  startTime = millis();
  timerRunning = 1;
  }
  if (timerRunning == 1 && fsrReading > 600){ 
  endTime = millis();
  timerRunning = 0;
  duration = endTime - startTime;
  Serial.println();
  //Serial.print ("Time between a step for one foot: ");
  duration = duration / 1000;
  //Serial.println (duration);
  

  } 

}

void onetwentybpm() {

sWav.setFolder("120bpm");
delay(100);
sWav.playTracks();
sWav.continuousPlay(ENABLE);
}

void onethirtybpm() {

sWav.setFolder("130bpm");
delay(100);
sWav.playTracks();
sWav.continuousPlay(ENABLE);
  
}

void onefortybpm() {

sWav.setFolder("140bpm");
delay(100);
sWav.playTracks();
sWav.continuousPlay(ENABLE);

}

void onefiftybpm() {
   
sWav.setFolder("150bpm");
delay(100);
sWav.playTracks();
sWav.continuousPlay(ENABLE);
  
}

void onesixtybpm() {

sWav.setFolder("160bpm");
delay(100);
sWav.playTracks();
sWav.continuousPlay(ENABLE);
  
}



