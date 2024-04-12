#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key string
 *
 * Return: The value associated with the element,
 * or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Get the index for the key */
	index = key_index((unsigned char *)key, ht->size);

	/* Traverse the linked list at the calculated index */
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		/* Compare keys */
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	/* Key not found */
	return (NULL);
}
