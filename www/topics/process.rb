require 'find'


Find.find('.').select do |entry|
  entry.end_with? '.tex' and %r{aux-} !~ entry and /handout/ !~ entry and /-bw/ !~ entry
end.each do |entry|
  contents = IO.read(entry)

  contents.gsub( /documentclass{pvm-slides}/, 'documentclass{../pvm-slides}' )
  
end
