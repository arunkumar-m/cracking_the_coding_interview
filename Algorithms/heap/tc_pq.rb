require_relative "pq"
require "test/unit"

class TestPriorityQueue < Test::Unit::TestCase

  def setup
    @test1 = [
      [6, "football"],
      [5, "basketball"],
      [3, "learn ruby"],
      [4, "learn rails"],
      [10, "learn scala"],
      [8, "project euler"],
      [1, "movie"],
    ]
    @expected1 = [
      [10, "learn scala"],
      [6, "football"],
      [8, "project euler"],
      [4, "learn rails"],
      [5, "basketball"],
      [3, "learn ruby"],
      [1, "movie"],
    ]
    @pq1 = PriorityQueue.new(@test1)
  end

  def test_peek
    data = @test1.dup
    pq = PriorityQueue.new(data)
    assert_equal(10, pq.peek[0])
  end

  def test_enqueue
    pq = @pq1.dup
    pq.enqueue([7, "world cup"])
    assert_equal([10, 7, 8, 6, 5, 3, 1, 4], pq.pq.map { |x| x[0] })
    pq.enqueue([12, "dinner"])
    assert_equal([12, 10, 8, 7, 5, 3, 1, 4, 6], pq.pq.map { |x| x[0] })
  end

  def test_dequeue
    pq = @pq1.dup
    assert_equal(10, pq.dequeue()[0])
    assert_equal(8, pq.dequeue()[0])
    assert_equal(6, pq.dequeue()[0])
    assert_equal(5, pq.dequeue()[0])
    assert_equal(4, pq.dequeue()[0])
    assert_equal(3, pq.dequeue()[0])
    assert_equal(1, pq.dequeue()[0])
    assert_equal(nil, pq.dequeue())
  end

  def test_increase_key
    pq = @pq1.dup
    pq.update_key("project euler", 15)
    assert_equal(15, pq.dequeue()[0])
    pq.update_key("movie", 9)
    assert_equal(10, pq.dequeue()[0])
    assert_equal(9, pq.dequeue()[0])
    assert_equal(6, pq.dequeue()[0])
    assert_equal(5, pq.dequeue()[0])
    assert_equal(4, pq.dequeue()[0])
    assert_equal(3, pq.dequeue()[0])
    assert_equal(nil, pq.dequeue())
  end

  def test_decrease_key
    pq = @pq1.dup
    pq.update_key("learn scala", 7)
    pq.update_key("project euler", 2)
    assert_equal(7, pq.dequeue()[0])
    assert_equal(6, pq.dequeue()[0])
    assert_equal(5, pq.dequeue()[0])
    assert_equal(4, pq.dequeue()[0])
    assert_equal(3, pq.dequeue()[0])
    assert_equal(2, pq.dequeue()[0])
    assert_equal(1, pq.dequeue()[0])
    assert_equal(nil, pq.dequeue())
  end

end
