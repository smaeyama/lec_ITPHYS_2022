#include <stdio.h>
#include <math.h>
#define G_ACC 9.8 /* 重力加速度 */
void calc_derivative(double xv[], double dxvdt[]);

int main(void){
  double dt = 0.01; /* 時間積分の刻み幅 dt (=h) */
  double t;         /* 時間 t */
  double xv[4];     /* 粒子の位置と速度を xv[0]=x,xv[1]=z,xv[2]=vx,xv[3]=vz とまとめた配列 */
  double k1[4];     /* 同様に dx/dt, dz/dt, dvx/dt, dvz/dt をまとめた配列 */
  int i;
  /* 初期値の設定 */
  t = 0.0;
  xv[0] = 0.0; /* x(t=0) */
  xv[1] = 0.0; /* z(t=0) */
  xv[2] = 20.0 * cos(2.0*M_PI*30.0/360.0); /* vx(t=0) */
  xv[3] = 20.0 * sin(2.0*M_PI*30.0/360.0); /* vz(t=0) */
  printf("#  t,  x,  z,  vx,  vz\n");
  printf("%f %f %f %f %f\n", t, xv[0], xv[1], xv[2], xv[3]);

  /* 時間積分 */
  for (t = dt; t <= 2.0; t=t+dt){
    calc_derivative(xv,k1);
    for (i=0;i<4;i++) {
      xv[i] = xv[i] + dt * k1[i];
    }
    printf("%f %f %f %f %f\n", t, xv[0], xv[1], xv[2], xv[3]);
  }
  return 0;
}

void calc_derivative(double xv[], double dxvdt[]){
  dxvdt[0] = xv[2];  /* dx/dt=vx */
  dxvdt[1] = xv[3];  /* dz/dt=vz */
  dxvdt[2] = 0.0;    /* dvx/dt=0 */
  dxvdt[3] = -G_ACC; /* dvz/dt=-g/m */
}
