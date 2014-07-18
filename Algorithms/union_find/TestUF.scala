object TestUF {
  def main(args: Array[String]) {
    println("Test Union/Find.")
    var uf = new UF(10)
    println("Initial size: " + uf.count())
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
    println("Size: " + uf.count());
    println("(0, 1): " + uf.connected(0, 1));
    println("(2, 3): " + uf.connected(2, 3));
    println("(7, 8): " + uf.connected(7, 8));
    println("(0, 9): " + uf.connected(0, 9));
    println("(1, 3): " + uf.connected(1, 3));
    println("(3, 4): " + uf.connected(3, 4));
  }
}
