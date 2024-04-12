#include "hash_tables.h"

/**
 * key_index - Gets the index of a key in the hash table array
 * @key: The key string
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	/* Get the hash value using the djb2 algorithm */
	hash_value = hash_djb2(key);

	/**
	 *  Calculate the index by taking the modulo of the hash value
	 * with the size of the array
	*/
	return (hash_value % size);
}
