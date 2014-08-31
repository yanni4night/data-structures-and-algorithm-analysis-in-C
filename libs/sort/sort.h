#ifndef __LIBS_SORT
#define __LIBS_SORT

/**
 * A rule that compares two object.
 * 
 * @param  s1
 * @param  s2
 * @return int
 */
typedef int (*greater_than)(void* s1,void* s2);

/**
 * sort an array in bubble.
 * 
 * @param src Double pointer to an array contains the pointer the multiple data.
 * @param len Length of the data.
 * @param greater A function pointer defines the compare rule.
 */
void sort_bubble(void** src,unsigned len,greater_than greater);

void sort_quick(void** src,unsigned len,greater_than greater);

#endif