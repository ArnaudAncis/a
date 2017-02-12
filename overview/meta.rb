require 'MetaData2'
require 'Html2'
require 'Template2'
require 'Upload2'
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
  extend MetaData2
  extend Template2::Actions
  extend Upload2::Actions

  inherit_remote_directory

  bind( { :html => template(input: 'overview.html.template', context: Context.new) } )
  
  uploadable('overview.html')
end
