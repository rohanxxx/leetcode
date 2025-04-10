class Solution {
  public:
  /*
  Return min number of rotations 
  if one could make all elements in A or B equal to x.
  Else return -1.
  */
  int check(int x, vector<int>& A, vector<int>& B, int n) {
    int rotations_a = 0, rotations_b = 0;
    for (int i = 0; i < n; i++) {
      if (A[i] != x && B[i] != x) return -1;
      else if (A[i] != x) rotations_a++;
      else if (B[i] != x) rotations_b++;
    }
    return min(rotations_a, rotations_b);
  }

  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int rotations = check(A[0], A, B, n);
    if (rotations != -1 || A[0] == B[0]) return rotations;
    else return check(B[0], B, A, n);
  }
};