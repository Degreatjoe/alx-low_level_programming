#ifndef DOG_H
#define DOG_H

/*
 * struct dog - the information of a dog.
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the name of the dog's owner
 * 
 */
struct dog
{
	char * name;
	float age;
	char * owner;
}
;
/*
 * dog_i - typedef for struct dog
 */
typedef struct dog dog_i;
#endif
