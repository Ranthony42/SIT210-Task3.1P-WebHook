// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#define DHTPIN D6    
#define DHTTYPE DHT11


String MyData;
DHT dht(DHTPIN, DHTTYPE);


void setup() {
    
    Serial.begin(9600);
    dht.begin();

}

void loop() {
    
    float t2 = dht.getTempCelcius();
    // float h2 = dht.getHumidity();
 
    
    //MyData = String::format("%.1f C, %.1f %", t2, h2);  //if we include humidity 
    MyData = String::format("%.1f C", t2);              //only temperature
    
    Particle.publish("Temp", MyData, PRIVATE);
    delay(20000);


}





