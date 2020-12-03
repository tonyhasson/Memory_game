
int choose_sound(int num);
int red=8,green=7,blue=6,yellow=5,buzz=13,count=0,temp_rand,guess=0,chk=0;;
int a[50]={0};
int tone_red=8000,tone_blue=6000,tone_green=4000,tone_yellow=2000;


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
  
  Serial.println("enter 1 to begin!");
  while(Serial.available()==0)
  {
    
  }
  
  chk=Serial.parseInt();
  while(chk==1)
  {
    game_turn();
    Serial.println("enter the color one by one(red-8,green-7,blue-6,yellow-5)");
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
  a[count]=random(5,9);
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
    Serial.println("enter color");
    while(Serial.available()==0);
    {

    }
    num=Serial.parseInt();
    if(num==a[i])
    {
      guess++;
      i++;
    }
    else
    {
      Serial.println("you lose!");
      delay(1000);
      exit(1);
    }
    
    
  }
  Serial.println("good job! get ready for the next round!");
  delay(1000);
}


int choose_sound(int num)
{
   switch(num)
  {
    case(8):
    {
      red_noise();
    }
     case(7):
    {
      green_noise();
    }
     case(6):
    {
      blue_noise();
    }
     case(5):
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
  
}
void lose_noise()
{
  
}
