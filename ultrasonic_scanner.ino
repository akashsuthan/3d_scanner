#define TRIGGER_PIN A0
#define ECHO_PIN A1

// Position of the ultrasonic sensor
const float sensor_x = 0;
const float sensor_y = 0;
const float sensor_z = 0;

// Angles at which the sensor is pointing
const float sensor_x_angle = 45;
const float sensor_y_angle = 30;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration / 58.0;

  if (distance >= 5 && distance <= 40) {
    // Calculate the coordinates
    float x_angle_rad = sensor_x_angle * PI / 180;
    float y_angle_rad = sensor_y_angle * PI / 180;
    float x = sensor_x + distance * cos(y_angle_rad) * cos(x_angle_rad);
    float y = sensor_y + distance * cos(y_angle_rad) * sin(x_angle_rad);
    float z = sensor_z + distance * sin(y_angle_rad);

    //Serial.print("Coordinates: (");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.print(z);
    Serial.println("");
  }

delay(100);
}