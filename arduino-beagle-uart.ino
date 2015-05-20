void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
}
 int cnt=0;
long int value=0;
char array[5];
void loop() {
  while (Serial1.available() == 1)
  {
   
    char a = Serial1.read();
    if(a!='\n')
    {
      array[cnt]=a;
      cnt++;
    }
    else if (a == '\n')
    {
      for(int i=0;i<cnt;i++)
      {
        value+=(int)(array[i]-48)*pow(10,cnt-i-1);
      }
      if(cnt>=3)
      {
       Serial.print(value+1);
       Serial.println("");
      }
      else
      {
       Serial.print(value);
       Serial.println("");
      }
 value=0;
 cnt=0;
    }
    } 

  }
