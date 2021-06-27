#include "pitches.h"
//melodies: 

int melody_next[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int melody_lose[]={
  
  NOTE_FS4,NOTE_G3,0,NOTE_C2
  
};
int melody_start[] = {

  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_B4, NOTE_A4, NOTE_C4, NOTE_G3, NOTE_C4
};

int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
}; 
const int red=10,green=9,blue=8,yellow=7,buzz=11; 
int count=0,temp_rand,guess=0,chk=0;
int red_button=6,green_button=5,blue_button=4,yellow_button=3;
int red_read=0,green_read=0,blue_read=0,yellow_read=0;
int a[50]={0};
int tone_red=8000,tone_blue=6000,tone_green=4000,tone_yellow=2000;


//declaring functions:

int choose_sound(int num);
void green_noise();
void yellow_noise();
void blue_noise();
void red_noise();
void next_noise();
void lose_noise();
void start_noise();
bool button_pressed();
int click_button();


void setup() {
  
   pinMode(red,OUTPUT);
   pinMode(green,OUTPUT);
   pinMode(blue,OUTPUT);
   pinMode(yellow,OUTPUT);
   pinMode(buzz,OUTPUT);
   Serial.begin(9600);
   randomSeed(analogRead(0));
}

void loop() {
  
  //Serial.println("enter 1 to begin!");
  //while(Serial.available()==0)
  //{
    
  //}
  Serial.println("press any button to begin!");
  while(!button_pressed())//running while no button was clicked
  {
    
  }
  chk=1;
  //chk=Serial.parseInt();
  start_noise();
  while(chk==1)
  {
    
    delay(500);
    game_turn();
    //Serial.println("enter the color one by one(red-10,green-9,blue-8,yellow-7)");
    Serial.println("your turn!");
    my_turn();
    
  }
 
  
}
void game_turn()
{
 
int i;



  for(i=0;i<count;i++)
  {
  
  digitalWrite(a[i],HIGH);
  choose_sound(a[i]);
  delay(1000);
  digitalWrite(a[i],LOW);
  delay(1000);
  
  }
  a[count]=random(yellow,red+1);
  digitalWrite(a[count],HIGH);
  choose_sound(a[count]);
  delay(1000);
  digitalWrite(a[count],LOW);
  delay(1000);
  count++;
  




  
}
void my_turn()
{
  int i=0,num=0;
  guess=0;
  while(guess<count)
  {
    //Serial.println("enter color");
    //while(Serial.available()==0);
    //{

    //}
    //num=Serial.parseInt();
    while((num=click_button())==-1)//running as long as no button was clicked
    {
    }
    
    if(num==a[i])
    {
      guess++;
      i++;
      digitalWrite(num,HIGH);
      choose_sound(num);
      digitalWrite(num,LOW);
     
    }
    else
    {
      Serial.println("you lose!");
      lose_noise();
      delay(1000);
      exit(1);
    }
    
    
  }
  delay(500);
  next_noise();
  Serial.println("good job! get ready for the next round!");
  delay(1000);
}


int choose_sound(int num)
{
   switch(num)
  {
    case(red):
    {
      red_noise();
    }
     case(green):
    {
      green_noise();
    }
     case(blue):
    {
      blue_noise();
    }
     case(yellow):
    {
      yellow_noise();
    }
  }
}
void red_noise()
{
  int i;
  for(i=0;i<30;i++)
  {
  digitalWrite(buzz,HIGH);
  delayMicroseconds(tone_red);
  digitalWrite(buzz,LOW);
  delayMicroseconds(tone_red-500);
  }
    
}

void green_noise()
{
  int i;
  for(i=0;i<30;i++)
  {
  digitalWrite(buzz,HIGH);
  delayMicroseconds(tone_green);
  digitalWrite(buzz,LOW);
  delayMicroseconds(tone_green+250);
  }
}
void blue_noise()
{
  int i;
  for(i=0;i<30;i++)
  {
  digitalWrite(buzz,HIGH);
  delayMicroseconds(tone_blue);
  digitalWrite(buzz,LOW);
  delayMicroseconds(tone_blue-600);
  }
}
void yellow_noise()
{
  int i;
  for(i=0;i<30;i++)
  {
  digitalWrite(buzz,HIGH);
  delayMicroseconds(tone_yellow+200);
  digitalWrite(buzz,LOW);
  delayMicroseconds(tone_yellow);
  }
}

void next_noise()
{
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzz, melody_next[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzz);
}
}
void lose_noise()
{
  for (int thisNote = 0; thisNote < 4; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzz, melody_lose[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzz);
}
}

void start_noise()
{
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzz, melody_start[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzz);
}
}

bool button_pressed()
{
  red_read=digitalRead(red_button);
  green_read=digitalRead(green_button);
  blue_read=digitalRead(blue_button);
  yellow_read=digitalRead(yellow_button);
  if(red_read==1||blue_read==1||green_read==1||yellow_read==1)
  {
    red_read=0;
    blue_read=0;
    green_read=0;
    yellow_read=0;
    return(true);
  }
  else
  {
    return(false);
  }
}
int click_button()
{
  red_read=digitalRead(red_button);
  green_read=digitalRead(green_button);
  blue_read=digitalRead(blue_button);
  yellow_read=digitalRead(yellow_button);
   if(red_read==1)
  {
    return(red);
  }
   else if(green_read==1)
  {
      return(green);
  }
  else if(blue_read==1)
  {
     return(blue);
  }
  else if(yellow_read==1)
  {
    return(yellow);
  }
  else
  {
    return(-1);
  }
}
