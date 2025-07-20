#include "matrixControl.h"

Matrix::Matrix(int* ppins, int* npins, int xsize, int ysize){
  p_pins = ppins;
  n_pins = npins;
  x_size = xsize;
  y_size = ysize;
}

void Matrix::init_matrix()
{
  matrix_val = (int*)malloc(sizeof(int)*x_size*y_size);
  for (int i = 0; i < y_size; i ++)
  {
    for(int j = 0; j < x_size; j++)
    {
      matrix_val[IX(i,j,x_size)] = 0;
    }
  }

  for (int i = 0; i < y_size; i ++)
  {
    pinMode(p_pins[i], OUTPUT);
  }
  for (int i = 0; i < x_size; i ++)
  {
    pinMode(n_pins[i], OUTPUT);
  }
}

void Matrix::update_matrix(float delay_time)
{
  for (int i = 0; i < x_size; i ++)
  {
    digitalWrite(n_pins[i], HIGH);
    for(int j = 0; j < y_size; j++)
    {
      if(analog)
      {
        analogWrite(p_pins[j] , matrix_val[IX(j,i,x_size)]);
        //digitalWrite(n_pins[j], HIGH);//matrix_val[IX(j,i,x_size)]);
      }
      else
      {
        digitalWrite(p_pins[j] ,matrix_val[IX(i,j,x_size)]);
        //digitalWrite(n_pins[j], matrix_val[IX(j,i,x_size)]);
      }

      
      //Serial.println(matrix_val[IX(i,j,x_size)]);

    }
    delay(delay_time);

    for(int j = 0; j < x_size; j++)
    {
      if(analog)
      {
        analogWrite(p_pins[i] ,0);
        analogWrite(n_pins[j], 0);
      }
      else
      {
        digitalWrite(p_pins[i] ,LOW);
        digitalWrite(n_pins[j], LOW);
      }

    }
  }
}

void Matrix::write_analog(int x, int y, int value)
{
  matrix_val[IX(x,y,x_size)] = value;
  analog = true;
}

void Matrix::write_digital(int x, int y, int value)
{
  matrix_val[IX(x,y,x_size)] = value;
  analog = false;
}
