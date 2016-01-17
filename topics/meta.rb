require 'MetaData'
require 'Upload'


meta_object do
  extend MetaData::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory + 'topics'
  end
end
