#include "vector_sequen.h"

static l_list_val __l_list_index(l_list_t*list, int index){
      assert(list);
      if (index < 0) {
         printf("index cant be negative\n");
         return 1;
      }
      if (list->num_ele == 0){
         printf("list has no elements\n");
         return 1;
      }
      if ( (list->alloc_chunks * L_LIST_CHUNK) < (index+1) ) {
         printf("array index out of range");
         return 1;
      }

      unsigned int mem_chunk = index / L_LIST_CHUNK;
      unsigned int in_chunk_index = index % L_LIST_CHUNK;

      l_list_val = list->acess_ptrs[mem_chunk][in_chunk_index];

      return l_list_val;

}

static bool __l_list_add(l_list_t*list,l_list_val val){
      assert(list);

      uint max_num_elem = list->alloc_chunks * L_LIST_CHUNK;

      uint cur_elem = list->num_ele;

      if ((cur_elem + 1) > max_num_elem) {


      }



}

l_list_t* create_l_list(){

   l_list_t* list = (l_list_t*)  malloc(sizeof(l_list_t));
   assert(list);

   l_list_val* first_chunk = (l_list_val*) malloc(sizeof(l_list_val) * L_LIST_CHUNK);
   assert(first_chunk);

   list->acess_ptrs[0] = first_chunk;
   list->alloc_chunks = 1;
   list->num_ele = 0;

   //list->index = 
}

int main(){
   unsigned int a = 200 / 256;
   unsigned int b = 257 % 256;
   printf("%u  %u", a, b);
}

