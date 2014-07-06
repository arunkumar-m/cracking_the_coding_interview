trait Sched {
  private val filename = "jobs.txt"
  def comparator(p1: (Int, Int), p2: (Int, Int)): Boolean
  lazy val data = {
    val source = scala.io.Source.fromFile(filename)
    val lines = source.getLines.toList.drop(1)
    source.close()
    lines map (line => line.split(" ") match {
      case Array(weight, length) => (weight.toInt, length.toInt)
      case _ => throw new Error("Parsing jobs.txt failed.")
    }) sortWith comparator
  }
  lazy val result = {
    (data.foldLeft(0: BigInt, 0: BigInt){
      case ((time, sum), (weight, length)) => {
        (time + length, sum + weight * (time + length))
      }
    })._2
  }
}

object Q1 extends Sched {
  override def comparator(p1: (Int, Int), p2: (Int, Int)): Boolean = {
    val diff1 = p1._1 - p1._2
    val diff2 = p2._1 - p2._2
    (diff1 > diff2) || ((diff1 == diff2) && (p1._1 >= p2._1))
  }
}

object Q2 extends Sched {
  override def comparator(p1: (Int, Int), p2: (Int, Int)): Boolean = {
    p1._1.toFloat / p1._2 > p2._1.toFloat / p2._2
  }
}

object Test {
  def main(args: Array[String]) {
    println("Q1: " + Q1.result)
    println("Q2: " + Q2.result)
  }
}
