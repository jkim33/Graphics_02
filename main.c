#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = MAX_COLOR;;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);
  struct matrix *edges;

  edges = new_matrix(4, 4);
  add_edge(edges, 250, 150, 0, 150, 250, 0);
  add_edge(edges, 250, 150, 0, 350, 250, 0);
  add_edge(edges, 150, 250, 0, 200, 320, 0);
  add_edge(edges, 200, 320, 0, 250, 300, 0);

  add_edge(edges, 250, 300, 0, 300, 320, 0);
  add_edge(edges, 300, 320, 0, 350, 250, 0);

  draw_lines( edges, s, c);
  // free_matrix( edges );

  display(s);
  save_extension(s, "matrix.png");
}  
