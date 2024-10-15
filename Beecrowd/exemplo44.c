/*
  * nome: exemplo44.c
  * descrição: ponteiros
  * data: 06/11/2012
  *Resolvido por Nicolas David da Cruz Santos
  */
 #include <stdio.h>
 int main()
 {
  int x=1,y=3 ;
  int *px=&y, *py=&y;
  *px=*px+*py;

 

  printf("x=%d, y=%d\n", x, y);
  printf("*px=%d, *py=%d\n", *px, *py);
  printf("px=%p, py=%p\n", px, py);
  printf("&x=%p, &y=%p\n", &x, &y);
  return 0;
 } 

