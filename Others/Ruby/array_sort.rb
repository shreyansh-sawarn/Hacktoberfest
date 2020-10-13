class ArraySort
  def initialize(array1, array2)
    @array_1 = array1
    @array_2 = array2
  end

  def combine
    i = 0
    j = 0
    [].tap do |combined_array|
      while combined_array.length < @array_1.length + @array_2.length
        val_1 = @array_1[i]
        val_2 = @array_2[j]
        if !val_1.nil? && (val_2.nil? || val_1 < val_2)
          combined_array << val_1
          i += 1
        elsif !val_2.nil?
          combined_array << val_2
          j += 1
        end
      end
    end
  end
end
