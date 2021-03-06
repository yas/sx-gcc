/* { dg-options "-O2 -fdump-tree-tailcall -fdump-tree-optimized" } */
/* { dg-xfail-if "profiling for sx*-nec-superux targets is not fully implemented" { sx*-nec-superux } { "*" } { "" } } */ 

__attribute__ ((noinline))
int factorial(int x)
{
   if (x == 1)
     return 1;
   else
     return x*factorial(--x);
}
int gbl;
int
main()
{
   gbl = factorial(100);
   return 0;
}
/* { dg-final-use { scan-tree-dump-not "Invalid sum" "tailc"} } */
/* { dg-final-use { scan-tree-dump-not "Invalid sum" "optimized"} } */
/* { dg-final-use { cleanup-tree-dump "tailc" } } */
/* { dg-final-use { cleanup-tree-dump "optimized" } } */
