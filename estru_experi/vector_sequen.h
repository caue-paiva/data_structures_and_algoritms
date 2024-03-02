#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h> 
#include <stdint.h>

#define L_LIST_CHUNK 256

typedef int l_list_val;

struct lookup_list {
   l_list_val ** acess_ptrs;
   int alloc_chunks;
   int num_ele;
   l_list_val (*index) (struct lookup_list* , int);
};

typedef struct lookup_list l_list_t;