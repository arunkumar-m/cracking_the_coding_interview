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
      [8, "projet euler"],
      [1, "movie"],
    ]
    @expected1 = [
      [10, "learn scala"],
      [6, "football"],
      [8, "projet euler"],
      [4, "learn rails"],
      [5, "basketball"],
      [3, "learn ruby"],
      [1, "movie"],
    ]
    @pq1 = PriorityQueue.new(@test1)
  end

  def test_max_heapify
    data = @test1.dup
    PriorityQueue.max_heapify(data, 2)
    assert_equal([6, 5, 8, 4, 10, 3, 1], data.map { |x| x[0] })
    PriorityQueue.max_heapify(data, 1)
    assert_equal([6, 10, 8, 4, 5, 3, 1], data.map { |x| x[0] })
    PriorityQueue.max_heapify(data, 0)
    assert_equal([10, 6, 8, 4, 5, 3, 1], data.map { |x| x[0] })
  end

  def test_build_heap
    data = @test1.dup
    PriorityQueue::build_heap(data)
    assert_equal([10, 6, 8, 4, 5, 3, 1], data.map { |x| x[0] })
  end

  def test_shift_up
    data = @expected1.dup << [9, "reactive programming"]
    PriorityQueue::shift_up(data, data.length - 1)
    assert_equal([10, 9, 8, 6, 5, 3, 1, 4], data.map { |x| x[0] })
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

end
