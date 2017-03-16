
used = Dir['*.tex'].map do |file|
  IO.read(file).scan(/code\[.*?\]\{([a-z.-]+)\}/)
end.flatten

files = Dir['*.cpp']



puts(files - used)
