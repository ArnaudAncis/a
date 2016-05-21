require 'MetaData'
require 'Html'
require 'Upload'
require 'Contracts'

class Context
  include Contracts::TypeChecking
  
  def topic(name, description, handouts: false)
    typecheck binding do
      assert(name: string, description: string)
    end

    if not File.directory? "../topics/#{name}"
    then abort "ERROR: No directory #{name}"
    end

    slides_link = %{<a href="topics/#{name}.pdf">#{description}</a>}
    handout_link = if handouts
                   then %{ <a class="handout" href="topics/#{name}-handouts.pdf">(handouts)</a>}
                   else ''
                   end
    
    "#{slides_link}#{handout_link}"
  end

  def lab(name, description)
    typecheck binding do
      assert(name: string, description: string)
    end

    if not File.directory? "../labs/#{name}"
    then abort "ERROR: No directory #{name}"
    end

    %{<a href="labs/#{name}/assignment.html">#{description}</a>}
  end
end


meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory
  end

  html_template('overview', group_name: 'html', context: Context.new)
  
  uploadable('overview.html')
  upload_action

  group_action(:full, [:html, :upload])
end
