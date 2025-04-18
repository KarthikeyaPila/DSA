#include <stddef.h>
#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h> 

enum ERROR_TYPE {
  CAPACITY_EXCEEDED = 1,
  UNREACHABLE_CODE,
};


typedef struct kv_pair{
  int key; 
  int value; 
  bool occupied;
} kv_pair; 


// buffer is where we store the key value
// size is the no. of key value pairs stored in the map
// capacity is the no. of kv pairs that could be stored.

typedef struct hashmap{
  kv_pair *buffer; 
  size_t size;
  size_t capacity;
} map;



size_t map_set(map *map, int key, int val);

int hash_idx(map* m, int key){
  return key % (m->capacity);
}

// Create

// give a empty map.
map *map_new(size_t capacity){
  map *m = malloc(sizeof(map));
  m->capacity = capacity; 
  m->size = 0; 
  m->buffer = malloc(sizeof(kv_pair)*m->capacity);

  for(size_t i=0; i<m->capacity; i++){
    m->buffer[i].occupied = false;
  }

  return m;
}

//  create a hashmap with a given array
map *map_create(size_t size, int arr[size][2], size_t capacity){
  map *m = map_new(capacity);

  for(size_t i=0; i<size; i++){
    map_set(m, arr[i][0], arr[i][1]);
  }

  return m;
}


// Read

// get the value at a given key
int map_get(map *m, int key){
  int idx = hash_idx(m, key);
  int idx_key = m->buffer[idx].key;

  // if the index and index keys are not the same then iterate till you find the keys.
  if(m->buffer[idx].occupied && idx_key != key){
    for(size_t i=idx; i<idx + m->capacity; i++){
      int buffer_idx = i % m->capacity;

      if(m->buffer[buffer_idx].key == key){
        return m->buffer[buffer_idx].value;
      }
    }
  } else if (m->buffer[idx].occupied && idx_key == key){
    return m->buffer[idx].value;
  }

  return -1;
}

// return the number of key_value pairs present.
size_t map_size(map *m){
  return m->size;
}

// print the whole map.
void map_print(map *m){
  printf("{\n");

  for(size_t i=0; i<m->capacity; i++){
    if(m->buffer[i].occupied == true){
      printf("(%d , %d)\n", m->buffer[i].key, m->buffer[i].value);
    }
  }

  printf("}\n");

  return;
}


// Update

// set a key_value pair to the hashmap. it returns the new m->size.
size_t map_set(map *m, int key, int val){
  if(m->size >= m->capacity){
    exit(CAPACITY_EXCEEDED);
  }

  int idx = hash_idx(m, key);

  if(m->buffer[idx].occupied == true && m->buffer[idx].key == key){
    m->buffer[idx].key = key;
    m->buffer[idx].value = val;
    m->buffer[idx].occupied = true;
    return m->size;
  }

  if(m->buffer[idx].occupied == false){
    m->buffer[idx].key = key;
    m->buffer[idx].value = val;
    m->buffer[idx].occupied = true;
    m->size++;
    return m->size;
  }

  for(size_t i=idx+1; i<=idx + m->capacity - 1; i++){
    int buffer_idx = i % m->capacity;
    if (m->buffer[buffer_idx].occupied && m->buffer[buffer_idx].key == key){
      m->buffer[buffer_idx].value = val;
      return m->size;
    }
    if(m->buffer[buffer_idx].occupied == false){
      m->buffer[buffer_idx].key = key;
      m->buffer[buffer_idx].value = val;
      m->buffer[buffer_idx].occupied = true;
      m->size++;
      return m->size;
    }
  }

  exit(UNREACHABLE_CODE);
}


// Delete

// delete a key_value pair
int map_delete(map *m, int key){

  int result = map_get(m, key);
  int idx = hash_idx(m, key);
  int idx_key = m->buffer[idx].key;

  if(!m->buffer[idx].occupied){
    return -1;
  }

  if(idx_key != key){
    for(size_t i=idx+1; i<=idx+m->capacity-1; i++){
      int buffer_idx = i % m->capacity;

      if(m->buffer[buffer_idx].key == key){
        idx = buffer_idx;
      } else if(m->buffer[buffer_idx].occupied == false){
        idx = -1;
      }
    } 
  }
  
  
  if(idx != -1){
    m->buffer[idx].key = 0;
    m->buffer[idx].value = 0;
    m->buffer[idx].occupied = false;
    m->size--;
  } else if(idx == -1){
    return -1;
  }

  return result;
}

// free the whole map.
void map_free(map *m){
  free(m->buffer);
  free(m);
}

