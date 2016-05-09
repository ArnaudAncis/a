require 'MetaData'
require 'Html'
require 'Code'
require 'LaTeX'
require 'Image'
require 'Upload'
require 'Html'
require 'Environment'
require 'pathname'
require 'fileutils'
require '../shared.rb'

module Quiz
  extend Html::Generation::Quiz
end


class Context < SharedContext
  include Contracts::TypeChecking
  include Html::Generation
end



meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend LaTeX::Actions
  extend Image::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory + Pathname.pwd.basename.to_s
  end

  html_template('assignment', context: Context.new, group_name: 'html')

  tex_to_png2(*Dir['*.tex'], group_name: :img)

  
  uploadable('assignment.html')
  upload_action

  group_action(:all, [:img, :html])
  group_action(:full, [:all, :upload])
end
