/*
 * This regression test ensures that the C front end can compile initializers
 * correctly when their size is not static.
 */
struct one
{
  int a;
  int values [];
};

struct one hobbit = {5, {1, 2, 3}};

int
main ()
{
  int index;

  for (index=0; index < 3; index++)
  {
    printf ("%d\n", hobbit.values[index]);
  }

  return 0;
}

