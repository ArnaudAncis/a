require 'MetaData'
require 'Upload'


meta_object do
  extend MetaData::Actions
  extend Upload::Mixin

  inherit_remote_directory('topics')
end
