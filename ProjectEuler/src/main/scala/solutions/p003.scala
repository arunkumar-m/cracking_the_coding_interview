package solutions

/**
 * Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13, 29.
 *
 * What is the largest prime factor of the number 600851475143?
 *
 */

object p003 {

  def sieve(x: Int): Seq[Int] = {
    val bound = math.sqrt(x)
    def loop(xs: Seq[Int]): Seq[Int] = xs match {
      case y +: ys => if (y <= bound) y +: loop(ys filter (_ % y != 0)) else xs
    }
    loop(2 to x)
  }

  def main(args: Array[String]): Unit = {
    val num = 600851475143L
    val primes = sieve(math.sqrt(num.toDouble).toInt)
    println("Largest prime factor: " + (primes filter (num % _ == 0)).max)
  }

}
