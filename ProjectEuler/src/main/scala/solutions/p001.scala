package solutions

/**
 * Multiples of 3 and 5.
 *
 * If we list all the natural numbers below 10 that are multiples of
 * 3 and 5, we get 3, 5, 6, 9. The sum of these multiples is 23. Find
 * the sum of all the multiples of 3 or 5 below 1000.
 *
 */

object p001 {

  def main(args: Array[String]) {
    val sum =
      (for (x <- 1 until 1000; if (x % 3 == 0) ||  (x % 5 == 0)) yield x).sum
    println("Answer: " + sum)
  }
}
