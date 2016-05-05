/* { dg-do run } */
/* { dg-require-profiling "-p" } */
/* { dg-options "-O2 -p" } */
/* { dg-options "-O2 -p -static" { target hppa*-*-hpux* } } */
/* { dg-error "profiler" "No profiler support" { target xstormy16-*-* } 0 } */
/* { dg-error "" "consider using `-pg' instead of `-p' with gprof(1)" { target *-*-freebsd* } 0 } */
/* { dg-xfail-if "profiling for sx*-nec-superux targets is not fully implemented" { sx*-nec-superux } { "*" } { "" } } */ 

extern void abort (void);
extern void exit (int);

int foo (void)
{
  int bar (int x)
  {
    return x + 3;
  }
  return bar (1) + bar (2);
}

int main (void)
{
  if (foo () != 9)
    abort ();
  exit (0);
}
