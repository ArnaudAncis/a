require 'Log'
require 'Dynamic'
require 'MetaData2'
require 'LaTeX2'
require 'Upload2'


meta_object do
  extend MetaData2
  extend LaTeX2::Actions
  extend Upload2::Actions
  
  inherit_remote_directory 'reference'

  pdf_action = tex_actions('full-edition.tex', 'limited-edition.tex')
  
  uploadable(*pdf_action.child_actions.map(&:output_path))

  bind({ :upload => upload_action })
end
