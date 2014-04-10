#include <ncurses.h>
#include <stdlib.h>

#include "ballgame.h"

bg_clear(int col)
{
  initscr();
  cbreak(); 
  noecho();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);  
}

bg_getres(int *xres, int *yres)
{
  char *tmp;

  //  *xres = ((tmp = getenv("COLUMNS")) != NULL ? atoi(tmp) : 80);
  //  *yres = ((tmp = getenv("LINES"))   != NULL ? atoi(tmp) : 72);

    *xres = ((tmp = getenv("COLUMNS")) != NULL ? atoi(tmp) : 80);
    *yres = ((tmp = getenv("LINES"))   != NULL ? atoi(tmp) : 50);
}

bg_setpixel(int x, int y, int col)
{
  mvaddch(y, x, col == BLACK ? ' ' : '*');
}

bg_update()
{
  refresh();
}
