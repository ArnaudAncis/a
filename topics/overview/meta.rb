require 'MetaData'
require 'Html'
require 'Upload'


meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory
  end

  html_template('overview', group_name: 'overview')
  
  uploadable('overview.html', 'ucll.css')
  upload_action

  group_action(:full, [:overview, :upload])
end
