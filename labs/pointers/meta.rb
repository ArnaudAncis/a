require 'MetaData'
require 'Html'
require 'Code'
require 'Cpp'
require 'Upload'
require 'Html'
require 'pathname'


module Quiz
  extend Html::Generation::Quiz
end


class Context
  include Contracts::TypeChecking
  include Html::Generation


  def compile(path)
    typecheck do
      assert(path: file)
    end

    Cpp.compile(path)
  end

  def interpret_exercise(basename)
    typecheck do
      assert(basename: string)
    end
    
    source_path = Pathname.new("#{basename}.cpp").expand_path

    typecheck do
      assert(source_path: file)
    end

    executable_path = Pathname.new("#{basename}.exe")

    Cpp.compile source_path
    output = `#{executable_path}`.strip

    <<-END
    <section class="interpretation-question">
      <h1>Interpretation Exercise</h1>
      <div class="code"><pre>#{Code.format_file(source_path).strip}</pre></div>
      <p>Output: #{Quiz.validated_input { verbatim output }}</p>
    </section>
    END
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
