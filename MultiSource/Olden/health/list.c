/* For copyright information, see olden_v1.0/COPYRIGHT */

/********************************************************************
 *  List.c:  Handles lists.                                         *
 *           To be used with health.c                               *
 ********************************************************************/

#undef JUMP

#include <stdio.h>
#include <stdlib.h>
#include "health.h"

#ifndef PLAIN
#include "mem-ref.h"
#else
#define MIGRPH(); 
#endif

void addList(struct List *list, struct Patient *patient) {
  struct List *b;

  /*MIGRPH();*/
  while (list != NULL) {
    b = list;
    list = list->forward; }
  
  list = (struct List *)malloc(sizeof(struct List));

  NOTEST();
  list->patient = patient;
  list->forward = NULL;
  list->back = b;
  RETEST();
  b->forward = list; } 


void removeList(struct List *list, struct Patient *patient) {
  struct List          *l1,*l2;
  struct Patient       *p;
  
  /*MIGRPH();*/
  p = list->patient;
  while(p != patient) {
      list = list->forward; 
      p = list->patient; }
    
  l1 = list->back;
  l2 = list->forward;
  l1->forward = l2;
  if (list->forward != NULL) {
    l1 = list->forward;
    l2 = list->back;
    l1->back = l2; }
  
  /*free(list);*/
}
     
