#include "matrixControl.h"
#include "math.h"

#define x_axis A1
#define y_axis A0

int p_pins[2] = {6,9};
int n_pins[2] = {3,5};

float val = 0;

Matrix m(&p_pins[0], &n_pins[0], 2, 2);
void setup() {

  Serial.begin(9600);

  pinMode(p_pins[0],OUTPUT);
  pinMode(n_pins[0],OUTPUT);

  analogWrite(p_pins[0],255);
  analogWrite(n_pins[0],25);

  m.init_matrix();
  //m.write_digital(0, 1, 1);
  //m.write_analog(1, 1, 25);
  //m.write_digital(1, 0, HIGH);
 // m.write_analog(0, 0, 1);

  //m.update_matrix(250);

}

void loop() {
  m.update_matrix(10);

  int posx = 750+750*sin(val);
  int posy = 750+750*cos(val);;
  m.write_analog(0,0, map(distance(0,0,posx,posy), 400, 1800, 1, 25));
  m.write_analog(0,1, map(distance(1500,0,posx,posy), 400, 1800, 1, 25));
  m.write_analog(1,0, map(distance(0,1500,posx,posy), 400, 1800, 1, 25));
  m.write_analog(1,1, map(distance(1500,1500,posx,posy), 400, 1800, 1, 25));

 // m.write_analog(0, 0, map(posx, 0, 1023, 0, 25));
 // m.write_analog(1, 0, map(posx, 0, 1023, 25, 0));
  val += 0.1;
  //Serial.println(distance(0,0,posx,posy));
}


float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}