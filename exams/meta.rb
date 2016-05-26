require 'MetaData2'
require 'LaTeX2'
require 'Template2'
require 'Upload2'
require 'Shortcuts'
require 'Cpp'


class Context
  include Contracts::TypeChecking

  def execute(filename)
    Cpp.compile_and_run(Pathname.new filename)
  end

  def generate_associative_answerboxes(cpp_output, arg)
    rows = cpp_output.lines.map do |line|
      /^(.):(.*)$/ =~ line.strip
      id, val = $1, $2
      "\\texttt{#{id}:} & \\answerbox[width=5cm,vertical alignment=c]{#{val}}"
    end.join("\\\\\n")

    <<-END
      \\begin{center}
        \\begin{tabular}{r@{}l}
          #{rows}
        \\end{tabular}
      \\end{center}
    END
  end

  def generate_string_answerbox(cpp_output, arg)
    if /n=(\d+)/ =~ arg then
      n_boxes = $1.to_i
    else
      n_boxes = cpp_output.length
    end

    if n_boxes < cpp_output.size then
      abort "Too few boxes to contain answer!"
    end

    padded_cpp_output = cpp_output.strip.ljust(n_boxes, ' ')
    
    boxes = padded_cpp_output.split(//).map do |char|
      "\\answerbox[width=1cm]{#{char}}"
    end.join(' ')

    <<-END
    \\begin{center}
      #{boxes}
    \\end{center}
    Vul \\'e\\'en teken per vakje in. Mogelijk worden er minder tekens uitgevoerd dan er vakjes zijn.
    END
  end
end


meta_object do
  extend MetaData2
  extend LaTeX2::Actions
  extend Template2::Actions
  extend Shortcuts::Actions
  extend Upload2::Actions

  template_actions = Dir['*.template'].map do |template_file|
    template(input: template_file, context: Context.new)
  end
  bind( { :tex => make_sequence(*template_actions, description: 'Processes templates') } )
  
  
  tex_files = [ 'with-solutions.tex', 'without-solutions.tex' ]
  texs = tex_actions(*tex_files, action_name: :pdf).child_actions

  quick_all( :tex, :pdf )

  inherit_remote_directory 'exams'

  uploadable( *texs.map { |tex| tex.output_path } )
end
