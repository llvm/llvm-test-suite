
/****
    Copyright (C) 1996 McGill University.
    Copyright (C) 1996 McCAT System Group.
    Copyright (C) 1996 ACAPS Benchmark Administrator
                       benadmin@acaps.cs.mcgill.ca

    This program is free software; you can redistribute it and/or modify
    it provided this copyright notice is maintained.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
****/

/*         benchmark.c          */
/*   quicksort and bubblesort   */
/*            made              */
/*          24/09/96            */
/*             by               */
/*    Jacob Grydholt Jensen     */
/* Email: grydholt@daimi.aau.dk */
/*             &&               */
/*       Claus Brabrand         */
/* Email: zracscan@daimi.aau.dk */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "readlist.h"

BOOL LessThan(int x, int y);

BOOL LessThan(int x, int y)
{
  return (x < y);
}

int main()
{
  int listno = 1;
  int err;
  LinkList *ll; /* ll = lINKED lIST */
  List *l;      /* l = lIST */
  while ((err = ReadList(&ll, &l)) == 0) {
    printf("\nList read (reverse order): ");fflush(stdout);
    PrintList(l);
    printf("\nBubbleSort: "); fflush(stdout);
    l = BubbleSort(l, LessThan);
    PrintList(l);
    printf("\nQuickSort:  "); fflush(stdout);
    ll = QuickSort(ll, LessThan);
    PrintLinkList(ll);
    printf("\n");
    listno++;
  }

  switch(err) {
  case COMMA_EXPECTED:
    printf("Comma expected in list number %d\n", listno);
    exit(1);
    break;
  case READ_EOF:
    printf("Last list read\n");
    break;
  default:
    printf("Program Error: Unrecognized errorcode from ReadList\n");
    exit(1);
    break;
  }
  exit(0);
}
