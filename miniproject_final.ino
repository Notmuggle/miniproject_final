

#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int read_count=0,tag_count=0,count1=1,count2=1;
int j=0,k=0,i=0;
char data_temp, RFID_data[12],data_store[10][12],data_store2[10][12],data_delete[12];
boolean disp_control;

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
   Serial.println("initialising..show the RFID card");
   lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.println("show the card   ");
   delay(5000);
  lcd.clear();
}

void loop()
{
   lcd.setCursor(0,0);
    lcd.print("objects inside       ");
  ReceiveData();
  StoreData();
  PrintData();
}

void ReceiveData()
{
 // Serial.println("received");
  if(mySerial.available()>0)
  {
    data_temp=mySerial.read();
    if(data_temp=='3')
    {
      count1++;
    }
    else if(data_temp=='7')
    {
      count2++;
    }
    RFID_data[read_count]=data_temp;
    read_count++;
  }
}
void StoreData()
{
  //Serial.println("store");
  if(read_count==12)
  {
    disp_control=true;
    for(k=tag_count;k<=tag_count;k++)
    {
for(j=0;j<12;j++)
{
  data_store[k][j]=RFID_data[j];  
}
    }
    read_count=0;
    tag_count++;
  }
  
}

void PrintData()
{
   if(disp_control==true)
   {
  if((count1%2)!=0)
  {
    Serial.println("1. ");
    lcd.setCursor(0,1);
    lcd.print(" ");
  }
  else if((count1%2)==0)
  {
    //Serial.println("1. object1");
    lcd.setCursor(0,1);
    lcd.print("1 ");
  }
  if((count2%2)!=0)
  {
    //Serial.println("2. ");    
    lcd.setCursor(2, 1);
    lcd.print("  ");
  }
   else if((count2%2)==0)
  {
    Serial.println("2 ");
     lcd.setCursor(2, 1);
    lcd.print("2 ");
  }

  Serial.println(" ");
  Serial.println(" ");
   disp_control=false;
  }
}


