#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
/*reduce refresh rate
//log file


/* This driver reads raw data from the BNO055
*/

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (300)

Adafruit_BNO055 bno = Adafruit_BNO055();

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(500);

  /* Display the current temperature */
  int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(true);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void)
{
  // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2


  int8_t temp;
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER); //get euler 
  imu::Vector<3> accraw = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  imu::Vector<3> magraw = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

  imu::Vector<3> gyro\
  
  = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);

  
  temp = bno.getTemp();
  /* Display the floating point data */

  /*Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");
  */

  
  /*   euler display
  Serial.print("Euler(X): ");
  Serial.print(euler.x());
  Serial.print("Euler(Y): ");
  Serial.print(euler.y());
  Serial.print("Euler(Z): ");
  Serial.print(euler.z());
*/

  Serial.print("ACCELEROMETER: ");
  Serial.print(euler.x());
  Serial.print("  ");
  Serial.print(euler.y());
  Serial.print("  ");
  Serial.print(euler.z());



  Serial.println("   ");
  Serial.print("GYROSCOPE: ");
  Serial.print(gyro.x());
  Serial.print("  ");
  Serial.print(gyro.y());
  Serial.print("  ");
  Serial.print(gyro.z());
  



  Serial.print("\t\t");

  /*
  // Quaternion data
  imu::Quaternion quat = bno.getQuat();
  Serial.print("qW: ");
  Serial.print(quat.w(), 4);
  Serial.print(" qX: ");
  Serial.print(quat.y(), 4);
  Serial.print(" qY: ");
  Serial.print(quat.x(), 4);
  Serial.print(" qZ: ");
  Serial.print(quat.z(), 4);
  Serial.print("\t\t");
  */

  /* Display calibration status for each sensor. 
  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  Serial.print("CALIBRATION: Sys=");
  Serial.print(system, DEC);
  Serial.print(" Gyro=");
  Serial.print(gyro, DEC);
  Serial.print(" Accel=");
  Serial.print(accel, DEC);
  Serial.print(" Mag=");
  Serial.println(mag, DEC);
*/
  delay(BNO055_SAMPLERATE_DELAY_MS);
}