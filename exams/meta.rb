require 'MetaData'
require 'LaTeX'
require 'Upload'


meta_object do
  extend MetaData::Actions
  extend LaTeX::Actions
  extend Upload::Mixin

  tex_files = [ 'exam.tex' ]
  tex_paths = tex_files.map { |tex_file| Pathname.new tex_file }
  tex_actions(*tex_files, group_name: :tex)
  pdf_paths = tex_paths.map { |tex| tex.sub_ext '.pdf' }

  def remote_directory
    world.parent.remote_directory + 'reference'
  end

  uploadable(*pdf_paths)
  upload_action

  group_action(:full, [:tex, :upload])
end
