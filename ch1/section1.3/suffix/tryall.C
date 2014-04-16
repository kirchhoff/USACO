#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define DEBUGLEVEL 1

#if DEBUGLEVEL >= 0
#define Debug0(A) A
#else
#define Debug0(A)
#endif
#if DEBUGLEVEL >= 1
#define Debug1(A) A
#else
#define Debug1(A)
#endif
#if DEBUGLEVEL >= 2
#define Debug2(A) A
#else
#define Debug2(A)
#endif
#if DEBUGLEVEL >= 3
#define Debug3(A) A
#else
#define Debug3(A)
#endif
#if DEBUGLEVEL >= 4
#define Debug4(A) A
#else
#define Debug4(A)
#endif
#if DEBUGLEVEL >= 5
#define Debug5(A) A
#else
#define Debug5(A)
#endif
#if DEBUGLEVEL >= 6
#define Debug6(A) A
#else
#define Debug6(A)
#endif

#define Assert(c) if(!(c))\
  {cout << "\nAssertion violation " << __FILE__ << ":" << __LINE__ << endl;}
#define Assert0(C) Debug0(Assert(C))
#define Assert1(C) Debug1(Assert(C))
#define Assert2(C) Debug2(Assert(C))
#define Assert3(C) Debug3(Assert(C))
#define Assert4(C) Debug4(Assert(C))
#define Assert5(C) Debug5(Assert(C))

#define Error(s) {cout << "\nError:" << s << " " << __FILE__ << ":" << __LINE__ << endl;}

////////////// min, max etc. //////////////////////////////////////

#ifndef Max
#define Max(x,y) ((x)>=(y)?(x):(y))
#endif

#ifndef Min
#define Min(x,y) ((x)<=(y)?(x):(y))
#endif

#ifndef Abs
#define Abs(x) ((x) < 0 ? -(x) : (x))
#endif

#ifndef PI
#define PI 3.1415927
#endif

// is this the right definition of limit?
inline double limit(double x, double bound)
{
  if      (x >  bound) { return  bound; }
  else if (x < -bound) { return -bound; }
  else                   return x;
}

/////////////////////// timing /////////////////////
#include <time.h>


