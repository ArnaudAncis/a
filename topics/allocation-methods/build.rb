require 'LaTeX'
require 'Template'
require 'Files'


build do
  action :tex do
    Files.dir(pattern: '*.tex.template').each do |template_path|
      # Strip .tex.template extension
      basename = template_path.basename('.tex.template')

      regular = "#{basename}.tex"
      handouts = "#{basename}-handouts.tex"

      Template.process_file(input: template_path, output: regular, context: { :handout? => false })
      Template.process_file(input: template_path, output: handouts, context: { :handout? => true })

      export(LaTeX.compile regular)
      export(LaTeX.compile handouts)
    end
  end
end
