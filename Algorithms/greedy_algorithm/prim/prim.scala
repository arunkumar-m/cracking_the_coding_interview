import scala.annotation.tailrec

object Prim {

  private val filename = "edges.txt"

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

  def prim(adjList: Map[Int, List[Int]], edges: Map[(Int, Int), Int]) = {
    val vertices = adjList.map(_._1).toSet
    @tailrec
    def loop(xs: Set[Int], mst: Set[(Int, Int)]): Set[(Int, Int)] = {
      if (xs == vertices) mst else {
        val (edge, cost) =
          edges.foldLeft((0, 0), Int.MaxValue)((acc, edge) => acc match {
            case (e, c) => {
              if (xs(edge._1._1) && (vertices -- xs)(edge._1._2) &&
                edge._2 < c)
                (edge._1, edge._2)
              else
                (e, c)
            }
          })
        loop(xs + edge._2, mst + edge)
      }
    }
    loop(Set(adjList.head._1), Set())
  }

  def main(args: Array[String]) {
    val mst = prim(adjList, edges)
    println("MST: " + mst.foldLeft(0)((cost, edge) => cost + edges(edge)))
  }
}
