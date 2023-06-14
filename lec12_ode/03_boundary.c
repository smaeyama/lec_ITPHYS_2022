#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G_ACC 9.8 /* 重力加速度 */
#define ACC 1.0e-12
void calc_derivative(double xv[], double dxvdt[]);

/* シューティング法により目標とする飛距離を出すために必要な初速度を推定する */
int main(){
  double x_target;
  double x, v, x_prev, v_prev, dv;
  char buf[30];
  int i;
  double landing_point(double v0);
  /*目標飛距離の入力*/
  printf("distance ?");
  fgets(buf,sizeof(buf),stdin);
  if (sscanf(buf,"%lf",&x_target) != 1) {
    fputs("input error\n", stderr);
    exit(-1);
  }

  v = 20.0; /* 初期推定値 */
  x = landing_point(v);
  v_prev = 1.01 * v; /* 微分の差分近似のために初期推定値を少しずらしたもの */
  x_prev = landing_point(v_prev);

  i = 0;
  do {
    i++;
    dv = - (v - v_prev) * (x - x_target) / (x - x_prev); /* 解の改良 */
    v_prev = v;
    x_prev = x;
    v = v + dv;
    x = landing_point(v);
      printf("i=%d, v=%25.16f: x=%25.16f\n", i, v, x);
    } while(fabs(x-x_target) >= ACC); /* 収束判定 */
  return 0;
}

/* 初速度v0を入力として、着地点(z=0)のx座標を返り値とする関数 */
/* 初期値問題のmain関数をほぼそのまま利用している */
double landing_point(double v0){
  double dt = 0.01; /* 時間積分の刻み幅 dt (=h) */
  double t;         /* 時間 t */
  double xv[4];     /* 粒子の位置と速度を xv[0]=x,xv[1]=z,xv[2]=vx,xv[3]=vz とまとめた配列 */
  double k1[4];     /* 同様に dx/dt, dz/dt, dvx/dt, dvz/dt をまとめた配列 */
  double x0, z0, x1, z1, x_landing;
  int i;
  /* 初期値の設定 */
  t = 0.0;
  xv[0] = 0.0;
  xv[1] = 0.0;
  xv[2] = v0 * cos(2.0*M_PI*30.0/360.0);
  xv[3] = v0 * sin(2.0*M_PI*30.0/360.0);

  /* 時間積分 */
  for (t = dt; xv[1] >= 0.0; t=t+dt){
    calc_derivative(xv,k1);
    for (i=0;i<4;i++) {
      xv[i] = xv[i] + dt * k1[i];
    }
  }

  /* 着地点を(x0,z0>0)と(x1,z1<0)の2点の内挿で求める */
  x0 = xv[0] - dt * k1[0];
  z0 = xv[1] - dt * k1[1];
  x1 = xv[0];
  z1 = xv[1];
  x_landing = (x1*z0 - x0*z1)/(z0-z1);
  return x_landing;
}

void calc_derivative(double xv[], double dxvdt[]){
  dxvdt[0] = xv[2];  /* dx/dt=vx */
  dxvdt[1] = xv[3];  /* dz/dt=vz */
  dxvdt[2] = 0.0;    /* dvx/dt=0 */
  dxvdt[3] = -G_ACC; /* dvz/dt=-g/m */
}
