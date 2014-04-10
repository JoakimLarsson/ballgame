// gcc -o bg ballgame.c vt220.c -lncurses

#include <stdio.h>
#include <stdlib.h>
#include "ballgame.h"

static draw_square(int x, int y)
{
  int i;
  for (i = 0; i < x; i++){ 
    bg_setpixel(i, 0, WHITE);
    bg_setpixel(i, y - 1, WHITE);
  }
  for (i = 0; i < y; i++){
    bg_setpixel(0, i, WHITE);
    bg_setpixel(x - 1, i, WHITE);
  }
}

// Globals (sorry)
int ball_posx;
int ball_dirx;
int ball_posy;
int ball_diry;
int ball_speed;
int xres, yres;

static init_ball(int x, int y, int xd, int yd, int speed)
{
  ball_posx = x << 4;
  ball_posy = y << 4;
  ball_dirx = xd << 4;
  ball_diry = yd << 4;
  ball_speed = speed << 2;
}

static update_ball()
{
  ball_posx += ball_dirx;
  ball_posy += ball_diry;

  // lousy bounce detect
  if (ball_posx <= 0 || ball_posx > (xres << 4)){
    ball_dirx = -ball_dirx;
    ball_posx += ball_dirx;
  }
  if (ball_posy <= 0 || ball_posy > (yres << 4)){
    ball_diry = -ball_diry;
    ball_posy += ball_diry;
  }
}

main()
{
  bg_clear(BLACK);
  bg_getres(&xres, &yres);
  draw_square(xres, yres);
  init_ball(xres / 2, yres / 2, 4, 3, 200);
  while(1){
    bg_setpixel(ball_posx >> 4, ball_posy >> 4, BLACK);
    update_ball();
    bg_setpixel(ball_posx >> 4, ball_posy >> 4, WHITE);
    bg_update();
    usleep(10000);
  }
}
