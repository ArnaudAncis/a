require 'MetaData'
require 'Upload'


meta_object do
  extend MetaData::Actions
  extend LaTeX::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory
  end

  uploadable('overview.html', 'ucll.css')
  upload_action
end
