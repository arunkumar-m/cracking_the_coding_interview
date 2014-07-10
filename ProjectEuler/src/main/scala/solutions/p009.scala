package solutions

/**
 * Special Pythagorean triplet.
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which, a^2 + b^2 = c^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 */

object p009 {

  def main(args: Array[String]) {
    val result = 
      for (a <- 1 to 998;
           b <- 1 to 998;
           if a < b;
           if math.pow(a, 2) + math.pow(b, 2) == math.pow(1000 - a - b, 2))
        yield a * b * (1000 - a - b)
    println("Special Pythagorean triplet: " + result.head)
  }
}
