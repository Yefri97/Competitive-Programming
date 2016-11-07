#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node {
  int item;
  node* next;
  node* prev;
  node(int _item) : item(_item), next(NULL), prev(NULL) {}
};

int main() {

  freopen("kenobi.in", "rt", stdin);
  freopen("kenobi.out", "wt", stdout);

  int size = 0;
  node* first;
  node* middle;
  node* last;
  first = middle = last = NULL;
  
  int t; scanf("%d", &t);
  while (t--) {
    char q[10]; scanf("%s", q);
    if (q[0] == 'a' && q[1] == 'd' && q[2] == 'd') {
      int n; scanf("%d", &n);
      node* ls; ls = new node(n);
      if (first == NULL) {
        first = middle = last = ls;
      } else {
        last->next = ls;
        ls->prev = last;
        last = ls;
      }
      size++;
      if (size % 2 == 0) middle = middle->next;
    } else if (q[0] == 't' && q[1] == 'a' && q[2] == 'k' && q[3] == 'e') {
      if (first == last) {
        first = middle = last = NULL;
      } else {
        last = last->prev;
        last->next = NULL;
      }
      if (size % 2 == 0) middle = middle->prev;
      size--;
    } else {
      if (size < 2) continue;
      node *f, *m, *l; f = first; m = middle; l = last;
      first = m;
      middle = (size % 2 == 0)? f : l;
      last = m->prev;

      f->prev = l;
      l->next = f;
      
      first->prev = NULL;
      last->next = NULL;
    }
  }

  printf("%d\n", size);
  int b = 1;
  node* p; p = first;
  while (p != NULL) {
    if (!b) printf(" "); b = 0;
    printf("%d", p->item);
    p = p->next;
  }
  printf("\n");

  return 0;
}