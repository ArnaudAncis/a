require 'MetaData'
require 'LaTeX'
require 'Upload'


meta_object do
  extend MetaData::Actions
  extend LaTeX::Actions
  extend Upload::Mixin

  tex_files = auto_tex(group_name: :tex)
  pdf_files = tex_files.map { |tex| tex.sub_ext '.pdf' }

  def remote_directory
    world.parent.remote_directory
  end

  uploadable(*pdf_files)
  upload_action
end
