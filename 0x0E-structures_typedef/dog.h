#ifndef DOG_H
#define DOG_H
/**
 * struct dog - the information of a dog.
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the name of the dog's owner
 *
 * Description: no long description
 */
struct dog
{
	char * name;
	float age;
	char * owner;
};
/**
 * dog_i - typedef for struct dog
 */
typedef struct dog dog_i;
void init_dog(struct dog *d, char *name, float age, char *owner)u;
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
#endif