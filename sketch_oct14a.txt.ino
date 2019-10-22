double Voltage;
int AnalogValue;
double Temp;
int Vin = A0;                                     // Vin is Analog Pin A0
double Low_Offset_Voltage = 0.4;                  // Value is used to counteract offset voltage
double Mid_Offset_Voltage = 0.08;                 // Value is used to counteract offset voltage

void setup(){
  Serial.begin(9600);                             // Start the connection with the computer. Transmits 9600 bits/sec which is the default for Arduino
  pinMode (Vin,INPUT);                            // Output from the amplifier will be connected to this pin
}

void loop(){
//Reads the bit value (ranges from 0-1023 bits)  
  AnalogValue=analogRead(Vin);                    // Read the input on analog A0
  Serial.print("AnalogValue: ");
  Serial.println(AnalogValue);                    // Prints out the bit value read (Between 0-1023)
  delay(1000);                                    // 1 second pause

//Bits to Voltage
  Voltage = (analogRead(Vin)/1023.0)*5.0;         // (bit value/max bit value)*Vmax 
  if(Voltage<1)
  Voltage=Voltage-Low_Offset_Voltage;             // Reduces the offset voltage seen between 0-1 volts
  if(Voltage>=1 && Voltage <2)
  Voltage=Voltage-Mid_Offset_Voltage;             // Reduces the offset voltage seen between 1-2 volts
  if(Voltage>=2 && Voltage <3)
  Voltage=Voltage-2*Mid_Offset_Voltage;           // Reduces the offset voltage seen between 2-3 volts
  if(Voltage>=3 && Voltage <4)
  Voltage=Voltage-3*Mid_Offset_Voltage;           // Reduces the offset voltage seen between 3-4 volts
  if(Voltage>=4 && Voltage <5)
  Voltage=Voltage-4*Mid_Offset_Voltage;           // Reduces the offset voltage seen between 4-5 volts
  if(Voltage<0)
  Voltage=0;                                      // Ensures the voltage is never a negative value
  Serial.print("Voltage: ");
  Serial.println(Voltage);                        // Prints out voltage value
  delay(1000);                                    // 1 second pause

//Convert digital value to temperature in Celsius
  Temp=(Voltage*20);                              // Change the multiplier with respect to the temperature range you want
  Serial.print("Temperature Value: ");            // Use line below to convert celsius to fahrenheit if necessary
                                                  // Temp = Temp*1.8+32;
  Serial.println(Temp);                           // Prints the Temperature
  delay(1000);                                    // 1 second pause
}

