// 5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
// 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
// implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix.
// (b) Tri-diagonal Matrix.
// (c) Lower triangular Matrix.
// (d) Upper triangular Matrix.
// (e) Symmetric Matrix





#include <iostream>
using namespace std;

/* ============== (a) Diagonal Matrix: size n ================== */
struct Diagonal {
    int n;
    int* a; // a[i] stores element at (i,i)
    Diagonal(int n): n(n) { a = new int[n]; for (int i=0;i<n;i++) a[i]=0; }
    ~Diagonal(){ delete[] a; }

    void set(int i, int j, int x){
        if (i<0||i>=n||j<0||j>=n) return;
        if (i==j) a[i]=x; // else ignored (must be zero)
    }
    int get(int i, int j) const{
        if (i<0||i>=n||j<0||j>=n) return 0;
        return (i==j)? a[i] : 0;
    }
};

/* ============== (b) Tri-diagonal Matrix: size 3n-2 ============
   Layout (0-based):
   [lower (n-1)] [main (n)] [upper (n-1)]
   Indexing:
   - (i==j+1) -> lower[j] -> idx = j               , j=0..n-2
   - (i==j)   -> main[i]  -> idx = (n-1) + i       , i=0..n-1
   - (i+1==j) -> upper[i] -> idx = (n-1)+n + i     , i=0..n-2
*/
struct Tridiagonal {
    int n;
    int* a; // length 3n-2
    Tridiagonal(int n): n(n) { a = new int[3*n-2]; for(int i=0;i<3*n-2;i++) a[i]=0; }
    ~Tridiagonal(){ delete[] a; }

    void set(int i, int j, int x){
        if (i<0||i>=n||j<0||j>=n) return;
        if (i==j+1)      a[j] = x;
        else if (i==j)   a[(n-1)+i] = x;
        else if (i+1==j) a[(n-1)+n + i] = x;
        // else ignored (must be zero)
    }
    int get(int i, int j) const{
        if (i<0||i>=n||j<0||j>=n) return 0;
        if (i==j+1)      return a[j];
        else if (i==j)   return a[(n-1)+i];
        else if (i+1==j) return a[(n-1)+n + i];
        return 0;
    }
};

/* ============== (c) Lower Triangular: size n(n+1)/2 ===========
   Store row-major lower triangle.
   Index formula (0-based, j<=i):
   idx = i*(i+1)/2 + j
*/
struct LowerTri {
    int n;
    int* a; // length n(n+1)/2
    LowerTri(int n): n(n) {
        a = new int[n*(n+1)/2];
        for (int k=0;k<n*(n+1)/2;k++) a[k]=0;
    }
    ~LowerTri(){ delete[] a; }

    inline int idx(int i, int j) const { return i*(i+1)/2 + j; }

    void set(int i, int j, int x){
        if (i<0||i>=n||j<0||j>=n) return;
        if (j<=i) a[idx(i,j)] = x; // else ignored (must be zero)
    }
    int get(int i, int j) const{
        if (i<0||i>=n||j<0||j>=n) return 0;
        return (j<=i) ? a[idx(i,j)] : 0;
    }
};

/* ============== (d) Upper Triangular: size n(n+1)/2 ===========
   Store row-major upper triangle (j>=i).
   Elements per row r: (n - r)
   Prefix count up to row i-1: S = i*n - (i*(i-1))/2
   idx = S + (j - i)
*/
struct UpperTri {
    int n;
    int* a; // length n(n+1)/2
    UpperTri(int n): n(n) {
        a = new int[n*(n+1)/2];
        for (int k=0;k<n*(n+1)/2;k++) a[k]=0;
    }
    ~UpperTri(){ delete[] a; }

    inline int idx(int i, int j) const {
        int S = i*n - (i*(i-1))/2;
        return S + (j - i);
    }

    void set(int i, int j, int x){
        if (i<0||i>=n||j<0||j>=n) return;
        if (j>=i) a[idx(i,j)] = x; // else ignored (must be zero)
    }
    int get(int i, int j) const{
        if (i<0||i>=n||j<0||j>=n) return 0;
        return (j>=i) ? a[idx(i,j)] : 0;
    }
};

/* ============== (e) Symmetric Matrix: size n(n+1)/2 ===========
   A == A^T. Store only lower triangle and mirror on access.
   Use same mapping as LowerTri; for (i,j):
   get/set lower(i>=j); else use (j,i).
*/
struct Symmetric {
    int n;
    int* a; // length n(n+1)/2, store lower-triangular part
    Symmetric(int n): n(n) {
        a = new int[n*(n+1)/2];
        for (int k=0;k<n*(n+1)/2;k++) a[k]=0;
    }
    ~Symmetric(){ delete[] a; }

    inline int idx(int i, int j) const { // assumes i>=j
        return i*(i+1)/2 + j;
    }

    void set(int i, int j, int x){
        if (i<0||i>=n||j<0||j>=n) return;
        if (i>=j) a[idx(i,j)] = x;
        else      a[idx(j,i)] = x; // write mirrored position
    }
    int get(int i, int j) const{
        if (i<0||i>=n||j<0||j>=n) return 0;
        if (i>=j) return a[idx(i,j)];
        else      return a[idx(j,i)];
    }
};

/* ----------------------- Demo ----------------------- */
int main(){
    int n = 4;

    // (a) Diagonal
    Diagonal D(n);
    for (int i=0;i<n;i++) D.set(i,i,(i+1)*10);
    cout << "Diagonal(2,2) = " << D.get(2,2) << ", off-diag(0,1) = " << D.get(0,1) << "\n";

    // (b) Tridiagonal
    Tridiagonal T(n);
    // main diagonal
    for (int i=0;i<n;i++) T.set(i,i,5);
    // upper
    for (int i=0;i<n-1;i++) T.set(i,i+1,1);
    // lower
    for (int i=1;i<n;i++) T.set(i,i-1,2);
    cout << "Tridiag(1,0)="<<T.get(1,0)<<", (1,1)="<<T.get(1,1)<<", (1,2)="<<T.get(1,2)<<", (0,3)="<<T.get(0,3)<<"\n";

    // (c) Lower triangular
    LowerTri L(n);
    for (int i=0;i<n;i++) for (int j=0;j<=i;j++) L.set(i,j,i*10+j);
    cout << "Lower(3,1) = " << L.get(3,1) << ", Upper position (0,3) = " << L.get(0,3) << "\n";

    // (d) Upper triangular
    UpperTri U(n);
    for (int i=0;i<n;i++) for (int j=i;j<n;j++) U.set(i,j,i*10+j);
    cout << "Upper(1,3) = " << U.get(1,3) << ", Lower position (3,1) = " << U.get(3,1) << "\n";

    // (e) Symmetric
    Symmetric S(n);
    // set few entries; mirrored automatically
    S.set(0,2,7);
    S.set(3,1,9);
    cout << "Sym(2,0) = " << S.get(2,0) << ", Sym(1,3) = " << S.get(1,3) << "\n";

    return 0;
}
