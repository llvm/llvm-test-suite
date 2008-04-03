#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

#define MAX_SIZE 1000000

/*==========================================================================*/

typedef struct internal_huffman_node{						/*1*/
  void* left;									/*2*/
  void* right;									/*3*/
} internal_node;

typedef union tree_node {							/*4*/
  char leafval;									/*5*/
  internal_node intnode;							/*6*/
} node;

typedef struct huffman_tree {							/*7*/
  int leaf;									/*8*/
  node treenode;								/*9*/
} hufftree;

hufftree* create_subtree(char* input, int offset, int size);			/*10*/

hufftree* build_tree(char* input, int offset) {					/*11*/
  int leftsize,rightsize;							/*12*/
  hufftree* res;								/*13*/
  leftsize = get_16_bit_int(input, offset);					/*14*/
  rightsize = get_16_bit_int(input, offset+leftsize+2);				/*15*/
  res = (hufftree*) malloc(sizeof(hufftree));					/*16*/
  (res->leaf)=0;								/*17*/
  ((res->treenode).intnode).left = create_subtree(input,offset+2,leftsize);	/*18*/
  ((res->treenode).intnode).right = 						/*19*/
    create_subtree(input,offset+4+leftsize,rightsize);				/*20*/
  return res;									/*21*/
}

hufftree* create_subtree(char* input, int offset, int size) {			/*22*/
  hufftree* res;								/*23*/
  if (size == 1) {								/*24*/
    res = (hufftree*) malloc(sizeof(hufftree));					/*25*/
    res->leaf=1;								/*26*/
    (res->treenode).leafval = input[offset];					/*27*/
    return res;									/*28*/
  }
  return build_tree(input, offset);						/*29*/
}
    
    

int get_bit(char* input, int offset) {						/*30*/
  int byte_offset, bit_offset;							/*31*/
  byte_offset = offset >> 3;							/*32*/
  bit_offset = 7-(offset & 7);							/*33*/
  return (1 << bit_offset) & input[byte_offset];				/*34*/
}

int get_16_bit_int(char* input, int offset) {					/*35*/
  int t1,t2,t3,res;								/*36*/
  t1 = (int) input[offset];							/*37*/
  t2 = (t1 & 255) << 8;								/*38*/
  t3 = (int) input[offset+1];							/*39*/
  res =  t2 | (t3 & 255);							/*40*/
  return res;									/*41*/
}
int get_32_bit_int(char* input, int offset) {					/*42*/
  return (((int) (input[offset] & 255) << 24) | 				/*43*/
	  ((int) (input[offset+1] & 255) << 16) |				/*44*/
	  ((int) (input[offset+2] & 255) << 8) | 				/*45*/
	  ((int) (input[offset+3] & 255)));  					/*46*/
} 

int decode(int offset, int limit, char* input, hufftree* orig, char* output) {	/*47*/
  hufftree* pres=orig;								/*48*/
  int ooffset=0;								/*49*/
  while (offset <= (limit+1)) {							/*50*/
    if (pres->leaf) {								/*51*/
      output[ooffset] = (pres->treenode).leafval;				/*52*/
      ooffset++;								/*53*/
      pres=orig;								/*54*/
    }
    else {
      if (get_bit(input,offset)) {						/*55*/
	pres = ((pres->treenode).intnode).right;				/*56*/
      }
      else {
	pres = ((pres->treenode).intnode).left;					/*57*/
      }
      offset++;									/*58*/
    }
  }
  return ooffset;								/*59*/
}

int do_decode(char* input, char* output) {					/*60*/
  int tree_size, no_of_bits, init_offset;					/*61*/
  hufftree* tree;								/*62*/
  tree_size = get_16_bit_int(input, 4);						/*63*/
  tree = build_tree(input,6);							/*64*/
  no_of_bits = get_32_bit_int(input,6+tree_size);				/*65*/
  init_offset = (10+tree_size)*8; 						/*66*/
  return decode(init_offset, no_of_bits+init_offset, input, tree, output);	/*67*/ 
}

/*==========================================================================*/

static size_t read_data(FILE *in, void *buffer)
{ 
  return fread(buffer, 1, MAX_SIZE, in);
}

static size_t write_data(FILE *out, int size, void *buffer)
{ 
  return fwrite(buffer, 1, size, out);
}



int main(int argc, char *argv[])
{
  FILE *in,*out;
  int i;
  size_t size;
  int outsize,time;
  unsigned char *inbuf, *outbuf, *temp;
  char outfilename[100];
  char postfix[] = ".c";
  struct timeval pre,post;
  
  /* optional input arg */
  inbuf = malloc(MAX_SIZE);
  outbuf = malloc(8*MAX_SIZE);
  
  if (argc > 1) {
    //create_test_data(argv[1]); // for testing purposes
    if ((in = fopen(argv[1], "r")) == NULL) {
      perror(argv[1]);
      exit(1);
    }
    strcpy(outfilename,argv[1]);
    strcat(outfilename,postfix);
    if ((out = fopen(outfilename, "w")) == NULL) {
      perror(outfilename);
      exit(1);
    }
    argv++; argc--;
  }
  
  else{
    in = stdin;
    out = stdout;
  }
  if (argc != 1) {
    printf("Usage: huffman [infile]\n");
    exit(2);
  }
  size = read_data(in, inbuf);
  gettimeofday(&pre,0);
  for(i=0;i<10;i++){
    outsize = do_decode(inbuf,outbuf);
  }
  gettimeofday(&post,0);
  time = ((post.tv_sec*1000000+post.tv_usec)-(pre.tv_sec*1000000+pre.tv_usec));
  printf("%d", outsize);
  exit(0); 
}