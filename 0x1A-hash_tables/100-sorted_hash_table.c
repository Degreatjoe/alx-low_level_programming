#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table, or NULL if something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;
	unsigned long int i;	
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);	
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;	
	ht->shead = NULL;
	ht->stail = NULL;	
	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value to
 * @key: The key string
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node = NULL, *tmp = NULL;
	if (ht == NULL || key == NULL || *key == '\0')
		return (0);	
	index = key_index((unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
		    free(tmp->value);
		    tmp->value = strdup(value);
		    if (tmp->value == NULL)
		        return (0);
		    return (1);
	    }
	    tmp = tmp->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);	
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}	
	new_node->next = ht->array[index];
	ht->array[index] = new_node;	
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		if (strcmp(new_node->key, ht->shead->key) < 0)
		{
		    new_node->snext = ht->shead;
			ht->shead->sprev = new_node;
	    	ht->shead = new_node;
		}
		else
		{
			tmp = ht->shead;
	    	while (tmp->snext != NULL && strcmp(tmp->snext->key, new_node->key) < 0)
	    		tmp = tmp->snext;	
	    	new_node->snext = tmp->snext;
	    	if (tmp->snext != NULL)
	    		tmp->snext->sprev = new_node;
	    	else
	    		ht->stail = new_node;	
	    	new_node->sprev = tmp;
	    	tmp->snext = new_node;
	    }
	}	
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key from the sorted hash table
 * @ht: The sorted hash table to look into
 * @key: The key string
 *
 * Return: The value associated with the element, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *tmp = NULL;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((unsigned char *)key, ht->size);

    tmp = ht->array[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node = NULL;
    int first_pair = 1;

    if (ht == NULL)
        return;

    printf("{");
    for (node = ht->shead; node != NULL; node = node->snext)
    {
        if (first_pair)
        {
            printf("'%s': '%s'", node->key, node->value);
            first_pair = 0;
        }
        else
        {
            printf(", '%s': '%s'", node->key, node->value);
        }
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node = NULL;
    int first_pair = 1;

    if (ht == NULL)
        return;

    printf("{");
    for (node = ht->stail; node != NULL; node = node->sprev)
    {
        if (first_pair)
        {
            printf("'%s': '%s'", node->key, node->value);
            first_pair = 0;
        }
        else
        {
            printf(", '%s': '%s'", node->key, node->value);
        }
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current, *tmp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            tmp = current;
            current = current->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
        }
    }

    free(ht->array);
    free(ht);
}
