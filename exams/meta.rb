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

  def generate_answerboxes(cpp_output)
    cpp_output.lines.map do |line|
      /^(.):(.*)$/ =~ line.strip
      id, val = $1, $2
      "#{id}: \\answerbox[width=1cm,vertical alignment=c]{#{val}} \\\\"
    end.join("\n")
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
