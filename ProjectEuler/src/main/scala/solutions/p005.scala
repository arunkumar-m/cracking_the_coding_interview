package solutions

/**
 * Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers
 * from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all
 * of the numbers from 1 to 20?
 *
 */

object p005 {

  private val ZERO= BigInt(0)

  def gcd(x: BigInt, y: BigInt): BigInt = (x, y) match {
    case (x, ZERO) => x
    case (x, y) => gcd(y, x % y)
  }

  def lcm(x: BigInt, y: BigInt) = x * y / gcd(x, y)

  def main(args: Array[String]) {
    println((2 to 10).foldLeft(BigInt(1))((x, y) => lcm(x, y)))
    println((2 to 20).foldLeft(BigInt(1))((x, y) => lcm(x, y)))
  }
}
