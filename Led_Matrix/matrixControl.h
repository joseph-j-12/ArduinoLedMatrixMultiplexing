#ifndef matCont
#define matCont

#define IX(i,j,xs) i*xs+j

#include "Arduino.h"
class Matrix{
  public:
  Matrix(int* ppins, int* npins, int xsize, int ysize);

  void init_matrix();
  void update_matrix(float delay_time);

  void write_analog(int x, int y, int value);
  void write_digital(int x, int y, int value);
  private:
  int* p_pins;
  int *n_pins;

  int x_size;
  int y_size;

  int *matrix_val;

  bool analog = false;

};
#endif