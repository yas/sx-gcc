
/* { dg-options "-O2 -fdump-tree-optimized-blocks" } */
/* { dg-xfail-if "profiling for sx*-nec-superux targets is not fully implemented" { sx*-nec-superux } { "*" } { "" } } */ 

int a[8];
__attribute__ ((noinline))
int t()
{
	int i;
	for (i = 0; i < 3; i++)
		if (a[i])
			break;
	return i;
}
main ()
{
  int i;
  for (i = 0; i < 1000; i++)
    t ();
  return 0;
}
/* { dg-final-use { scan-tree-dump-not "Invalid sum" "optimized"} } */
/* { dg-final-use { cleanup-tree-dump "optimized" } } */
