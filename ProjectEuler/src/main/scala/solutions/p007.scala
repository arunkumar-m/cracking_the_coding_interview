package solutions

import scala.annotation.tailrec

/**
 * 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
 * see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 *
 */

object p007 {

  /* Change List to Seq if larger range is needed. */
  def sieve(num: Int) = {
    @tailrec
    def loop(xs: List[Int], acc: List[Int]): List[Int] = xs match {
      case y :: ys =>
        if (y * y <= num) loop(ys filter (_ % y != 0), y :: acc) else acc.reverse ++ (y :: ys)
      case _ => throw new Error("Should not be here.")
    }
    loop((2 to num).toList, Nil)
  }

  def main(args: Array[String]) {
    val primes = sieve(200000)
    println("Size: " + primes.size)
    println("10001st prime: " + (primes take 10001).last)
  }
}
