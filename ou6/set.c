#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "set.h"

struct set {
    int capacity;
    int size;
    char *array;
};


set *set_empty()
{
    set *s = malloc(sizeof(set));
    s->capacity = 8;
    s->size = 0;
    s->array = malloc(s->size * sizeof(char));
    s->array[0] = 0;

    return s;
}


set *set_single(const int value)
{
    int bit_in_array = value;
    int no_of_bytes = bit_in_array / 8 + 1;

    set *s = malloc(sizeof(set));
    s->size = 1;
    s->capacity = no_of_bytes * 8;
    s->array = malloc(no_of_bytes * sizeof(char));

    for (int i = 1 ; i < no_of_bytes ; i++) {
        s->array[i] = 0;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    s->array[byte_no] = s->array[byte_no] | 1 << bit;

    return s;
}


void set_insert(const int value, set *s)
{
    if (!set_member_of(value, s)) {
        int bit_in_array = value; // To make the code easier to read

        // Increase the capacity if necessary
        if (bit_in_array >= s->capacity) {
            int no_of_bytes = bit_in_array / 8 + 1;
            s->array = realloc(s->array, no_of_bytes);
            for (int i = s->capacity / 8 ; i < no_of_bytes ; i++) {
                s->array[i] = 0;
            }
            s->capacity = no_of_bytes * 8;
        }

        // Set the bit
        int byte_no = bit_in_array / 8;
        int bit = 7 - bit_in_array % 8;
        s->array[byte_no] = s->array[byte_no] | 1 << bit;
        s->size++;
    }
}


// Note: More effective implementations are possible, but this is
// okay for this assignment.
set *set_union(const set *const s1, const set *const s2)
{
    set *s = set_empty();

    for (int i = 0 ; i < s1->capacity || i < s2->capacity ; i++) {
        if (set_member_of(i, s1) || set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }

    return s;
}


set *set_intersection(const set *const s1, const set *const s2)
{
    set *s = NULL;
    return s;
}


set *set_difference(const set *const s1, const set *const s2)
{
    set *s = NULL;
    return s;
}


bool set_is_empty(const set *const s)
{
    return true;
}


bool set_member_of(const int value, const set *const s)
{
    int bit_in_array = value; // To make the code easier to read

    if (bit_in_array >= s->capacity) {
        return false;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    char the_byte = s->array[byte_no];

    return the_byte & 1 << bit;
}


int set_choose(const set *const s)
{
    return 1;
}


void set_remove(const int value, set *const s)
{
}


bool set_equal(const set *const s1, const set *const s2)
{
    return false;
}


bool set_subset(const set *const s1, const set *const s2)
{
    return false;
}


int set_size(const set *const s)
{
    return 1;
}


int *set_get_values(const set *const s)
{
    return NULL;
}


void set_destroy(set *s)
{
    free(s->array);
    free(s);
}
