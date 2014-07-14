class PriorityQueue

  attr_accessor :pq

  def initialize(data)
    @pq = Array.new
    @entry_finder = Hash.new
    @entry_finder.default = nil
    data.each { |x| @pq << x }
    @pq.each_with_index { |x, i| @entry_finder[x[1]] = i }
    build_heap()
  end

  def peek()
    @pq[0]
  end

  def dequeue()
    return nil if @pq.length == 0
    first = @pq[0]
    last = @pq.length - 1
    @entry_finder[@pq[last][1]] = 0
    @entry_finder.delete(first[1])
    @pq[0] = @pq[last]
    @pq.delete_at(last)
    heapify(0)
    first
  end

  def enqueue(elem)
    @pq << elem
    @entry_finder[elem[1]] = @pq.length - 1
    shift_up(@pq.length - 1)
  end

  def shift_up(i)
    parent = (i+1)/2 - 1
    if parent >= 0 && @pq[i][0] > @pq[parent][0]
      @entry_finder[@pq[i][1]] = parent
      @entry_finder[@pq[parent][1]] = i
      @pq[i], @pq[parent] = @pq[parent], @pq[i]
      shift_up(parent)
    end
  end

  def build_heap()
    (0..(@pq.length / 2).floor).reverse_each do |i|
      heapify(i)
    end
  end

  def heapify(i)
    l = i * 2 + 1
    r = i * 2 + 2
    largest = i
    if l < @pq.length && @pq[l][0] > @pq[i][0]
      largest = l
    end
    if r < @pq.length && @pq[r][0] > @pq[largest][0]
      largest = r
    end
    if largest != i
      @entry_finder[@pq[i][1]] = largest
      @entry_finder[@pq[largest][1]] = i
      @pq[largest], @pq[i] = @pq[i], @pq[largest]
      heapify(largest)
    end
  end

  def to_s
    pq = @pq.map { |priority, item| "#{priority} - #{item}" }.join("\n")
    ef = @entry_finder.map { |k, v| "#{k}: #{v}" }.join("\n")
    "\n** Priority queue:\n" + pq + "\n** Entry finder:\n" + ef
  end

  def update_key(key, value)
    index = @entry_finder[key]
    return false if index == nil
    old_value, @pq[index][0] = @pq[index][0], value
    if value < old_value
      heapify(index)
    elsif value > old_value
      shift_up(index)
    end
    true
  end

end
