/*
 *  ITMOx Course - 2nd Week Problems
 *  Problem: Kenobi's Lightsabers
 *  Level: Medium
 */
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
  ios::sync_with_stdio(false);  // Fast input - output
  ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
  /*** Code ***/
  int size = 0;
  node* first;
  node* middle;
  node* last;
  first = middle = last = NULL;
  
  int t; fin >> t;
  while (t--) {
    char q[10];fin >> q;
    if (q[0] == 'a' && q[1] == 'd' && q[2] == 'd') {
      int n; fin >> n;
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

  fout << size << endl;
  int b = 1;
  node* p; p = first;
  while (p != NULL) {
    if (!b) fout << " "; b = 0;
    fout << p->item;
    p = p->next;
  }
  fout << endl;

  return 0;
}