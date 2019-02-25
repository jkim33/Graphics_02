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
  c.blue = MAX_COLOR;

  clear_screen(s);

  struct matrix *m2 = new_matrix(4,4);
  add_edge(m2, 1,2,3,4,5,6);
  printf("testing add_edge: (1,2,3), (4,5,6). m2=\n");
  print_matrix(m2);
  
  struct matrix *m1 = new_matrix(4,4);
  ident(m1);
  printf("identity matrix. m1=\n");
  print_matrix(m1);

  printf("testing matrix mult. m1*m2=\n");
  matrix_mult(m1,m2);
  print_matrix(m2);

  free_matrix(m1);
  m1 = new_matrix(4,4);
  printf("m1=\n");
  add_edge(m1, 1,2,3,4,5,6);
  add_edge(m1, 7,8,9,10,11,12);
  print_matrix(m1);

  printf("m1*m2=\n");
  matrix_mult(m1,m2);
  print_matrix(m2);
  
  struct matrix *edges;

  edges = new_matrix(4, 4);
  add_edge(edges, 0,250,0,250,500,0);
  add_edge(edges, 250,500,0,500,250,0);
  add_edge(edges, 500,250,0,250,0,0);
  add_edge(edges, 250,0,0,0,250,0);

  add_edge(edges, 125,125,0,125,375,0);
  add_edge(edges, 125,375,0,375,375,0);
  add_edge(edges, 375,375,0,375,125,0);
  add_edge(edges, 375,125,0,125,125,0);

  add_edge(edges, 125,250,0,250,375,0);
  add_edge(edges, 250,375,0,375,250,0);
  add_edge(edges, 375,250,0,250,125,0);
  add_edge(edges, 250,125,0,125,250,0);

  draw_lines( edges, s, c);
  free_matrix( edges );

  display(s);
  save_extension(s, "matrix.png");
}  
