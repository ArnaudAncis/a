require 'MetaData'
require 'LaTeX'
require 'Upload'
require 'Template'
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
  extend MetaData::Actions
  extend LaTeX::Actions
  extend Upload::Mixin
  extend Template::Actions

  
  tex_files = [ 'with-solutions.tex', 'without-solutions.tex' ]
  tex_paths = tex_files.map { |tex_file| Pathname.new tex_file }
  tex_actions(*tex_files, group_name: :pdf)
  pdf_paths = tex_paths.map { |tex| tex.sub_ext '.pdf' }

  action_names = Dir['*.template'].map do |template_name|
    template_path = Pathname.new template_name
    output_path = template_path.basename '.template'
    template_generate(template_name, output_path.to_s, context: Context.new) # Returns action_name
  end

  group_action(:tex, action_names)
  
  def remote_directory
    world.parent.remote_directory + 'exams'
  end

  uploadable(*pdf_paths)
  upload_action

  group_action(:full, [:tex, :pdf, :upload])
end
