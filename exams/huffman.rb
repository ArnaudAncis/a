Leaf = Struct.new :letter, :weight
Branch = Struct.new :left, :right, :weight


def freqs(str)
  result = Hash.new 0
  
  str.split(//).each do |letter|
    result[letter] += 1
  end

  result
end


def build_tree(freqs)
  nodes = freqs.to_a.map { |letter, weight| Leaf.new(letter, weight) }

  while nodes.length > 1
    nodes.sort! { |x, y| x.weight <=> y.weight }

    left = nodes.shift
    right = nodes.shift

    nodes << Branch.new(left, right, left.weight + right.weight)
  end

  nodes[0]
end


def build_codes(tree)
  case tree
  when Branch
  then
    lcodes = build_codes tree.left
    rcodes = build_codes tree.right

    Hash[ lcodes.to_a.map do |letter, code|
            [ letter, "0#{code}" ]
          end + rcodes.to_a.map do |letter, code|
            [ letter, "1#{code}" ]
          end ]

  when Leaf
  then { tree.letter => "" }
  end
end

fs = { 'A' => 50,
       'B' => 7,
       'C' => 44,
       'D' => 34,
       'E' => 25,
       'F' => 12,
       'G' => 19,
       'H' => 30 }

tree = build_tree fs

codes = build_codes tree

p fs
p codes

