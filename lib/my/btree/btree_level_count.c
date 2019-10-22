/*
** EPITECH PROJECT, 2019
** btree_level_count
** File description:
** Count btree levels
*/

#include <unistd.h>
#include "btree.h"

int btree_level_count(btree_t const *root)
{
    int left;
    int right;

    if (root == NULL)
        return 0;
    else {
        left = btree_level_count(root->left);
        right = btree_level_count(root->right);
        if (left > right)
            return (1 + left);
        else
            return (1 + right);
    }
}
