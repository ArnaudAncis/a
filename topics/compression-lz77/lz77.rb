class String
  def prefix_match_length(str)
    len = [ length, str.length ].min
    
    (0...len).find do |char|
      self[char] != str[char]
    end or len
  end
  
  def longest_match(str)
    (0...length).to_a.reverse.map do |i|
      [i, self[i..-1].prefix_match_length(str)]
    end.max_by do |idx, len|
      len
    end or [0, 0]
  end
end


def lz77(str)
  result = []
  i = 0
  
  while i < str.length
    past = str[0...i]
    future = str[i..-2]

    index, length = past.longest_match(future)
    p [past, future, i, index, length]
    result << if length == 0 then 0 else i - index end
    result << length
    result << str[i + length].ord

    i += length + 1
  end

  result
end


result = lz77 'muxmuxbarbarmuxbarbarmuxmuxbarbarmuxbarbarbarmux'

puts( result.map do |i|
        i.to_s(16)
      end.join ' ' )
