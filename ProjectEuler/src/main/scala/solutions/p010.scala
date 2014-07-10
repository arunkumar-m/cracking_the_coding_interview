package solutions

import scala.annotation.tailrec

/**
 * Summation of Primes.
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 */

object p010 {

  def sieve(num: Int) = {
    @tailrec
    def loop(xs: List[Int], acc: List[Int]): List[Int] = xs match {
      case y :: ys =>
        if (y * y <= num) loop(ys filter (_ % y != 0), y :: acc) else acc.reverse ++ (y :: ys)
      case _ => throw new Error("Should not be here.")
    }
    loop((2 to num).toList, Nil)
  }

  def sum(a: BigInt, b: BigInt) = a + b

  def main(args: Array[String]) {
    val primes = sieve(2000000)
    println("Summation of primes: " + primes.foldLeft(BigInt(0))(sum(_, _)))
  }
}
