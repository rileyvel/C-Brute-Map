#define BRUTE_MAP_SIZE 99999
#define BME_DEP_SIZE 99
#define BME brute_map_entry

#define THINK if (0) printf

// Generate a new entry for brute_map and return it
// NOTE - all values are initialised to 0, except ref_count to 1
BME* brute_map_add(brute_map* map) {

    if (map->used == map->size) {
        fprintf(stderr, "target brute_map is already full.\n");
        return NULL;
    }
    
    THINK("Generating a new brute_map_entry\n");
    BME* new_entry = (BME*) calloc(1, sizeof(BME));
    
    new_entry->key = NULL;
    new_entry->ref_count = 1;
    new_entry->dep_n = 0;
    new_entry->deps = (void**) calloc(BME_DEP_SIZE, sizeof(void*));

    THINK("Generated. Adding it to map...\n");
    map->entries[map->used++] = new_entry;

    return new_entry;
}

// Fetch an entry from brute map with is key
BME* brute_map_get(brute_map* map, void* key) {

    THINK("Trying to find an entry with key %p...\n", key);

    if (key == NULL) {
        THINK("Key is null. Cowardly bailing out...\n");
        return NULL;
    }

    for (int i = 0; i < map->used; ++i) {
        BME* this_entry = map->entries[i];
        if (this_entry->key == key) {
            THINK("Found it. Returning...\n");
            return this_entry;
        }
    }

    THINK("Unable to find the corresponding entry.\n");
    return NULL;

}

void brute_map_init(&map) {
    THINK("Initialising the map...\n");
        
    THINK("Size is %d\n", BRUTE_MAP_SIZE);
    map->entries = (BME**) calloc(BRUTE_MAP_SIZE, sizeof(brute_map_entry*));
    map->size = BRUTE_MAP_SIZE;
    map->used = 0;

    THINK("Initialisation done.\n");
}
