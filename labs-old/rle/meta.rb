require 'MetaData'
require 'Html'
require 'Code'
require 'Cpp'
require 'Upload'
require 'Html'
require 'Environment'
require 'pathname'
require 'fileutils'
require 'find'
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
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory + Pathname.pwd.basename.to_s
  end

  html_template('assignment', context: Context.new, group_name: 'html')
  
  uploadable('assignment.html')
  uploadable_globs( '*.jpg' )
  uploadable_globs( 'sample.bmp' )
  upload_action

  group_action(:full, [:html, :upload])
end
