/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

typedef struct btree {
    void *item;
    struct btree *left;
    struct btree *right;
} btree_t;

void btree_apply_infix(btree_t *root, int (*applyf)(void *));
void btree_apply_prefix(btree_t *root, int (*applyf)(void *));
void btree_apply_sufix(btree_t *root, int (*applyf)(void *));
btree_t *btree_create_node(void *item);
void btree_insert_data(btree_t **root, void *item, int (*cmpf)());
int btree_level_count(btree_t const *root);
void *btree_search_item(btree_t const *root, void const *data_ref,
                        int (*cmpf)());