// elapsed CPU time see also /usr/include/sys/time.h
inline double cpuTime()
{ //struct timespec tp;

  return clock() * 1e-6;
//  clock_gettime(CLOCK_VIRTUAL, &tp);
//  return tp.tv_sec + tp.tv_nsec * 1e-9;
}
inline bool leq(int a1, int a2,   int b1, int b2) { // lexic. order for pairs
  return(a1 < b1 || a1 == b1 && a2 <= b2);
}                                                   // and triples
inline bool leq(int a1, int a2, int a3,   int b1, int b2, int b3) {
  return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3));
}
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K)
{ // count occurrences
  int* c = new int[K + 1];                          // counter array
  for (int i = 0;  i <= K;  i++) c[i] = 0;         // reset counters
  for (int i = 0;  i < n;  i++) c[r[a[i]]]++;    // count occurences
  for (int i = 0, sum = 0;  i <= K;  i++) { // exclusive prefix sums
     int t = c[i];  c[i] = sum;  sum += t;
  }
  for (int i = 0;  i < n;  i++) b[c[r[a[i]]]++] = a[i];      // sort
  delete [] c;
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
  int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
  int* s12  = new int[n02 + 3];  s12[n02]= s12[n02+1]= s12[n02+2]=0;
  int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
  int* s0   = new int[n0];
  int* SA0  = new int[n0];

  // generate positions of mod 1 and mod  2 suffixes
  // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
  for (int i=0, j=0;  i < n+(n0-n1);  i++) if (i%3 != 0) s12[j++] = i;

  // lsb radix sort the mod 1 and mod 2 triples
  radixPass(s12 , SA12, s+2, n02, K);
  radixPass(SA12, s12 , s+1, n02, K);
  radixPass(s12 , SA12, s  , n02, K);

  // find lexicographic names of triples
  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (int i = 0;  i < n02;  i++) {
    if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
      name++;  c0 = s[SA12[i]];  c1 = s[SA12[i]+1];  c2 = s[SA12[i]+2];
    }
    if (SA12[i] % 3 == 1) { s12[SA12[i]/3]      = name; } // left half
    else                  { s12[SA12[i]/3 + n0] = name; } // right half
  }

  // recurse if names are not yet unique
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    // store unique names in s12 using the suffix array
    for (int i = 0;  i < n02;  i++) s12[SA12[i]] = i + 1;
  } else // generate the suffix array of s12 directly
    for (int i = 0;  i < n02;  i++) SA12[s12[i] - 1] = i;

  // stably sort the mod 0 suffixes from SA12 by their first character
  for (int i=0, j=0;  i < n02;  i++) if (SA12[i] < n0) s0[j++] = 3*SA12[i];
  radixPass(s0, SA0, s, n0, K);

  // merge sorted SA0 suffixes and sorted SA12 suffixes
  for (int p=0,  t=n0-n1,  k=0;  k < n;  k++) {
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
    int i = GetI(); // pos of current offset 12 suffix
    int j = SA0[p]; // pos of current offset 0  suffix
    if (SA12[t] < n0 ?
        leq(s[i],       s12[SA12[t] + n0], s[j],       s12[j/3]) :
        leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
    { // suffix from SA12 is smaller
      SA[k] = i;  t++;
      if (t == n02) { // done --- only SA0 suffixes left
        for (k++;  p < n0;  p++, k++) SA[k] = SA0[p];
      }
    } else {
      SA[k] = j;  p++;
      if (p == n0)  { // done --- only SA12 suffixes left
        for (k++;  t < n02;  t++, k++) SA[k] = GetI();
      }
    }
  }
  delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

void printV(int* a, int n, char *comment) {
  cout << comment << ":";
  for (int i = 0;  i < n;  i++) {
    cout << a[i] << " " ;
  }
  cout << endl;
}

bool isPermutation(int *SA, int n) {
  bool *seen = new bool[n];
  for (int i = 0;  i < n;  i++) seen[i] = 0;
  for (int i = 0;  i < n;  i++) seen[SA[i]] = 1;
  for (int i = 0;  i < n;  i++) if (!seen[i]) return 0;
  return 1;
}

bool sleq(int *s1, int *s2) {
  if (s1[0] < s2[0]) return 1;
  if (s1[0] > s2[0]) return 0;
  return sleq(s1+1, s2+1);
}

// is SA a sorted suffix array for s?
bool isSorted(int *SA, int *s, int n) {
  for (int i = 0;  i < n-1;  i++) {
    if (!sleq(s+SA[i], s+SA[i+1])) return 0;
  }
  return 1;
}

// try all inbuts from {1,..,b}^n for 1 <= n <= nmax
int main(int argc, char **argv) {
  //int n = 13;
  //int s1[] = {2,1,4,4,1,4,4,1,3,3,1,0,0,0}; // mississippi
  //int s2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  //int n = 8;
  //int s1[] = {2,1,3,1,3,1,0,0,0}; // banana
  //int s2[] = {0,0,0,0,0,0,0,0,0};
  int nmax = atoi(argv[1]);
  int b    = atoi(argv[2]);
  // try all strings from (1..b)^n
  for (int n = 2;  n <= nmax;  n++) {
    cout << n << endl;
    int N = int(pow(double(b),n) + 0.5);
    int* s = new int[n+3];
    int* SA = new int[n+3];
    for (int i = 0;  i < n;  i++) s[i] = SA[i] = 1;
    s[n] = s[n+1] = s[n+2] = SA[n] = SA[n+1] = SA[n+2] = 0;
    for (int j =0;  j < N;  j++) {
      Debug1(printV(s, n, "s"));
      suffixArray(s, SA, n, b);
      Assert0(s[n] == 0);
      Assert0(s[n+1] == 0);
      Assert0(SA[n] == 0);
      Assert0(SA[n+1] == 0);
      Assert0(isPermutation(SA, n));
      Assert0(isSorted(SA, s, n));
      Debug1(printV(SA, n, "SA"));

      // generate next s
      int i;
      for (i = 0;  s[i] == b;  i++) s[i] = 1;
      s[i]++;
    }
    delete [] s;
    delete [] SA;
  }
}
