package solutions

/**
 * Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 */

object p004 {

  // All palindromes with 5 digits.
  lazy val digits5 = {
    for (x <- 1 to 9; y <- 0 to 9; z <- 0 to 9)
      yield (x.toString + y.toString + z.toString +y.toString +
          x.toString).toInt
  }

  // All palindromes with 6 digits.
  lazy val digits6 = {
    for (x <- 1 to 9; y <- 0 to 9; z <- 0 to 9)
      yield (x.toString + y.toString + z.toString + z.toString +
          y.toString + x.toString).toInt
  }

  // All numbers that is the product of two 3-digit numbers.
  lazy val candidates = {
    for (x <- 100 to 999; y <- 100 to 999)
      yield x * y
  }


  def main(args: Array[String]): Unit = {
    println(((digits5 ++ digits6) intersect candidates).max)
  }

}
