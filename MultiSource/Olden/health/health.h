/* For copyright information, see olden_v1.0/COPYRIGHT */

/****************************************************************
 * health.h: header file for health.c                           *
 ****************************************************************/


#ifndef _HEALTH
#define _HEALTH
#define USE_ARRAY_CODE 1

#include <stdio.h>
#include <stdlib.h>

#define PLAIN         /* Toronto uses the "plain" version */
#define chatting printf

#define IA 16807
#define IM 2147483647
#define AM (1.0 / IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

int                      max_level;
long long                     max_time,
                         seed;

int dealwithargs(int argc, char *argv[]);

struct Results {
  double                  total_patients;
  double                  total_time;
  double                  total_hosps; 
};

struct Patient {
  int                    hosps_visited;
  int                    time;
  int                    time_left;
  struct Village         *home_village;
};

struct List {
  struct List            *forward;
  struct Patient         *patient;
  struct List            *back;
};

struct Hosp {
#if 0
  int                    personnel; 
  int                    free_personnel; 
  int                    num_waiting_patients; 
  struct List            waiting; 
  struct List            assess; 
  struct List            inside;
  struct List            up;
#else
  int                    free_personnel; 
  struct List            waiting;
  struct List            assess;
  struct List            inside;
  struct List            up;
  int                    personnel; 
  int                    num_waiting_patients; 
#endif
};
  
struct Village {
#if 0
#if USE_ARRAY_CODE
  struct Village         *forward[4];
#else
  struct Village         *forward0, *forward1, *forward2, *forward3;
#endif
  struct Village         *back;
  struct List            returned;
  struct Hosp            hosp;   
  int                    label;
  long long              seed;
#else
  struct Hosp            hosp;   
  long long              seed;
  struct Village         *forward[4];
  int                    label;
  struct List            returned;
  struct Village         *back;
#endif
};

#if USE_ARRAY_CODE
#define getValN(P, n) P[n]
#define setValN(P, n, v) P[n] = v
#else
#define getValN(P, n) \
   ((n == 0) ? P##0 : ((n == 1) ? P##1 : ((n == 2) ? P##2 : P##3)))
#define setValN(P, n, v) \
  do { if (n == 0) { P##0 = v; } else if (n == 1) { P##1 = v; } else \
       if (n == 2) { P##2 = v; } else             { P##3 = v; } } while (0)
#endif



struct Village *alloc_tree(int level, int lo, int proc, 
                           int label, struct Village *back);
int dealwithargs(int argc, char *argv[]);
double my_rand(long long idum);
struct Patient *generate_patient(struct Village *village);
void put_in_hosp(struct Hosp *hosp, struct Patient *patient);
void addList(struct List *list, struct Patient *patient);
void removeList(struct List *list, struct Patient *patient);
struct List *sim(struct Village *village);
void check_patients_inside(struct Village *village, struct List *list);
struct List *check_patients_assess(struct Village *village, struct List *list);
void check_patients_waiting(struct Village *village, struct List *list);
double get_num_people(struct Village *village);
double get_total_time(struct Village *village);
double get_total_hosps(struct Village *village);
struct Results get_results(struct Village *village);

#endif

