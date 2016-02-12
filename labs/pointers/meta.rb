require 'MetaData'
require 'Html'
require 'Code'
require 'Cpp'
require 'Upload'
require 'pathname'


class Context
  include Contracts::TypeChecking

  def code(filename)
    typecheck do
      assert(filename: name_of_existing_file)
    end

    path = Pathname.new filename
    
    Cpp.compile(path)

    %{<div class="code"><pre>#{Code.format_file(path)}</pre></div>}
  end
end


meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory
  end

  html_template('assignment', context: Context.new, group_name: 'html')
  
  uploadable('assignment.html')
  upload_action

  group_action(:full, [:upload])
end
