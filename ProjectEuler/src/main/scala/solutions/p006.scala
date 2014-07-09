package solutions

/**
 * Sum square difference.
 *
 * The sum of the squares of the first ten natural numbers is 385.
 * The square of the sum of the first ten natural numbers if 3025.
 * Hence the difference between sum of squares of the first ten natural
 * numbers and the square of the sum is 3025 - 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one
 * hundred natural numbers and the square of the sum.
 * 
 */

object p006 {

  def main(args: Array[String]) {
    val sumOfSquares = ((1 to 100) map (x => x * x)).sum
    val squareOfSum = math.pow(((1 to 100).sum), 2)
    println("Difference: " + math.abs(sumOfSquares - squareOfSum).toInt)
  }
}
