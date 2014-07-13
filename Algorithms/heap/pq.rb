class PriorityQueue

  attr_accessor :pq

  def initialize(data)
    @pq = Array.new
    data.each { |x| @pq << x }
    PriorityQueue::build_heap(@pq)
  end

  def peek()
    @pq[0]
  end

  def dequeue()
    nil if @pq.length == 0
    first = @pq[0]
    last = @pq.length - 1
    @pq[0] = @pq[last]
    @pq.delete_at(last)
    PriorityQueue::max_heapify(@pq, 0)
    first
  end

  def enqueue(elem)
    @pq << elem
    PriorityQueue::shift_up(@pq, @pq.length - 1)
  end

  def self.shift_up(pq, i)
    parent = (i+1)/2 - 1
    if parent >= 0 && pq[i][0] > pq[parent][0]
      pq[i], pq[parent] = pq[parent], pq[i]
      shift_up(pq, parent)
    end
  end

  def self.build_heap(pq)
    (0..(pq.length / 2).floor).reverse_each do |i|
      max_heapify(pq, i)
    end
  end

  def self.max_heapify(pq, i)
    l = i * 2 + 1
    r = i * 2 + 2
    largest = i
    if l < pq.length && pq[l][0] > pq[i][0]
      largest = l
    end
    if r < pq.length && pq[r][0] > pq[largest][0]
      largest = r
    end
    if largest != i
      pq[largest], pq[i] = pq[i], pq[largest]
      max_heapify(pq, largest)
    end
  end

  def to_s
    @pq.each { |priority, item| puts "#{priority} - #{item}" }
  end

end
