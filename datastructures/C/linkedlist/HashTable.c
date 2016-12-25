/* Hash Table Collision Resolution code by codingstreet.com */
#include<stdio.h>
#include<stdlib.h>
struct hash {

	struct hashnode *ptr;

};

struct hashnode {

	int		val;

	struct hashnode *next;

};

struct hash    *
create_hash(int size)
{

	struct hash    *htable;

	int		i;

	htable = (struct hash *)malloc(sizeof(struct hash) * size);

	if (htable == NULL) {

		printf("\n Out of Memory !!");

		return NULL;
	}
	for (i = 0; i < size; i++)
		htable[i].ptr = NULL;

	return htable;

}

struct hashnode *
create_hashnode(int val)
{

	struct hashnode *tmp;

	tmp = (struct hashnode *)malloc(sizeof(struct hashnode));

	if (tmp == NULL)
		printf("\n System out of Memory");

	tmp->next = NULL;

	tmp->val = val;

}

int 
insert_value(struct hash **htable, int val, int hsize)
{

	int		slot;

	struct hash    *htptr = (*htable);

	struct hashnode *tmp;

	if ((*htable) == NULL) {

		printf("\n Hash Table is not created");

		return 0;

	}
	slot = (val) % hsize;

	if (htptr[slot].ptr == NULL) {

		tmp = create_hashnode(val);

		htptr[slot].ptr = tmp;

	} else {

		tmp = create_hashnode(val);

		tmp->next = htptr[slot].ptr;

		htptr[slot].ptr = tmp;

	}

	return 1;

}

void 
print_hashtable(struct hash **htable, int size)
{

	int		i;

	struct hashnode *tmp;

	struct hash    *htmp = (*htable);

	for (i = 0; i < size; i++) {

		tmp = htmp[i].ptr;

		while (tmp != NULL) {

			printf(" %d ", tmp->val);

			tmp = tmp->next;

		}

		printf("\n");

	}

}

int 
seach_hashtable(struct hash **htable, int val, int size)
{

	int		slot      , found = 0;

	slot = val % size;

	struct hashnode *tmp;

	tmp = (*htable)[slot].ptr;

	while (tmp != NULL) {

		if (tmp->val == val) {

			found = 1;

			break;

		}
		tmp = tmp->next;

	}

	return found;

}

int 
main()
{

	struct hash    *hashtable1;

	int		hashtable1size;

	printf("\n Enter the size of HashTable : ");

	scanf("%d", &hashtable1size);

	hashtable1 = create_hash(hashtable1size);

	if (hashtable1 != NULL)
		printf("\nTable Created Successfully !!");

	int		key       , val, found;

	do {

		printf("\n Hash Table Collision Resolution by Codingstreet.com");

		printf("\n 1. Insert value ");

		printf("\n 2. Search Value");

		printf("\n 3. Print Table");

		printf("\n 4. Exit");

		printf("\n Enter the key [1-4] :");

		scanf("%d", &key);

		switch (key) {

		case 1:

			printf("\n Enter Val : ");

			scanf("%d", &val);

			insert_value(&hashtable1, val, hashtable1size);

			break;

		case 2:

			printf("\n Enter Val : ");

			scanf("%d", &val);

			found = seach_hashtable(&hashtable1, val, hashtable1size);

			if (found == 0)
				printf("\n Val not found");

			else
				printf("\n %d found at slot %d ", val,
				       val % hashtable1size);

			break;

		case 3:

			print_hashtable(&hashtable1, hashtable1size);

			break;

		case 4:

			printf("\n Thank you !!! ");

			break;

		default:

			break;

		}

	} while (key != 4);

	printf("\n Thanks for using Codingstreet.com 's Data structure solution\n");

	return 0;
}