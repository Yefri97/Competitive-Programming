int f(int x) { return ; }

ii cycleFinding(int xo) {
  int tortoise = f(xo), hare = f(f(xo));
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  int mu = 0; hare = xo;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
  int lambda = 1; hare = f(hare);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return ii(mu, lambda);
}