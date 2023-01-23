int thermpin=0;
int vout;
float r1=20000;
float logr2, r2, t, tc, tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  vout=analogRead(thermpin);
  r2=r1*((1023.0/ (float)vout ) - 1.0); 
  logr2=log(r2);
  t=(1.0/(c1 + c2*logr2 + c3*logr2*logr2*logr2));
  tc=t - 273.15;
  //tf=(tc * 9.0)/5.0 + 32.0; for fahrenheit
  if(tc>50){
    Serial.print("Sensor not working : Temperature too high");
  }
 // else if(tc<10){
   // Serial.print("Sensor not installed correctly or Temperature too cold");
  //}
  else{
    Serial.print("Body Temperature:");
    Serial.println(tc);
  }
  
  // using steinhart hart equation and approximating it to 2 terms.
  // put your main code here, to run repeatedly:
  //model b3950

} 
