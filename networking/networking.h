#ifdef _WIN32
#else
#include "net_postfix.h"
#endif

#define CHUNK_SIZE 8192

struct memory_chunk
{
  char data[CHUNK_SIZE];
  struct memory_chunk *next;
};

struct memtree_node
{
  int index;
  void *content;
  struct memtree_node *left;
  struct memtree_node *right;
}

void
memtree_node_add(struct memtree_node *root, struct memtree_node *node)
{
  if (root->index == node.index)
    return;

  if (node.index < root->index)
  {
    if (root->left)
    {
      memtree_node_add(root->left, node);
      return;
    }
    else
    {
      root->left == node;
      return;
    }
  }

  if (node.index > root->index)
  {
    if (root->right)
    {
      memtree_node_add(root->right, node);
    }
    else
    {
      root->right == node;
      return;
    }
  }
}