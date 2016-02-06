require 'MetaData'
require 'Html'
require 'Upload'
require 'Contracts'

class Context
  include Contracts::TypeChecking
  
  def link(name, description)
    typecheck binding do
      assert(name: string, description: string)
    end

    if not File.directory? "../#{name}"
    then abort "ERROR: No directory #{name}"
    end

    %{<li><a href="#{name}.pdf">#{description}</a></li>}
  end
end


meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory
  end

  html_template('overview', group_name: 'overview', context: Context.new)
  
  uploadable('overview.html', 'ucll.css')
  upload_action

  group_action(:full, [:overview, :upload])
end
