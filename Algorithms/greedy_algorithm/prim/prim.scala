object Prim {

  private val filename = "test.txt"

  lazy val data = {
    val source = scala.io.Source.fromFile(filename)
    val lines = source.getLines.toList.drop(1)
    lines map (_.split(" ") match {
      case Array(x, y, z) => (x.toInt, y.toInt, z.toInt)
      case _ => throw new Error("Cannot parse the file.")
    })
  } flatMap (x => List(x, (x._2, x._1, x._3)))

  lazy val adjList =
    data groupBy (p => p._1) map {
      case (k, v) => k -> (v map (t => t._2) sortWith (_ < _))
      case _ => throw new Error("Cannot obtain adjacency list.")
    }

  lazy val edges = {
    data groupBy (p => (p._1, p._2)) map {
      case (k, v) => k -> (v match {
        case x :: Nil => x._3
        case _ => throw new Error("Self loop detected.")
      })
      case _ => throw new Error("Cannot obtain edge costs.")
    }
  }

  def main(args: Array[String]) {
    println(data)
    println(adjList)
    println(edges)
  }
}
