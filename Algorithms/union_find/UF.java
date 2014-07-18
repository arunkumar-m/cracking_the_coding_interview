/**
 * Union find data structure.
 */

class UF {

  private int[] id; // id[i] = parent of i.
  private int[] sz; // sz[i] = number of objects in the tree rooted at i.
  private int count; // Number of components.

  /**
   * Initialize N with integer names 0 to N-1.
   */
  public UF(int N) {
    id = new int[N];
    sz = new int[N];
    count = N;
    for (int i = 0; i < N; i++) {
      id[i] = i;
      sz[i] = 1;
    }
  }

  /**
   * Add connection between p and q.
   */
  public void union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;

    // Make smaller root point to larger one.
    if (sz[rootP] < sz[rootQ]) {
      id[rootP] = rootQ;
      sz[rootQ] += sz[rootP];
    } else {
      id[rootQ] = rootP;
      sz[rootP] += sz[rootQ];
    }
    count--;
  }

  /**
   * Component identifier for p (0 to N-1).
   */
  public int find(int p) {
    while (p != id[p]) {
      p = id[p];
    }
    return p;
  }

  /**
   * Number of components.
   */
  public int count() {
    return count;
  }

  /**
   * Are the two components connected?
   */
  public boolean connected(int p, int q) {
    return find(p) == find(q);
  }

  public static void main(String[] args) {
    UF uf = new UF(10);
    System.out.println("Size: " + uf.count());
    uf.union(3, 4);
    uf.union(3, 8);
    uf.union(6, 5);
    uf.union(9, 4);
    uf.union(2, 1);
    uf.union(8, 9);
    uf.union(5, 0);
    uf.union(7, 2);
    uf.union(6, 1);
    uf.union(1, 0);
    uf.union(6, 7);
    System.out.println("Size: " + uf.count());
    System.out.println("(0, 1): " + uf.connected(0, 1));
    System.out.println("(2, 3): " + uf.connected(2, 3));
    System.out.println("(7, 8): " + uf.connected(7, 8));
    System.out.println("(0, 9): " + uf.connected(0, 9));
    System.out.println("(1, 3): " + uf.connected(1, 3));
    System.out.println("(3, 4): " + uf.connected(3, 4));
  }
}
